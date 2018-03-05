#include <iostream>

using namespace std ;

template <class T>
class Nodo {
public:
    T dato ;
    Nodo *siguiente ;

    Nodo(T x){
        dato = x ;
        siguiente = NULL ;
    }
    Nodo(T x, Nodo *p){
        dato = x ;
        siguiente = p ;
    }
} ;

template <class T>  
class ListaSimple {
    Nodo<T> *pdato ;
public:
    ListaSimple<T>(){
        pdato = NULL ;
    }
    void insertar(T x){
        pdato = new Nodo<T>(x, pdato) ;     // Crea el nodo
    }
    void mostrar(){
        cout << "ListaSimple = [" ;
        if(pdato){
            cout << pdato->dato ;
            for(Nodo<T> *q = pdato->siguiente; q; q = q->siguiente)
                cout << ", " << q->dato ;
        }
        cout << "]\n" ;
    }
    int size(){
        int s = 0 ;
        for(Nodo<T> *q = pdato; q; q = q->siguiente)
            s += 1 ;
        return s ;
    }
} ;


int main()
{
    ListaSimple<int> year = ListaSimple<int>() ;    // Constructor objeto year
    ListaSimple<string> autor = ListaSimple<string>() ;   // objeto autor       

    year.insertar(2010) ;
    year.insertar(2017) ;

    autor.insertar("Patrick Rothfuss") ;
    autor.insertar("Dan Brown") ;

    year.mostrar() ;
    autor.mostrar() ;

    return 0 ;
}
