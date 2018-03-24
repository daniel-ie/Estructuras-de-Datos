#ifndef NODO_H
#define NODO_H

#include <iostream>
//#include <fstream>  // writer
#include <string>
#include <cstring>
#include <sstream>
#include <stdlib.h>
//#include <vector>


using namespace std ;

////////////////////////////////////////////////////
///             Clase Nodo
////////////////////////////////////////////////////
class Nodo {
    /* *********************************************
    * La clase Nodo permite crear un registro que
    * contiene elementos o datos de interés, y a su
    * vez ofrece uno o dos punteros para referenciar
    * (apuntar) a otro nodo.
    *
    * Ejemplo de uso:
    *
    * pdato = NULL ;
    * pdato = new Nodo(elem, pdato) ;
    *
    * En el ejemplo anterior se inserta
    * el dato "elem" en el Nodo, el cual tiene
    * asociado el puntero "pdato".
    *
    * */
public:
    // Registros que soporta el Nodo
    string isbn, titulo, autor, year, cantidad ;
    string user ;
    // Puntero al siguiente Nodo
    Nodo *siguiente ;

    Nodo(string, string) ;
    Nodo(string, string, Nodo *) ;
    /* =====================================================
        * Constructor con sobrecarga para la Clase Pqueue
        *
        * Entradas
        *        isbn   : ISBN del libro solicitado
        *        user   : Nombre del usuario
        *        pdato  : Puntero para referenciar el Nodo
        * Salidas
        *        Instancia de la Clase Nodo.
        * Restricciones
        *        Recibe tipo string.
    * ================================================ */

    // Punteros al frente y final para Lista circular doble
    Nodo *frente ;
    Nodo *final ;

    Nodo(string, string, string, string, string) ;
    Nodo(string, string, string, string, string, Nodo *) ;
    /* =============================================================
        * Constructor con sobrecarga para la Clase Book
        *
        * Entradas
        *        isbn     : ISBN del libro
        *        titulo   : Titulo del libro
        *        autor    : Autor del libro
        *        año      : Año de publicación del libro
        *        cantidad : Cantidad de ejemplares en la Biblioteca
        *        pdato    : Recibe un puntero al Nodo para referenciar
        * Salidas
        *        Instancia de la Clase Nodo.
        * Restricciones
        *        Recibe tipo string.
    * ============================================================== */
} ;


#endif // NODO_H
