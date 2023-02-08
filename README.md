# SLEEFE
A library to build Subdividable Linear Equi-spaced Efficient Function Enclosures (SLEEFE)

## INTRODUCTION

This repository contains  the source code and  documentation files for
the library `SLEEFE`. This library offers functionality to build tight
lower and upper piecewise-linear envelopes for the graph of univariate
polynomial  functions  in  Bernstein-Bézier form.  The  picture  below
illustrates a sleefe for a univariate polynomial function of degree 3.
The Bernstein-Bézier coefficients of the function are `3`, `-2`, `-1`,
and `0.5`.   The lower and  upper envelopes  of the sleefe  have three
line segments (i.e., four breakpoints) each.

![sleefe example](doc/img/sleefe_example.png | width=100px)

The source code is organized as follows:

* `bin`            - subdirectory where the executable `sleefe-demo` will be installed
* `doc`            - subdirectory where `Doxygen` documentation files are
* `ide`            - subdirectory where ready-to-use project files for Visual Studio, Visual Code, and Xcode are
* `include`        - subdirectory where header files of the library will be installed
* `lib`            - subdirectory where the lib file of the library will be installed
* `plots`          - subdirectory containing plots of the anti-difference functions
* `src`            - subdirectory containing the library, demo, and uni tests source files
* `tst`           - subdirectory where the executable `sleefe-tst` will be installed 
* `CMakeLists.txt` - input file for the `CMake` build system
* `LICENSE.md`     - copyright and license file
* `README.md`      - this file

> Detailed documentation of the code can be found in the file `refman.pdf` inside the directory `doc`.

## INSTALLATION

You will need `CMake` 3.15 or  higher and a C++ compiler that supports
C++  17 to  build the  library, the  demo, and  (optionally) the  unit
tests. If you  enable the generation of unit tests,  then `CMake` will
try   to    download   and   install   the    *GTest*   library   from
[here](https://github.com/google/googletest/).   Both   options   have
successfully been built  with `CMake` version 3.22.1  on Linux (Ubuntu
22.04 LTS with GNU g++ 11.2.0),  Windows 10 (MS Visual Studio 17), and
macOS Monterrey version 12.6.2 (clang version 14.0.0).

To build and install the library, follow the steps below:

1. Download or clone the code, and then enter the directory `SLEEFE`
2. Run `cmake -S . -B build`
3. Run `cmake --build build --config Release`
4. Run `cmake --install build --prefix <full path to your SLEEFE directory>`

If all goes well, then you should see the executable `sleefe-demo` (or `sleefe-demo.exe`
on `Windows`) in subdirectory `bin` and the library `libslefe.a` (or `slefe.lib` on
`Windows`) in subdirectory `lib`.

If you wish to build the unit tests, then execute the steps above with the following change to step 2:

+ Run `cmake -S . -B build -D BUILD_UNIT_TESTS=ON`

If all goes well, then you should see the application `sleefe-tst` (or `sleefe-tst.exe`
on Windows) in subdirectory `tst`.

Likewise, if you wish to build `Doxygen` documentation files, then execute the
same steps above with the following change to step 2:

+ Run `cmake -S . -B build -D BUILD_DOC=ON`

or

+ Run `cmake -S . -B build -D BUILD_UNIT_TESTS=ON -D BUILD_DOC=ON`


Documentation is generated only if `CMake` can find `Doxygen` in your system. If
this is the case and the build succeeds, then the documentation files are placed
in subdirectory `doc`.

If you wish `CMake' to create a Visual Studio project, then step 2 above should
be

+ Run `cmake -G "Visual Studio 15 2017" -A x64 -S . -B build`

The exact generator depends on the version of your Visual Studio. Please, refer 
to the CMake [documentation](https://cmake.org/cmake/help/latest/manual/cmake-generators.7.html) 
to determine which one is right for you.


If you wish `CMake' to create an Xcode project, then 2 above should
be

+ Run `cmake -G Xcode -S . -B build`

**If you  do not  want to  use CMake**, you  can try  the ready-to-use
projects  in directory  `ide`.   There are  ready-to-use projects  for
Visual Studio (Windows),  XCode (macOSX), and Linux  (Visual Code). In
all  cases, the  paths  are  *relative*.  So,  do  **not** move  these
projects out of  directory `ide`. During the build,  the projects will
place the library file and the executable demo file in the directories
`lib` and `bin`, respectively.

##  References

1. Lutterkort, D.,
   [Envelopes for Nonlinear Geometry][1],
   PhD thesis, Purdue University, May 2000.

2. Lutterkort, D. and Peters, J.,
   [Linear envelopes for uniform B-spline curves][2],
   Curves and Surface Fitting, Saint-Malo, France, July 1-7, 1999, p. 239-246.

3. Lutterkort, D. and Peters, J.,
   [Optimized refinable enclosures of multivariate polynomial pieces][3],
   CAGD, 18(9), 2001, p. 851-863.

4. Wu, X. and Peters, J.,
   [On the Optimality of Piecewise Linear Max-norm Enclosures based on Slefes][4],
   Curves and Surface Design, Saint-Malo, France, 2002, p. 335-344.

[1]: https://www.cise.ufl.edu/research/SurfLab/papers/99envthesis.pdf
[2]: https://www.cise.ufl.edu/research/SurfLab/papers/stmalo.ps
[3]: https://doi.org/10.1016/S0167-8396(01)00067-X
[4]: https://www.cise.ufl.edu/research/SurfLab/papers/02stmaloSlefe.ps.gz


## CONTACT

If you run  into trouble compiling or using the library, please email me at:

mfsiqueira@gmail.com

Have fun!

Marcelo Siqueira
