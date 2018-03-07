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

class MergeSort {    
public:
    Nodo *pdatoGlobal ;
    MergeSort(){
        pdatoGlobal = NULL ;
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
    Nodo *pdato = NULL ;
    MergeSort lista = MergeSort() ;
    
    lista.push(&pdato, 6) ;
    lista.push(&pdato, 4) ;

    lista.printList(lista.pdatoGlobal) ;

    lista.mergeSort(&lista.pdatoGlobal) ;
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
 
