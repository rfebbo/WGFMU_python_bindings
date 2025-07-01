# WGFMU Python Bindings

## B1530A Software Prerequisites

- [B1530a wgfmu instrument library](https://www.keysight.com/ca/en/lib/software-detail/driver/b1530a-wgfmu-instrument-library--sample-programs-2117445.html)

## Current Status

The C++ file was initially created using a python script which parses wgfmu.h then modified manually. The manual modifications fixed a few functions that used C++ pointers which needed to be converted into std::vectors. There are still several funcitons which need this treatment.

## Building

The wgfmu.h and wgfmu.lib files from B1530A wgfmu instrument library are required. After installation, they should be located in the C:\Program Files\Agilent\B1530A\ directory. This project was built using Visual Studio 2022. The .sln file is included. Once the project is built, copy the .pyd file to the Python site-packages folder.