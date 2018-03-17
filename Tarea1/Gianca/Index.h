#include "Nodo.h"
#include "IndexVal.h"
#ifndef INDEX_H
#define INDEX_H
#include <string>
using namespace std;

//Declaracion de la clase con sus atributos y metodos.
template <class T>
class Index
{
        T index;
        Nodo<T>* inicio;

    public:
        Index<T>(T);
        void setInicio(Nodo<T>*);
        Nodo<T>* getFinal();
        void insertar(Nodo<T>*);
        Nodo<T>* buscarN(Nodo<T>);

};

#endif // INDEX_H
