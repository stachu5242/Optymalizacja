/***************************************************************/
/* Autorzy:             Rados³aw Szwarc                        */
/*                      Krzysztof Ginter                       */
/***************************************************************/

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include "GAosobnik.h" 
#include "GAzakres.h"
#include "GAzagadnienie.h"
#include "macierz.h"
#include "powell.h"
#include "funkcja.h"
#include "dziedzina.h"
#include "globals.h"

using namespace std;

using std::vector;

/// Konstruktor klasy.
/** 
    Jako parametr przyjmuje nazwê pliku z danymi. Je¶li nazwa <br> 
    nie zosta³a podana obiera domyslnie "INPUT" 
*/
zagadnienie_class::zagadnienie_class(string str)
{
  ifstream plik;
  plik.open(str.c_str());
  if (plik == NULL) // blad - pliku nie znaleziono.
    {
      cerr << "Podany przez Ciebie plik nie istnieje." << endl;
      cerr << "Nie istnieje tak¿e odmy¶lny plik INPUT." << endl;
      exit(1);
    }
  else // rozpoczynamy wczytywanie pliku 
    {
      stringstream ss;
      char znak;
      while( plik.get(znak))
	{
	  if (znak == '#') // trafilismy na komentarz w pliku
	    {
	      while (znak != '\n' || plik.eof())
		{
		  plik.get(znak);
		}
	    } // koniec if znak == '#'
	  
	  else // nie trafilismy na znak komentarza...
	    {
	      ss << znak; // i dopisujemy znaczek do string stream'a
	    }
	} // koniec while (plik.get(znak))
      plik.close(); // zamykam plik z danymi
      // wszystkie informacje z pliku z wycieciem komentarzy znajduja sie juz w string streamie...
      // przystepuje do wczytania danych pod odpowiednie zmienne
      if (!ss.fail())
	{
	  ss >> ilosc_zmiennych;
	}
      else 
	{
	  cerr << "Co¶ jest nie tak z danymi... (ilo¶æ zmiennych)." << endl;
	  exit(1);
	}
      if (!ss.fail())
	{
	  ss >> maksimum;
	}
      else 
	{
	  cerr << "Co¶ jest nie tak z danymi... (ilo¶æ zmiennych)." << endl;
	  exit(1);
	}
      if (!ss.fail())
	{
	  for (unsigned int i=0; i < ilosc_zmiennych; i++)
	    {
	      zakres_class z;
	      if (!ss.fail())
		{
		  ss >> z.a >> z.b;
		  if (z.a > z.b) // Je¶li u¿ytkownik podal przedzialy w pliku na odwrot to zamieniamy
		    {
		      double temp;
		      temp = z.a;
		      z.a = z.b;
		      z.b = temp;
		    }
		  zakres.push_back(z);
		}
	      else
		{
		  cerr << "Co¶ jest nie tak z danymi... (ograniczenia)." << endl;
		  exit(1);
		}
	    }
	}
      else 
	{
	  cerr << "Co¶ jest nie tak z danymi... (maksimum)." << endl;
	  exit(1);
	}
      
      if (!ss.fail())
	{
	  ss >> wielkosc_populacji;
	}
      else 
	{
	  cerr << "Co¶ jest nie tak z danymi... (ograniczenia)." << endl;
	  exit(1);
	}  
      if (!ss.fail())
	{
	  ss >> ilosc_pokolen;
	}
      else 
	{
	  cerr << "Co¶ jest nie tak z danymi... (wielko¶æ populacji)." << endl;
	  exit(1);
	} 
      if (!ss.fail())
	{
	  ss >> dokladnosc;
	}
      else 
	{
	  cerr << "Co¶ jest nie tak z danymi... (ilo¶æ pokolen)." << endl;
	  exit(1);
	}
      if (!ss.fail())
	{
	  ss >> mut_stala;
	}
      else
	{
	  cerr << "Co¶ jest nie tak z danymi... (dok³adno¶æ)." << endl;
	  exit(1);
	}
      if (!ss.fail())
	{
	  ss >> czy_krzyzowac;
	}
      else
	{
	  cerr << "Co¶ jest nie tak z danymi... (okreslanie mutacji)." << endl;
	  exit(1);
	}
      if (!ss.fail())
	{
	  ss >> stosuj_powella;
	}
      else
	{
	  cerr << "Co¶ jest nie tak z danymi... (okre¶lanie czy krzy¿owaæ)." << endl;
	  exit(1);
	}
      if (!ss.fail())
	{
	  ss >> wypisuj_postep;
	}
      else
	{
	  cerr << "Co¶ jest nie tak z danymi... (stosowanie Powella)." << endl;
	  exit(1);
	}
      




      if (ss.fail())
	{
	  cerr << "jaki¶ b³±d w danych wejsciowych." << endl;
	  cerr << "Najprawdopodobniej za ma³o danych wej¶ciowych w pliku." << endl;
	  exit(1);
	}

      if (dokladnosc == 0.0)
	{
	  cerr << "Co¶ jest nie tak z danymi... (dok³adno¶æ)." << endl;
	  cerr << "Nie powinno byæ zero!" << endl;
	  exit(1);
	}
      // DANE zosta³y wczytane pod odpowiednie zmienne
    }// koniec else (wszytywanie danych z pliku

  

  // Uruchamiam generator liczb losowych
  srand(time(NULL));

  /********************************************************************************************/
  /***************      Okre¶lenie rozmiaru pojedyñczego osobnika                **************/
  /********************************************************************************************/

  for (unsigned int i = 0; i < ilosc_zmiennych; i++) // dla kazdego wymiaru liczymy inaczej
    {
      vector< bool > v_bool; // pomocnicza zmienna
      double przedzial; // zmienna pomocnicza
      przedzial = zakres[i].b - zakres[i].a; // koncowy - poczatkowy
      double ilosc; // zmienna pomocnicza
      ilosc = przedzial / dokladnosc;
      double ile = 1.0; // dwa do potegi x
      long x = 0;// potega liczby 2
      
      while(ile < ilosc) // dopuki nie otrzymamy lepszego przyblizenia niz chcemy
	{      // szukamy coraz to wiekszej potegi liczby 2
	  x++;
	  ile = ile * 2;
	} // po wyjsciu z petli x jest nasza szukana wielkoscia chromosomu... (dla jednej zmiennej) 
      // x to teraz ilosc zer i jedynek np dla 0001110101 x = 10

      najlepszy_osobnik.skok( przedzial / ile ); // obliczylismy skok naszego osobnika 
      v_bool.resize(x);// zmieniamy wielkosc pomocniczego wektora na wyliczona

      najlepszy_osobnik.osobnik(v_bool); // wstawiamy do osobnika chromosom
    }
 
  // oddaje osobniki do populacji i nowa_populacji (by nie musiec bawic sie z pozniejszym jej ustawianiem
  for (unsigned int i = 0; i < wielkosc_populacji; i++)
    {
      //dodaj_do_populacji(najlepszy_osobnik);
      populacja.push_back(najlepszy_osobnik);
      nowa_populacja.push_back(najlepszy_osobnik);
      
    }
  /********************************************************************************************/
  /***************      LOSOWANIE POCZ¡TKOWYCH OSOBNIKÓW                         **************/
  /********************************************************************************************/

  for (unsigned int i = 0; i < wielkosc_populacji;i++)
    {
      for (unsigned int j=0; j < ilosc_zmiennych; j++)
	{
	  for (unsigned int k =0; k < populacja[i].rozmiar(j); k++)
	    {
	      populacja[i].zmien_gen(j,k,losuj01());
	    }
	}
    }
  


  // Obliczam pierwsz± warto¶æ funkcji w punkcie (osobniku) i ustawiam j± na maksymaln±
  if (maksimum)
    {
      max = funkcja( punkt(0) );
    }
  else
    {
      max = - funkcja( punkt(0) );
    }


  /***************************************************/
  /*****        Ustawienia   pocz±tkowe klasy    *****/
  /***************************************************/
  dobry_kierunek_rozwoju = 0;

  zly_kierunek_rozwoju = 0;
  
  ile_zmutowalem = 0;

  /***********************************************/
  /******      USTAWIENIA DLA MUTACJI      *******/
  /***********************************************/

  // Warto¶ci te muszê do¶wiadczalnie zmierzyæ i zobaczyæ jak siê bêdzie najkorzystniej 

  // prawdopodobieñstwo mutacji zmiennej genów znacz±cych 1 grupy osobników (do rozrzucenia)
  p_mutacji_zmiennej_z_1 = 0.30; // powinno byæ dosyæ du¿e jak na pocz±tku.
  
  // prawdopodobieñstwo mutacji zmiennej genów znacz±cych 2 grupy osobników
  p_mutacji_zmiennej_z_2 = 0.07; // powinno byæ du¿o mniejsze od ..._z_1

  // prawdopodobieñstwo mutacji zmiennej genów nie znacz±cych 1 grupy osobników (do rozrzucenia)
  p_mutacji_zmiennej_nie_z_1 = 0.05;  // "standardowe" prawdopodobieñstwo
  
  //prawdopodobieñstwo mutacji zmiennej genów nie znacz±cych 2 grupy osobników
  p_mutacji_zmiennej_nie_z_2 = 0.07;  // "standardowe" prawdopodobieñstwo
  
  // Ewolucja ukierunkowana nast±pi po: 
  ewolucja_ukierunkowana = 0.95; // 95 % postêpu ... i zaczynamy siê ukierunkowywaæ.
                                 // zmienia siê prawdopodobienstwo mutacji znaczacej ->bardzo maleje
  
  procent_genow_znaczacych = 0.60; // procent genów znacz±cych.
    

  GrupaOsobnikowDoRozrzucenia = 0.50; // procent pierwszej grupy.
  

  // prawdopodobieñstwo mutacji sta³ej
  p_mutacji_stalej = 0.05;
  
} // KONIEC KONSTRUKTORA






