#!/usr/bin/env bash

set -eu -o pipefail

if [[ "$TRAVIS_OS_NAME" == "linux" ]]; then
  CMAKE_VERSION="3.13.4"
  target_path=$HOME/Deps/cmake/$CMAKE_VERSION
  cmake_url="https://cmake.org/files/v${CMAKE_VERSION%.*}/cmake-${CMAKE_VERSION}-Linux-x86_64.tar.gz"
  mkdir -p "$target_path"
  curl -Ls "$cmake_url" | tar -xz -C "$target_path" --strip-components=1
  pip install --user pipenv --upgrade
fi
