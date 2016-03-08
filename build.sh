#!/usr/bin/env bash

# github.com/rubicks/libmorton/build.sh

set -eu
_here=$(dirname $(readlink -f ${BASH_SOURCE}))
if [ ! -f "${_here}/configure" ]
then
    ${_here}/autogen.sh
fi
${_here}/configure
make
make check
make distcheck
