#include"macierz.h"
#include <cmath>
#include<iostream>
#define MAXIT 30
#define ZERO  0.0
#define ONE   1.0
#define MACH_EPS  1e-16

using namespace std;

size_t matrix::size() const {return d1*d2;}
size_t matrix::il_kl() const {return d2;}
size_t matrix::il_wr() const {return d1;}
matrix::~matrix() {delete v;}

inline Slice_iter<double> matrix::operator() (size_t i) {return wiersz(i);}
inline Cslice_iter<double> matrix::operator() (size_t i) const {return wiersz(i);}
inline Slice_iter<double> matrix::operator[] (size_t i) {return wiersz(i);}
inline Cslice_iter<double> matrix::operator[] (size_t i) const {return wiersz(i);}

valarray<double>& matrix::array() {return *v;}



//[konstruktory]
matrix::matrix(){
  d1=0;
  d2=0;
  v = new std::valarray<double> (d1*d2);
  for(size_t i=0;i<d1*d2;i++)
    (*v)[i]=0;
}
matrix::matrix(size_t x,size_t y){
  d1=x;
  d2=y;
  v = new std::valarray<double> (x*y);
  for(size_t i=0;i<d1*d2;i++)
    (*v)[i]=0;
}
matrix:: matrix(size_t x,size_t y,double a){
  d1=x;
  d2=y;
  v = new std::valarray<double> (x*y);
  for(size_t i=0;i<d1*d2;i++)
    (*v)[i]=a;
}
matrix:: matrix(size_t x,size_t y,int a){
  d1=x;
  d2=y;
  v = new std::valarray<double> (x*y);
  for(size_t i=0;i<d1*d2;i++)
    (*v)[i]=static_cast<double>(a);
}
matrix:: matrix(size_t x,size_t y,float a){
  d1=x;
  d2=y;
  v = new std::valarray<double> (x*y);
  for(size_t i=0;i<d1*d2;i++)
    (*v)[i]=static_cast<double>(a);
}
matrix:: matrix(size_t x,size_t y,long a){
  d1=x;
  d2=y;
  v = new std::valarray<double> (x*y);
  for(size_t i=0;i<d1*d2;i++)
    (*v)[i]=static_cast<double>(a);
}

matrix::matrix(const matrix& a){
  d1=a.il_kl();
  d2=a.il_wr();
  v=new valarray<double>(a.size());
  for(size_t i=0;i<size();i++) (*v)[i]=(*a.v)[i];
}

void matrix::resize(size_t n){
  d1=n;
  d2=n;
  delete v;
  v=new valarray<double>(n*n);
  for(size_t i=0; i<size();i++) (*v)[i]=0;
}
void matrix::resize(size_t n,size_t m){
  d1=n;
  d2=m;
  delete v;
  v=new valarray<double>(n*m);
  for(size_t i=0; i<size();i++) (*v)[i]=0;
}
matrix matrix::wr(size_t n)
{ matrix a(1,d2);
  valarray<double> wycinek=(*v)[slice(n,d2,d1)];
  for(size_t i=0;i<d2;i++) (*a.v)[i]=wycinek[i];
  return a; 
}; 
matrix matrix::kl(size_t n){
  matrix a(d1,1);
  valarray<double> wycinek=(*v)[slice(n*d2,d1,1)];
  for(size_t i=0;i<d1;i++) (*a.v)[i]=wycinek[i];
  return a; 
}
valarray<double> matrix::wr_val(size_t n)
{ 
  return (*v)[slice(n,d2,d1)];
}; 
valarray<double>  matrix::kl_val(size_t n){
  return (*v)[slice(n*d2,d1,1)];
}
vector<double> matrix::wr_vec(size_t n)
{ 
  std::vector<double> wektor;
  std::valarray<double> walarray(d2);
  walarray = (*v)[slice(n,d2,d1)];
  for (size_t i =0; i < d2; i++)
    {
      wektor.push_back(walarray[i]);
    }
  return wektor;
}; 
vector<double>  matrix::kl_vec(size_t n){
  std::vector<double> wektor;
  std::valarray<double> walarray(d1);
  walarray = (*v)[slice(n*d2,d1,1)];
  for (size_t i =0; i < d1; i++)
    {
      wektor.push_back(walarray[i]);
    }
  return wektor;
}


//***********************************************************************************************
//[indeksy i chwala bogo za to ze dzialaja]

inline Slice_iter<double> matrix::wiersz(size_t i) 
{  return Slice_iter<double> (v,slice(i,d2,d1));
}
inline Cslice_iter<double> matrix::wiersz(size_t i) const
{  return Cslice_iter<double> (v,slice(i,d2,d1));
}
inline Slice_iter<double> matrix::kolumna(size_t i) 
{  return Slice_iter<double> (v,slice(i*d2,d1,1));
}
inline Cslice_iter<double> matrix::kolumna(size_t i) const
{  return Cslice_iter<double> (v,slice(i*d2,d1,1));
}
double& matrix::operator()(size_t x, size_t y)
{  return wiersz(x)[y];
}


//*******************************************************************************
//macierz i liczba   [sekcja 3]

matrix& matrix::operator+=(double a){
  (*v)+=a;
  return *this;
}
matrix& matrix::operator+=(int a){
  (*v)+=static_cast<double>(a);
  return *this;
}
matrix& matrix::operator+=(float a){
  (*v)+=static_cast<double>(a);
  return *this;
}
matrix& matrix::operator+=(long a){
  (*v)+=static_cast<double>(a);
  return *this;
}
matrix& matrix::operator*=(double a){
  (*v)*=a;
  return *this;
}
matrix& matrix::operator*=(int a){
  (*v)*=static_cast<double>(a);
  return *this;
}
matrix& matrix::operator*=(float a){
  (*v)*=static_cast<double>(a);
  return *this;
}
matrix& matrix::operator*=(long a){
  (*v)*=static_cast<double>(a);
  return *this;
}
matrix& matrix::operator-=(double a){
  (*v)-=a;
  return *this;
}
matrix& matrix::operator-=(int a){
  (*v)-=static_cast<double>(a);
  return *this;
}
matrix& matrix::operator-=(float a){
  (*v)-=static_cast<double>(a);
  return *this;
}
matrix& matrix::operator-=(long a){
  (*v)-=static_cast<double>(a);
  return *this;
}
matrix& matrix::operator/=(double a){
  (*v)/=a;
  return *this;
}
matrix& matrix::operator/=(int a){
  (*v)/=static_cast<double>(a);
  return *this;
}
matrix& matrix::operator/=(float a){
  (*v)/=static_cast<double>(a);
  return *this;
}
matrix& matrix::operator/=(long a){
  (*v)/=static_cast<double>(a);
  return *this;
}


