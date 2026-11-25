FROM git.miku/talisein/songbot-sdk:latest AS builder

WORKDIR /scratch

# LAYERED SO A concerts-raw_data.cppm-ONLY COMMIT REUSES EVERYTHING ELSE.
# Needs `buildah bud --layers` (docker-build.yml) and the runner's persistent
# image store.
#
# Stage one copies every file except raw_data and builds everything it can.
# The placeholder is an #error, so each target that imports concerts fails,
# while std, dpp, prometheus, songs and the ~88 MB vocadb data modules all
# build and get cached in this layer. `-k 0` lets it keep going; that keeps
# the target list from needing upkeep, at the cost of a deliberately
# "failing" ninja run.
#
# .git is excluded too, because every commit changes it (and locally so does
# any `git status`), and that would invalidate this layer every time. Only
# gen_version.py reads it, and version.hpp is regenerated on every build
# anyway, so .git arrives in stage two.
COPY --exclude=src/concerts-raw_data.cppm --exclude=.git . .
RUN echo '#error placeholder: the real file is copied in a later layer' > src/concerts-raw_data.cppm && \
    meson setup build --prefix /app -Dcpp_std=c++26 --buildtype=release && \
    (ninja -C build -k 0 > /dev/null 2>&1 || true)

# Stage two. The touch makes the real file newer than everything in the
# cached build/ whatever mtime COPY gave it, so ninja rebuilds raw_data and
# exactly the targets that depend on it.
COPY .git/ .git/
COPY src/concerts-raw_data.cppm src/
RUN touch src/concerts-raw_data.cppm

ARG RUN_BENCHMARKS
# --skip-subprojects: only songbot's own targets belong in /app. Without it
# magic_enum's headers and .pc file were installed there too.
RUN meson compile -C build && meson test -C build --suite songbot && meson install -C build --skip-subprojects
RUN if [ -n "$RUN_BENCHMARKS" ]; then meson test -C build --benchmark -v; fi

# The vocadb data library goes in its own image layer (see below), so move it
# out of /app here, or the /app COPY would carry it a second time.
RUN mkdir -p /out/vocadb/app/lib64 && mv /app/lib64/libsongbot-vocadb.so* /out/vocadb/app/lib64/

FROM git.miku/talisein/songbot-runtime:latest

# ~93 MB, and byte-identical unless vocadb or localvoid data changed, so the
# layer cache gives it the same digest: the push skips the blob and 39music's
# pull reports "already exists". Keep this COPY before the /app one.
COPY --from=builder /out/vocadb/ /
COPY --from=builder /app /app

RUN echo "/app/lib64" > /etc/ld.so.conf.d/app.conf && ldconfig

ENTRYPOINT ["/app/bin/songbot"]
