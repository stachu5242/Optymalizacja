/*
                     Klasa macierzy


  Program napisany przez studenta II roku FTiMS Krzysztofa Gintera
 
*/



#ifndef matrix_h
#define matrix_h
#include"slice.tcc"
#include<vector>

///Klasa macierzy 2-wymiarowych
class matrix{
  std::valarray<double>* v; ///< moj kontener dla macierzy
  size_t d1,d2; ///< rozmiar macierzy
 public:
  ///konstruktor domyslny
  matrix();
  ///konstruktor domyslny
  matrix(size_t x,size_t y); 
  ///konstruktor wpisujacy w kazde pole wartosc a
  matrix(size_t x,size_t y,double a);
  ///konstruktor wpisujacy w kazde pole wartosc a
  matrix(size_t x,size_t y,int a);
  ///konstruktor wpisujacy w kazde pole wartosc a
  matrix(size_t x,size_t y,float a);
  ///konstruktor wpisujacy w kazde pole wartosc a
  matrix(size_t x,size_t y,long a);
  ///konstruktor kopiujacy
  matrix(const matrix& a);
  ///destruktor
  ~matrix();
  ///funkcja zmieniajaca wielkosc macierzy (tworzy kwadratowa o wym n)
  void resize(size_t  n);
  ///funkcja zmieniajaca wielkosc macierzy o wym n na m
  void resize(size_t  n,size_t m);
  ///funkcja zwracajaca rozmiar macierzy
  size_t size() const; 
  ///funkcja zwracajaca ilosc kolumn
  size_t il_kl() const;
  ///funkcja zwracajaca ilosc wierszy
  size_t il_wr() const;
  ///funkcja zwracajaca odpowiedni wiersz
  matrix wr(size_t n); 
  ///funkcja zwracajaca odpowiednia kolumne
  matrix kl(size_t n);
  std::valarray<double> wr_val(size_t n);
  std::valarray<double> kl_val(size_t n);

  /// zwraca kolumne przerobiona na wektor
  std::vector<double> kl_vec(size_t n);
  /// zwraca wiersz przerobiony na wektor
  std::vector<double> wr_vec(size_t n);
  //********************************************************************************

  // indeksy [sekcja 2]
  ///funcja zwracajaca wycinek odpowiedni macierzy
  Slice_iter<double> wiersz(size_t a);
  ///funcja zwracajaca wycinek odpowiedni staly macierzy
  Cslice_iter<double> wiersz(size_t a) const;
  ///funcja zwracajaca wycinek odpowiedni macierzy
  Slice_iter<double> kolumna(size_t a);
  ///funcja zwracajaca wycinek odpowiedni staly macierzy
  Cslice_iter<double> kolumna(size_t a) const;
  ///operator na ksztalt fortranowego
  double& operator() (size_t x, size_t y);
  ///operator na ksztalt fortranowego dla stalych
  double operator() (size_t x, size_t y) const;
  ///operator pojedynczy
  Slice_iter<double> operator() (size_t i); 
  ///operator pojedynczy dla stalych
  Cslice_iter<double> operator() (size_t i) const; 
  ///operator pojedynczy jak w c
  Slice_iter<double> operator[] (size_t i);
  ///operator pojedynczy dla stalych jak w c
  Cslice_iter<double> operator[] (size_t i) const;

  //*********************************************************************************

  // operacje na calej macierzy [sekcja 3]
  ///przeciarzone dodawanie do kazdego elementu macierzy
  matrix& operator+=(double);
  ///przeciarzone dodawanie do kazdego elementu macierzy
  matrix& operator+=(int);
  ///przeciarzone dodawanie do kazdego elementu macierzy
  matrix& operator+=(float);
  ///przeciarzone dodawanie do kazdego elementu macierzy
  matrix& operator+=(long);
  ///przeciarzone dzielenie do kazdego elementu macierzy
  matrix& operator/=(double);
  ///przeciarzone dzielenie do kazdego elementu macierzy
  matrix& operator/=(int);
  ///przeciarzone dzielenie do kazdego elementu macierzy
  matrix& operator/=(float);
  ///przeciarzone dzielenie do kazdego elementu macierzy
  matrix& operator/=(long);
  ///przeciarzone mnozenie do kazdego elementu macierzy
  matrix& operator*=(double);
  ///przeciarzone mnozenie do kazdego elementu macierzy
  matrix& operator*=(int);
  ///przeciarzone mnoozenie do kazdego elementu macierzy
  matrix& operator*=(float);
  ///przeciarzone mnozenie do kazdego elementu macierzy
  matrix& operator*=(long);
  ///przeciarzone odejmowanie do kazdego elementu macierzy
  matrix& operator-=(double);
  ///przeciarzone odejmowanie do kazdego elementu macierzy
  matrix& operator-=(int);
  ///przeciarzone odejmowanie do kazdego elementu macierzy
  matrix& operator-=(float);
  ///przeciarzone odejmowanie do kazdego elementu macierzy
  matrix& operator-=(long);
  //*********************************************************************************