//koniec [sekcji 3]

//********************************************************************************************8 
//[sekcja 4]

matrix& matrix::operator=(const matrix& a)
{
  if (il_kl() == a.il_kl() && il_wr() == a.il_wr())
    {
      if(this!=&a){
	delete v;
	v=new valarray<double>(a.size());
	for(size_t i=0; i<size();i++) (*v)[i]=(*a.v)[i];
      }
    }
  else
     blad("error: you are trying to copy matrix of different sizes");
  return *this;
};

inline matrix& matrix::operator+=(const matrix& a)
  {
    if (il_kl() == a.il_kl() && il_wr() == a.il_wr())
      {
	for(size_t i=0;i<size();i++)
	 (*v)[i]+=(*a.v)[i];
      }
    else
       blad("error: you are trying to add matrixes of different sizes");
    
    return *this;
  };

inline matrix& matrix::operator-=(const matrix& a)
  {
    if (il_kl() == a.il_kl() && il_wr() == a.il_wr())
      {
	for(size_t i=0;i<size();i++)
	  (*v)[i]-=(*a.v)[i];
      }
    else
       blad("error: you are trying to subtract  matrix of different sizes");
 
    
    return *this;
  };

matrix operator+(const matrix a,const matrix b)
{
  matrix r=a;
  r+=b;
   return r;

};
matrix operator-(const matrix a,const matrix b)
{
  matrix r=a;
  r-=b;
   return r;

};

matrix operator*(const matrix a,const matrix b){
  
  matrix swap(a.il_kl(),b.il_wr());

  if(a.il_wr()==b.il_kl())
    {
      
      for(size_t i=0;i<a.il_wr();i++){
	for(size_t j=0;j<b.il_kl();j++){
	  for(size_t z=0;z<a.il_wr();z++){
	    swap(i)[j]+=a.wiersz(i)[z]*b.wiersz(z)[j];
	  }
	}
      }
    }
  else 
    swap.blad("error: these are not proper matrixes to multiply");

  return swap;
  }


matrix operator*(double a,matrix b){
  return b*=a;
}


double matrix::wyzn(){

matrix mt(il_kl(),il_wr());
 (*mt.v)=(*v); 
 size_t n = mt.il_kl();

 if(n==il_wr())
   {

     // przystepuje do eliminacji gaussa-jordana
     // eliminacja Gauss'a
     for (size_t i = 0; i < n-1; i++)
       {
	 for (size_t j = i+1; j < n; j++)
	   {
	     double a; 
	     a = - (mt.wiersz(j)[i])/(mt.wiersz(i)[i]);
	     
	     for (size_t k = i; k < n; k++)
	       {
		 mt.wiersz(j)[k] = mt.wiersz(j)[k] + mt.wiersz(i)[k]*a;
	       }
	   }
       }
   }
 else blad("error: this is not a square matrix");
 
 double wyznacznik = 1;
 for (size_t i = 0; i < n; i++)
   {
     // mnozymy elementy na diagonali
     wyznacznik = wyznacznik * mt.wiersz(i)[i];
   }
 
 return wyznacznik; // zwracam wyznacznik
 
}
double matrix::wyzn(size_t n){

matrix mt(il_kl(),il_wr());
 (*mt.v)=(*v); 
 if(n<=il_wr())
   {

     // przystepuje do eliminacji gaussa-jordana
     // eliminacja Gauss'a
     for (size_t i = 0; i < n-1; i++)
       {
	 for (size_t j = i+1; j < n; j++)
	   {
	     double a; 
	     a = - (mt.wiersz(j)[i])/(mt.wiersz(i)[i]);
	     
	     for (size_t k = i; k < n; k++)
	       {
		 mt.wiersz(j)[k] = mt.wiersz(j)[k] + mt.wiersz(i)[k]*a;
	       }
	   }
       }
   }
 else blad("error: this is not a square matrix");
 
 double wyznacznik = 1;
 for (size_t i = 0; i < n; i++)
   {
     // mnozymy elementy na diagonali
     wyznacznik = wyznacznik * mt.wiersz(i)[i];
   }
 
 return wyznacznik; // zwracam wyznacznik
 
}


double matrix::slad(){
  double tarce=0;
  matrix wt=*this;
  for(size_t i=0;i<il_kl();i++)
    tarce+=wt.wiersz(i)[i];
  return tarce;
}

bool matrix::operator==(const matrix& a){
  bool row=true;
  if(a.size()==size()){
    for(size_t i=0;i<a.size();i++)
      row=row && ((*a.v)[i]==(*v)[i]);
  }
  else{ 
    row=false;}
  return row;
}
bool matrix::operator!=(const matrix& a){
  bool row=true;
  if(a.size()==size())
    row=false;
  return row;
}

ostream& operator<< (ostream& s, matrix& a)
{
  for (size_t i=0;i<a.il_wr();i++){
    for(size_t j=0;j<a.il_kl();j++){
      s.width(12);s.precision(8);
      s<< a(i)[j]<<" ";}
    s<<endl;
  }
  return s;
}

istream& operator>> (istream& s, matrix& a)
{
   for (size_t i=0;i<a.il_wr();i++){
    for(size_t j=0;j<a.il_kl();j++){
    s>>a[i][j];
    if(s.bad() || s.fail()) a.blad("something went wrong heheh");
    }
    
   }
  return s;
}



matrix matrix::trans()
{
  matrix swap=*this;
  size_t n=il_kl();
  size_t m=il_wr();
  for(size_t i=0;i<n;i++){
    for(size_t j =0;j<m;j++){
      swap(i,j)=wiersz(j)[i];
    }
  }
  return swap;
}


matrix operator+(const matrix s,int jednos){
  matrix swap=s;
  size_t n=s.il_kl();
  if(s.il_kl()==s.il_wr()){

    for(size_t i=0;i<n;i++)
      swap.wiersz(i)[i]+=jednos;
  }
  else  swap.blad("macierz nie jest kwadratowa");

  return swap;
}

