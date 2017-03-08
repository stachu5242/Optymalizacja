#ifndef slice_h
#define slice_h
#include<valarray>


///Klsa iteratora dla macierzy
template< class T> class Slice_iter{
  std::valarray<T>* v;
  std::slice s;
  size_t curr;   //indeks bierzacego elementu
  T& ref(size_t i) const;

 public:
    ///	konstruktor domyslny
  Slice_iter(std::valarray<T>* vv,std::slice ss);// : v(vv), s(ss), curr(0){}
  ///koniec macierzy
  Slice_iter end();
    ///przesun pole o 1
  Slice_iter& operator++();
  ///	przesun pole o kilka
  Slice_iter operator++(int);
    ///indeksy
  T& operator[] (size_t i);
    ///indeksy
  T& operator() (size_t i);
    ///wskazanie	
  T& operator*();
  
};
///klsasa stalego iteratora dla macierzy
template< class T> class Cslice_iter{
  std::valarray<T>* v;
  std::slice s;
  size_t curr;   //indeks bierzacego elementu
  T& ref(size_t i) const;
  
 public:
  Cslice_iter(std::valarray<T>* vv,std::slice ss);// : v(vv), s(ss), curr(0){}
  size_t size();
  Cslice_iter end();
  Cslice_iter& operator++();
  Cslice_iter operator++(int);
  T& operator[] (size_t i);
  T& operator() (size_t i);
  T& operator*();

};
///operator rownosci
template<class T> 
bool operator== (const Slice_iter<T>& p, const Slice_iter<T>& q);
///operator nie rownosci
template<class T>
bool operator!= (const Slice_iter<T>& p, const Slice_iter<T>& q);
///operator mniejszosci
template<class T>
bool operator< (const Slice_iter<T>& p, const Slice_iter<T>& q);

#endif
