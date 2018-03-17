#include "Index.h"
//Inicializa las variables de los constructores de la clase.
template <class T>
Index<T>::Index(T ind)
{
    index=ind;
    inicio=NULL;
}

//Retorna el puntero final de la lista.
template <class T>
Nodo<T>* Index<T>::getFinal()
{
    Nodo<T>* fin;
    while(fin->siguiente!=NULL){
        fin= fin->siguiente;
    }
    return fin;
}
//inserta un nuevo nodo al inicio de la lista.
template <class T>
void Index<T>::insertar(Nodo<T>*nuevo)
{
    nuevo->siguiente=inicio;
    inicio=nuevo;
}
//Busca un nodo por su id en este caso se maneja por enteros
template <class T>
Nodo<T>* Index<T>::buscarN(Nodo<T> dto){
   Nodo<T>*aux=inicio;
   while(aux!=NULL){
        if(aux.dato==dto)
            {break;}
        aux=aux->siguiente;
   }
   return aux;
}
