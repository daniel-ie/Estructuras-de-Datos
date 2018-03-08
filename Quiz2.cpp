#include <iostream>
#include <string>
#include <stdlib.h>

#ifdef WIN32
#include <Windows.h>
#else
#include <sys/time.h>
#include <ctime>
#endif


using namespace std ;

/* Returns the amount of milliseconds elapsed since the UNIX epoch. Works on both * windows and linux. */
typedef long long int64; typedef unsigned long long uint64;
int64 GetTimeMs64(){
    #ifdef WIN32
     /************** Windows **************/
     FILETIME ft;
     LARGE_INTEGER li;
     /* Get the amount of 100 nano seconds intervals elapsed since January 1, 1601 (UTC) and copy it * to a LARGE_INTEGER structure. */
     GetSystemTimeAsFileTime(&ft);
     li.LowPart = ft.dwLowDateTime;
     li.HighPart = ft.dwHighDateTime;

     uint64 ret = li.QuadPart;
     ret -= 116444736000000000LL; /* Convert from file time to UNIX epoch time. */
     ret /= 10000; /* From 100 nano seconds (10^-7) to 1 millisecond (10^-3) intervals */
     return ret;

    #else
     /************** Linux **************/
     struct timeval tv;
     gettimeofday(&tv, NULL);
     uint64 ret = tv.tv_usec;
     /* Convert from micro seconds (10^-6) to milliseconds (10^-3) */
     ret /= 1000;
     /* Adds the seconds (10^0) after converting them to milliseconds (10^-3) */
     ret += (tv.tv_sec * 1000);
     return ret;
    #endif
}
 
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
            case 3: // permuta
                for(int i=0; i<n; i++)
                    push(&pdatoX, i) ; 
                for(int i=0; i<n; i++){
                    int j = rand()%n ;
                    intercambie(i, j) ; //push(&pdatoX, i), push(&pdatoX, rand()%n)) ;
                    push(&pdatoX, i) ;
                }
                break ;                
            case 4: ///aleatoria
                for(int i=0; i<n; i++)
                    push(&pdatoX, rand()%n) ;
                break ;
            default: // ascendente
                for(int i=0; i<n; i++)
                    push(&pdatoX, i) ;                   
                break ;
        }
    } 

    void intercambie(int &a, int &b){
        int temp = a ;
        a = b; 
        b = temp ;        
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

double RunMergeSort(int nNumeros, int ordenamientoTipo){
/***** Algoritmo de ordenamiento MergeSort por listas enlazadas *****/
    double t1, t2 ;
    t1 = GetTimeMs64() ;     

    Nodo *pdato = NULL ;
    MergeSort lista = MergeSort() ;    

    //ordenamientos: ascendente=1, descendente=2, aleatorio=3   
    lista.genere(&pdato, nNumeros, ordenamientoTipo) ;  // (punteroRef, num datos, ordenamiento)
    lista.printList(lista.pdatoGlobal) ;

    lista.mergeSort(&lista.pdatoGlobal) ; // ordena ascendentemente
    lista.printList(lista.pdatoGlobal) ;
 
    t2 = GetTimeMs64(); 

    return t2-t1 ;
}

int main(void)
{
    // (nNumeros, ordenamientoTipo)
    //ordenamientos: ascendente=1, descendente=2, permuta=3, aleatorio=4 
    // tambien brinda tiempo de ejecucion 
    double t = RunMergeSort(100, 1) ; 
    
    cout << "\n\nTiempo de ejecucion:" << t << "ms" << endl ;

    return 0;
}
