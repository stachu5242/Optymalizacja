#include"linmin.h"

int ncom;
std::vector<double> pcom, xicom;
double (*nrfunc)(std::vector<double>);

/*procedura na podstawie ksiazki ::                     *
 *                                                      *
 *"Numerical Recipes, The Art of Scientific             *
 *             Computing by W.H. Press, B.P. Flannery,  *
 *             S.A. Teukolsky and W.T. Vetterling,      *
 *             Cambridge University Press, 1986".       *
 *                                                      */
/****************************************************************************************
 **          Funkcja linmin znajduje minimum w danym kierunku                           *
 **                                                                                     *
 **=====================================================================================*
 **                                                                                     *
 ** Parametry wejsciowe:                                                                *
 **=====================                                                                *
 **                                                                                     *
 **   (*f)                  wskazanie na funkcje ktora zwroci wartosc dla parametrow    *
 **                                                                                     *
 **    p                    wektor czyli punkt pocztkowy                                *
 **                                                                                     *
 **    xi                   kierunek na ktorym ma byc minimalizowana funkcja            *
 **                                                                                     *
 **                                                                                     *
 ** Parametry wyjsciowe:                                                                *
 **=====================                                                                *
 **                                                                                     *
 **   p                    nalepszy punkt                                               *
 **                                                                                     *
 **   xi                   kirunek zmian                                                *
 **                                                                                     *
 **   wartosc              wynik szukanego minimum                                      *
 **                                                                                     *
 **  Funkcje:                                                                           *
 **  ==========                                                                         *
 **            f1   funkcja modyfikujaca funkcje wielowymiarowa                         *
 **                  pomysl z ksiazki wyzej wymienionej                                 *
 **                                                                                     *
 **                                                                                     *
 ****************************************************************************************/


void linmin(std::vector<double>& p,std::vector<double>& xi,double& wartosc,double (*f)(std::vector<double>),double ax,double xx)
{
  double xmin,bx;
  int n=p.size();
  ncom=n;  pcom.resize(n);  xicom.resize(n);
  nrfunc=f;  xicom=xi;  pcom=p;
  //  ax=0.0;  xx=1.0; //to mi sie nie podoba
  mnbark(ax,xx,bx,&f1);
  wartosc=brent(ax,xx,bx,&f1,TOL,xmin);
  for (int i =0; i< n; i++)
    {
      xi[i]*=xmin;
      p[i]+=xi[i];
    }
}

  
double f1(double x)
{
  double f;
  std::vector<double> xt(ncom);
  for (int i = 0 ; i < ncom; i++)
    {
      xt[i]=pcom[i]+x*xicom[i];
    }
  f=(*nrfunc)(xt);
  return f;
}





