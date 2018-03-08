#include <iostream>
#include <string>
#include <stdlib.h>

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

class MergeSort {    
public:
    Nodo *pdatoGlobal ;
    int ordenamiento ;
    MergeSort(){
        pdatoGlobal = NULL ;
    }
 
    int genere(Nodo **pdato, int n, int tipo){
        Nodo *pdatoX = NULL ;
        ordenamiento = tipo ;
        switch(tipo){
            case 1: // ascendente
                for(int i=0; i<n; i++)                                     
                    push(&pdatoX, i) ;                
                break ;
            case 2: // descendente
                for(int i=n-1; i>=0; i--)
                    push(&pdatoX, i) ;
                break ;
            case 3: ///aleatoria
                for(int i=0; i<n; i++)
                    push(&pdatoX, rand()%n) ;
                break ;
            default: // ascendente
                for(int i=0; i<n; i++)
                    push(&pdatoX, i) ;                   
                break ;
        }
    } 

    void push(Nodo **pdato, int dato){
        Nodo *newNode = new Nodo(dato) ;
        if((*pdato) == NULL){
            *pdato = newNode ;
            pdatoGlobal = *pdato ;
        }
        else{
            (*pdato)->siguiente = newNode ;
            *pdato = newNode ;
        }
    }

    void printList(Nodo *pdato){
        Nodo *current = pdato ;
        cout << "Lista = [" ;
        if(current){
            cout << current->dato ;
            for(Nodo *q = current->siguiente; q; q=q->siguiente)
                cout << ", " << q->dato ;
        }
        cout << "]\n" ;
    } 

    void mergeSort(Nodo **source){
        Nodo *pdato1 = *source, *a=NULL, *b=NULL ;
        if(pdato1==NULL || pdato1->siguiente==NULL)
            return ;
        partition(pdato1, &a, &b) ;
        mergeSort(&a) ;
        mergeSort(&b) ;
        *source = mergeLists(a, b) ;
    }

    Nodo *mergeLists(Nodo *a, Nodo *b){
        Nodo *mergedList = NULL ;
        if(a == NULL)
            return b ;
        else if(b == NULL)
            return a ;        

        // Ordenamiento ascendente
        if(a->dato <= b->dato){
            mergedList = a ;
            mergedList->siguiente = mergeLists(a->siguiente, b) ;
        }
        else{
            mergedList = b ;
            mergedList->siguiente = mergeLists(a, b->siguiente) ;
        }
        return mergedList ;
    }

    void partition(Nodo *pdato, Nodo **front, Nodo **back){
        Nodo *fast, *slow ;
        if(pdato==NULL || pdato->siguiente==NULL){
            *front = pdato ;
            *back = NULL ;
        }
        else{
            slow = pdato;
            fast = pdato->siguiente;
            while(fast != NULL){
                fast = fast->siguiente;
                if(fast != NULL){
                    slow = slow->siguiente;
                    fast = fast->siguiente;
                }
            }
            *front = pdato ;
            *back = slow->siguiente ;
            slow->siguiente = NULL ;
            printList(*front) ;
            printList(*back) ;
        }
    }

} ;


int main(void)
{

/***** Algoritmo de ordenamiento MergeSort por listas enlazadas *****/
    Nodo *pdato = NULL ;
    MergeSort lista = MergeSort() ;

    //ordenamientos: ascendente=1, descendente=2, aleatorio=3   
    lista.genere(&pdato, 100, 3) ;  // (punteroRef, num datos, ordenamiento)
    lista.printList(lista.pdatoGlobal) ;

    lista.mergeSort(&lista.pdatoGlobal) ; // ordena ascendentemente
    lista.printList(lista.pdatoGlobal) ;
 
    return 0;
}
