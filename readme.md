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

This produces `WGFMUpy.pyd`. Rather than copying it into site-packages by hand, prefer the
`pip install .` path above — pip installs the module into the correct location and manages
it. A hand-copied `.pyd` placed elsewhere on `sys.path` (e.g. the stdlib `Lib\` folder) can
shadow the pip-installed one and load a stale build, so avoid manual copies.

## Maintaining the type stub (`WGFMUpy.pyi`)

The rich docstrings/signatures live in `WGFMUpy.pyi` (a PEP 561 stub), and `setup.py`
installs it next to the compiled module so editors and type-checkers pick it up. The stub
is **hand-written**, so it can drift from the actual bindings if you change `wgfmu_py.cpp`
without updating it (that's how a few signatures/enum names got out of sync historically).

The runtime docstrings (`help(WGFMUpy.foo)`) come from the terse `R"pbdoc(...)"` strings in
`wgfmu_py.cpp` — the good prose is only in the stub.

To keep them in sync, treat the compiled module as the source of truth for **signatures**
and regenerate a reference stub with [`pybind11-stubgen`](https://github.com/sizmailov/pybind11-stubgen):

    pip install pybind11-stubgen
    pip install .                         # build/install the current bindings
    pybind11-stubgen WGFMUpy -o _stubcheck # generates _stubcheck/WGFMUpy.pyi from the module

then diff `_stubcheck/WGFMUpy.pyi` against `WGFMUpy.pyi` — any signature/enum-name
difference is drift to reconcile. (The generated stub won't have the hand-written prose, so
use it to check signatures, not to replace the maintained stub.)

For full auto-sync you could instead move the docstrings into the C++ `pbdoc` strings and
let `pybind11-stubgen` generate the whole `.pyi` — that makes the `.cpp` the single source
of truth (`help()` works too), at the cost of a one-time prose migration.