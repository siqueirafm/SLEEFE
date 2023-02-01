#pragma once

#include <vector>

namespace sleefe {

/**
 * \class UniSleefe
 * \brief A class representing sleefes of univariate Bezier polynomial functions. 
 */
class UniSleefe {
public:
  /**
   * \fn UniSleefe()
   * \brief Creates a sleefe for a univariate function.
   * \param lower The values of the upper component of the sleefe at the
   * breakpoints.
   * \param upper The values of the lower component of the sleefe at the
   * breakpoints.
   */
  UniSleefe(const std::vector<double> &lower, const std::vector<double> &upper);

  /**
   * \fn lowerValueAt()
   * \brief Computes the value of the lower component of the sleefe at a given
   * parameter value.
   * \param t A parameter value in the interval [0,1].
   * \return The value of the lower component of the sleefe at \c t.
   */
  double lowerValueAt(double t) const;

  /**
   * \fn upperValueAt()
   * \brief Computes the value of the upper component of the sleefe at a given
   * parameter value.
   * \param t A parameter value in the interval [0,1].
   * \return The value of the upper component of the sleefe at \c t.
   */
  double upperValueAt(double t) const;

  /**
   * \fn lowerValues()
   * \brief Returns the values of the lower component of the sleefe at the
   * breakpoints.
   * \return The values of the lower component of the sleefe at the
   * breakpoints.
   */
  const std::vector<double> &lowerValues() const;

  /**
   * \fn upperValues()
   * \brief Returns the values of the upper component of the sleefe at the
   * breakpoints.
   * \return The values of the upper component of the sleefe at the
   * breakpoints.
   */
  const std::vector<double> &upperValues() const;

  /**
   * \fn numberOfSegments()
   * \brief Returns the number of segments of each sleefe component.
   * \return The number of segments of each sleefe component.
   */
  int numberOfSegments() const;

private:
  /** The number of segments of each sleefe component. */
  int _numberOfSegments;

  /** The values of the lower component of the sleefe. */
  std::vector<double> _lower;

  /** The values of the upper component of the sleefe. */
  std::vector<double> _upper;
};

} // namespace sleefe
