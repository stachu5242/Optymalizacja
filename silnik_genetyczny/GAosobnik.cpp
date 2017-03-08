/***************************************************************/
/* Autorzy:             Rados³aw Szwarc                        */
/*                      Krzysztof Ginter                       */
/***************************************************************/

#include <vector>
#include <iostream>
#include "GAosobnik.h"
using std::vector;
using std::cerr;
using std::endl;








/// Funkcja zwraca warto¶æ funkcji w punkcie wskazywanym przez osobnika.
double osobnik_class::wartosc()
{
  return wartosc_d;
}



/// Funkcja ustawia warto¶æ funkcji dla danego osobnika.
/**
   Warto¶æ jest wyliczna na podstawie zewnêtrznej funcji 
*/
void osobnik_class::wartosc(double d)
{
  wartosc_d = d;
}


/// Funkcja zwraca warto¶æ funkcji w punkcie (powiêkszon±) wskazywanym przez osobnika.
double osobnik_class::wartosc_plus()
{
  return wartosc_plus_d;
}



/// Funkcja ustawia warto¶æ funkcji (powiêkszon±) dla danego osobnika.
/**
   Warto¶æ jest wyliczna na podstawie zewnêtrznej funcji 
*/
void osobnik_class::wartosc_plus(double d)
{
  wartosc_plus_d = d;
}


/// Funkcja dodaje liczbê do wektora skoku. 
/** 
    Wykonuje po prostu push_back.
*/
void osobnik_class::skok(double d)
{
  skok_v.push_back(d);
}




/// Funkcja zwraca warto¶æ skoku dla i'tej zmiennej.
/**
   Zwyk³y return skok[int].
*/
double osobnik_class::skok(unsigned int i)
{
  if (i >= skok_v.size())
    {
      cerr << "Wyszed³es poza ilo¶æ elementów w skok_v. " << endl;
      cerr << "Bronie siê przed Segmentation faultem. exit(1)" << endl;
      exit(1);
    }
  else
    {
      return skok_v[i];
    }
}



/// Metoda dodaje chromosom do osobnika.
void osobnik_class::osobnik(vector<bool> v)
{
  osobnik_vv.push_back(v);
}

/// Metoda pomocnicza wypisuje wartosci osobnika (jego zmienne)
void osobnik_class::wypisz_wartosci()
{
  if (roznica_d > 1.0)
    {
      cerr << "war:\t" << wartosc_d << "    \twar+:\t" << wartosc_plus_d;
      cerr << "\troz:\t" << roznica_d << endl;
    }
  else
    {
      cerr << "war:\t" << wartosc_d << "    \twar+:\t" << wartosc_plus_d;
      cerr << "\troz:\t\t" << roznica_d << endl;
    }
}

/// Metoda pomocnicza wypisuje osobnika
void osobnik_class::wypisz_osobnika()
{
  cerr << "Wypisywanie osobnika!" << endl;
  for (unsigned int i = 0; i < osobnik_vv.size(); i++)
    {
      cerr << "i = " << i << ") ";
      for (unsigned int j = 0; j < osobnik_vv[i].size(); j++)
	{
	  cerr << osobnik_vv[i][j];
	}

      long wartosc = 0;
      long z = 0; // zmienna pomocnicza (Pokazuje która to potêga)
      for (int j = osobnik_vv[i].size()-1; j >-1; j--)
	{
	  switch(osobnik_vv[i][j])
	    {
	    case 0 :
	      {
		z++;
	      }break;
	    case 1 :
	      {
		wartosc += (long)pow(2,z);
		z++;
	      }break;
	    }
	
	}
      cerr << " = " << wartosc << " = " << wartosc * skok(i);
      cerr << endl;
    }
  cerr << "Warto¶æ: " << wartosc_d << endl;
}





/// Zwraca liczbê genów w chromosomie.
unsigned int osobnik_class::rozmiar(unsigned int i)
{
  if (i >= osobnik_vv.size())
    {
      cerr << "i = " << i << " " << osobnik_vv.size();
      cerr << "Starasz odwo³aæ siê do zmiennej która nie ma tylu elementów" << endl;
      cerr << "chodzi o zmienn± osobnik_vv" << endl;
      cerr << "Bronie siê przed Segmentation Faultem. exit(1)" << endl;
      exit(1);
    }
  else
    {
      return osobnik_vv[i].size();
    }
}


/// Funkcja zmienia zadany gen 

void osobnik_class::zmien_gen(unsigned int i ,unsigned int j, bool g)
{
  if (i >= osobnik_vv.size())
  {
    cerr << "Odwo³anie do za du¿ego elementu w osobnik_vv." << endl;
    cerr << "Nie mamy funkcji o takiej ilo¶ci wymiarów." << endl;
    cerr << "Bronie siê przed Segmentation faultem - exit(1)." << endl;
    exit(1);
  }
  if (j >= osobnik_vv[i].size())
  {
    cerr << "Odwo³anie do za du¿ego elementu w osobnik_vv." << endl;
    cerr << "Osobnik nie ma tylu genów na zmiennej." << endl;
    cerr << "Bronie siê przed Segmentation faultem - exit(1)." << endl;
    exit(1);
  }
  osobnik_vv[i][j] = g;
}



/// zwraca wspó³rzedne punktu danego osobnika (!!! Bez przesuniêcia !!!)
/**
   Bardzo wa¿ne: zwraca warto¶ci które zagadnienie musi przesun±æ
*/
vector < double > osobnik_class::punkt()
{
  vector< double > lokalizacja;
  long wartosc = 0;
  int z = 0;
  // zamieniam ci±gi binarne na liczby ca³kowite
  for (unsigned int i = 0; i < osobnik_vv.size(); i++)
    {
      wartosc = 0;
      z = 0; // zmienna pomocnicza (Pokazuje która to potêga)
      for (int j = osobnik_vv[i].size()-1; j >-1; j--)
	{
	  switch(osobnik_vv[i][j])
	    {
	    case 0 :
	      {
		z++;
	      }break;
	    case 1 :
	      {
		wartosc += (long)pow(2,z);
		z++;
	      }break;
	    }
	
	}
      // lokalizacja to warto¶æ osobnika np. (0011) * skok

      lokalizacja.push_back(wartosc * skok_v[i]);
    }
  return lokalizacja;
}






/// Zwraca ilo¶æ wymiarów danego osobnika.
unsigned int osobnik_class::ile_wymiarow()
{
  return osobnik_vv.size();
}




/// Metoda zwraca konkretny chromosom.
vector <bool> osobnik_class::zwroc_chromosom(unsigned int& i)
{
  if (i >= osobnik_vv.size())
    {
      cerr << "Osobnik nie ma tylu wymiarów... odwo³ujesz siê do zbyt du¿ego wymiaru." << endl;
      cerr << "Bronie siê przed Segmentation Faultem. exit(1)" << endl;
      exit(1);
    }
  else 
    {
      return osobnik_vv[i];
    }
}


void osobnik_class::roznica(double d)
{
  roznica_d = d;
}

double osobnik_class::roznica()
{
  return roznica_d;
}


bool osobnik_class::gen(unsigned int i, unsigned int j)
{
    return osobnik_vv[i][j];
}
