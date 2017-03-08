#include"globals.h"
#include"linmin.h"
#include"macierz.h"
#include"funkcja.h"

/*procedura na podstawie ksiazki ::                     *
 *                                                      *
 *"Numerical Recipes, The Art of Scientific             *
 *             Computing by W.H. Press, B.P. Flannery,  *
 *             S.A. Teukolsky and W.T. Vetterling,      *
 *             Cambridge University Press, 1986".       *
 *                                                      */
/****************************************************************************************
 **          Funkcja powell znajduje minimum funkcji n wymiarowej                       *
 **                                                                                     *
 **=====================================================================================*
 **                                                                                     *
 ** Parametry wejsciowe:                                                                *
 **=====================                                                                *
 **   (*f)                  wskazanie na funkcje ktora zwroci wartosc dla parametrow    *
 **                                                                                     *
 **   tol                   tolerancja mozna nazwac tez dokladnioscia                   *
 **                                                                                     *
 **   p                     wektor poczatkowy czyli punkt starowy                       *
 **                                                                                     *
 **   xi                    pusta macierz                                               *
 **                                                                                     *
 **                                                                                     *
 ** Parametry wyjsciowe:                                                                *
 **=====================                                                                *
 **                                                                                     *
 **   p                    najlepszy punkt(minimum funkcji)                             *
 **                                                                                     *
 **   xi                   koncowa tablica kierunkow                                    *
 **                                                                                     *
 **   wartosc              minimum funkcji n wymiarowej                                 *
 **                                                                                     *
 **  iter                  liczba wykonanych iteracji                                   *
 **                                                                                     *
 **                                                                                     *
 ****************************************************************************************/
int powell(std::vector<double>& p, matrix& xi,double& wartosc, double tol,double (*f)(std::vector<double>)){
  xi.resize(p.size());
  int n=xi.il_kl();           //rozmiar macierzy
  xi=xi+1;                    //macierz wektorow unitarnych
  int ibig,iter;
  double del,fp,fptt,t;
  std::vector<double> pt(n),ptt(n),xit(n);
  wartosc=(*f)(p);
  for (int i = 0; i< n; i++)
    {
      pt[i] = p[i];
    }
  for(iter=1;;iter++)
    {      //glowna petla
      fp = wartosc;
      ibig=0;
      del=ZERO;                //najwiekszy spadek
      for(int i=0;i<n;i++)
        {
	  xit=xi.kl_vec(i);  //przepisz kolejny kierunek
	  fptt=wartosc;
          linmin(p,xit,wartosc,f,p[i],p[i]+1);         //znajdz minimum
          if((fptt-wartosc)>del)           //jesli lepsz niz del to zamien
            {
              del=fptt-wartosc;
              ibig=i;
            }
        }
      if(2.0*(fp-wartosc)<= tol*(fabs(fp)+fabs(wartosc)+TINYP))
        return 0;
      if(iter== ITPMAX) {std::cout<<"za duzo iteracji w procedurze powella"; exit(1);}
     
      for (int i = 0; i< n; i++)
	{
	  ptt[i]=2.0*p[i]-pt[i];
	  xit[i]=p[i]-pt[i];
	  pt[i]=p[i];
	}

      fptt=(*f)(ptt);
      
      if(fptt<fp)
        {
          t=2.0*(fp-2.0*wartosc+fptt)*SQR(fp-wartosc-del)-del*SQR(fp-fptt);
          if(t<ZERO){
            linmin(p,xit,wartosc,f,0.0,1.0);          //nowe minimum i nowy kierunek
            for(int j=0;j<n;j++){
              xi(j,ibig)=xi(j,n-1);
              xi(j,n-1)=xit[j];
            }
          }
        }
    }
}


/// Funkcja potrzebna funkcji powell by ta mog³a liczyæ maksimum
/**
   Zwraca warto¶æ ujemn± wywo³ania funkcji funkcja(vector< double >);
*/
double maksimum_powell(std::vector <double> a)
{
  return -funkcja(a);
}