/// metoda klasy losujaca 0 lub 1
bool zagadnienie_class::losuj01()
{
  int z;
  z = rand() %2;
  if (z == 0)
    {
      return 0;
    }
  else 
    {
      return 1;
    }
}


/// metoda klasy losuj±ca liczbê z przedzia³u od <0 ; 1)
double zagadnienie_class::losuj0do1()
{
  double d;
  
  d = double(rand() / (RAND_MAX + 1.0)); // dodajemy jeden by nie by³o liczby 1... bylko 1)
  return d;
} 







/// Funkcja zwraca "poprawione" (z przesuniêciem) wspó³rzêdne punktu dla osobnika z pokolenia
vector< double > zagadnienie_class::punkt(int i)
{
  vector< double > lokalizacja;
  // przyjmuje wartosci jakie zwracaja osobniki nie przesuniête.
  lokalizacja = populacja[i].punkt();
  for (unsigned int i =0; i < ilosc_zmiennych; i++)
    {
      // przesuwam je o przedzia³
      lokalizacja[i] += zakres[i].a;
    }
  return lokalizacja;
}



/// Funkcja zwraca "poprawione" (z przesuniêciem) wspó³rzêdne punktu dla dowolnego osobnika
vector< double > zagadnienie_class::punkt(osobnik_class i)
{
  vector< double > lokalizacja;
  // przyjmuje wartosci jakie zwracaja osobniki nie przesuniête.
  lokalizacja = i.punkt();
  for (unsigned int i =0; i < ilosc_zmiennych; i++)
    {
      // przesuwam je o przedzia³
      lokalizacja[i] += zakres[i].a;
    }
  return lokalizacja;
}








