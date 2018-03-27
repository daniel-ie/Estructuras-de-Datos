#include <iostream>
#include <fstream>  // writer
#include <string>
#include <cstring>
#include <sstream>
#include <stdlib.h>
#include <vector>
#include <array>
#include <iterator>

#include<bits/stdc++.h>

#include "queue.h"
#include "mstorage.h"
#include "nodo.h"
#include "cmd.h"

////////////////////////////////////////////////////
///             Clase Queue
////////////////////////////////////////////////////
//Queue::Invalid{} ;
Queue::Queue():MStorage(){
    front = -1 ;
    rear  = -1 ;
    size  =  100 ;
    arr ;
}
Queue::Queue(string isbnQ, string userQ):MStorage(){
    front = -1 ;
    rear  = -1 ;
    size  =  100 ;
    arr   ;
    this->isbnQ = isbnQ ;
    this->userQ = userQ ;
}

void Queue::enQueue(Nodo &nodo){
    cout << "nodito " << nodo.isbn << endl ;

    if ((front == 0 && rear == size-1) ||
            (rear == front-1)){
        cout << "Cola llena" << endl ;
        return ;
    }
    else if (front == -1){ // Insert First Element
        cout << "Primero en cola = " << endl ;
        front = 0 ;
        rear = 0 ;
        arr[rear] = nodo ;
    }
    else if (rear == size-1 && front != 0){
        cout << "?? en cola = " << endl ;
        rear = 0;
        arr[rear] = nodo ;
    }
    else{
        cout << "Colas " << endl ;
        rear += 1;
        arr[rear] = nodo ;
    }
}

/*void Queue::enQueue(string isbnQ, string userQ, string prestarQ){
    this->isbnQ     = isbnQ ;
    this->userQ     = userQ ;
    this->prestarQ  = prestarQ ;
}*/
/*
    front = -1 ;
    rear  = -1 ;
    size  =  1000 ;
    //*arr ; //   = NULL ;
    node = NULL ;

    node = new Nodo(isbnQ, userQ, prestarQ, node) ;
    cout << "Nodo queue = " << node->isbn << endl ;

    if ((front == 0 && rear == size-1) ||
            (rear == front-1)){
        cout << "Cola llena" << endl ;
        return ;
    }
    else if (front == -1){ // Insert First Element
        cout << "Primero en cola = " << endl ;
        front = 0 ;
        rear = 0 ;
        arr[rear] = nodo ;
    }
    else if (rear == size-1 && front != 0){
        cout << "?? en cola = " << endl ;
        rear = 0;
        arr[rear] = node ;
    }
    else{
        cout << "Colas " << endl ;
        rear += 1;
        arr[rear] = node ;
        //arr[rear] = node ;

    }*/

void Queue::displayQueue(){
    if (front == -1){
        cout << "Cola vacia" << endl ;
        return ;
    }
    cout << "rear: " << rear << "front: " << front << endl ;
    if (rear >= front){
        cout << "\nISBN" << "\t\t\t" << "Usuario" << "\t\t\t" << "Estado" << endl ;
        for (unsigned int i = 0 ; i < 2; i++){
            cout << arr[i].isbn << "\t" ; // VER COMO ACCEDER CON CONTADOR
            //cout << arr[i]->user << "\t" ;
            //cout << (arr.begin()+i)->stockResult << endl ;
            //cout << "it= " << it << endl ;
        }
    }
    else{
        cout << "in 2" ;
    }
}
int Queue::inStock(vector<Book> &newMyStorage){
    int cant = 0 ;
    unsigned int size = newMyStorage.size() ;
    for(unsigned int i=0; i<size; i++){
        if((newMyStorage.begin()+i)->getIsbn() == isbnQ) // revisa si el libro esta en existencias
            cant += 1 ;
    }
    return cant ;
}

/*for (int i = front; i < size; i++){
    //cout << arr[i] << " " ;
    cout << arr[i]->isbn << "\t" ;
    cout << arr[i]->user << "\t" ;
    cout << arr[i]->stockResult << endl ;
}
for (int i = 0; i <= rear; i++){
    cout << arr[i]->isbn << "\t" ;
    cout << arr[i]->user << "\t" ;
    cout << arr[i]->stockResult << endl ;
}*/




/*if(final == NULL){
cout << "No se han realizado nuevas solicitudes" << endl  ;
return ;
}
node = final->siguiente ; // LA COLA NO ESTA ALMACENANDO NUEVOS ELEMENTOS

cout << "ISBN     " << string(15, ' ') ;
cout << "Usuario  " << string(15, ' ') ;
cout << "Resultado" << string(15, ' ') ;
cout << endl ;
while(node != final){
cout << node->isbn << string(24-node->isbn.length(), ' ') ;  // espaceo ct
cout << node->user << string(24-node->user.length(), ' ') ;
cout << node->stockResult ;
cout << endl ;
node = node->siguiente ;
}
cout << node->isbn << string(24-node->isbn.length(), ' ') ;
cout << node->user << string(24-node->user.length(), ' ') ;
cout << node->stockResult ;
cout << endl ;*/
