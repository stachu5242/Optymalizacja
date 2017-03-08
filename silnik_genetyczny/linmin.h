#ifndef _LINMIN_
#define _LINMIN_

#define ZERO 0.0
#define TINYP 1.0e-25
#define ITPMAX 200
#define TOL 2.0e-10
#include"brent.h"
#include"mnbark.h"
#include"globals.h"
inline double SQR(double a){
  return (a==0.0)? 0.0:a*a;}
void linmin(std::vector<double>& p,std::vector<double>& xi,double& wartosc,double (*f)(std::vector<double>),double ax,double xx);
double f1(double x);
#endif