void zagadnienie_class::reprodukcja()
{
  // Obliczam warto¶æ funkcji w punkcie (osobniku) dla wszystkich osobniów z populacji
  // i od razu sumujê je, oraz szukam najmniejszej warto¶ci ujemnej

  // mo¿emy zaczynaæ od zera, bo je¶li nie znajdziemy ujemnych to nie bêdziemy musieli przeskalowywaæ
  min = 0.0;
  suma = 0.0; // zerujemy sume
  for (unsigned int i = 0; i < populacja.size(); i++)
  {
    // Jesli dany osobnik nie nalezy do dziedziny funkcji to losuje na jego
    //miejsce innego osobnika... 
    while ( !dziedzina( punkt(i) ) )
      {
	for (unsigned int i = 0; i < wielkosc_populacji;i++)
	  {
	    for (unsigned int j=0; j < ilosc_zmiennych; j++)
	      {
		for (unsigned int k =0; k < populacja[i].rozmiar(j); k++)
		  {
		    populacja[i].zmien_gen(j,k,losuj01());
		  }
	      }
	  }
      } // po wyj¶ciu z pêtli while wylosowany zosta³ nowy osobnik

    populacja[i].wartosc(funkcja(punkt(i)));
    
      // je¿eli szukami minium musimy odwróciæ znak warto¶ci funkcji jak± policzyli¶my (warto¶æ)
      if (!maksimum)
	{
	  populacja[i].wartosc( - populacja[i].wartosc() );
	}


      suma += populacja[i].wartosc(); // do sumy dodajemy warto¶æ osobnika
      
      // sprawdzam czy warto¶æ otrzymana jest mniejsza ni¿ nasze minimum
      if (min > populacja[i].wartosc())
	{
	  min = populacja[i].wartosc();
	}
     
      if (max < populacja[i].wartosc())
	{
	  // licze powella dla najlepszego znalezionego punktu
	  // jako ze procedura jest bardzo szybka..:)

	  najlepszy_osobnik = populacja[i];
	  max = najlepszy_osobnik.wartosc();
	}
    }
  
  
  if ( min < 0.0)
    {
      for (unsigned int i =0; i < populacja.size(); i++)
	{
	  populacja[i].wartosc_plus(populacja[i].wartosc() - min + 1.0);
	}
      suma_plus = suma + (populacja.size() * ( - min + 1.0));
    }
  else
    {
      suma_plus = suma;
    }


  // Ustawiam roznice pomiedzy osobnikami.
  // populacja.size() -2 bo ostatniego osobnika ustawiam dokladnie na 1.0
  populacja[0].roznica(populacja[0].wartosc_plus() / suma_plus);
  najlepszy_osobnik.roznica( najlepszy_osobnik.wartosc_plus() / suma_plus );
  for (unsigned int i = 1; i < populacja.size() -1; i++)
    {
      populacja[i].roznica(populacja[i-1].roznica() + populacja[i].wartosc_plus() / suma_plus );
    }
  populacja[populacja.size()-1].roznica(1.0);


  // Wstawiam najlepszego znanego osobnika do nowej populacji.
  // Tak aby by³ w grupie rozrzutu i grupie zbie¿nej...
  nowa_populacja[0] = najlepszy_osobnik;
  nowa_populacja[1] = najlepszy_osobnik;
  nowa_populacja[nowa_populacja.size()-1] = najlepszy_osobnik;
  nowa_populacja[nowa_populacja.size()-2] = najlepszy_osobnik;
  
  for (unsigned int i = 1; i < populacja.size()-1; i++)
    {
      // liczba wylosowana ktora poslozy do wybierania osobnika
      double wylosowana;
      wylosowana = losuj0do1();
      int j;
      j = 0;
      while (populacja[j].roznica() < wylosowana)
	{
	  j++;
	} // Po wyjsciu z tej petli natrafilem na odpowiedniego osobnika.
      // wylosowana jest < 1.0 natomiast ostatni osobnik populacji ma roznice 
      // ustawiona na 1.0 wiec jest gwarancja poprawnosci.
      
      nowa_populacja[i] = populacja[j];
    }

  populacja.swap(nowa_populacja);



  // Sprawdzam czy populacja ewoluuje w dobrym kierunku.

  // potrzebuje tej zmiennej zeby okreslic czy populacja zmieza w dobrym kierunku
  static bool second_time = false;
  // jesli jeszcze nie przechodzilismy przez 
  if (second_time)
    {
      if (suma < suma_poprzednia)
	zly_kierunek_rozwoju++;
      else
	dobry_kierunek_rozwoju++;
    }

  if (!second_time)
    {
      suma_poprzednia = suma;
      second_time = true;
    }
  
} // KONIEC REPRODUKCJI









