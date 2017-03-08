/***************************************************************/
/* Autorzy:             Rados�aw Szwarc                        */
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


/// G��wna klasa silnika genetycznego.
/**
   Nie jest niestety doskona�a :/ ale stara�em si�.
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

  /// Zmienna okre�la czy mamy mutowa� ze sta�ym prawdop. czy nie
  /**
     true - STALE prawdopodobienstwo
     false - ZMIENNE prawdopodobnienstwo
  */
  bool mut_stala;


  /// Zmienna okre�la czy mam krzy�owa� osobniki czy te� nie.
  /**
     true - Z Krzy�owaniem
     false - Bez Krzy�owania.
  */
  bool czy_krzyzowac;
  

  /// Zmienna okresla czy mam stosowa� w ko�cowej fazie metod� Powella
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
  
  /// Wektor osobnik�w - tworzy pokolenie.
  vector< osobnik_class > populacja; 

  /// Wektor osobnik�w kt�ry wchodzi do nowej populacji.
  vector< osobnik_class > nowa_populacja;
  
  /// Zakres zmiennych (ograniczenia na poszczegolne zmienne).
  vector< zakres_class > zakres; 


  /// Suma warto�ci osobnik�w z poprzedniego pokolenia
  /**
     Na podstawie tej zmiennej mo�emy stwierdzi� czy populacja rozwija si� poprawnie <br>
     i czy mutacje oraz krzy�owania daj� coraz to lepsze rezultaty. 
  */
  double suma_poprzednia;
  

  /// Suma warto�ci osobnik�w obecnego pokolenia
  /**
     Warto�� tej sumy nie jest jeszcze powi�kszona o abs() najmniejszego ujemnego elementu.
  */
  double suma;
  
  /// Suma warto�ci osobnik�w obecnego pokolenia (powi�kszona)
  /**
     Suma powi�kszona o abs() najmniejszego ujemnego elementu.
  */
  double suma_plus;

  /// Najmniejsza znaleziona warto�� funkcji.
  double min;
  
  /// Najlepszy jak dot�d znaleziony osobnik.
  /**
     Zastanawiam si� nad umieszczaniem najlepszego osobnika _zawsze_ <br>
     w nowej populacji. Zastanawiam si� tak�e czy mutacja na tym osobniku <br>
     nie powinna by� du�o wi�ksza ni� na pozosta�ych, poniewa� populacja b�dzie <br>
     si� zbli�a�a do niego, wi�c aby unika� maksim�w lokalnych powinni�my go <br>
     mutowa� w poszukiwaniu innych maksim�w.
  */
  osobnik_class the_best;

  /// Maksymalna jak dot�d znaleziona warto�� (osobnika)
  /** 
      Jak na razie jest mi potrzebna, poniewa� nie mam zdefiniowanego operatora <br>
      przypisania osobnikowi innego osobnika, a tak b�dzie mi �atwiej szuka� <br>
      maksymalnej warto�ci.
  */
  double max;
  


  /// Zmienna okre�la czy na ekranie ma by� widoczny post�p w liczeniu.
  /** 
      Wczytywana jest ona z pliku jako ostatnia zmienna.
  */
  bool wypisuj_postep;
  
  
  /// Zmienna mowiaca z jakim prawdopodobienstwem mam mutowac geny.
  /**
     Wartosc ta jak narazie jest stala, ale mam w planach to zmienic.
  */
  double p_mutacji_stalej;



  /// Z jakim prawdopodobienstwem mutowa� geny znacz�ce.
  /**
     Chodzi tutaj o mutacj� zmienn�. s� geny bardziej znacz�ce <br>
     i mniej znacz�ce... dlatego mamy 2 zmienne. <br>
     <br>
     Na pocz�tku powinni�my mutawa� z wi�kszym prawdopodobie�stwem <br>
     geny bardziej znacz�ce aby dotrze� do w miar� wszystkich ekstrem�w <br>
     i wybra� to najlepsze. <br>
  */
  double p_mutacji_zmiennej_z_1;
  

  /// To samo co p_mutacji..._z_1 lecz dla osobnik�w z 2 cz�ci populacji.
  double p_mutacji_zmiennej_z_2;
  
  /// Z jakim prawdopodobie�stwem mutowa� geny mniej znacz�ce.
  double p_mutacji_zmiennej_nie_z_1;

  /// Podobnie do p_mutacji..._nie_z_1 lecz dla 2 cz�ci populacji.
  double p_mutacji_zmiennej_nie_z_2;
  

  /// Po jakakim procencie ewolucji zredukowa� do 0.0 mutacje znacz�c�.
  double ewolucja_ukierunkowana;

  /// Ilo�� gen�w znacz�cych
  double procent_genow_znaczacych;

  /// Procent osobnik�w przeznaczony do "rozrzutu"
  /** 
      Chodzi o to �eby z wi�kszym prawdopodobie�stwem <br>
      szuka� minim�w i maksim�w globalnych. <br>
      Jest to procent osobnik�w dla kt�rych prawdopodobie�stwo <br>
      mutacji dalszej jest wi�ksze. <br>
  */
  double GrupaOsobnikowDoRozrzucenia;


  /// Zmienna okresla ile razy populacja rozwija�a si� w dobr� stron�.
  /**
     Suma wszystkich osobnik�w by�a wi�ksza od sumy poprzedniego <br>
     pokolenia.
  */
  unsigned long dobry_kierunek_rozwoju;

  /// Zmienna okre�la ile razy populacja rozwija�a si� w z�� stron�.
  /**
     Suma wszystkich osobnik�w by�a mniejsza od sumy poprzedniego <br>
     pokolenia.
  */
  unsigned long zly_kierunek_rozwoju;




  /// Zmienna m�wi ile osobnik�w z danej populacji ju� si� zmutowa�o.
  /**
     Jest to zmienna pomocnicza, kt�ra okre�la czy osobnik z danej 
     "grupy" nale�y od tak zwanej grupy rozrzutu, grupy poszukiwawczej
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
  

  /// funkcja losuje liczb� _z przedzia�u_ <0 ; 1)
  /**
     Nie trafimy nigdy na 1, ale mo�emy otrzyma� zero. <br>
     Nale�y pami�ta�, �e jest to u�amek (double)
  */
  double losuj0do1();


  /// Funkcja zwraca "poprawione" (z przesuni�ciem) wsp�rz�dne punktu.
  /** 
      Dzia�a tylko dla osobnika z populacji
      Chodzi tutaj o punkt wskazywany przez konkretnego osobnika. <br>
      Funkcja punkt() z klasy osobnik_class nie przesuwa wsp�rz�dnych... <br>
      Musi to zrobi� za ni� powy�sza funkcja z clasy zagadanienie_class. <br>
      <br>
      Funkcja pobiera numer osobnika w populacji. (Nie samego osobnika)
  */
  vector< double > punkt(int);
  
  /// Funkcja zwraca "poprawione" (z przesuni�ciem) wsp�rz�dne punktu dla dowolnego osobnika
  vector< double > punkt(osobnik_class);


  /// Funkcja odpowiedzialna jest za reprodukcj� populacji
  /**
     Reprodukcja wybiera (dzi�ki funkcji dopasowania) najlepiej przystosowe <br>
     osobniki w populacji, wylicza sum� warto�ci populacji, wybiera <br>
     najlepiej przystosowanego osobnika w populacji, dokonuje por�wna� <br>
     z najlepszym osobnikiem kiedykolwiek znalezionym, <br>
     <br>
     WA�NE: 
     <br>
     Dopiero w tym miejscu nast�puje liczenie warto�ci funkcji <br>
     w punkcie (osobniku).
  */
  void reprodukcja();
  
  
  /// Metoda mutuj�ca osobnika ze sta�ym prwadopodobie�stwem
  /**
     Nie zale�y od niczego... Prawdopodobie�stwo mutacji ustawione jest <br>
     w miennej
  */
  void mutacja_stala(osobnik_class&);



  /// Metoda mutuj�ca osobnika ze zmiennym prawdopodobie�stwem
  /**
     Zale�y od tego jaki jest post�p w ewolucji (ile generacji <br>
     przesz�o ju� zagadnienie). <br>
     Zale�y od tego kt�ry jest osobnik w pokoleniu (ze wzgl�du na to <br>
     �e pierwszy osobnik jest najlepiej przystosowany osobnik <br>
     jest zawsze na pierwszym miejscu w nowym pokoleniu <br>
     dlatego te� b�dziemy go mutowa� jak najbardziej w poszukiwaniu <br>
     innych ekstrem�w i warto�ci najwi�kszych.
  */
  void mutacja_zmienna(osobnik_class&);




  /// Krzy�owanie nr 1.
  /**
     Krzy�ujemy osobnika w taki spos�b, �e lozujemy wsp�rz�dn� <br>
     i krzy�ujemy tylko j�, a reszte z osobnika przepisujemy. <br>
   */
  void krzyzowanie_1(osobnik_class&, osobnik_class);

  /// Krzy�owanie nr 2.
  /**
     Krzy�ujemy ka�d� ze wsp�rz�dnych oddzielnie.
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


  /// Metoda pomocnicza wypisuje "warto�ci" wszystkich osobnik�w z populacji.
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
