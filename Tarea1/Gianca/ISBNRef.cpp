#include "ISBNRef.h"
template <class T>
ISBNRef<T>::ISBNRef(T var)
{
    variable=var;
    inicio= NULL;
    fin= NULL;
}
template <class T>
void ISBNRef<T>::insertar(Nodo<T>* nuevo)
{
        if(inicio==NULL){
        inicio=nuevo;
        fin=nuevo;
    }
    else{
        inicio=nuevo;
        inicio->siguiente->anterior=inicio;
    }
}
template <class T>
Nodo<T>* ISBNRef<T>::buscarN(Nodo<T> dto)
{
      Nodo<T>*aux=inicio;
   while(aux!=NULL){
        if(aux.dato==dto)
            {break;}
        aux=aux->siguiente;
   }
   return aux;
}