matrix operator-(const matrix s,int jednos){
  matrix swap=s;
  size_t n=s.il_kl();
  if(s.il_kl()==s.il_wr()){

    for(size_t i=0;i<n;i++)
      swap.wiersz(i)[i]-=jednos;
  }
  else  swap.blad("macierz nie jest kwadratowa");

  return swap;
}
/**====================================================================*
 *                                                                    <BR>
 *              mnor zwraca wycinek macierzy                          <br>
 *====================================================================<br>
 *                                                                    <br>
 *  Parametry wejscia:                                                <br>
 *   ================                                                 <br>
 *      s      matrix s;      czyli macierz wywolywana                <br>
 *      dlx    size_t dlx     dlugosc x                               <br>
 *      dly    size_t dly     dlugosc y                               <br>
 *      pox    size_t pox     dolny zakres x                          <br>
 *      poy    size_t poy     dolny zakres y                          <br> 
 *                                                                    <br>
 *   Parametry wyjsciowe:                                             <br>
 *   =================                                                <br>
 *    Zwraca wybrany minor                                            <br>
 *====================================================================<br>*/



matrix mnor(matrix& s, size_t dlx, size_t dly, size_t pox, size_t poy)
{
  
  matrix swap(dlx-pox,dly-poy);
  
  if(dly < poy || dlx < pox) swap.blad("no ktos tu jest wybitnie glupi");
  if(dly < s.il_kl() || dlx < s.il_wr()){

    for(size_t i=0;i<dlx-pox;i++){
      for(size_t j=0;j<dly-poy;j++){
	swap.wiersz(i)[j]=s.wiersz(i+pox)[j+poy];
      }
    }
  }
  else swap.blad("too big minor ");
  
  return swap;
}

/**====================================================================*
 *                                                                    <BR>
 *             lu funkcja dokonuje rozkladu lu                        <br>
 *<hr>
 *====================================================================<br>
 *                                                                    <br>
 *  Parametry wejscia:                                                <br>
 *   ================                                                 <br>
 *      *this      matrix *this;      czyli macierz wywolywana        <br>
 *      jaka       char jaka                                          <br>
 *                   znak macierzy do zwrucenia "l" lub "u"           <br>
 *<hr>                                                                <br>
 *   Parametry wyjsciowe:                                             <br>
 *   =================                                                <br>
 *   l/u       matrix l/u                                             <br>
 *             macierze rozkladu                                      <br>
 *====================================================================<br>*/

matrix matrix::lu(const char jaka){
  size_t p=il_kl();
  matrix l(p,p),u(p,p);
  l=l+1;
  // utworzenie pierwszego wiersza i kolumny:
  for(size_t i=0; i<p; i++){
    u(0,i)=wiersz(0)[i];
    l(i,0)=wiersz(i)[0]/u(0,0);
  }
  // Macierz U:
  for(size_t k=1; k<p; k++){
    for(size_t j=k; j<p; j++){
      double sum=0;
      for(size_t y=0; y<=k-1; y++){
        sum=sum+(l(k,y)*u(y,j));
      }
      u(k,j)=wiersz(k)[j]-sum;
    }
    // Macierz L:
    for(size_t i=k+1; i<p; i++){
      double sum=0;
      for(size_t y=0; y<=k-1; y++){
        sum=sum+l(i,y)*u(y,k);
      }
      l(i,k)=(wiersz(i)[k]-sum)/u(k,k);
    }
  }

  return (jaka=='l')?l:u; 
}
//macierz odwrotna
matrix matrix::inverse()
{
  int k1,l1,n1,n=il_kl();
  double d1,v,w;
  matrix b(n,n),inverse(n,n);
  d1 = wyzn();
  if(d1==0.0)
    {
      cout << "Zmienne sa zalezne : Nie istnieje macierz odwrotna.\n\n";
      exit(1);
    }
  else
    {
      v=-1.0;
      for(int i=0;i<n;i++)
	{
	  v=-v;
	  w=-1.0;
	  for(int j=0;j<n;j++)
	    {
	      w=-w;
	      n1=n-1;
	      for(int k=0;k<n1;k++)
		{
		  k1=k;
		  if(k>=i) k1=k+1;
                  for(int l=0;l<n1;l++)
		    {
		      l1=l;
		      if(l>=j) l1=l+1;
		      b[k][l]=wiersz(k1)[l1];
		    }
		}
	      inverse[j][i]=b.wyzn(n1)/d1*v*w;
	    }
	}
    }
  return inverse;
}

//trojdiagonalizacja macierzy symetrycznej do macierzy trojdiagonalnej
void matrix::tridiag(){
  matrix b=*this;
  const double eps=0.00000000001;
  size_t n= b.il_kl();
  std::valarray<double> u,v,z;
  u.resize(n);
  v.resize(n);
  z.resize(n);

  for(size_t i=0;i<n-2;i++){
    double sum=0.0;
    for(size_t j=i+1;j<n;j++){
      sum+=pow(b(i,j),2);
    }
    double test =(n-1)*eps;
    if(sum<test)
      continue;
    double check=b(i,i+1);
    double prosimo=check/abs(check);
    double s= prosimo* sqrt(sum);
    double den =s*(s+b(i,i+1));
    double den2=2*den;
    for(size_t j=i;j<n;j++){
      if(j==i) u[j]=0.0;
      else if(j==i+1) u[j]=b(i,i+1)+s;
      else u[j]=b(i,j);
    }
    for(size_t j=i;j<n;j++){
      sum=0.0;
      for(size_t k=i+1;k<n;k++)
        sum+=b(j,k)*u[k];
      z[j]=sum/den;
    }
    for(size_t j=i;j<n;j++){
      sum = 0.0;
      for(size_t k=i+1;k<n;k++)
        sum = sum+u[k]*z[k];
      v[j] = z[j]-sum*u[j]/den2;
    }
    for(size_t j=i;j<n;j++){
      for(size_t k=i;k<n;k++){
        b(j,k) = b(j,k)-u[j]*v[k]-u[k]*v[j];
      }
    }
    for(size_t j=i;j<n;j++)
      for(size_t k=i;k<n;k++)
        b(k,j) =  b(j,k);
  }
  for(size_t j=0;j<n;j++){
    for(size_t i=0;i<n;i++)
      {
	if(abs(b(j,i))<eps) b(j,i)=0.0;
      }
  }
  *this=b;
}
/**====================================================================*
 *                                                                    <BR>
 *     jacobi znajduje wartosci wlasne oraz wektory wlasne        <BR><br>
 *               macierzy kwadratowej symetrycznej                    <br>
 *====================================================================<br>
 *                                                                    <br>
 *  Parametry wejscia:                                                <br>
 *   ================                                                 <br>
 *      *this      matrix *this;      czyli macierz wywolywana        <br>
 *                                                                    <br>
 *   Parametry wyjsciowe:                                             <br>
 *   =================                                                <br>
 *   V       matrix V                                                 <br>
 *             macierz z wektorami wlasnymi                           <br>
 *   E       wektor wartosci wlasnych                                 <br><br>
 *   rot     int rot                                                  <br>
 *            liczba rotacji                                          <br>
 *====================================================================<br>
 *                                                                    <br>
 *   funkcje:   ???????                                               <br>
 *   =======                                                          <br>
 *                                                                    <br>
 *====================================================================<br>*/
