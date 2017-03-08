/***************************************************************/
/* Autorzy:             Rados³aw Szwarc                        */
/*                      Krzysztof Ginter                       */
/***************************************************************/


#ifndef GAzagadnienie_H
#define GAzagadnienie_H
#include <vector>
#include <string>

#include "GAosobnik.h"
#include "GAzakres.h"

using std::vector;
using std::string;


/// G³ówna klasa silnika genetycznego.
/**
   Nie jest niestety doskona³a :/ ale stara³em siê.
*/
class zagadnienie_class
{
  /// dokladnosc z jaka liczymy maksimum.
  /** 
      Zmienna wczytywana z pliku wejsciowego. <br>
      Na podstawie tej wartosci ustala sie dlugosc chromosomu.
  */
  double dokladnosc; 
  
  /// zmienna okresla czy liczymy minimum czy maksimum. 
  /** mozliwe wartosci: <br>
   * true - MAXIMUM zostanie policzone<br>
   * false - MINIMUM zostanie policzone<br>
   */
  bool maksimum; 

  /// Zmienna okre¶la czy mamy mutowaæ ze sta³ym prawdop. czy nie
  /**
     true - STALE prawdopodobienstwo
     false - ZMIENNE prawdopodobnienstwo
  */
  bool mut_stala;


  /// Zmienna okre¶la czy mam krzy¿owaæ osobniki czy te¿ nie.
  /**
     true - Z Krzy¿owaniem
     false - Bez Krzy¿owania.
  */
  bool czy_krzyzowac;
  

  /// Zmienna okresla czy mam stosowaæ w koñcowej fazie metodê Powella
  bool stosuj_powella;


  /// ilosc zmiennych od ktorych zalezna jest funkcja.
  unsigned int ilosc_zmiennych; 
  

  /// ile pokolen (generacji) ma przejsc dany problem.
  /** Okresla ile razy ewoluowac maja osobniki. */
  unsigned int ilosc_pokolen;
                             
  /// Ilosc osobnikow w pokoleniu.
  /** Zmienna najprawdopodobniej nie bedzie potrzebna <br>
     ale zobaczymy. */
  unsigned int wielkosc_populacji; 
                                  

  /// Najlepszy dotychczas znaleziony osobnik.... (wstawiany jest do nowej populacji).
  osobnik_class najlepszy_osobnik;
  
  /// Wektor osobników - tworzy pokolenie.
  vector< osobnik_class > populacja; 

  /// Wektor osobników który wchodzi do nowej populacji.
  vector< osobnik_class > nowa_populacja;
  
  /// Zakres zmiennych (ograniczenia na poszczegolne zmienne).
  vector< zakres_class > zakres; 


  /// Suma warto¶ci osobników z poprzedniego pokolenia
  /**
     Na podstawie tej zmiennej mo¿emy stwierdziæ czy populacja rozwija siê poprawnie <br>
     i czy mutacje oraz krzy¿owania daj± coraz to lepsze rezultaty. 
  */
  double suma_poprzednia;
  

  /// Suma warto¶ci osobników obecnego pokolenia
  /**
     Warto¶æ tej sumy nie jest jeszcze powiêkszona o abs() najmniejszego ujemnego elementu.
  */
  double suma;
  
  /// Suma warto¶ci osobników obecnego pokolenia (powiêkszona)
  /**
     Suma powiêkszona o abs() najmniejszego ujemnego elementu.
  */
  double suma_plus;

  /// Najmniejsza znaleziona warto¶æ funkcji.
  double min;
  
  /// Najlepszy jak dot±d znaleziony osobnik.
  /**
     Zastanawiam siê nad umieszczaniem najlepszego osobnika _zawsze_ <br>
     w nowej populacji. Zastanawiam siê tak¿e czy mutacja na tym osobniku <br>
     nie powinna byæ du¿o wiêksza ni¿ na pozosta³ych, poniewa¿ populacja bêdzie <br>
     siê zbli¿a³a do niego, wiêc aby unikaæ maksimów lokalnych powinni¶my go <br>
     mutowaæ w poszukiwaniu innych maksimów.
  */
  osobnik_class the_best;

