#ifndef _POWELL_H_
#define _POWELL_H_

#include <vector>


/// Funkcja liczy metod� powella minimum lokalne
/**
   Dzi�ki funkcji maksimum_powell mo�e tak�e liczy� maksimum.
*/
int powell(std::vector<double>& p, matrix& xi,double& wartosc, double tol,double (*f)(std::vector<double>));


/// Funkcja potrzebna funkcji powell by ta mog�a liczy� maksimum
/**
   Zwraca warto�� ujemn� wywo�ania funkcji funkcja(vector< double >);
*/
double maksimum_powell(std::vector <double> a);


#endif
