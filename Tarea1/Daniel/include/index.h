#ifndef INDEX_H
#define INDEX_H
#include <string>

#include "nodo.h"

using namespace std;

class index
{
public:
    Nodo *elem;
    index();
    void insertarI(string);
    void buscarI(string);
    void eliminarI(string);
    void imprimir();

};

#endif // INDEX_H
