FROM fedora:42 AS builder

RUN dnf -y install meson g++ libcurl-devel zlib-ng-devel openssl-devel systemd-devel git cmake && dnf clean all

RUN mkdir /app

RUN mkdir /scratch
WORKDIR /scratch

COPY . .

RUN meson setup build --prefix /app -Dcpp_std=c++26

RUN meson compile -C build && meson test -C build && meson install -C build

FROM fedora:42

RUN dnf -y install libcurl zlib-ng openssl tini && dnf clean all

COPY --from=builder /app /app

RUN echo "/app/lib64" > /etc/ld.so.conf.d/app.conf && ldconfig

ENTRYPOINT ["/usr/bin/tini", "--", "/app/bin/songbot"]