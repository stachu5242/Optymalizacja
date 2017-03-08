/***************************************************************/
/* Autorzy:             Rados�aw Szwarc                        */
/*                      Krzysztof Ginter                       */
/***************************************************************/


#ifndef GAosobnik_H
#define GAosobnik_H

#include <vector>
#include <cmath>
using std::vector;

/// Klasa majaca odzwierciedla� pojedy�czego osobnika
/** 
    Mam nadzieje �e mi si� to uda�o. (Jestem optymist� :).
*/

class osobnik_class
{
  /// Zbi�r chromosom�w 
  /**
     Jest to zbi�r chromosom�w dla wszystkich wsp�rz�dnych, <br>
     Czyli _ca�a_ informacja genetyczna niesiona przez osobnika.
     osobnik[1][4] to 5 miejsce w chromosomie dla 2 zmiennej.
     
  */
  vector< vector <bool> > osobnik_vv;

  /// Wielko�� o jak� r�ni si� dany osobnik od "nast�pnego"
  /**
     Dla przyk�adu osobnik 000 i 001 r�nia si� o 1, ale w rzeczywisto�ci r�nia si� <br>
     np. o 0.0001 i to 0.0001 jest w�a�nie tym skokiem. <br>
     Dla r�nych wsp�rz�dnych mo�e by� r�nie. <br>
     Warto policzy� to raz bo potem b�d� z tego ko�ysta�.
  */
     
  vector< double > skok_v;

  /// Warto�� funkcji w punkcie (osobnik wskazuje ten punkt)
  /**
     Warto�� ta wyliczana jest na podstawie funkcji zewn�trznej.
  */
  double wartosc_d;



  /// Warto�� jak� przyjmuje osobnik powi�kszona by wszystko by�o dodatnie
  /**
     Generalnie chodzi o to, by warto�ci funkcji przystosowania nie by�y <br>
     ujemne. Dlatego szukamy najmniejszej z warto�ci jakie posiadaj� <br>
     osobniki, i je�li warto�� ta jest ujemna to dodajemy abs() tej warto�ci <br>
     plus jeszcze 1.0 (by nie wysz�o zero dla osobnika najs�abszego). 
  */
  double wartosc_plus_d;

  /// Wartosc o jaka rozni sie ten osobnik od nastepnego w populacji.
  /**
     Chodzi tutaj o liczbe: wartosc_plus_d / suma_plus z nastepnego osobnika <br>
     Wartosc ta wstawiona jest wlasnie w tego osobnika.0
  */
  double roznica_d;




 public:
  /// Funkcja zwraca warto�� osobnika
  double wartosc();


  /// Funkcja _ustawia_ warto�� osobnika
  /**
     W rzeczywisto�ci funkcja nie oblicza warto�ci osobnika <br>
     poniewa� b�dzie to robi�a zewn�trzna funkcja podawana <br>
     przez u�ytkownika w innym miejscu. <br>
  */
  void wartosc(double);


  /// Funkcja dodaje liczb� do wektora skoku. 
  /** 
      Wykonuje po prostu push_back.
  */
  void skok(double);


  /// Funkcja zwraca warto�� skoku dla i'tej zmiennej.
  /**
     Zwyk�y return skok[int].
  */
  double skok(unsigned int);

  /// Metoda dodaje chromosom do osobnika.
  /**
     Wykonuje po prostu push_back.
  */
  void osobnik(vector< bool > );



  /// Zwraca liczb� gen�w w chromosomie.
  /**
     Zwraca .size() dla zadanej zmiennej.
  */
  unsigned int rozmiar(unsigned int);



  /// Metoda zwraca ilo�� wymiar�w danego osobnika.
  unsigned int ile_wymiarow();



  /// Metoda zwraca konkretny chromosom.
  /**
     Zwraca vector<bool> . Metoda potrzebna dla operatora=
  */
  vector <bool> zwroc_chromosom(unsigned int& i);

  /// Funkcja zmienia zadany gen 
  /** 
     Nie wiedzia�em jak rozwi�za� ten problem bez pisania operator�w... <br>
     Musz� si� w ko�cu ich nauczy� :P <br> <br>

     Funkcja pobiera 3 argumenty: <br>
     --- 1: numer zmiennej <br>
     --- 2: numer genu     <br>
     --- 3: 0 lub 1 (gen)  <br>
  */
  void zmien_gen(unsigned int, unsigned int, bool);


  /// Funkcja zwraca konkretny punkt wskazywany przez osobnika.
  /**
     Mo�na bezpo�rednio umie�ci� w wywo�aniu funkcji. <br>
     Ale tutaj chyba nie uwzgl�dniamy zakres�w zmiennych, wi�c chyba <br>
     nie mo�na ustawi� w wywo�aniu funkcji.
  */
  vector< double > punkt();


  /// Funkcja ustawia przesuni�cie dla osobnik�w na konkretnej zmiennej.
  /**
     Metoda wykonuje prosty push_back (jako �e mamy do czynienia z wektorem).
  */
  void przesuniecie( double );



  /// Funkcja zwraca przesuni�cie dla osobnik�w na konkretnej zmiennej.
  /**
     Jako parametr przyjmuje integer (numer zmiennej).
  */
  double przesuniecie ( int );


  /// Funkcja zwraca roznice pomiedzy osobnikiem obecnym a nastepnym.
  /** 
      Jest to zwykly return roznica_d.
  */
  double roznica();
  
  /// Funkcja ustawia roznice pomiedzy osobnikiem obecnym a nastepnym.
  /** 
      Funkcja potrzebna, jako ze zmienna jest prywatna.
  */
  void roznica(double);
  
  
  /// Funkcja zwraca warto�� osobnika o zwi�kszonej warto�ci
  double wartosc_plus();

  /// Funkcja _ustawia_ warto�� osobnika o zwi�kszonej warto�ci
  void wartosc_plus(double);


  /// Zmienia osobnika na innego (zamiast operatora=).
  /** 
      Musz� si� w ko�cu przy�o�y� do tych operator�w... :/
  */
  void nowa_wartosc(osobnik_class);

  /// Funkcja zwraca wartosc genu o jaki pytamy.
  bool gen(unsigned int, unsigned int);

  // POMOCNICZE funkcje (metody)
  
  /// wypisuje warto�ci poszczeg�lnych genow osobnika
  void wypisz_osobnika();

  /// wypisuje wartosci osobnika (w tym roznice wartosc itp.)
  void wypisz_wartosci();
};


#endif // ifndef GAosobnik_H
