# github.com/rubicks/morton/Dockerfile

from alpine
maintainer rubicks

run \
  apk update  && \
  apk upgrade && \
  apk add     \
    autoconf  \
    automake  \
    coreutils \
    file      \
    g++       \
    git       \
    libtool   \
    make      \
    man       \
    tar       \
    xz        \
  && >/stamp.txt date -uIs

env WORKDIR=/morton

workdir ${WORKDIR}

add . .

run \
  cd $(mktemp -d) && \
  autoreconf -ivf ${WORKDIR} && \
  ${WORKDIR}/configure && \
  make && \
  make check && \
  make distcheck && \
  make install

cmd /bin/sh
