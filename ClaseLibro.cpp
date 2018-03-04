#include <iostream>

using namespace std ;

class Nodo {
public:
    int dato ;

    Nodo *siguiente ;
    Nodo(int x){
        dato = x ;
        siguiente = NULL ;
    }
    Nodo(int x, Nodo *p){
        dato = x ;
        siguiente = p ;
    }
} ;

class ListaSimple {
    Nodo *pdato ;
public:
    ListaSimple(){
        pdato = NULL ;
    }

    void insertar(int x){
        pdato = new Nodo(x, pdato) ;     // Crea el nodo
    }
    void mostrar(){
        cout << "ListaSimple = [" ;
        if(pdato){
            cout << pdato->dato ;
            for(Nodo *q = pdato->siguiente; q; q = q->siguiente)
                cout << ", " << q->dato ;
        }
        cout << "]\n" ;
    }
    int size(){
        int s = 0 ;
        for(Nodo *q = pdato; q; q = q->siguiente)
            s += 1 ;
        return s ;
    }
} ;


int main()
{
    ListaSimple year = ListaSimple() ;    // Constructor objeto year
    ListaSimple autor = ListaSimple() ;   // objeto autor       

    year.insertar(2010) ;
    year.insertar(2017) ;
    
    //autor.insertar("Patrick Rothfuss") ;

    year.mostrar() ;

    return 0 ;
}
