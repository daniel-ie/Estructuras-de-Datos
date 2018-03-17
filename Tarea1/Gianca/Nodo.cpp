#include "Nodo.h"


template <class T>
Nodo<T>::Nodo(T dt)
{
    dato=dt;
    siguiente=NULL;
    anterior=NULL;
}
template <class T>
Nodo<T>::Nodo(T dt,Nodo<T>* sig)
{
    dato=dt;
    siguiente=sig;
}