void matrix::jacobi(matrix& A,matrix& V,std::valarray<double>& D,int& rot){
  std::valarray<double>  B, Z;
  B.resize(A.il_kl());
  Z.resize(A.il_kl());
  double  c,g,h,s,sm,t,tau,theta,tresh;
  int     N=A.il_kl();
  
  V=V+1; //macierz jenostkowa
  for (int ip=0; ip<N; ip++) {
    B[ip]=A[ip][ip];
    D[ip]=B[ip];
    Z[ip]=0;
  }//warunki poczatkowe
  rot=0;
  for (int i=0; i<50; i++) {//maxymalna liczba iteracji 50 jak sie nie uda to koniec
    sm=0;
    for (int ip=0; ip<(N-1); ip++)    //suma elementow na nie-przekatnej
      for (int iq=ip+1; iq<N; iq++)
        sm+=fabs(A[ip][iq]);
    if (sm==0) {
      return;       //koniec algorytmu "sukces"
    }
    if (i < 3)
      tresh=0.2*sm*sm;
    else
      tresh=0;
    for (int ip=0; ip<N-1; ip++) {
      for (int iq=ip+1; iq<N; iq++) {
        g=100*fabs(A[ip][iq]);
	if ((i > 3) && (fabs(D[ip])+g == fabs(D[ip])) && (fabs(D[iq])+g == fabs(D[iq])))
          A[ip][iq]=0;
        else if (fabs(A[ip][iq]) > tresh) {
          h=D[iq]-D[ip];
          if (fabs(h)+g == fabs(h))
            t=A[ip][iq]/h;
          else {
            theta=0.5*h/A[ip][iq];
            t=1/(fabs(theta)+sqrt(1.0+theta*theta));
            if (theta < 0)  t=-t;
          }
          c=1.0/sqrt(1.0+t*t);
          s=t*c;
          tau=s/(1.0+c);
          h=t*A[ip][iq];
          Z[ip] -= h;
          Z[iq] += h;
          D[ip] -= h;
          D[iq] += h;
          A[ip][iq]=0;
          for (int j=0; j<ip; j++) {
	    g=A[j][ip];
            h=A[j][iq];
            A[j][ip] = g-s*(h+g*tau);
            A[j][iq] = h+s*(g-h*tau);
          }
          for (int j=ip+1; j<iq; j++) {
            g=A[ip][j];
            h=A[j][iq];
            A[ip][j] = g-s*(h+g*tau);
            A[j][iq] = h+s*(g-h*tau);
          }
          for (int j=iq+1; j<N; j++) {
            g=A[ip][j];
            h=A[iq][j];
            A[ip][j] = g-s*(h+g*tau);
            A[iq][j] = h+s*(g-h*tau);
          }
	  //wektory wlasne 
	    for (int j=0; j<N; j++) {
            g=V[j][ip];
            h=V[j][iq];
            V[j][iq] = g-s*(h+g*tau);
	    V[j][ip] = h+s*(g-h*tau);
	    }
          rot=rot++;
        } 
      } 
    } 
    for (int ip=0; ip<N; ip++) {
      B[ip] += Z[ip];
      D[ip]=B[ip];
      Z[ip]=0;
    }
  } 
  cout<<"\n 50 iterations !\n";
  return;  //za duzo iteracji jakis blad
}
/**====================================================================*
 *                                                                    <BR>
 *     ujacobi znajduje wartosci wlasne oraz wektory wlasne       <BR><br>
 *               macierzy kwadratowej symetrycznej                    <br>
 *====================================================================<br>
 *                                                                    <br>
 *  Parametry wejscia:                                                <br>
 *   ================                                                 <br>
 *      *this      matrix *this;      czyli macierz wywolywana        <br>
 *                                                                    <br>
 *   Parametry wyjsciowe:                                             <br>
 *   =================                                                <br>
 *   V       matrix V                                                 <br>
 *             macierz z wektorami wlasnymi                           <br>
 *   E       wektor wartosci wlasnych                                 <br><br>
 *   ewentualnie funkcja moze zwracac rownierz libze rotacji          <br>
 *====================================================================<br>
 *                                                                    <br>
 *   funkcje:   jacobi                                                <br>
 *   =======                                                          <br>
 *                                                                    <br>
 *====================================================================<br>*/

void matrix::ujacobi(std::valarray<double>& E,matrix& V){
  int rot;//ilosc obrotow jak bedzie potrzebna to sie funkcje zmieni
  E.resize(il_kl());
  matrix ala=*this;
  jacobi(ala,V,E,rot);
};

/**====================================================================*
 *                                                                    <BR>
 *     trisym znajduje wartosci wlasne oraz wektory wlasne        <BR><br>
 *                dla macierzy trojdiagonalnej                        <br>
 *====================================================================<br>
 *                                                                    <br>
 *  Parametry wejscia:                                                <br>
 *   ================                                                 <br>
 *      *this      matrix *this;      czyli macierz wywolywana        <br>
 *                                                                    <br>
 *   Parametry wyjsciowe:                                             <br>
 *   =================                                                <br>
 *      Z         matrix Z;                                           <br> 
 *                 macierz z wektorami wlasnymi                       <br>
 *      D         wektor z wartosciami wlasnymi                       <br>
 *====================================================================<br>
 *                                                                    <br>
 *   funkcje:   SIGN                                                  <br>
 *   =======                                                          <br>
 *                                                                    <br>
 *====================================================================<br>*/

