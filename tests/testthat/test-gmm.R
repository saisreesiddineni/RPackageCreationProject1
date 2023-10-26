library(RPackageCreationProject1)
library(testthat)
context("gmm")

test_that("gmm_algo computes the same answer as R", {
  N <- 1000
  K <- 20 
  max_iterations <- 100
  data <- numeric(N)
  set.seed(123)
  data <- runif(N)
  gmm <- gmm_algo(data, K, max_iterations)
  expect_equal(gmm[[3]], 100)
  expect_equal(gmm[[2]], K)
})
