#include <Sleefe.hpp> // this is the only header file needed to use the library

#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace sleefe;

int main() {
  // For this example, let us define coefficients of univariate Bezier
  // functions of degree 2 through 9. For each set of coefficients, we
  // will build  sleefes with  1,...,d segments for  the corresponding
  // function.
  std::vector<std::vector<double>> bezierCoeffs = {
      {0.0, 1.0, 0.8},                                    // degree 2
      {0.0, 1.0, 0.8, -0.2},                              // degree 3
      {0.0, 1.0, 0.8, -0.2, 2.5},                         // degree 4
      {0.0, 1.0, 0.8, -0.2, 2.5, 3.5},                    // degree 5
      {0.0, 1.0, 0.8, -0.2, 2.5, 3.5, 2.0},               // degree 6
      {0.0, 1.0, 0.8, -0.2, 2.5, 3.5, 2.0, 5.2},          // degree 7
      {0.0, 1.0, 0.8, -0.2, 2.5, 3.5, 2.0, 5.2, 4.0},     // degree 8
      {0.0, 1.0, 0.8, -0.2, 2.5, 3.5, 2.0, 5.2, 4.0, 0.5} // degree 9
  };

  // To build one or more sleefes, we start by defining a builder.
  UniSleefeBuilder builder;

  std::cout << std::fixed << std::setprecision(10) << std::endl;

  for (const auto &coeffs : bezierCoeffs) {
    // Compute the degree of the Bezier function.
    const auto degree = static_cast<int>(coeffs.size()) - 1;

    // Create sleefes with 1,...,9 segments for the current function.
    for (auto nSegs = 1; nSegs <= UniSleefeBuilder::MaximumNumberOfSegments;
         ++nSegs) {
      std::cout << "Degree " << degree << ", " << nSegs
                << " segments(s): " << std::endl;

      // A sleefe is created by calling method 'build()'.
      const auto sleefe = builder.build(nSegs, coeffs);

      // Display the values of the sleefe upper component breakpoints.
      for (const auto &pt : sleefe.upperValues()) {
        std::cout << pt << "  ";
      }

      std::cout << std::endl;

      // Display the values of the sleefe lower component breakpoints.
      for (const auto &pt : sleefe.lowerValues()) {
        std::cout << pt << "  ";
      }

      std::cout << std::endl;
    }

    std::cout << std::endl;
  }

  return EXIT_SUCCESS;
}
