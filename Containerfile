FROM git.miku/talisein/songbot-sdk:latest AS builder

WORKDIR /scratch

COPY . .

RUN meson setup build --prefix /app -Dcpp_std=c++26 --buildtype=debugoptimized -Dinstall_tests=true

ARG RUN_BENCHMARKS
RUN meson compile -C build && meson test -C build --suite songbot && meson install -C build
RUN if [ -n "$RUN_BENCHMARKS" ]; then meson test -C build --benchmark -v; fi

FROM git.miku/talisein/songbot-runtime:latest

COPY --from=builder /app /app

RUN echo "/app/lib64" > /etc/ld.so.conf.d/app.conf && ldconfig

ENTRYPOINT ["/app/bin/songbot"]