  //operacje na macierzch [sekcja 4]
  ///operator przypisania
  matrix& operator= (const matrix&);
  ///suma 2 macierzy podstawiana pod pierwsza z nich
  matrix& operator+=(const matrix& a);
  ///roznica 2 macierzy podstawiana pod pierwsza z nich
  matrix& operator-=(const matrix& a);
  ///iloczyn 2 macierzy podstawiana pod pierwsza z nich
  matrix& operator*=(const matrix& a);
  ///operator rownosc
  bool operator==(const matrix& a);
  ///operator nierownosci
  bool operator!=(const matrix& a);

  //*********************************************************************************
  //metody dla macierzy
  /// funkcja wczytujaca macierz ze strumienia
  friend std::istream& operator>> (std::istream& s, matrix& a);
  /// funkcja wypisujaca macierz do strumienia 
  friend std::ostream& operator<< (std::ostream& s, matrix& a);  
  ///funkcja zwracajaca dane z macierzy w formie tablicy
  std::valarray<double>& array();
  ///funkcja liczaca wyznacznik dla wycinka macierzy
  double wyzn(size_t n);
  ///funkcja liczaca wyznacznik
  double wyzn();
  ///funkcja liczaca slad dla macierzy
  double slad();
  ///funkcja transponujaca macierz
  matrix trans();
  ///funkcja odwracajaca macierz
  matrix inverse();
  ///rozklada lu macierzy
  matrix lu(const char jaka);
  ///funkcja ustawiajaca macierz w najlepszej pozycji do algorytmu qr
  void balance();
  ///funkcja ustawiajaca macierz w najlepszej pozycji do algorytmu qr efektywniejsza dla duzych macierzy
  void balance_full(int& low,int& high,std::valarray<double>& scal);
  /// Bardziej rozbudowana wersja redukcji do macierzy Hassenberga wykorzystje lepszy balance
  void elmhes_full(int low,int high, std::valarray<double>& permu); 
  ///funkcja redukujaca macierz do macierzy gornej hasenberga wersja prosta
  matrix elmhes();
  ///trojdiagonalizacja macierzy symetrycznej
  void tridiag();
  /// Funkcja liczac wartosci wlasne metoda Jacobiego
  void jacobi(matrix& a,matrix& v,std::valarray<double>& d,int& rot);
  ///funkcja liczaca wartosci wlasne macierzy symetrycznej 
  void ujacobi(std::valarray<double>& E, matrix& V);
  ///funkcja liczaca wartosci wlasne macierzy trojdiagonalnej symetrycznej
  void trisym(matrix& z,std::valarray<double>& wlasne);
  ///funkcja liczaca wartosci wlasne dowolnej macierzy
  void qr_full(std::valarray<double>& wr,std::valarray<double>& wi);
  ///funkcja liczaca wartosci wlasne metoda qr dla macierzy Hessenberga
  int qr(std::valarray<double>& wr,std::valarray<double>& wi);
 ///funkcja liczaca wartosci wlasne metoda qr dla macierzy Hessenberga
  int new_qr(std::valarray<double>& wr,std::valarray<double>& wi,int low,int high);
  ///funkcja obclugujaca bledy
  void blad(const char* blad);
  ///funkcja zwracajaca wycinek macierzy
  friend matrix mnor(matrix& s, size_t dlx, size_t dly, size_t pox, size_t poy);
  ///operator odejmowania od macierzy macierzy jednostkowej
  friend matrix operator-(const matrix s,int jednos);
  ///operator dodawania od macierzy macierzy jednostkowej
  friend matrix operator+(const matrix s,int jednos);
  ///operator mnozenia dla 2 macierzy
  friend matrix operator*(const matrix a,const matrix b);
  ///operator mnozenia dla liczby i macierzy 
  friend matrix operator*(double a,matrix b);
  ///operator odejmowania dla 2 macierzy
  friend matrix operator-(const matrix a,const matrix b);
  ///operator dodawania dla 2 macierzy
  friend matrix operator+(const matrix a,const matrix b);
  // Makra wykorzystwane przez rozne funkcje
  ///funkcja zamiany 2 argumentow
  friend void SWAP(double& a,double& b)
    { double temp; temp = a; a = b; b = temp; };
  ///funkcja zwracajaca odpowiednia wartosc bezwzgledna zalezna od znaku zmiennej b
  friend double SIGN(double a,double b)
   {return ((b>=0)? fabs(a): -fabs(a)); };
  ///funkcja zwracajaca wartosc maksymalna dla dwuch zmiennych naturalnych
  friend int IMAX(int a,int b)
   {return ((a>=b)? a : b);};
  //Funkcja zwracajaca minimum dla dwuch zmiennych naturalnych
  friend int MIN(int a,int b)
    {return ((a>=b)? b: a);};
};

#endif
