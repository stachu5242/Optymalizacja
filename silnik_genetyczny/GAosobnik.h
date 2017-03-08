/***************************************************************/
/* Autorzy:             Rados³aw Szwarc                        */
/*                      Krzysztof Ginter                       */
/***************************************************************/


#ifndef GAosobnik_H
#define GAosobnik_H

#include <vector>
#include <cmath>
using std::vector;

/// Klasa majaca odzwierciedlaæ pojedyñczego osobnika
/** 
    Mam nadzieje ¿e mi siê to uda³o. (Jestem optymist± :).
*/

class osobnik_class
{
  /// Zbiór chromosomów 
  /**
     Jest to zbiór chromosomów dla wszystkich wspó³rzêdnych, <br>
     Czyli _ca³a_ informacja genetyczna niesiona przez osobnika.
     osobnik[1][4] to 5 miejsce w chromosomie dla 2 zmiennej.
     
  */
  vector< vector <bool> > osobnik_vv;

  /// Wielko¶æ o jak± ró¿ni siê dany osobnik od "nastêpnego"
  /**
     Dla przyk³adu osobnik 000 i 001 ró¿nia siê o 1, ale w rzeczywisto¶ci ró¿nia siê <br>
     np. o 0.0001 i to 0.0001 jest w³a¶nie tym skokiem. <br>
     Dla ró¿nych wspó³rzêdnych mo¿e byæ ró¿nie. <br>
     Warto policzyæ to raz bo potem bêdê z tego ko¿ysta³.
  */
     
  vector< double > skok_v;

  /// Warto¶æ funkcji w punkcie (osobnik wskazuje ten punkt)
  /**
     Warto¶æ ta wyliczana jest na podstawie funkcji zewnêtrznej.
  */
  double wartosc_d;



  /// Warto¶æ jak± przyjmuje osobnik powiêkszona by wszystko by³o dodatnie
  /**
     Generalnie chodzi o to, by warto¶ci funkcji przystosowania nie by³y <br>
     ujemne. Dlatego szukamy najmniejszej z warto¶ci jakie posiadaj± <br>
     osobniki, i je¶li warto¶æ ta jest ujemna to dodajemy abs() tej warto¶ci <br>
     plus jeszcze 1.0 (by nie wysz³o zero dla osobnika najs³abszego). 
  */
  double wartosc_plus_d;

  /// Wartosc o jaka rozni sie ten osobnik od nastepnego w populacji.
  /**
     Chodzi tutaj o liczbe: wartosc_plus_d / suma_plus z nastepnego osobnika <br>
     Wartosc ta wstawiona jest wlasnie w tego osobnika.0
  */
  double roznica_d;




 public:
  /// Funkcja zwraca warto¶æ osobnika
  double wartosc();


  /// Funkcja _ustawia_ warto¶æ osobnika
  /**
     W rzeczywisto¶ci funkcja nie oblicza warto¶ci osobnika <br>
     poniewa¿ bêdzie to robi³a zewnêtrzna funkcja podawana <br>
     przez u¿ytkownika w innym miejscu. <br>
  */
  void wartosc(double);


  /// Funkcja dodaje liczbê do wektora skoku. 
  /** 
      Wykonuje po prostu push_back.
  */
  void skok(double);


  /// Funkcja zwraca warto¶æ skoku dla i'tej zmiennej.
  /**
     Zwyk³y return skok[int].
  */
  double skok(unsigned int);

  /// Metoda dodaje chromosom do osobnika.
  /**
     Wykonuje po prostu push_back.
  */
  void osobnik(vector< bool > );



  /// Zwraca liczbê genów w chromosomie.
  /**
     Zwraca .size() dla zadanej zmiennej.
  */
  unsigned int rozmiar(unsigned int);



  /// Metoda zwraca ilo¶æ wymiarów danego osobnika.
  unsigned int ile_wymiarow();



  /// Metoda zwraca konkretny chromosom.
  /**
     Zwraca vector<bool> . Metoda potrzebna dla operatora=
  */
  vector <bool> zwroc_chromosom(unsigned int& i);

  /// Funkcja zmienia zadany gen 
  /** 
     Nie wiedzia³em jak rozwi±zaæ ten problem bez pisania operatorów... <br>
     Muszê siê w koñcu ich nauczyæ :P <br> <br>

     Funkcja pobiera 3 argumenty: <br>
     --- 1: numer zmiennej <br>
     --- 2: numer genu     <br>
     --- 3: 0 lub 1 (gen)  <br>
  */
  void zmien_gen(unsigned int, unsigned int, bool);


  /// Funkcja zwraca konkretny punkt wskazywany przez osobnika.
  /**
     Mo¿na bezpo¶rednio umie¶ciæ w wywo³aniu funkcji. <br>
     Ale tutaj chyba nie uwzglêdniamy zakresów zmiennych, wiêc chyba <br>
     nie mo¿na ustawiæ w wywo³aniu funkcji.
  */
  vector< double > punkt();


  /// Funkcja ustawia przesuniêcie dla osobników na konkretnej zmiennej.
  /**
     Metoda wykonuje prosty push_back (jako ¿e mamy do czynienia z wektorem).
  */
  void przesuniecie( double );



  /// Funkcja zwraca przesuniêcie dla osobników na konkretnej zmiennej.
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
  
  
  /// Funkcja zwraca warto¶æ osobnika o zwiêkszonej warto¶ci
  double wartosc_plus();

  /// Funkcja _ustawia_ warto¶æ osobnika o zwiêkszonej warto¶ci
  void wartosc_plus(double);


  /// Zmienia osobnika na innego (zamiast operatora=).
  /** 
      Muszê siê w koñcu przy³o¿yæ do tych operatorów... :/
  */
  void nowa_wartosc(osobnik_class);

  /// Funkcja zwraca wartosc genu o jaki pytamy.
  bool gen(unsigned int, unsigned int);

  // POMOCNICZE funkcje (metody)
  
  /// wypisuje warto¶ci poszczególnych genow osobnika
  void wypisz_osobnika();

  /// wypisuje wartosci osobnika (w tym roznice wartosc itp.)
  void wypisz_wartosci();
};


#endif // ifndef GAosobnik_H