void matrix::trisym(matrix& Z,std::valarray<double>& D){
  double b,c,dd,f,g,p,r,s;
  int n=Z.il_kl(),iter=0,m;
  
  std::valarray<double> E;
  D.resize(n);
  E.resize(n);
  Z=Z+1; //macierz jednostkowa
  for(int i=0;i<n;i++)
    D[i]=wiersz(i)[i];
  for(int i=1;i<n;i++)
    E[i]=wiersz(i)[i-1];
 
  if (n>1) {
    for (int i=1; i<n; i++)  E[i-1]=E[i];
    E[n-1]=0.0;
    for (int l=0; l<n; l++) {
      iter=0;
    l1: for (m=l; m>n; m--) {
      dd=fabs(D[m])+fabs(D[m+1]);
      if (fabs(E[m]-dd)<1e-8) goto l2;
    }
      m=n-1;
    l2: if (m!=l) {
      if (iter==30) {
	//cout<<"\n 30 iterations.\n";
	return;
      }
      iter++;
      g=(D[l+1]-D[l])/(2.0*E[l]);
      r=sqrt(g*g+1.0);
      g=D[m]-D[l]+E[l]/(g+SIGN(r,g));
      s=1.0; c=1.0; p=0.0;
      for (int i=m-1; i>l-1; i--) {
	f=s*E[i]; b=c*E[i];
	if (fabs(f)>=fabs(g)) {
	  c=g/f;
	  r=sqrt(c*c+1.0);
	  E[i+1]=f*r;
	  s=1.0/r;
	  c=c*s;
	}
	else {
	  s=f/g;
	  r=sqrt(s*s+1.0);
	  E[i+1]=g*r;
	  c=1.0/r;
	  s=s*c;
	}
	g=D[i+1]-p;
	r=(D[i]-g)*s+2.0*c*b;
	p=s*r;
	D[i+1]=g+p;
	g=c*r-b;
	//wektory wlasne dla chetnych
	for (int k=0; k<n; k++) {
	  f=Z[k][i+1];
	  Z(k,i+1)=s*Z[k][i]+c*f;
	  Z(k,i)=c*Z[k][i]-s*f;
	}
	}
      D[l]=D[l]-p;
      E[l]=g; E[m]=0.0;
      goto l1;
    }
    } //of l loop
    if (iter<30)
      cout<<iter<<" iterations.\n";
  }
}
 
/**====================================================================*
 *                                                                    <BR>
 *   balance  przerabia macierz na macierz zbalansowaa            <BR><br>
 *====================================================================<br>
 *                                                                    <br>
 *  Parametry wejscia:                                                <br>
 *   ================                                                 <br>
 *      *this      matrix *this;      czyli macierz wywolywana        <br>
 *                                                                    <br>
 *   Parametry wyjsciowe:                                             <br>
 *   =================                                                <br>
 *      a      matrix   a;                                            <br>
 *               macierz zbalansowana                                 <br>
 *      low    int low                                                <br>
 *               indeks pierwszej kolumny niezerowej                  <br>
 *      high   int high                                               <br>
 *               indeks ostaniej niezerowej kolumny                   <br>
 *      scal   wektor zmian                                           <br> 
 *====================================================================<br>
 *                                                                    <br>
 *   funkcje:   SWAP                                                  <br>
 *   =======                                                          <br>
 *                                                                    <br>
 *====================================================================<br>*/

void matrix::balance_full(int& low,int& high,std::valarray<double>& scal){
  matrix mat=*this;
  int basis=2;
  int i, j, n=il_kl();
  scal.resize(n);
  int k, m;
  bool iter;
  double b2, r, c, f, g, s;

  b2 = double((basis * basis));
  m = 0;
  k = n - 1;
  do
    {
      iter = false;
      for (j = k; j >= 0; j--)
	{
	  for (r = 0, i = 0; i <= k; i++)
	    if (i != j)  r += fabs(mat[j][i]);

	  if (r == 0)
	    {
	      scal[k] = (double) j;
	      if (j != k)
		{
		  for (i = 0; i <= k; i++) SWAP(mat[i][j], mat[i][k]);
		  for (i = m; i < n; i++)  SWAP(mat[j][i], mat[k][i]);
									}
	      k--;
	      iter = true;
	    }
	}  
    }   
  while (iter);
  
  do
    {
      iter = false;
      for (j = m; j <= k; j++)
	{
	  for (c = 0, i = m; i <= k; i++)
	    if (i != j) c += fabs(mat[i][j]);
	  if (c == 0)
	    {
	      scal[m] = (double)j;
	      if ( j != m )
		{
		  for (i = 0; i <= k; i++) SWAP (mat[i][j], mat[i][m]);
		  for (i = m; i < n; i++)  SWAP(mat[j][i], mat[m][i]);
									}
	      m++;
	      iter = true;
	    }
	}  
    }   
  while (iter);

  low = m;
  high = k;
  for (i = m; i <= k; i++) scal[i] = 1;

  do
    {
      iter = false;
      for (i = m; i <= k; i++)
	{
	  for (c = r = 0, j = m; j <= k; j++)
	    if (j !=i)
	      {
		c +=  fabs(mat[j][i]);
		r += fabs(mat[i][j]);
	      }
	  g = r / basis;
	  f = 1.0;
	  s = c + r;

	  while (c < g)
	    {
	      f *= basis;
	      c *= b2;
	    }

	  g = r * basis;
	  while (c >= g)
	    {
	      f /= basis;
	      c /= b2;
	    }

	  if ((c + r) / f < (double)0.95 * s)
	    {
	      g = 1 / f;
	      scal[i] *= f;
	      iter = true;
	      for (j = m; j < n; j++ ) mat[i][j] *= g;
	      for (j = 0; j <= k; j++ ) mat[j][i] *= f;
	    }
	}
    }
  while (iter);
  *this=mat;
}
/**====================================================================*
 *                                                                    <BR>
 *     balance  przerabia macierz na macierz zbalansowaa            <BR><br>
 *====================================================================<br>
 *                                                                    <br>
 *  Parametry wejscia:                                                <br>
 *   ================                                                 <br>
 *      *this      matrix *this;      czyli macierz wywolywana        <br>
 *                                                                    <br>
 *   Parametry wyjsciowe:                                             <br>
 *   =================                                                <br>
 *      a      matrix   a;                                            <br>
 *               macierz zbalansowana                                 <br>
 *====================================================================<br>
 *                                                                    <br>
 *   funkcje:   SWAP                                                  <br>
 *   =======                                                          <br>
 *                                                                    <br>
 *====================================================================<br>*/

