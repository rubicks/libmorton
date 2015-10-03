#!/usr/bin/env bash

# github.com/rubicks/morton/autogen.sh

set -eu
autoreconf -ivf $(dirname $(readlink -f ${BASH_SOURCE}))
