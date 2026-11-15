# patchcord

patchcord is meant to carry audio between two Macs on the same local
network (LAN). This first version is only a build skeleton. It builds one
small `patchcord` program that links the [AOO](https://github.com/essej/aoo)
audio-over-network library and prints both versions. It does not stream audio yet.

## Prerequisites

- macOS with Apple clang from the Command Line Tools (`xcode-select --install`)
- git
- [uv](https://docs.astral.sh/uv/)

uv provides pinned versions of CMake and Ninja, set in `pyproject.toml` and
`uv.lock`. You do not need a separate CMake or Ninja install.

## Build

```sh
git clone --recurse-submodules https://github.com/boecht/patchcord.git
cd patchcord
uv run cmake --preset dev
uv run cmake --build --preset dev
uv run ctest --preset dev
```

If you cloned without `--recurse-submodules`, first fetch AOO:

```sh
git submodule update --init --recursive
```

Then run the program:

```sh
./build/dev/patchcord --version
```

## License

patchcord is licensed under the MIT License (see `LICENSE`). It uses AOO,
which is included as a git submodule in `external/aoo` and keeps its own
BSD-3-Clause license.
