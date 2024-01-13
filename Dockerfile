FROM debian:stable as builder

MAINTAINER Guy John <memento@rumblesan.com>

RUN apt-get update
RUN apt-get install -y clang cmake make git

RUN apt-get install -y libshout3-dev libconfig-dev libvorbis-dev libsndfile-dev libck-dev liblua5.4-dev
ENV CC /usr/bin/clang

RUN git clone https://github.com/rumblesan/bclib.git /opt/bclib
RUN cd /opt/bclib/build && cmake .. && make && make install

RUN git clone --recurse-submodules https://github.com/libpd/libpd.git /opt/libpd
RUN cd /opt/libpd && make && make install

RUN mkdir -p /opt/memento/build
COPY CMakeLists.txt /opt/memento
COPY libmemento /opt/memento/libmemento
COPY main /opt/memento/main
COPY tests /opt/memento/tests

WORKDIR /opt/memento
RUN cd build; cmake ..; make


FROM debian:stable

RUN apt-get update
RUN apt-get install -y git make
RUN apt-get install -y libshout3 libconfig9 libvorbis-dev libsndfile1 libck-dev libssl-dev
RUN apt-get install -y liblua5.4-dev luarocks
RUN mkdir -p /opt/memento/app
RUN mkdir -p /opt/memento/cfg
RUN mkdir -p /opt/memento/patches
RUN mkdir -p /opt/memento/lua

RUN luarocks --lua-version=5.4 install milua CRYPTO_DIR=/usr

WORKDIR /opt/memento/app

COPY --from=builder /opt/memento/build/main/memento /usr/local/bin/
COPY patches /opt/memento/patches

# this feels sketchy...
COPY --from=builder /usr/local/lib/libpd.so /usr/local/lib/
COPY cfg /opt/memento/cfg
COPY lua /opt/memento/lua

CMD ["memento", "/opt/memento/cfg/radio.cfg"]