  /// Maksymalna jak dot±d znaleziona warto¶æ (osobnika)
  /** 
      Jak na razie jest mi potrzebna, poniewa¿ nie mam zdefiniowanego operatora <br>
      przypisania osobnikowi innego osobnika, a tak bêdzie mi ³atwiej szukaæ <br>
      maksymalnej warto¶ci.
  */
  double max;
  


  /// Zmienna okre¶la czy na ekranie ma byæ widoczny postêp w liczeniu.
  /** 
      Wczytywana jest ona z pliku jako ostatnia zmienna.
  */
  bool wypisuj_postep;
  
  
  /// Zmienna mowiaca z jakim prawdopodobienstwem mam mutowac geny.
  /**
     Wartosc ta jak narazie jest stala, ale mam w planach to zmienic.
  */
  double p_mutacji_stalej;



  /// Z jakim prawdopodobienstwem mutowaæ geny znacz±ce.
  /**
     Chodzi tutaj o mutacjê zmienn±. s± geny bardziej znacz±ce <br>
     i mniej znacz±ce... dlatego mamy 2 zmienne. <br>
     <br>
     Na pocz±tku powinni¶my mutawaæ z wiêkszym prawdopodobieñstwem <br>
     geny bardziej znacz±ce aby dotrzeæ do w miarê wszystkich ekstremów <br>
     i wybraæ to najlepsze. <br>
  */
  double p_mutacji_zmiennej_z_1;
  

  /// To samo co p_mutacji..._z_1 lecz dla osobników z 2 czê¶ci populacji.
  double p_mutacji_zmiennej_z_2;
  
  /// Z jakim prawdopodobieñstwem mutowaæ geny mniej znacz±ce.
  double p_mutacji_zmiennej_nie_z_1;

  /// Podobnie do p_mutacji..._nie_z_1 lecz dla 2 czê¶ci populacji.
  double p_mutacji_zmiennej_nie_z_2;
  

  /// Po jakakim procencie ewolucji zredukowaæ do 0.0 mutacje znacz±c±.
  double ewolucja_ukierunkowana;

  /// Ilo¶æ genów znacz±cych
  double procent_genow_znaczacych;

  /// Procent osobników przeznaczony do "rozrzutu"
  /** 
      Chodzi o to ¿eby z wiêkszym prawdopodobieñstwem <br>
      szukaæ minimów i maksimów globalnych. <br>
      Jest to procent osobników dla których prawdopodobieñstwo <br>
      mutacji dalszej jest wiêksze. <br>
  */
  double GrupaOsobnikowDoRozrzucenia;


  /// Zmienna okresla ile razy populacja rozwija³a siê w dobr± stronê.
  /**
     Suma wszystkich osobników by³a wiêksza od sumy poprzedniego <br>
     pokolenia.
  */
  unsigned long dobry_kierunek_rozwoju;

  /// Zmienna okre¶la ile razy populacja rozwija³a siê w z³± stronê.
  /**
     Suma wszystkich osobników by³a mniejsza od sumy poprzedniego <br>
     pokolenia.
  */
  unsigned long zly_kierunek_rozwoju;




  /// Zmienna mówi ile osobników z danej populacji ju¿ siê zmutowa³o.
  /**
     Jest to zmienna pomocnicza, która okre¶la czy osobnik z danej 
     "grupy" nale¿y od tak zwanej grupy rozrzutu, grupy poszukiwawczej
  */
  unsigned long ile_zmutowalem;


public:


  /// Konstruktor klasy
  /** 
      Jako parametr przyjmuje nazwe pliku z danymi. Jesli nazwa <br> 
      nie zostala podana obiera domyslnie "INPUT" 
  */
  zagadnienie_class(string = "INPUT");


  /// funkcja losujaca liczbe 0 lub 1
  /**
     Nie przyjmuje parametrow i dziala w prosty sposob: rand() % 2
     zwraca bool'a
  */
  bool losuj01();
  

  /// funkcja losuje liczbê _z przedzia³u_ <0 ; 1)
  /**
     Nie trafimy nigdy na 1, ale mo¿emy otrzymaæ zero. <br>
     Nale¿y pamiêtaæ, ¿e jest to u³amek (double)
  */
  double losuj0do1();


