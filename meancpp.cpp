#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
double meanC(NumericVector x) {
  int n = x.size();
  double total = 0;
  
  for (int i = 0; i < n; ++i) {
    total += x[i];
  }
  return total /n ;
}

// [[Rcpp::export]]
NumericVector pdistC(double x, NumericVector ys) {
  int n = ys.size();
  NumericVector out(n);
  for (int i = 0; i < n; ++i) {
    out[i] = sqrt(pow(ys[i] -x, 2.0));
  }
  return out;
}

// [[Rcpp::export]]
NumericVector rowSumsC(NumericMatrix x) {
  int nrow = x.nrow(), ncol = x.ncol();
  NumericVector out(nrow);
  for (int i = 0; i < nrow; ++i) {
    double total = 0;
    for (int j =0; j < ncol; ++j) {
      total += x(i, j);
    }
    out[i] = total;
  }
  return out;
}

// [[Rcpp::export]]
bool allC(LogicalVector x) {
  int n = x.size();
  for (int i = 0; i < n; ++i) {
    if (!x[i]) {
      return false;
    }
  }
  return true;
}

