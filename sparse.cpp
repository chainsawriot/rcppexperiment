#include <RcppArmadillo.h>

using namespace Rcpp;
using namespace arma;

// [[Rcpp::depends(RcppArmadillo)]]

// [[Rcpp::export]]
sp_mat xcorC(S4 mat, bool show) {
  IntegerVector dims = mat.slot("Dim");
  arma::urowvec i = Rcpp::as<arma::urowvec>(mat.slot("i"));
  arma::urowvec p = Rcpp::as<arma::urowvec>(mat.slot("p"));
  arma::vec x = Rcpp::as<arma::vec>(mat.slot("x"));
  int nrow = dims[0], ncol = dims[1];
  arma::sp_mat res(i, p, x, nrow, ncol);
  //  mat z = arma::cor(res);
  return res;
}


// [[Rcpp::export]]
mat corArma(NumericVector x, NumericVector y) {
  colvec yarma(y.begin(), y.size(), false); //conversion of Rcpp numericVector to colvec
  colvec xarma(x.begin(), x.size(), false);  
  mat g = arma::cor(xarma, yarma);
  return g;
}

