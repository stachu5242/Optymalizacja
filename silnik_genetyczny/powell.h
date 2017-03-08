#ifndef _POWELL_H_
#define _POWELL_H_

#include <vector>


/// Funkcja liczy metod± powella minimum lokalne
/**
   Dziêki funkcji maksimum_powell mo¿e tak¿e liczyæ maksimum.
*/
int powell(std::vector<double>& p, matrix& xi,double& wartosc, double tol,double (*f)(std::vector<double>));


/// Funkcja potrzebna funkcji powell by ta mog³a liczyæ maksimum
/**
   Zwraca warto¶æ ujemn± wywo³ania funkcji funkcja(vector< double >);
*/
double maksimum_powell(std::vector <double> a);


#endif
