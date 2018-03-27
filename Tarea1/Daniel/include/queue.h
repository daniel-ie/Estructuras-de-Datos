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
    string isbnQ, userQ, prestarQ, stockResultQ, prestar ;
    MStorage *myStorage ;
    Nodo *node ;
public:
    int rear, front, size ;
    Nodo arr[100]  ; 	 // Circular queue

    Queue() ;
    Queue(string, string) ;
    void enQueue(Nodo &) ;
    //void enQueue(string, string, string) ; //int value) ;
    int  deQueue() ;
    void displayQueue() ; // void pqueue() ;
    int inStock(vector<Book> &) ;
} ;
/*class Queue:public MStorage{
    Nodo *pdato ; Nodo *frente ; Nodo *final ;
    string isbnQ, userQ, stockResultQ, prestar ;
    MStorage *myStorage ;
public:
    Queue() ;
    Queue(string, string) ;
    void registraSolicitud(string, string, bool) ;
    void pqueue() ;
    int inStock(vector<Book> &) ;
} ;*/


#endif // QUEUE_H
