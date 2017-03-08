#include"globals.h"
#include"mnbark.h"

/*procedura na podstawie ksiazki ::                     *
 *                                                      *
 *"Numerical Recipes, The Art of Scientific             *
 *             Computing by W.H. Press, B.P. Flannery,  *
 *             S.A. Teukolsky and W.T. Vetterling,      *
 *             Cambridge University Press, 1986".       *
 *                                                      */
/****************************************************************************************
 **          Funkcja mnbark osacza minimum odpowiednimi punktami                        *
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
 **  
 **                                                                                     *
 **                                                                                     *
 **                                                                                     *
 ** Parametry wyjsciowe:                                                                *
 **=====================                                                                *
 **                                                                                     *
 **                                                                                     *
 ****************************************************************************************/


void mnbark(double& ax, double& bx, double& cx,double (*f)(double))
{
  double  ulim,u,r,q,fu,dum,fa,fb,fc;
  
  fa=(*f)(ax);  //wartosci dla punktow poczatkowych
  fb=(*f)(bx);
  if (fb > fa) { 
    Zmian(dum,ax,bx,dum);
    Zmian(dum,fb,fa,dum);
  }
  cx=(bx)+GOLD*(bx-ax);
  fc=(*f)(cx);
  
  //no to zaczynamy
  
  while (fb > fc) {    
    r=(bx-ax)*(fb-fc);      //szykujemy parabole
    q=(bx-cx)*(fb-fa);  
    u=(bx)-((bx-cx)*q-(bx-ax)*r) / (2.0*Sign(MAX(fabs(q-r),TINY),q-r));
    ulim=(bx)+GLIMIT*(cx-bx);
    if ((bx-u)*(u-cx) > 0.0) {  
      fu=(*f)(u);
      if (fu < fc) {
	ax=(bx);
	bx=u;
	fa=(fb);
	fb=fu;
	return;
      } else if (fu > fb) {
	cx=u;
	fc=fu;
	return;
      }
      u=(cx)+GOLD*(cx-bx); 
      fu=(*f)(u);   
    } else if ((cx-u)*(u-ulim) > 0.0) {  
      fu=(*f)(u);               
      if (fu < fc) {
	double pom=(*f)(u);
	double pom2=cx+GOLD*(cx-bx);
	Zmian(bx,cx,u,pom2);
	Zmian(fb,fc,fu,pom);
      }
    } else if ((u-ulim)*(ulim-cx) >= 0.0) {
      u=ulim;                        
      fu=(*f)(u);
    } else {   
      u=(cx)+GOLD*(cx-bx); 
      fu=(*f)(u);
    }
    Zmian(ax,bx,cx,u);                     
    Zmian(fa,fb,fc,fu);
  }
}

