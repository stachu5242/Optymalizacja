#include"globals.h"
#include"brent.h"

/*procedura na podstawie ksiazki ::                     *
 *                                                      *
 *"Numerical Recipes, The Art of Scientific             *
 *             Computing by W.H. Press, B.P. Flannery,  *
 *             S.A. Teukolsky and W.T. Vetterling,      *
 *             Cambridge University Press, 1986".       *
 *                                                      */
/****************************************************************************************
 **          Funkcja brent znajduje minimum w danym otoczeniu                           *
 **                                                                                     *
 **=====================================================================================*
 **                                                                                     *
 ** Parametry wejsciowe:                                                                *
 **=====================                                                                *
 **   ax,bx,cx              sa to wartosci argumentow o odpowiedniej wartosci           *
 **                         ax lub cx < bx < ax lub cx                                  *
 **                         oraz warosc funkcji dla punktu bx < od war dla punktu ax cx *
 **                                                                                     *
 **   (*f)                  wskazanie na funkcje ktora zwroci wartosc dla parametrow    *
 **                                                                                     *
 **   toler                 tolerancja mozna nazwac tez dokladnioscia                   *
 **                                                                                     *
 **                                                                                     *
 **                                                                                     *
 ** Parametry wyjsciowe:                                                                *
 **=====================                                                                *
 **                                                                                     *
 **   xmin                  wartosc argumentu dla ktorego funkcja osiaga miniumum       *
 **                                                                                     *
 **   Funkcja zwraca wrtosc miniumum dla punktu xmin                                    *
 **                                                                                     *
 ****************************************************************************************/

double brent(double ax, double bx, double cx, double (*f)(double), double toler,double& xmin)
{
  double a,b,d=0,etemp,fu,fv,fw,fx,p,q,r,tol1,tol2,u,v,w,x,xm;
  double e=0.0; 
  
  a=MIN(ax,cx);
  b=MAX(ax,cx);
  x=w=v=bx;                                  //wszytkie ustawienie poczatkowe
  
  fw=fv=fx=(*f)(x);                         //wartosc dla minimum "paraboli" no moze nie tu ale potem to bedzie
  for (int iter=1;iter<=ITMAX;iter++) {         //szukanie minimum dla maxymalnej liczby iteracji            
    
    xm=0.5*(a+b);                          //sredek przedzilu :)
    tol2=2.0*(tol1=toler*fabs(x)+ZEPS);     
    if (fabs(x-xm) <= (tol2-0.5*(b-a))) {   //test czy jest sens szukac minimum
      xmin=x;
      return fx;
    }
    
    if (fabs(e) > tol1) 
      {                  //tworzenie paraboli       
	r=(x-w)*(fx-fv);                    //najciekawsze ze przy pierwszym przejsciu to jest all 0
	q=(x-v)*(fx-fw);
	p=(x-v)*q-(x-w)*r;
	q=2.0*(q-r);
	if (q > 0.0) p = -p;               //za 1 razem tu nie wejdzie
	q=fabs(q);
	etemp=e;
	e=d;
	if (fabs(p) >= fabs(0.5*q*etemp) || p <= q*(a-x) || p >= q*(b-x))//tu sie zainicjuje d za 1 razem
	  d=CGOLD*(e=(x >= xm ? a-x : b-x));
	else 
	  {
	    d=p/q; 
	    if (u-a < tol2 || b-u < tol2)
	      d=Sign(tol1,xm-x);
	  }
      } 
    else 
      {
	d=CGOLD*(e=(x >= xm ? a-x : b-x));
      }
    u=(fabs(d) >= tol1 ? x+d : x+Sign(tol1,d));
    fu=(*f)(u);
    if (fu <= fx) {
      if (u >= x) a=x; else b=x;
      Zmian(v,w,x,u);
      Zmian(fv,fw,fx,fu);
    } 
    else 
      {
	if (u < x) a=u; else b=u;
	if (fu <= fw || w == x) {
	  v=w;
	  w=u;
	  fv=fw;
	  fw=fu;
	} else if (fu <= fv || v == x || v == w) 
	  {
	    v=u;
	    fv=fu;
	  }
      }
  }
  std::cerr<<"Too many iterations in brent";
  xmin=x;  
  return fx;
}