void matrix::balance(){
  matrix mat=*this;
  int basis=2;
  int i,j;
  int k, m, n=il_kl();;
  bool iter;
  double b2, r, c, f, g, s;

  b2 = double((basis * basis));
  m = 0;
  k = n - 1;
  do
    {
      iter = false;
      for (j = k; j >= 0; j--)
	{
	  for (r = 0, i = 0; i <= k; i++)
	    if (i != j)  r += fabs(mat[j][i]);

	  if (r == 0 && j!=k)
	    {
	      for (i = 0; i <= k; i++) SWAP(mat[i][j], mat[i][k]);
	      for (i = m; i < n; i++)  SWAP(mat[j][i], mat[k][i]);
	    }
	  k--;
	  iter = true;
	}
    }  while (iter);
  do
    {
      iter = false;
      for (j = m; j <= k; j++)
	{
	  for (c = 0, i = m; i <= k; i++)
	    if (i != j) c += fabs(mat[i][j]);
	  if (c == 0 && j!=m)
	    {
	      for (i = 0; i <= k; i++) SWAP (mat[i][j], mat[i][m]);
	      for (i = m; i < n; i++)  SWAP(mat[j][i], mat[m][i]);
	    }
	  m++;
	  iter = true;
	}  
    }  while (iter);
  do
    {
      iter = false;
      for (i = m; i <= k; i++)
	{
	  for (c = r = 0,j = m; j <= k; j++)
	    if (j !=i)
	      {
		c +=  fabs(mat[j][i]);
		r += fabs(mat[i][j]);
	      }
	  g = r / basis;
	  f = 1.0;
	  s = c + r;
	  
	  while (c < g)
	    {
	      f *= basis;
	      c *= b2;
	    }
	  
	  g = r * basis;
	  while (c >= g)
	    {
	      f /= basis;
	      c /= b2;
	    }

	  if ((c + r) / f < (double)0.95 * s)
	    {
	      g = 1 / f;
	      iter = true;
	      for (j = m; j < n; j++ ) mat[i][j] *= g;
	      for (j = 0; j <= k; j++ ) mat[j][i] *= f;
	    }
	}
    }  while (iter);

  *this=mat;
}


/**====================================================================*
  *                                                            
  *    elmhes_full przerabia macierz na gorna macierz Hassenberga     <BR><br>
  *                                                            
  *====================================================================<br>
  *                                                                    <br>
  *  Parametry wejscia:                                                <br>
  *   ================                                                 <br>
  *      low      int low;                                             <br>
  *      high     int high;  spojrz na   balance                       <br>
  *      mat      matrix mat;  czyli macierz wywolywana                <br>
  *                                                                    <br>
  *   Parametry wyjsciowe:                                             <br>
  *   =================                                                <br>
  *      mat      matrix   mat;                                        <br>
  *               gorna macierz Hassenberga dodatkowe informacje       <br>
  *               o zamiana zachowane sa w jej dolnym trojkacie        <br>
  *      perm     int perm[];                                          <br>
  *               wektor permutacji dla elmtrans                       <br>
  *                                                                    <br>
  *====================================================================<br>
  *                                                                    <br>
  *   funkcje:   SWAP                                                  <br>
  *   =======                                                          <br>
  *                                                                    <br>
  *====================================================================<br>*/


void matrix::elmhes_full(int low,int high,std::valarray<double>& perm){
  matrix mat=*this;
  int n= il_kl();
  int i, j, m;
  double x, y;
  for (m = low + 1; m < high; m++)
    {
      i = m;
      x = 0;
      for (j = m; j <= high; j++)
	if (fabs(mat[j][m-1]) > fabs(x))
	  {
	    x = mat[j][m-1];
	    i = j;
	  }

      perm[m] = i;
      if (i != m)
	{
	  for (j = m - 1; j < n; j++) SWAP(mat[i][j], mat[m][j]);
	  for (j = 0; j <= high; j++) SWAP(mat[j][i], mat[j][m]);
								      }
      if (x != 0)
	{
	  for (i = m + 1; i <= high; i++)
	    {
	      y = mat[i][m-1];
	      if (y != 0)
		{
		  y = mat[i][m-1] = y / x;
		  for (j = m; j < n; j++) mat[i][j] -= y * mat[m][j];
		  for (j = 0; j <= high; j++) mat[j][m] += y * mat[j][i];
		}
	    }
	}
    }
  *this=mat;
}

/**====================================================================*
 *                                                                    <BR>
 *   elmhes przerabia macierz na gorna macierz Hassenberga      <BR><br>
 *====================================================================<br>
 *                                                                    <br>
 *  Parametry wejscia:                                                <br>
 *   ================                                                 <br>
 *      *this      matrix *this;      czyli macierz wywolywana        <br>
 *                                                                    <br>
 *   Parametry wyjsciowe:                                             <br>
 *   =================                                                <br>
 *      a      matrix   a;                                            <br>
 *               gorna macierz Hassenberga bez dodatkowych inform.    <br>
 *====================================================================<br>
 *                                                                    <br>
 *   funkcje:   SWAP                                                  <br>
 *   =======                                                          <br>
 *                                                                    <br>
 *====================================================================<br>*/

matrix matrix::elmhes(){
  matrix a=*this;
  int n=a.il_kl(),i;
  double y,x;
  for (int m=1;m<n;m++) {
    x=0.0;
    i=m;
    for (int j=m;j<n;j++) {
      if (fabs(a[j][m-1]) > fabs(x)) {
        x=a[j][m-1];
        i=j;
      }
    }
    if (i != m) {
      for (int j=m-1;j<n;j++) SWAP(a[i][j],a[m][j]);
      for (int j=0;j<n;j++) SWAP(a[j][i],a[j][m]);
    }
    if (x) {
      for (i=m+1;i<n;i++) {
	if ((y=a[i][m-1]) != 0.0) {
	  y /= x;
	  a[i][m-1]=y;
	  for (int j=m;j<n;j++)
	    a[i][j] -= y*a[m][j];
	  for (int j=0;j<n;j++)
	    a[j][m] += y*a[j][i];
	}
      }
    }
  }
  for(i=0;i<n;i++) //zerowanie odpowiednich komorek
    for (int j=i+2;j<n;j++)
    a[j][i]=0.0;
  return a;
}

