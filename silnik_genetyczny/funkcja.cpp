/***************************************************************/
/* Autorzy:             Rados³aw Szwarc                        */
/*                      Krzysztof Ginter                       */
/***************************************************************/



#include "funkcja.h"
#include <vector> 
#include <cmath>
using std::vector;

/// Funkcja której maksimum / minimum liczymy.
/**
   Jak widaæ przyjmuje ona jeden parametr, którym jest wektor doubli. <br>
   U¿ytkownik sam musi wpisaæ funkcjê, a potem skompilowaæ (polecenie make). <br> 
   Obecnie zaimplementowana jest funkcja -x*x + 4
   Nale¿y pamiêtaæ, ¿e pierwsza zmienna to zmienna[0] <br>
   zmienna[1] to 2 zmienna i tak dalej...
*/
double funkcja( vector< double> zmienna)
{
  double wynik;
  double x1 = zmienna[0];
  double x2 = zmienna[1];
  double x3 = zmienna[2];
  /*******************/
  /* FUNKCJE TESTOWE */
  /*******************/
  // Branin RCOS (RC) 2 zmienne:
  //f(x) = pow((x2 - ( 5.0 / (4.0 * M_PI*M_PI))*x1*x1 + 
  //(5.0 / M_PI)*x1 - 6.0),2) 
  //+ 10.0 * (1.0-(1.0/(8.0*M_PI)))*cos(x1) + 10;
  // -5 < x1 < 10
  // 0 < x2 < 15
  // wyniki: 3 minima globalne:
  // (-pi , 12.275)
  // ( pi, 2.275)
  // (9.42478, 2.475)
  // wartosc: 0.397887    
  // WNIOSKI: Algorytm podaje troche inne punkty (byc moze ze wzg. na
  // dokladnosc obliczen...) Powell sie sypie.
  // OK

  // B2  2 zmienne:
  //wynik = x1*x1 + 2*x2*x2 - 0.3*cos(3.0 * M_PI * x1) - 0.4*cos(4.0*M_PI*x2)
  //  + 0.7;
  // -100 < x1, x2 < 100
  // wynik: kilka minimow lokalnych, 1 globalne
  // (0,0)
  // wartosc : 0.0
  // WNIOSKI: Algorytm daje dobry wynik. Powell OK.
  // OK
  
  // Easom (ES) 2 zmienne:
  //  wynik = -cos(x1)*cos(x2)*exp(-(pow(x1-M_PI,2) + pow(x2 - M_PI,2)));
  // wynik: kilka minimow lokalnych , 1 globalne
  // -100< x1, x2 < 100
  // (pi, pi)
  // wartosc: -1
  // WNIOSKI: Alg gen dziala dobrze. Powell nie radzi sobie :/


  // Goldstein and Price (GP) 2 zmienne:
  //wynik = (1.0 + (x1 + x2 + 1)*(x1 + x2 + 1) *
  //	   (19 - 14 *x1 + 3*x1*x1 - 14*x2 + 6*x1*x2 + 3*x2*x2)) *
  // (30 + (2*x1 - 3*x2)*(2*x1 - 3*x2) * (18 - 32*x1 + 12*x1*x1 + 48*x2 - 
  //                                      36*x1*x2 + 27*x2*x2));
  // -2 < x1, x2 < 2
  // wynik: 4 minima lokalne, 1 globalne:
  // (0,-1)
  // wartosc: 3
  // WNIOSKI: Alg gen dziala dobrze. Powell OK
  
  
  // Shubert (SH) 2 zmienne:
  //double wynik1 = 0.0;
  //double wynik2 = 0.0;
  //for (int j = 1; j < 6; j++)
  //  {
  //    wynik1 += (j*cos( (j + 1)*x1 + j));
  //    wynik2 += (j*cos( (j + 1)*x2 + j));
  //  }
  //wynik = wynik1 * wynik2;
  // -10 < x1, x2 < 10
  // wynik: 760 minimow lokalnych: 18 globalnych minimow
  // wartosc: -186.7309
  // WNIOSKI: Alg dziala dobrze. Powell nie radzi sobie.
  
  
  // De Joung (DJ) 3 zmienne
  wynik = x1*x1 + x2*x2 + x3*x3;
  // -5.12 < x1, x2, x3 < 5.12
  // wynik: jedno minimum lokalne i globalne
  // (0,0,0)
  // wartosc: 0
  // WNIOSKI: AL gen dziala dobrze. Powell OK.

  // Hartman (H3,4) 3 zmienne:
  //  double c[4] = {1.0, 1.2, 3.0, 3.2};
  //double a[3][4] = { 3.0, 10.0, 30.0,
  //0.1, 10.0, 35.0,
  //3.0, 10.0, 30.0,
  // 0.1, 10.0, 35.0 };
  //for (int i = 1; i < 5; i++)
  // {
  //   for (int j = 1; j < 4; j++)
  //{
  //  cout << a[i][j] << endl;
  //}
  //}

  return wynik;
}
