# WGFMU Python Bindings

## B1530A Software Prerequisites

- [B1530a wgfmu instrument library](https://www.keysight.com/ca/en/lib/software-detail/driver/b1530a-wgfmu-instrument-library--sample-programs-2117445.html)

- Python with pybind11


## Building

This project was built using Visual Studio 2022. The wgfmu.h and wgfmu.lib files from B1530A wgfmu instrument library are required. After installation, they should be located in the C:\Program Files\Agilent\B1530A\ directory. Install Python then, using pip, install pybind11.


    pip install pybind11 

The Python installation is expected to be located here

    %AppData%\..\Local\Programs\Python\Python310

Depending on the python version installed, the AdditionalLibraryDirectories and AdditionalIncludeDirectories may need to be edited.

Open the .sln file with Visual Studio 2022, right click on the project and build solution.

Once the project is built, copy the .pyd file to the Python site-packages folder.

Optionally copy the .pyi file to the Python site-packages folder for docstrings