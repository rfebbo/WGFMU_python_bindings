# WGFMU Python Bindings

## B1530A Software Prerequisites

- [B1530a wgfmu instrument library](https://www.keysight.com/ca/en/lib/software-detail/driver/b1530a-wgfmu-instrument-library--sample-programs-2117445.html)

- Python with pybind11


## Building

### With pip (recommended)

The bindings ship a `setup.py` / `pyproject.toml`, so they build with just the MSVC
toolchain — the **Build Tools for Visual Studio 2022** ("Desktop development with C++" /
VCTools workload), no full IDE required. The `wgfmu.h` / `wgfmu.lib` from the B1530A
instrument library must be present (default `C:\Program Files\Agilent\B1530A\`).

    pip install pybind11
    pip install .                                              # from a local clone
    # or straight from GitHub, without cloning first:
    pip install git+https://github.com/rfebbo/WGFMU_python_bindings.git

This compiles `WGFMUpy` and installs it into site-packages (importable directly — no
manual `.pyd` copy). It uses the building interpreter's own headers/libs, so it is not
tied to a fixed Python path. If the Keysight SDK is elsewhere, point to it first:

    set WGFMU_SDK=C:\Program Files\Agilent\B1530A

### With Visual Studio 2022 (manual)

This project was built using Visual Studio 2022. The wgfmu.h and wgfmu.lib files from B1530A wgfmu instrument library are required. After installation, they should be located in the C:\Program Files\Agilent\B1530A\ directory. Install Python then, using pip, install pybind11.


    pip install pybind11 

The Python installation is expected to be located here

    %AppData%\..\Local\Programs\Python\Python310

Depending on the python version installed, the AdditionalLibraryDirectories and AdditionalIncludeDirectories may need to be edited.

Open the .sln file with Visual Studio 2022, right click on the project and build solution.

Once the project is built, copy the .pyd file to the Python site-packages folder.

Optionally copy the .pyi file to the Python site-packages folder for docstrings