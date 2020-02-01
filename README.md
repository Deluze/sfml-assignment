# Waves - SFML Tower Defense Game

## Introduction

This game has been made accordingly to the `Waves` theme for the BUAS intake assignment (2020).
It uses the libraries of [SFML](https://github.com/SFML/SFML) to make rendering and the use of utility functions possible.

My goal was to also make this project cross-platform, so it has made using CMake and vcpkg.

## The game

The game is comparable to some known tower defense games out there.

### Controls

```bash
    Forcing waves:
        If there are 0 enemies on the field (counter, right top) you can force a wave
        by pressing the 'Next Wave' button on the right top side.
        
    Building towers:
        If you have enough gold you can click on a tower on the bottom side (the shop)
        After that, to build the tower you have to click on a tile that is buildable (green tiles)
        and now, the tower will forever attack automatically.
```


# Installation instructions

### Pre-requisites:
[CMake](https://cmake.org/) has to be installed

[vcpkg](https://github.com/microsoft/vcpkg) has to be installed (user wide integration setup OR `VCPKG_ROOT` environment variable set)

## Windows:

```bash
    git clone https://github.com/deluze/sfml-assignment
    cd sfml-assignment
    vcpkg install sfml
    mkdir build
    cd build
    cmake ..
```

and you can now open up the solution file.

## Linux:

```bash
    git clone https://github.com/deluze/sfml-assignment
    cd sfml-assignment
    sudo apt-get install libsfml-dev
    mkdir build
    cd build
    cmake ..
```

if you want to compile your code use

```bash
    cmake --build .
```

in the cmake target directory

## Sources

[CMakeSettings](https://docs.microsoft.com/en-us/cpp/build/cmakesettings-reference?view=vs-2019)
: for making builds for windows easy

[SFML](https://github.com/SFML/SFML) : For graphic functionality & utility functions

All the assets have been made by me
