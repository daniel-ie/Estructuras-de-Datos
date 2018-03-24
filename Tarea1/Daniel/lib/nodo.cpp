#include "nodo.h"

////////////////////////////////////////////////////
///             Clase Nodo
////////////////////////////////////////////////////
/*--------------------------- Sobrecarga para  Clase Queue ----------------------------------------------*/
Nodo::Nodo(string isbn, string user){
    this->isbn = isbn ; this->user = user ;
    siguiente = NULL ;
}
Nodo::Nodo(string isbn, string user, Nodo *p){
    this->isbn = isbn ; this->user = user ;
    siguiente = p ;
}
/*---------------------------- Sobrecarga para  Clase Book ----------------------------------------------*/
Nodo::Nodo(string isbn, string titulo, string autor, string year, string cantidad){
    this->isbn = isbn ;
    this->titulo = titulo ;
    this->autor = autor ;
    this->year = year ;
    this->cantidad = cantidad ;
    siguiente = NULL ;
}
Nodo::Nodo(string isbn, string titulo, string autor, string year, string cantidad, Nodo *p){
    this->isbn = isbn ;
    this->titulo = titulo ;
    this->autor = autor ;
    this->year = year ;
    this->cantidad = cantidad ;
    siguiente = p ;
}
