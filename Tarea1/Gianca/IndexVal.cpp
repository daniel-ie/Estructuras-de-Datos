#include "IndexVal.h"

//Inicializa la clase junto a sus atributos y sus metodos
template <class T>
IndexVal<T>::IndexVal(T val)
{
    valor=val;
    inicio=NULL;
    fin=NULL;
}
//Inserta un nuevo nodo al inicio de la lista
template <class T>
void IndexVal<T>::insertar(Nodo<T>* nuevo)
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
//Busca un nodo por su id en la lista
template <class T>
Nodo<T>* IndexVal<T>::buscarN(Nodo<T> dto)
{
   Nodo<T>*aux=inicio;
   while(aux!=NULL){
        if(aux.dato==dto)
            {break;}
        aux=aux->siguiente;
   }
   return aux;
}