/**====================================================================*
 *                                                                    <BR>
 *  qr wylicza wartosci wlasne dla dowolnej macierzy Hassenberga      <BR><br>
 *====================================================================<br>
 *                                                                    <br>
 *  Parametry wejscia:                                                <br>
 *   ================                                                 <br>
 *      *this      matrix *this;      czyli macierz wywolywana        <br>
 *                                                                    <br>
 *   Parametry wyjsciowe:                                             <br>
 *   =================                                                <br>
 *      a      matrix   a;                                            <br>
 *               gorna macierz Hassenberga bez dodatkowych inform.    <br>
 *      wr     wektor czesci rzeczywistych wartosci wlasnych          <br><br>
 *      wi     wektor czesci urojonych wartosci wlasnych              <br>
 *====================================================================<br>
 *                                                                    <br>
 *   funkcje:                                                         <br>
 *   =======                                                          <br>
 *                                                                    <br>
 *   zdefinoiwane stale:                                              <br>
 *   ===================                                              <br>
 *   MACH_EPS  dokladnosc dla danej maszyny                           <br>
 *   ZERO   == 0.0                                                    <br>
 *   ONE    == 1.0                                                    <br>
<HR>
 *====================================================================<br>*/

int matrix::qr(std::valarray<double>& wr,std::valarray<double>& wi){
  matrix h=*this;
  int n=il_kl();
  wr.resize(n);
  wi.resize(n);
  if (il_kl()!=il_wr()) h.blad("macierz nie jest kwadratowa");

  int  i,j;//vec=0;
  int  na, en, iter, k, l, m,low=0,high=n-1;
  double p = ZERO, q = ZERO, r = ZERO, s, t, w, x, y, z;
  for (i = 0; i < n; i++)
    if (i < low || i > high)
      {
	wr[i] = h[i][i];
	wi[i] = ZERO;
	
      }

  en = high;
  t = ZERO;

  while (en >= low)
    {
      iter = 0;
      na = en - 1;

      for ( ; ; )
	{
	  for (l = en; l > low; l--) 
	    if ( fabs(h[l][l-1]) <=  
		 MACH_EPS * (fabs(h[l-1][l-1]) + fabs(h[l][l])) )  break;

	  x = h[en][en];
	  if (l == en)               
	    {
	      wr[en] = h[en][en] = x + t;
	      wi[en] = ZERO;
	      en--;
	      break;
	    }

	  y = h[na][na];
	  w = h[en][na] * h[na][en];

	  if (l == na)
	    {
	      p = (y - x) * 0.5;
	      q = p * p + w;
	      z = sqrt (fabs (q));
	      x = h[en][en] = x + t;
	      h[na][na] = y + t;
	      if (q >= ZERO)
		{    
		  z = (p < ZERO) ? (p - z) : (p + z);
		  wr[na] = x + z;
		  wr[en] = s = x - w / z;
		  wi[na] = wi[en] = ZERO;
		  x = h[en][na];
		  r = sqrt (x * x + z * z);
		}  
	      else 
		{  
		  wr[na] = wr[en] = x + p;
		  wi[na] =   z;
		  wi[en] = - z;
		}

	      en -= 2;
	      break;
	    } 

	  if (iter >= MAXIT)
	    {
	      return (en);                         /* MAXIT Iteracji     */
	    }

	  if ( (iter != 0) && (iter % 10 == 0) )
	    {
	      t += x;
	      for (i = low; i <= en; i++) h[i][i] -= x;
	      s = fabs (h[en][na]) + fabs (h[na][en-2]);
	      x = y = (double)0.75 * s;
	      w = - (double)0.4375 * s * s;
	    }

	  iter ++;

	  for (m = en - 2; m >= l; m--)
	    {
	      z = h[m][m];
	      r = x - z;
	      s = y - z;
	      p = ( r * s - w ) / h[m+1][m] + h[m][m+1];
	      q = h[m + 1][m + 1] - z - r - s;
	      r = h[m + 2][m + 1];
	      s = fabs (p) + fabs (q) + fabs (r);
	      p /= s;
	      q /= s;
	      r /= s;
	      if (m == l) break;
	      if ( fabs (h[m][m-1]) * (fabs (q) + fabs (r)) <=
		   MACH_EPS * fabs (p)
		   * ( fabs (h[m-1][m-1]) + fabs (z) + fabs (h[m+1][m+1])) )
		break;
	    }

	  for (i = m + 2; i <= en; i++) h[i][i-2] = ZERO;
	  for (i = m + 3; i <= en; i++) h[i][i-3] = ZERO;

	  for (k = m; k <= na; k++)
	    {
	      if (k != m) 
		{         
		  p = h[k][k-1];
		  q = h[k+1][k-1];
		  r = (k != na) ? h[k+2][k-1] : ZERO;
		  x = fabs (p) + fabs (q) + fabs (r);
		  if (x == ZERO) continue;
		  p /= x;
		  q /= x;
		  r /= x;
		}
	      s = sqrt (p * p + q * q + r * r);
	      if (p < ZERO) s = -s;

	      if (k != m) h[k][k-1] = -s * x;
	      else if (l != m)
		h[k][k-1] = -h[k][k-1];
	      p += s;
	      x = p / s;
	      y = q / s;
	      z = r / s;
	      q /= p;
	      r /= p;

	      for (j = k; j < n; j++)     
		{
		  p = h[k][j] + q * h[k+1][j];
		  if (k != na)
		    {
		      p += r * h[k+2][j];
		      h[k+2][j] -= p * z;
		    }
		  h[k+1][j] -= p * y;
		  h[k][j]   -= p * x;
		}

	      j = (k + 3 < en) ? (k + 3) : en;
	      for (i = 0; i <= j; i++)    
		{
		  p = x * h[i][k] + y * h[i][k+1];
		  if (k != na)
		    {
		      p += z * h[i][k+2];
		      h[i][k+2] -= p * r;
		    }
		  h[i][k+1] -= p * q;
		  h[i][k]   -= p;
		}
	    }   
	}    
    }    
  return 0;
}

