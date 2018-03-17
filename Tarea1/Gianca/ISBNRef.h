#ifndef ISBNREF_H
#define ISBNREF_H
#include "Nodo.h"
//#include "BOOK.h"
//Declaracion de la clase isbnref junto a sus metodos y atributos
using namespace std;

template <class T>

class ISBNRef
{
    T variable;//Aqui debe ir la variable que es de tipo book pero solo se debe obtener el isbn
    Nodo<T>* inicio;
    Nodo<T>* fin;
    public:
        ISBNRef(T);
        void insertar(Nodo<T>*);
        Nodo<T>* buscarN(Nodo<T>);
};

#endif // ISBNREF_H
