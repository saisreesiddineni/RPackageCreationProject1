#' Gaussian Mixture Model Algorithm
#' 
#' This function takes in the data and returns the final estimates of mean, covariance 
#' and prior weight values that maximize the likelihood using Gaussian Mixture Model Algorithm
#'
#' @param data input data that needs to be clustered [vector of values of type double]
#' @param K number of clusters [integer value]
#' @param max_iterations number of iterations [integer value]
#'
#' @return vector of mean, covariance and prior weight values
#' @export
#'
#' @examples
#'  N <- 100
#'  K <- 2 
#'  max_iterations <- 100
#'  data <- numeric(N)
#'  set.seed(123)
#'  data <- runif(N)
#'  gmm_algo(data, K, max_iterations)
gmm_algo <- function(data, K, max_iterations)
{
  result.vec <- .C("fitGMM_interface", 
                   data, K, max_iterations,
                   PACKAGE = "RPackageCreationProject1")
  result.vec
}