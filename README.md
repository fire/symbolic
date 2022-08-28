[![Builds](https://github.com/tmigimatsu/symbolic/actions/workflows/builds.yaml/badge.svg)](https://github.com/tmigimatsu/symbolic/actions/workflows/builds.yaml)
[![Tests](https://github.com/tmigimatsu/symbolic/actions/workflows/tests.yaml/badge.svg)](https://github.com/tmigimatsu/symbolic/actions/workflows/tests.yaml)
[![Docs](https://github.com/tmigimatsu/symbolic/actions/workflows/docs.yaml/badge.svg)](https://github.com/tmigimatsu/symbolic/actions/workflows/docs.yaml)

# symbolic

`symbolic` is a C++ library for parsing and manipulating [Planning Domain
Definition Language (PDDL)](https://planning.wiki/_citedpapers/pddl1998.pdf)
symbols for AI planning. This library is built upon
[VAL](https://github.com/KCL-Planning/VAL), a C++ library for validating PDDL
specifications.

See the documentation for `symbolic`
[here](https://tmigimatsu.github.io/symbolic/).

## Installation

To compile the C++ library, follow the instructions below.

This library is written in C++. It has been tested on
Ubuntu 18.04, Ubuntu 20.04, and macOS 10.15 Catalina.

Compilation requirements:
- `cmake >= 3.11`
- C++17 support (`gcc >= 7`, `clang >= 7`).

See [Updating CMake](#updating-cmake) for details on how to install the latest
`cmake`. Ubuntu 20.04 comes with a sufficient version of `cmake` out of the box.

### C++ only

The C++ portion of `symbolic` is header-only, but to add `symbolic` as a
`cmake` dependency, you can run the following:
```sh
mkdir build
cmake -B build
```

## Updating CMake

### Ubuntu 18.04

You can also install it through `apt`:
```sh
sudo apt-get update && sudo apt-get install -y apt-transport-https ca-certificates gnupg wget
wget -O - https://apt.kitware.com/keys/kitware-archive-latest.asc 2>/dev/null | gpg --dearmor - | sudo tee /etc/apt/trusted.gpg.d/kitware.gpg >/dev/null
sudo apt-add-repository -y 'deb https://apt.kitware.com/ubuntu/ bionic main'
sudo apt-get update && sudo apt-get install -y cmake kitware-archive-keyring
sudo rm /etc/apt/trusted.gpg.d/kitware.gpg
```

### macOS

Install `cmake` through Homebrew:
```sh
brew install cmake
```
