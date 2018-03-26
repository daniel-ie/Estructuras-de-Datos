#ifndef INDEXVAL_H
#define INDEXVAL_H
#include <string>

#include "nodo.h"

using namespace std;
/////////////////////////////////////////////////////////////////////
/// Clase indexval con sus metodos y atributos correspondientes. ///
///////////////////////////////////////////////////////////////////
class indexval
{
    public:
        Nodo* elem;
        indexval();
        void insertarI(int);
        void buscar(int);
        void eliminar(int);
        void mostrar();
        void bbsort();
};

#endif // INDEXVAL_H