/// Mutacja sta³a osobnika.
void zagadnienie_class::mutacja_stala(osobnik_class& o)
{
  // Jak narazie jest to zwykla mutacja losowa (nie ma znaczenia ktory bit)
  for (unsigned int i = 0; i < ilosc_zmiennych; i++)
    {
      for (unsigned int j = 0; j < o.rozmiar(i); j++)
        {
	  // losujemy prawdopodobienstwo mutacji... jesli jest mniejsze to zmieniamy bit na przeciwny.
          if (losuj0do1() < p_mutacji_stalej)
            {
              o.zmien_gen(i,j,1-o.gen(i,j));
            }
        }
    }
}

/// Mutacja zmienna osobnika.
void zagadnienie_class::mutacja_zmienna(osobnik_class& osob)
{
  
  // zmienna mówi o tym ile osobnikóz z danej populacji ju¿ siê zmutowa³o.
  // Potrzebujê tej zmiennej do okre¶lenia czy osobnik nale¿y do grupy rozrzutu czy te¿ nie.
  double prawd_z;
  double prawd_nz;
  // Sprawdzam czy osobnik nalezy do grupy rozrzutu czy nie...
  if ( double(ile_zmutowalem) / double(wielkosc_populacji) > GrupaOsobnikowDoRozrzucenia)
    {
      prawd_z = p_mutacji_zmiennej_z_2;
      prawd_nz = p_mutacji_zmiennej_nie_z_2;
    }
  else
    {
      prawd_z = p_mutacji_zmiennej_z_1;
      prawd_nz = p_mutacji_zmiennej_nie_z_1;
    }
  for (unsigned int i = 0; i < ilosc_zmiennych; i++)
    {
      for (unsigned int j = 0; j < osob.rozmiar(i); j++)
        {


	  // mamy do czynienia z genami nie znaczacymi.
	  if ( double(j) / double(osob.rozmiar(i)) > procent_genow_znaczacych)
	    {
	      // losujemy prawdopodobienstwo mutacji... jesli jest mniejsze to zmieniamy bit na przeciwny.
	      if (losuj0do1() < prawd_nz)
		{
		  osob.zmien_gen(i,j,1-osob.gen(i,j));
		}
	    }
	  else  // mamy do czynienia z genami znaczacymi.
	    {
	      // losujemy prawdopodobienstwo mutacji... jesli jest mniejsze to zmieniamy bit na przeciwny.
	      if (losuj0do1() < prawd_z)
		{
		  osob.zmien_gen(i,j,1-osob.gen(i,j));
		}
	    }

        }
    }
  ile_zmutowalem++;

  // zmienna ile_przeszlo jest statyczna... dlatego te¿ musimy j± w odpowiednim momencie wyzerowaæ.
  if (ile_zmutowalem == wielkosc_populacji)
    {
      ile_zmutowalem = 0;
    }
}



