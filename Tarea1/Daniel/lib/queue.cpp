#include <iostream>
#include <fstream>  // writer
#include <string>
#include <cstring>
#include <sstream>
#include <stdlib.h>
#include <vector>

#include "queue.h"
#include "mstorage.h"
#include "nodo.h"

////////////////////////////////////////////////////
///             Clase Queue
////////////////////////////////////////////////////
//Queue::Invalid{} ;
Queue::Queue():MStorage(){
    pdato = NULL ;
    frente = NULL ;
    final = NULL ;
}
Queue::Queue(string isbnQ, string userQ):MStorage(){
    pdato = NULL ;
    frente = NULL ;
    final = NULL ;
    this->isbnQ = isbnQ ;
    this->userQ = userQ ;

    //stock() ;
    insert(isbnQ, userQ) ; //isbnQ, userQ) ;
    //inStock() ;
    //mostrar() ;
}

void Queue::insert(string isbnQ, string userQ){
    this->isbnQ = isbnQ ;
    this->userQ = userQ ;

    pdato = new Nodo(isbnQ, userQ, pdato) ;
    pdato->isbn = isbnQ ; pdato->user = userQ ;
    if(final == NULL){
        final = pdato ;
        pdato->siguiente = final ;
    }
    else{
        pdato->siguiente = final->siguiente ;
        final->siguiente = pdato ;
        final = pdato ;
    }
    //inStock() ;
}
void Queue::mostrar(int stockCant){ // será el comando queue
    if(final == NULL){
        cout << "list is empty" << endl  ;
        return ;
    }

    string stockResult ;
    if(stockCant>0)
        stockResult = "Asignado" ;
    else
        stockResult = "No asignado" ;

    pdato = final->siguiente ;

    cout << "ISBN     " << string(15, ' ') ;
    cout << "Usuario  " << string(15, ' ') ;
    cout << "Resultado" << string(15, ' ') ;
    cout << endl ;
    while(pdato != final){
        cout << pdato->isbn << string(24-pdato->isbn.length(), ' ') ;  // espaceo ct
        cout << pdato->user << string(24-pdato->user.length(), ' ') ;
        cout << stockResult ;
        cout << endl ;
        pdato = pdato->siguiente ;
    }
    cout << pdato->isbn << string(24-pdato->isbn.length(), ' ') ;
    cout << pdato->user << string(24-pdato->user.length(), ' ') ;
    cout << stockResult ;
    cout << endl ;

}
int Queue::inStock(vector<Book> &newMyStorage){
    int cant = 0 ;
    unsigned int size = newMyStorage.size() ;
    for(unsigned int i=0; i<size; i++){
        if(newMyStorage[i].getIsbn() == isbnQ)  // revisa si el libro esta en existencias
            cant += 1 ;
    }
    return cant ;
}
