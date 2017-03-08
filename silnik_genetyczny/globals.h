#ifndef _GLOBALS_
#define _GLOBALS_
#include<iostream>
#include<cmath>
#include<valarray>
#include<vector>

inline double MIN(double a, double b){
  return ((a<b)?a:b);}

inline double MAX(double a, double b){
  return ((a<b)?b:a);}

inline double Sign(double a, double b){
  return ((b>=0)?fabs(a):-fabs(a));}

inline void Zmian(double& a,double& b,double& c,double& d){
  a=b; b=c; c=d;}

#endif
