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
    xz

run wget -qO- https://raw.githubusercontent.com/rubicks/autotoolme/master/autotoolme.sh | sh

add . .

run ./build.sh

cmd /bin/sh