/// Krzy¿owanie numer 1.
void zagadnienie_class::krzyzowanie_1(osobnik_class& osobnik1, osobnik_class osobnik2)
{
  unsigned int wylosowana;

  // na ktorej zmiennej mam krzyzowaæ...
  wylosowana = rand() % ilosc_zmiennych;

  // zmienne przed zmienn± któr± bêdê krzy¿owaæ zostawiam w spokoju...

  //ale resztê przepisujê z osobnika2
  for (unsigned int i = wylosowana+1; i < ilosc_zmiennych; i++)
    {
      for (unsigned int j = 0;j < osobnik1.rozmiar(i); j++)
	{
	  osobnik1.zmien_gen(i,j,osobnik2.gen(i,j));
	}
    }
  
  // muszê jeszcze ustaliæ w którym miejscu nastêpuje krzy¿owanie na danej zmiennej
  unsigned int gdzie;
  gdzie = rand() % osobnik1.rozmiar(wylosowana);
  for (unsigned int i = gdzie; i < osobnik1.rozmiar(wylosowana);i++)
    {
      osobnik1.zmien_gen(wylosowana,i,osobnik2.gen(wylosowana,i));
    }
  // tutaj ju¿ jestem po krzy¿owaniu osobników...
}




/// Krzy¿owanie numer 2.
void zagadnienie_class::krzyzowanie_2(osobnik_class& osobnik1, osobnik_class& osobnik2)
{
  for (unsigned int i = 0; i < ilosc_zmiennych; i++)
    {
      unsigned int gdzie;
      gdzie = rand() % osobnik1.rozmiar(i);
      for (unsigned int j = gdzie; j < osobnik1.rozmiar(i);j++)
	{
	  osobnik1.zmien_gen(i,j,osobnik2.gen(i,j));
	}
    }
}



