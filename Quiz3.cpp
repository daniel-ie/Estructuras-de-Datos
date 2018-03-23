#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std ;

class HashNode{
   public:
    int value, key ;
    HashNode(int key, int value){   // Constructor
        this->key = key ;
        this->value = value ;
    }
} ;

class HashMap{              // Punteros al Nodo
    HashNode **arr ;        // hash element array
    HashNode *dummy ;       // dummy node
    int TAM, size ;
public:
    HashMap(){                          // b.1 (Constructor)
        TAM = 20 ;
        size = 0 ;
        arr = new HashNode *[TAM] ;
        for(int i=0; i<TAM; i++)
            arr[i] = NULL ;
        dummy = new HashNode(-1, 1) ;
    }
    bool insertar(int key, int value){  // b.2 (insertar(int x))
        HashNode *temp = new HashNode(key, value) ;
        int hashIndex = hashf(key) ;
        while(arr[hashIndex] != NULL && arr[hashIndex]->key != -1){
            if(arr[hashIndex]->key == key){ // La insercion no procede                
                return false ;
            }
            hashIndex++ ;
            hashIndex %= TAM ;
        }
        arr[hashIndex] = temp ;
        return true ;
    }
    int hashf(int Key){
        return Key%TAM ;
    }
    bool existe(int key){                 // b.3 (existe(int x))
        //Funcion que busca el valor para un llave especifica
        // Aplica hashf para encontrar index para una llave especifica
        int hashIndex = hashf(key);
        // encontrando el nodo con una llave especifica
        while(arr[hashIndex] != NULL){
            if(arr[hashIndex]->key == key)
                return true ;
            hashIndex++;
            hashIndex %= TAM;
        }        
        return false ;
    }    
    bool eliminar(int key){               // b.4 (eliminar(int x))
        int hashIndex = hashf(key);
        while(arr[hashIndex] != NULL){
            if(arr[hashIndex]->key == key){ // encuentra nodo
                HashNode *temp = arr[hashIndex];
                arr[hashIndex] = dummy;
                size--;
                return true ; // Si encontro el nodo!
            }
            hashIndex++;
            hashIndex %= TAM ;
        }
        return false;
    }
    void display(){
        for(int i=0; i<TAM; i++){
            if(arr[i] != NULL && arr[i]->key != -1){
                cout << "key = " << arr[i]->key << ", value = " << arr[i]->value << endl ;
            }
        }
    }

} ;


int main(){
    HashMap *h = new HashMap ;
    string s ;

////////////////// Solucion a. //////////////////
    cout << "Solucion a. " << endl << "Los atributos privados son:" << endl ;
    cout << "HashNode **arr  ; //Nodo para elementos" << endl ;
    cout << "HashNode *dummy ; // Nodo auxiliar" << endl ;
    cout << "int TAM; // Tamaño de la Tabla" << endl << endl ;

////////////////// Solucion b. //////////////////
    cout << "Solucion b. " << endl << "Implementacion de insertar(int x), existe(int x) y eliminar(x)" << endl ;

    h->insertar(1, 2) ;
    h->insertar(2, 3) ;
    cout << "Tabla " << endl ;
    h->display() ;
    cout << endl ;
///////// bool insertar(int x) /////////
    bool inserto = h->insertar(2, 5) ;      // Intentando insertar llave repetida
         inserto==1 ? s="true":s="false" ;
    cout << "Insercion de 2 es              --> " << s << "!" << endl ;

///////// bool existe(int x) /////////
    bool exist = h->existe(1) ;               // Revisando si llave "1" existe
         exist==1 ? s="true":s="false" ;
    cout << "Usuario: Existe la llave 1?    --> " << s << "!" << endl ;

///////// bool eliminar(int x) /////////
    bool elimina = h->eliminar(1) ;               // Eliminando elemento existente "1"
         elimina==1 ? s="true":s="false" ;
    cout << "Se elimino llave 1?            --> " << s << "!" << endl ;

    cout << "\n Otro display!" << endl ;
    h->display() ;
    return 0 ;
}

