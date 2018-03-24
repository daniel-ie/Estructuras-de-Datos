#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <stdlib.h>

#include "mstorage.h"
#include "nodo.h"

////////////////////////////////////////////////////
///             Clase Queue
////////////////////////////////////////////////////
class Queue:public MStorage{
    Nodo *pdato ;
    Nodo *frente ;
    Nodo *final ;
    string isbnQ, userQ ;
public:
    class Invalid{} ;

    //Queue():MStorage(){}
    //Queue(string, string):MStorage(){}
    Queue() ;
    Queue(string, string) ;
    void insert(string, string) ;
    void mostrar(int) ;
    int inStock(vector<Book> &) ;

} ;


#endif // QUEUE_H
