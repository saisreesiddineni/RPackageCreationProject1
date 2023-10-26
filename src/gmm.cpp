#include "gmm.h"
#include <Rcpp.h>
using namespace Rcpp;

// Mixture weights
std::vector<double> weight(K);

// Function to fit a GMM to the data and return results
std::vector<GaussianComponent> fitGMM(std::vector<double>& data, int numComponents, int maxIters) {
  // Initialize means, covariances, and weights.
  GetRNGstate();
          std::vector<GaussianComponent> components(numComponents);
          for (int k = 0; k < numComponents; k++) {
            components[k].mean = static_cast<double>(unif_rand()) / RAND_MAX;
            components[k].covariance = 0.1; // Initial covariance
            weight[k] = 1.0 / numComponents;
          }
          
          // EM algorithm
          for (int iteration = 0; iteration < maxIters; iteration++) {
            // E-step
            std::vector<std::vector<double>> responsibilities(N, std::vector<double>(numComponents));
            for (int i = 0; i < N; i++) {
              double denominator = 0.0;
              for (int k = 0; k < numComponents; k++) {
                double exponent = -0.5 * std::pow((data[i] - components[k].mean) / components[k].covariance, 2);
                responsibilities[i][k] = weight[k] * (1.0 / (components[k].covariance * sqrt(2 * M_PI))) * exp(exponent);
                denominator += responsibilities[i][k];
              }
              
              for (int k = 0; k < numComponents; k++) {
                responsibilities[i][k] /= denominator;
              }
            }
            
            // M-step
            for (int k = 0; k < numComponents; k++) {
              double sum_responsibilities = 0.0;
              double sum_weights = 0.0;
              double sum_weighted_data = 0.0;
              double sum_weighted_sq_data = 0.0;
              
              for (int i = 0; i < N; i++) {
                sum_responsibilities += responsibilities[i][k];
                sum_weights += responsibilities[i][k];
                sum_weighted_data += responsibilities[i][k] * data[i];
                sum_weighted_sq_data += responsibilities[i][k] * (data[i] * data[i]);
              }
              
              components[k].mean = sum_weighted_data / sum_weights;
              components[k].covariance = (sum_weighted_sq_data / sum_weights) - (components[k].mean * components[k].mean);
              weight[k] = sum_weights / N;
            }
          }
          PutRNGstate();
          // Return the final estimates of means, covariances, and weights
          return components;
}
