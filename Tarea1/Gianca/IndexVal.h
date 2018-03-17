#ifndef INDEXVAL_H
#define INDEXVAL_H
#include "Index.h"
#include "Nodo.h"
#include "ISBNRef.h"

using namespace std;
//declaracion de la clase con sus respectivos metodos y atributos
template <class T>
class IndexVal
{
    T valor;
    Nodo<T>* inicio;
    Nodo<T>* fin;
    public:
        IndexVal(T);
        void insertar(Nodo<T>*);
        Nodo<T>* buscarN(Nodo<T>);
};

#endif // INDEXVAL_H