void zagadnienie_class::ewolucja()
{

  // zwieksz sie w raz z postepem czasowym... dochodzi do ilosci_pokolen
  unsigned int ilosc = 0;

  // zmienna okresja jaki procent zostal juz wykonany
  double procent = 0.01;
  cerr << "Zaczynam liczenie!!!" << endl;
  
  while (ilosc < ilosc_pokolen)
    {
      if ( (double(ilosc) / double(ilosc_pokolen)) >= procent)
	{
	  if (procent == 0.01)
	    {
	      cerr << "Postêp   Najlepsza warto¶æ    z³y kier. rozwoju    dobry kier. rozwoju" << endl;
	    }
	  procent = (double(ilosc) / double(ilosc_pokolen)) + 0.01;



	  if(procent > ewolucja_ukierunkowana)
	    {
	      p_mutacji_zmiennej_z_1 = 0.03;
	      p_mutacji_zmiennej_z_2 = 0.03;
	      GrupaOsobnikowDoRozrzucenia = 0.0;
	    }
	  
	  
	  
	  // Wypisuje postêp w liczeniu...
	  if (wypisuj_postep)
	    {
	      cerr.width(5);
	      cerr << right <<  int((double(ilosc) / double(ilosc_pokolen)) * 100) << "%";
	      cerr << "   ";
	      cerr.width(13);
	      cerr.precision(8);
	      if (maksimum)
		cerr << fixed << najlepszy_osobnik.wartosc();
	      else
		cerr << fixed << - najlepszy_osobnik.wartosc();
	      cerr << "               -: " << zly_kierunek_rozwoju << "                +: " << dobry_kierunek_rozwoju << endl;
	    }
	}
      reprodukcja();



      // pêtla dla krzy¿owania... je¶li u¿ytkownik chce krzy¿owaæ
      if (czy_krzyzowac)
	{
	  for (unsigned int i = 0; i < wielkosc_populacji; i++)
	    {
	      if (losuj01()) // je¶li tak to:
		{
		  unsigned int wylosowana = rand() % wielkosc_populacji;
		  krzyzowanie_1(populacja[i], populacja[wylosowana]);
		}
	      else
		{
		  unsigned int wylosowana = rand() % wielkosc_populacji;
		  krzyzowanie_2(populacja[i], populacja[wylosowana]);
		}
	    }
	}

      // pêtla dla mutacji... zawsze mutujemy (bo inaczej nie by³o by sensu szukanie
      for (unsigned int i = 0; i < wielkosc_populacji; i++)
	{
	  // sprawdzam co podal uzytkownik
	  if(mut_stala)
	    mutacja_stala(populacja[i]); // sta³a mutacja
	  else
	    mutacja_zmienna(populacja[i]); // zmienna mutacja
	}

      
      ilosc++;
    }
  
  

  
  // wypisuje wspó³rzêdnej najlepiej przystosowanego osobnika (maksimum)lub(minimum)
  cerr << endl;
  cerr << "*************************************************" << endl;
  cerr << "***     Najlepsze znalezione rozwi±zanie:     ***" << endl;
  cerr << "*************************************************" << endl;
  vector< double > wspolrzedne_maksimum = punkt(najlepszy_osobnik);
  cerr << endl <<  "************************" << endl;
  cerr <<          "*  Metod± Genetyczn±:  *"  << endl;
  cerr <<          "************************" << endl;
  for (unsigned int i = 0; i < wspolrzedne_maksimum.size(); i++)
    {
      cerr << "X" << i << "\t: " << fixed << wspolrzedne_maksimum[i] << endl;
    }
  cerr << "Warto¶æ: " << najlepszy_osobnik.wartosc() << endl << endl;
  

  // sprawdzam czy u¿ytkownik chcia³ stosowaæ metodê powella do okre¶lenia
  // lepszego wyniku
  if(stosuj_powella)
    {
      double wyliczona_wartosc;
      matrix A;
      // je¶li szukamy maksimum musimy funkcji powell podaæ przygotowan± funkcjê
      if (maksimum)
	powell(wspolrzedne_maksimum,A,wyliczona_wartosc,dokladnosc*0.00001,&maksimum_powell);
      else
	powell(wspolrzedne_maksimum,A,wyliczona_wartosc,dokladnosc*0.00001,&funkcja);
      //populacja[i].wartosc(wyliczona_wartosc);
      cerr << endl;
      cerr <<   "***********************" << endl;
      cerr <<   "*  Metod± Powella:    *" << endl;
      cerr <<   "***********************" << endl;
      
      for (unsigned int i = 0; i < wspolrzedne_maksimum.size(); i++)
	{
	  cerr << "X" << i << "\t: " << fixed << wspolrzedne_maksimum[i] << endl;
	}
      
      cerr << "Warto¶æ : " << wyliczona_wartosc << endl;
    }
    
}




