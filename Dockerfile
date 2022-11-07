FROM debian:stretch as builder

MAINTAINER Guy John <memento@rumblesan.com>

RUN apt-get update
RUN apt-get install -y clang cmake make git

RUN apt-get install -y libshout3-dev libconfig-dev libvorbis-dev libsndfile-dev libck-dev
ENV CC /usr/bin/clang

RUN git clone https://github.com/rumblesan/bclib.git /opt/bclib
RUN cd /opt/bclib/build && cmake .. && make && make install

RUN git clone --recurse-submodules https://github.com/libpd/libpd.git /opt/libpd
RUN cd /opt/libpd && make && make install

RUN mkdir -p /opt/memento/build
COPY CMakeLists.txt /opt/memento
COPY libpatchwerk /opt/memento/libpatchwerk
COPY main /opt/memento/main
COPY tests /opt/memento/tests

WORKDIR /opt/memento
RUN cd build; cmake ..; make


FROM debian:stretch-slim

RUN apt-get update
RUN apt-get install -y libshout3 libconfig9 libvorbis-dev libsndfile1 libck-dev
RUN mkdir -p /opt/memento

WORKDIR /opt/memento

COPY --from=builder /opt/memento/build/main/memento /usr/local/bin/
COPY patches /opt/memento/patches

# this feels sketchy...
COPY --from=builder /usr/local/lib/libpd.so /usr/local/lib/
COPY radio.cfg /opt/memento/

CMD ["memento", "/opt/memento/radio.cfg"]