  /// Funkcja zwraca "poprawione" (z przesuniêciem) wspó³rzêdne punktu.
  /** 
      Dzia³a tylko dla osobnika z populacji
      Chodzi tutaj o punkt wskazywany przez konkretnego osobnika. <br>
      Funkcja punkt() z klasy osobnik_class nie przesuwa wspó³rzêdnych... <br>
      Musi to zrobiæ za ni± powy¿sza funkcja z clasy zagadanienie_class. <br>
      <br>
      Funkcja pobiera numer osobnika w populacji. (Nie samego osobnika)
  */
  vector< double > punkt(int);
  
  /// Funkcja zwraca "poprawione" (z przesuniêciem) wspó³rzêdne punktu dla dowolnego osobnika
  vector< double > punkt(osobnik_class);


  /// Funkcja odpowiedzialna jest za reprodukcjê populacji
  /**
     Reprodukcja wybiera (dziêki funkcji dopasowania) najlepiej przystosowe <br>
     osobniki w populacji, wylicza sumê warto¶ci populacji, wybiera <br>
     najlepiej przystosowanego osobnika w populacji, dokonuje porównañ <br>
     z najlepszym osobnikiem kiedykolwiek znalezionym, <br>
     <br>
     WA¯NE: 
     <br>
     Dopiero w tym miejscu nastêpuje liczenie warto¶ci funkcji <br>
     w punkcie (osobniku).
  */
  void reprodukcja();
  
  
  /// Metoda mutuj±ca osobnika ze sta³ym prwadopodobieñstwem
  /**
     Nie zale¿y od niczego... Prawdopodobieñstwo mutacji ustawione jest <br>
     w miennej
  */
  void mutacja_stala(osobnik_class&);



  /// Metoda mutuj±ca osobnika ze zmiennym prawdopodobieñstwem
  /**
     Zale¿y od tego jaki jest postêp w ewolucji (ile generacji <br>
     przesz³o ju¿ zagadnienie). <br>
     Zale¿y od tego który jest osobnik w pokoleniu (ze wzglêdu na to <br>
     ¿e pierwszy osobnik jest najlepiej przystosowany osobnik <br>
     jest zawsze na pierwszym miejscu w nowym pokoleniu <br>
     dlatego te¿ bêdziemy go mutowaæ jak najbardziej w poszukiwaniu <br>
     innych ekstremów i warto¶ci najwiêkszych.
  */
  void mutacja_zmienna(osobnik_class&);




  /// Krzy¿owanie nr 1.
  /**
     Krzy¿ujemy osobnika w taki sposób, ¿e lozujemy wspó³rzêdn± <br>
     i krzy¿ujemy tylko j±, a reszte z osobnika przepisujemy. <br>
   */
  void krzyzowanie_1(osobnik_class&, osobnik_class);

  /// Krzy¿owanie nr 2.
  /**
     Krzy¿ujemy ka¿d± ze wspó³rzêdnych oddzielnie.
  */
  void krzyzowanie_2(osobnik_class&, osobnik_class&);



  /// Metoda klasy odpowiedzialna za przebieg reprodukcji mutacji i krzyzowania
  void ewolucja();









  ///////////////////////////////////////////////
  ///////////////////////////////////////////////
  ////////          POMOCNICZE          /////////
  ///////////////////////////////////////////////
  ///////////////////////////////////////////////





  /// Metoda pomocnicza (wypisuje wszystkie zmienne z klasy
  void wypisz_zmienne(int a = 0);


  /// Metoda pomocnicza wypisuje "warto¶ci" wszystkich osobników z populacji.
  /** 
      Wypisije ich geny itp.
  */
  void wypisz_osobnikow();
  
  /// Metoda pomocnicza wypisuje wartosci osobnikow.
  /**
     Wypisuje ich konkretna wartosc, wartosc_plus i roznice (po reprodukcji)
  */
  void wypisz_wartosci_osobnikow();
  
  /// Podobnie jak wyzej.
  void wypisz_wartosci_osobnikow_new();
  
};


#endif // ifndef GAzagadnienie_H
