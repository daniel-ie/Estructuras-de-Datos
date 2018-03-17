#ifndef NODO_H
#define NODO_H
#include <string>


//Declaracion de la clase con sus variables y metodos.
template <class T>
class Nodo
{
    T dato;
    Nodo* siguiente;
    Nodo* anterior;

	public:
		Nodo(T);
		Nodo(T,Nodo*);
};

#endif // NODO_H
