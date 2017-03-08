#define ITMAX  100           //maksymalna liczba iteracji
#define CGOLD  0.3819660     //zloty srodek
#define ZEPS   1.0E-10       //odleglosc aby nie dzielic przez zero
double brent(double ax,double bx,double cx,double (*f)(double),double toler,double& min);




