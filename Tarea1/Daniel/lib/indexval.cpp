#include "indexval.h"

/// Inicializacion de la clase junto con sus metodos ///

// constructor de la clase: crea un objeto de tipo indexval el cual maneje sus metodos.
indexval::indexval()
{
    elem=NULL;
}
//Crea un nuevo nodo y lo inserta a la lista en la primera posición.
void indexval::insertarI(int n){
    Nodo *nuevo= new Nodo(n);
    nuevo->siguiente= elem;
    elem=nuevo;
}
//Busca el elemento especificado dentro de la lista y lo imprime.
void indexval::buscar(int n){
        bool band= false;
    Nodo* aux;
    aux= elem;
    while(aux!=NULL){
        if(aux->anno==n){
            band=true;
        }
        aux=aux->siguiente;
    }
    if(band== true){
        cout<<"El elemento: "<<aux->anno<< ", ha sido encontrado"<<endl;
    }
    else{
        cout<<"No se ha encontrado el elemento"<<endl;
    }
}
//Elimina el elemento indicado de la lista.
void indexval::eliminar(int n){
        Nodo *aux;
    Nodo *ant=NULL;
    aux= elem;
    if(elem!=NULL){
        while((aux!=NULL)&&(aux->anno!=n)){
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
            cout<<"El elemento: "<<aux->anno<<", ha sido eliminado"<<endl;
            delete aux;
        }
    }
}
//Muestra todos los elementos en la lista.
void indexval::mostrar(){
        Nodo* aux;
    aux=elem;
    while(aux!=NULL){
        cout<<aux->anno<<"->";
        aux=aux->siguiente;
    }
}
//Ordena la lista de indices por año de menor a mayor.
void indexval::bbsort(){
    Nodo *aux, *aux1, *aux2, *aux3, *aux4;
    aux3= NULL;
    while(aux3!=elem){
        aux2= aux =elem;
        aux1=aux->siguiente;

        while(aux!= aux3){
            if(aux->anno > aux1->anno){
                if(aux==elem){
                    aux4=aux2->siguiente;
                    aux1->siguiente=aux;
                    aux->siguiente=aux4;

                    elem= aux1;
                    aux2=aux1;
                }
                else{
                    aux4=aux1->siguiente;
                    aux1->siguiente=aux;
                    aux->siguiente=aux4;

                    aux2->siguiente=aux1;
                    aux2=aux1;
                }
            }
            else{
                aux2=aux;
                aux=aux->siguiente;
            }
            aux1=aux->siguiente;
            if(aux1==aux3){
                aux3=aux1;
            }
        }
    }
}