/****************************************************************************/
/****************************************************************************/
/****************************************************************************/
/****************************************************************************/
/*                                                                          */
/*                                                                          */
/*                            METODY POMOCNICZE                             */
/*                                                                          */
/*                                                                          */
/****************************************************************************/
/****************************************************************************/
/****************************************************************************/
/****************************************************************************/





/// Metoda pomocnicza wypisuje "warto¶ci" wszystkich osobników z populacji.
void zagadnienie_class::wypisz_osobnikow()
{
  for (unsigned int i = 0; i < populacja.size(); i++)
    {
      vector <double > pomoc;
      pomoc = populacja[i].punkt();
      populacja[i].wypisz_osobnika();
      
      for (unsigned int j = 0; j < pomoc.size(); j++)
	{
	  cerr << i << ") " << j << ") " << pomoc[j]+zakres[j].a << endl;
	}
    }

  cerr << endl << endl;
  cerr << "NAJELPRZY OSOBNIK to: " << endl;
  najlepszy_osobnik.wypisz_osobnika();
}




void zagadnienie_class::wypisz_wartosci_osobnikow()
{
  double suma_ = 0;
  cerr << "Wartosci osobnikow populacji populacji." << endl;
  for (unsigned int i =0 ; i < populacja.size() ; i++)
    {
      populacja[i].wypisz_wartosci();
      suma_ += populacja[i].wartosc();
    }
  cerr << "Suma populacji: " << suma_ << endl;
}

void zagadnienie_class::wypisz_wartosci_osobnikow_new()
{
  cerr << "Wartosci osobnikow nowej populacji." << endl;
  for (unsigned int i =0 ; i < populacja.size() ; i++)
    {
      nowa_populacja[i].wypisz_wartosci();
    }
}










// Metoda pomocnicza wypisujaca zmienne....
void zagadnienie_class::wypisz_zmienne(int a)
{
  cerr << "dokladnosc:         " << dokladnosc << endl;
  

  cerr << "maksimum:           " << maksimum << endl;
  

  cerr << "ilosc_zmiennych:    " << ilosc_zmiennych << endl;

  cerr << "ilosc_pokolen:      " << ilosc_pokolen << endl;

  cerr << "wielkosc_populacji: " << wielkosc_populacji << endl;

  cerr << "populacja.size():   " << populacja.size() << endl;
  
  cerr << "zakres.size():      " << zakres.size() << endl;
  
  if (a == 1)
    {
      for (unsigned int i = 0; i < zakres.size(); i++)
	{
	  cerr << "\t zakres[" << i << "]: " << zakres[i].a << "     " << zakres[i].b << endl;
	}
    }
  
  if (a == 1)
    {
      for (unsigned int i = 0; (i < populacja.size()) && (i < 10); i++)
	{
	  for (unsigned int j = 0; j < 3; j++)
	    {
	      cerr << "\t populacja[" << i << "]: " << populacja[i].skok(j) << endl;
	    }
	}
    }
}





