#pragma once

#include "UniSleefe.hpp"

#include <vector>

namespace sleefe {

/**
 * \class UniSleefeBuilder
 * \brief A class to build sleefes from Bezier coefficients of univariate polynomial functions. 
 */
class UniSleefeBuilder {
public:
  /** Default constructor. */
  UniSleefeBuilder() = default;

  /**
   * \fn build()
   * \brief Builds a sleefe for a univariate Bezier function of a given degree.
   * \param numberOfSegments Number of linear pieces in the sleefe.
   * \param coeffs Array with the Bezier coefficients of the function.
   * \return A sleefe for the given univariate function.
   */
  UniSleefe build(int numberOfSegments,
                  const std::vector<double> &coeffs) const;

private:
  /** 
   * Computes the affine combination of two values.
   * \param t The ratio of the affine combination.
   * \param a A real value.
   * \param b A real value.   
   * \return The value \f$(1 - t) a + t b\f$ 
   */
  double aerp(double t, double a, double b) const;

public:
  /** Maximum degree of a polynomial basis function. */
  constexpr static int MaximumDegree = 9;

  /** Maximum number of linear segments of a sleefe. */
  constexpr static int MaximumNumberOfSegments = 9;

  /** Data type for the pre-tabulated upper and lower bounds. */
  using UniSleefeTableType = std::vector<std::vector<std::vector<double>>>;

  /** Table of upper bounds of sleefes for univariate functions. */
  static const UniSleefeTableType UpperBounds;

  /** Table of lower bounds of sleefes for univariate functions. */
  static const UniSleefeTableType LowerBounds;
};

} // namespace sleefe