/**====================================================================*
 *                                                                    <BR>
 *   new_qr wylicza wartosci wlasne dla dowolnej macierzy HESS...    <BR><br>
 *====================================================================<br>
 *                                                                    <br>
 *  Parametry wejscia:                                                <br>
 *   ================                                                 <br>
 *      low,high   wyniki przestawien w balance_full                  <br>
 *      *this      matrix *this;      czyli macierz wywolywana        <br>
 *                                                                    <br>
 *   Parametry wyjsciowe:                                             <br>
 *   =================                                                <br>
 *      a      matrix   a;                                            <br>
 *               gorna macierz Hassenberga bez dodatkowych inform.    <br>
 *      wr     wektor czesci rzeczywistych wartosci wlasnych          <br><br>
 *      wi     wektor czesci urojonych wartosci wlasnych              <br>
 *====================================================================<br>
 *                                                                    <br>
 *   funkcje:                                                         <br>
 *   =======                                                          <br>
 *                                                                    <br>
 *   zdefinoiwane stale:                                              <br>
 *   ===================                                              <br>
 *   MACH_EPS  dokladnosc dla danej maszyny                           <br>
 *   ZERO   == 0.0                                                    <br>
 *   ONE    == 1.0                                                    <br>
<HR>
 *====================================================================<br>*/

int matrix::new_qr(std::valarray<double>& wr,std::valarray<double>& wi,int low,int high){
  matrix h=*this;
  int n=il_kl();
  wr.resize(n);
  wi.resize(n);
  if (il_kl()!=il_wr()) h.blad("macierz nie jest kwadratowa");
  int  i,j;
  int  na, en, iter, k, l, m;
  double p = ZERO, q = ZERO, r = ZERO, s, t, w, x, y, z;
  for (i = 0; i < n; i++)
    if (i < low || i > high)
      {
	wr[i] = h[i][i];
	wi[i] = ZERO;
	
      }

  en = high;
  t = ZERO;

  while (en >= low)
    {
      iter = 0;
      na = en - 1;

      for ( ; ; )
	{
	  for (l = en; l > low; l--) 
	    if ( fabs(h[l][l-1]) <=  
		 MACH_EPS * (fabs(h[l-1][l-1]) + fabs(h[l][l])) )  break;

	  x = h[en][en];
	  if (l == en)               
	    {
	      wr[en] = h[en][en] = x + t;
	      wi[en] = ZERO;
	      en--;
	      break;
	    }

	  y = h[na][na];
	  w = h[en][na] * h[na][en];

	  if (l == na)
	    {
	      p = (y - x) * 0.5;
	      q = p * p + w;
	      z = sqrt (fabs (q));
	      x = h[en][en] = x + t;
	      h[na][na] = y + t;
	      if (q >= ZERO)
		{    
		  z = (p < ZERO) ? (p - z) : (p + z);
		  wr[na] = x + z;
		  wr[en] = s = x - w / z;
		  wi[na] = wi[en] = ZERO;
		  x = h[en][na];
		  r = sqrt (x * x + z * z);
		}  
	      else 
		{  
		  wr[na] = wr[en] = x + p;
		  wi[na] =   z;
		  wi[en] = - z;
		}

	      en -= 2;
	      break;
	    } 

	  if (iter >= MAXIT)
	    {
	      return (en);                         /* MAXIT Iteracji     */
	    }

	  if ( (iter != 0) && (iter % 10 == 0) )
	    {
	      t += x;
	      for (i = low; i <= en; i++) h[i][i] -= x;
	      s = fabs (h[en][na]) + fabs (h[na][en-2]);
	      x = y = (double)0.75 * s;
	      w = - (double)0.4375 * s * s;
	    }

	  iter ++;

	  for (m = en - 2; m >= l; m--)
	    {
	      z = h[m][m];
	      r = x - z;
	      s = y - z;
	      p = ( r * s - w ) / h[m+1][m] + h[m][m+1];
	      q = h[m + 1][m + 1] - z - r - s;
	      r = h[m + 2][m + 1];
	      s = fabs (p) + fabs (q) + fabs (r);
	      p /= s;
	      q /= s;
	      r /= s;
	      if (m == l) break;
	      if ( fabs (h[m][m-1]) * (fabs (q) + fabs (r)) <=
		   MACH_EPS * fabs (p)
		   * ( fabs (h[m-1][m-1]) + fabs (z) + fabs (h[m+1][m+1])) )
		break;
	    }

	  for (i = m + 2; i <= en; i++) h[i][i-2] = ZERO;
	  for (i = m + 3; i <= en; i++) h[i][i-3] = ZERO;

	  for (k = m; k <= na; k++)
	    {
	      if (k != m) 
		{         
		  p = h[k][k-1];
		  q = h[k+1][k-1];
		  r = (k != na) ? h[k+2][k-1] : ZERO;
		  x = fabs (p) + fabs (q) + fabs (r);
		  if (x == ZERO) continue;
		  p /= x;
		  q /= x;
		  r /= x;
		}
	      s = sqrt (p * p + q * q + r * r);
	      if (p < ZERO) s = -s;

	      if (k != m) h[k][k-1] = -s * x;
	      else if (l != m)
		h[k][k-1] = -h[k][k-1];
	      p += s;
	      x = p / s;
	      y = q / s;
	      z = r / s;
	      q /= p;
	      r /= p;

	      for (j = k; j < n; j++)     
		{
		  p = h[k][j] + q * h[k+1][j];
		  if (k != na)
		    {
		      p += r * h[k+2][j];
		      h[k+2][j] -= p * z;
		    }
		  h[k+1][j] -= p * y;
		  h[k][j]   -= p * x;
		}

	      j = (k + 3 < en) ? (k + 3) : en;
	      for (i = 0; i <= j; i++)    
		{
		  p = x * h[i][k] + y * h[i][k+1];
		  if (k != na)
		    {
		      p += z * h[i][k+2];
		      h[i][k+2] -= p * r;
		    }
		  h[i][k+1] -= p * q;
		  h[i][k]   -= p;
		}
	    }   
	}    
    }    
  return 0;
}


void matrix::qr_full(std::valarray<double>& wr,std::valarray<double>& wi){
  matrix m=*this;
  int low,high;
  std::valarray<double> scal;
  scal.resize(m.il_kl());
  m.balance_full(low,high,scal);
  m.elmhes_full(low,high,scal);
  m.new_qr(wr,wi,low,high);
}  


//**************************************************************


inline void matrix::blad(const char* blad){
  cerr<<endl<<blad<<endl<<"program exited with ldstatus(1)"<<endl;

  exit(1);
}

