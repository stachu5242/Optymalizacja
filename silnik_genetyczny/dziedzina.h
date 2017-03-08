/***************************************************************/
/* Autorzy:             Rados³aw Szwarc                        */
/*                      Krzysztof Ginter                       */
/***************************************************************/

#ifndef DZIEDZINA_H
#define DZIEDZINA_H
#include <vector>

using std::vector;
/// Funkcja która mówi czy punkt (osobnik nalezy do dziedziny).
/**
   Funkcja zwraca true jest osobnik nalezy do dziedziny funkcji <br>
   oraz false gdy jest inaczej. <br>
   Za dziedzine odpowiedzialny jest uzytkownik... aby program dzialal poprawnie <br>
   nie mozemy zwracac zawsze false, nalezy bronic sie przed "return false". <br>
   Jesli osobnik nie nalezy do dziedziny funkcji to na jego miejsce losowany <br> 
   jest nastepny osobnik i tak do skutku az natrafimy na osobnika nalezacego do <br>
   dziedziny.
*/
bool dziedzina(vector<double>);

#endif //DZIEDZINA_H 
