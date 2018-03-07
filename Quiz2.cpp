#include <iostream>
#include <string>

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
    MergeSort(int orden){
        pdatoGlobal = NULL ;
        ordenamiento = orden ;
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

    void ascendente(){

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

        switch (ordenamiento)
        {
        case 1 : //"ascendente" :            
            // Ordenamiento ascendente
            if(a->dato <= b->dato){
                mergedList = a ;
                mergedList->siguiente = mergeLists(a->siguiente, b) ;
            }
            else{
                mergedList = b ;
                mergedList->siguiente = mergeLists(a, b->siguiente) ;
            }
            break ;
        case 2 : // "descendente" :
            // Ordenamietno descendente
            if(a->dato >= b->dato){
                mergedList = a ;
                mergedList->siguiente = mergeLists(a->siguiente, b) ;
            }
            else{
                mergedList = b ;
                mergedList->siguiente = mergeLists(a, b->siguiente) ;
            }
            break ;
        default:
            // Ordenamiento ascendente
            if(a->dato <= b->dato){
                mergedList = a ;
                mergedList->siguiente = mergeLists(a->siguiente, b) ;
            }
            else{
                mergedList = b ;
                mergedList->siguiente = mergeLists(a, b->siguiente) ;
            }
            break ; 
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
    Nodo *pdato = NULL ;
    MergeSort lista = MergeSort(2) ;
    
    lista.push(&pdato, 100) ;
    lista.push(&pdato, 200) ;
    lista.push(&pdato, 400) ;
    lista.push(&pdato, 500) ;
    lista.push(&pdato, 1000) ;
    lista.push(&pdato, 2000) ;
    lista.push(&pdato, 5000) ;
    lista.push(&pdato, 10000) ;
    lista.push(&pdato, 20000) ;
    lista.push(&pdato, 40000) ;
    lista.push(&pdato, 50000) ;
    lista.push(&pdato, 100000) ;


    lista.printList(lista.pdatoGlobal) ;
    lista.mergeSort(&lista.pdatoGlobal) ; //"descendente") 
    lista.printList(lista.pdatoGlobal) ;
 
    return 0;
}

// *head = head in the main function,
// it is only there to connect the two and
// not let make the function return anything
// passed by reference
// globalHead points to the start of the linked list
// if you are passing the address over here you have to
// make a double pointer over there in the function
 
