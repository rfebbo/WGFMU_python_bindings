"""setup.py for the WGFMU pybind11 bindings (github.com/rfebbo/WGFMU_python_bindings).

Build the WGFMUpy extension with just the MSVC toolchain -- the "Build Tools for
Visual Studio 2022" (Desktop C++ / VCTools workload) are enough; the full VS IDE and
the checked-in .sln are not needed:

    py -m pip install pybind11        # (build dep; also pulled in automatically below)
    py -m pip install .               # compile + install WGFMUpy into site-packages

Because setuptools uses the *building* interpreter's own headers and import library,
this is portable across Python installs -- no hard-coded Python path like the .sln has.
The one machine-specific input is the Keysight B1530A WGFMU SDK (which provides
wgfmu.h / wgfmu.lib). It defaults to the standard install location; override with:

    set WGFMU_SDK=C:\\Program Files\\Agilent\\B1530A
    py -m pip install .

At runtime WGFMUpy.pyd still needs wgfmu.dll on PATH (installed by the Keysight
B1500/B1530 software).
"""
import glob
import os

from pybind11.setup_helpers import Pybind11Extension, build_ext
from setuptools import setup

# Keysight B1530A WGFMU SDK: has include\wgfmu.h and Lib_x64\wgfmu.lib.
SDK = os.environ.get("WGFMU_SDK", r"C:\Program Files\Agilent\B1530A")

sources = sorted(glob.glob(os.path.join("wgfmu_py", "*.cpp")))
if not sources:
    raise SystemExit("No sources found under wgfmu_py/ -- run pip from the repo root.")

ext_modules = [
    Pybind11Extension(
        "WGFMUpy",  # must match PYBIND11_MODULE(WGFMUpy, m) in wgfmu_py.cpp
        sources=sources,
        include_dirs=[os.path.join(SDK, "include")],
        library_dirs=[os.path.join(SDK, "Lib_x64")],  # x64 import library
        libraries=["wgfmu"],                            # links wgfmu.lib
        cxx_std=14,
    )
]

setup(
    name="WGFMUpy",
    version="0.1",
    description="pybind11 bindings for the Keysight B1530A WGFMU C API",
    author="Rocco Febbo",
    url="https://github.com/rfebbo/WGFMU_python_bindings",
    ext_modules=ext_modules,
    cmdclass={"build_ext": build_ext},
    python_requires=">=3.8",
    # Ship the type stub next to the compiled module so IDEs / type checkers pick it up.
    # WGFMUpy is a single top-level extension (not a package), so there is no package to
    # attach package_data to; installing WGFMUpy.pyi via the wheel's data scheme drops it
    # into <prefix>\Lib\site-packages next to WGFMUpy.pyd. (Windows layout, which is all
    # this lib targets.)
    data_files=[("Lib/site-packages", ["WGFMUpy.pyi"])],
)
