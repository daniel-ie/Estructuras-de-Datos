#include "index.h"

index::index()
{
    elem=NULL;
}
void index::insertarI(string n){
    Nodo* nuevo= new Nodo(n);
    nuevo->siguiente=elem;
    elem=nuevo;
}
void index::buscarI(string n){
    bool band= false;
    Nodo* aux;
    aux= elem;
    while(aux!=NULL){
        if(aux->val==n){
            band=true;
        }
        aux=aux->siguiente;
    }
    if(band== true){
        cout<<"El elemento ha sido encontrado"<<endl;
    }
    else{
        cout<<"No se ha encontrado el elemento"<<endl;
    }
}
void index::eliminarI(string n){
    Nodo *aux;
    Nodo *ant=NULL;
    aux= elem;
    if(elem!=NULL){
        while((aux!=NULL)&&(aux->val!=n)){
            ant=aux;
            aux=aux->siguiente;
        }
        if(aux==NULL){
            cout<<"El elemento no se encuentra en la lista."<<endl;
        }
        if(ant==NULL){
            elem==NULL;
        }
        else{
            ant->siguiente=aux->siguiente;
            delete aux;
        }
    }
}
void index::imprimir(){
    Nodo* aux;
    aux=elem;
    while(aux!=NULL){
        cout<<aux->val<<"->";
        aux=aux->siguiente;
    }
}
