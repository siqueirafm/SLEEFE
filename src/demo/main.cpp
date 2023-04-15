#include <Sleefe.hpp>

#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace sleefe;
namespace fs = std::filesystem;

namespace {
struct InputParams {
  fs::path inFilepath;
  fs::path ouFilepath;
  int numberOfSegments = 0;
};

InputParams parseInputParameterValues(char *argv[]) {
  InputParams params;

  params.inFilepath = fs::path(argv[1]);
  if (!fs::is_regular_file(params.inFilepath)) {
    throw std::runtime_error("Could not open input file: " +
                             params.inFilepath.string());
  }

  params.ouFilepath = fs::path(argv[2]);
  if (params.ouFilepath.empty()) {
    throw std::runtime_error("Output filename cannot be the empty string");
  }

  params.numberOfSegments = std::stoi(argv[3]);
  if (params.numberOfSegments < 1) {
    throw std::runtime_error("Number of sleefe segments must be positive");
  }
  if (params.numberOfSegments > UniSleefeBuilder::MaximumNumberOfSegments) {
    throw std::runtime_error(
        "Number of sleefe segments cannot exceed " +
        std::to_string(UniSleefeBuilder::MaximumNumberOfSegments));
  }

  return params;
}

std::vector<double> readCoefficients(const fs::path &file) {
  std::ifstream istr(file.c_str());
  istr.exceptions(std::ifstream::badbit | std::ifstream::failbit);

  auto degree = 0;
  istr >> degree;

  if (degree < 2) {
    throw std::runtime_error(
        "Degree of the polynomial function must be at least 2");
  }

  std::vector<double> coeffs(degree + 1);
  for (auto &coeff : coeffs) {
    istr >> coeff;
  }

  istr.close();

  return coeffs;
}

void writeSleefe(const fs::path &file, const UniSleefe &sleefe) {
  std::ofstream ostr(file.c_str());
  ostr.exceptions(std::ofstream::badbit | std::ofstream::failbit);

  ostr << std::fixed << std::setprecision(10) << std::endl;

  ostr << sleefe.numberOfSegments() << std::endl;

  for (const auto bound : sleefe.upperValues()) {
    ostr << bound << std::endl;
  }

  for (const auto bound : sleefe.lowerValues()) {
    ostr << bound << std::endl;
  }

  ostr.close();
}
} // namespace

int main(int argc, char *argv[]) {
  if (argc != 4) {
    std::cout << std::endl;
    std::cout << "USAGE:" << std::endl << std::endl;
    std::cout << "sleefe-demo <input file> <output file> <number of segments>"
              << std::endl;
    std::cout << std::endl;
    return EXIT_SUCCESS;
  }

  std::chrono::duration<double> elapsedSeconds{0};

  //
  // Parse the input parameter values
  //

  std::cout << std::endl;
  std::cout << "Parsing the input parameter values... ";
  auto start = std::chrono::system_clock::now();

  const auto params = parseInputParameterValues(argv);

  auto end = std::chrono::system_clock::now();
  elapsedSeconds = end - start;
  std::cout << elapsedSeconds.count() << " secs" << std::endl;

  //
  // Read in the polynomial function coefficients from input file
  //

  std::cout << "Reading in the polynomial function coefficients from the input "
               "file... ";
  start = std::chrono::system_clock::now();

  const auto coeffs = readCoefficients(params.inFilepath);

  end = std::chrono::system_clock::now();
  elapsedSeconds = end - start;
  std::cout << elapsedSeconds.count() << " secs" << std::endl;

  //
  // Compute the sleefe components
  //

  std::cout << "Computing the sleefe components... ";
  start = std::chrono::system_clock::now();

  UniSleefeBuilder builder;
  const auto sleefe = builder.build(params.numberOfSegments, coeffs);

  end = std::chrono::system_clock::now();
  elapsedSeconds = end - start;
  std::cout << elapsedSeconds.count() << " secs" << std::endl;

  //
  // Write the sleefe bounds to the output file
  //

  std::cout << "Writing the sleefe bounds to the output file... ";
  start = std::chrono::system_clock::now();

  writeSleefe(params.ouFilepath, sleefe);

  end = std::chrono::system_clock::now();
  elapsedSeconds = end - start;
  std::cout << elapsedSeconds.count() << " secs" << std::endl;

  std::cout << "Done!" << std::endl << std::endl;

  return EXIT_SUCCESS;
}
