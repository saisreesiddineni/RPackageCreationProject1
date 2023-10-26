#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <R.h>
#include <Rmath.h> 

// Define the number of data points, Gaussian components, and iterations.
const int N = 100;
const int K = 2;

// Gaussian components (mean and covariance)
struct GaussianComponent {
  double mean;
  double covariance;
};


std::vector<GaussianComponent> fitGMM(std::vector<double>& data, int numComponents, int maxIters);