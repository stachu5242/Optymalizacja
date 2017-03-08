#include"slice.h"

template< class T>
inline T& Slice_iter< T>::ref(size_t i) const 
{ 
  return(*v)[s.start()+i*s.stride()];
}

template<class T> 
Slice_iter<T>::Slice_iter(std::valarray<T>* vv,std::slice ss) : v(vv), s(ss), curr(0){}

template<class T>
inline Slice_iter<T> Slice_iter<T>::end()
{
  Slice_iter t=*this;
  t.curr = s.size();
  return t;
}

template< class T>
inline Slice_iter<T>& Slice_iter<T>::operator++()
{
  curr++;
  return *this;
}
template<class T> 
inline Slice_iter<T> Slice_iter<T>::operator++(int) 
{
  Slice_iter t= *this; 
  curr++; 
  return t;
}
template<class T>
inline T& Slice_iter<T>::operator[] (size_t i) 
{
  return ref(curr=i);
}
template<class T>
inline T& Slice_iter<T>::operator() (size_t i) 
{
  return ref(curr=i);
}
template<class T> 
inline T& Slice_iter<T>::operator*() 
{
  return ref(curr=i);
}


template<class T> 
inline T& Cslice_iter<T>::ref(size_t i) const 
{
  return(*v)[s.start()+i*s.stride()];
}

template<class T>
inline Cslice_iter<T>::Cslice_iter(std::valarray<T>* vv,std::slice ss) : v(vv), s(ss), curr(0){}
template<class T>
size_t Cslice_iter<T>::size()
{
  return s.size();
}
template<class T>
inline Cslice_iter<T> Cslice_iter<T>::end()
{
  Cslice_iter t=*this;
  t.curr = s.size();
  return t;
}
template<class T> 
inline Cslice_iter<T>& Cslice_iter<T>::operator++()
{
  curr++;return *this;
}
template<class T>
inline Cslice_iter<T> Cslice_iter<T>::operator++(int) 
{
  Cslice_iter t= *this; 
  curr++; 
  return t;
}
template<class T>
inline T& Cslice_iter<T>::operator[] (size_t i) 
{
  return ref(curr=i);
}
template<class T>
inline T& Cslice_iter<T>::operator() (size_t i) 
{
  return ref(curr=i);
}
template<class T>
inline T& Cslice_iter<T>::operator*() 
{
  return ref(curr=i);
}


template<class T>
bool operator== (const Slice_iter<T>& p, const Slice_iter<T>& q)
{
  return p.curr==q.curr && p.s.stride()==Q.s.stride() && p.s.start()==q.s.start();
}
template<class T>
bool operator!= (const Slice_iter<T>& p, const Slice_iter<T>& q)
{
  return !(p==q);
}
template<class T>
bool operator< (const Slice_iter<T>& p, const Slice_iter<T>& q)
{
  return p.curr<q.curr && p.s.stride()==q.s.stride() && p.s.start()==q.s.start();
}

