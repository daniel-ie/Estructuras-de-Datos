#ifndef BOOK_H
#define BOOK_H

#include <iostream>
//#include <fstream>  // writer
#include <string>
#include <cstring>
#include <sstream>
#include <stdlib.h>
#include <vector>

#include "nodo.h"


using namespace std ;

////////////////////////////////////////////////////
///             Clase Book
////////////////////////////////////////////////////
class Book {
    /* *********************************************
    * La clase Book permite crear el objeto libro,
    * que mantiene la información de un libro.
    *
    * Ejemplo de uso:
    *
    * Book book = Book(ISBN, Titulo, Autor,
    *                 Año, Cantidad) ;
    *
    * En el ejemplo anterior se crea un nuevo libro.
    *
    * */

    // Puntero a Nodo para Registrar información
    Nodo *pdato ;
    // Parámetros de cada libro
    string isbnB ="", tituloB, autorB, yearB, cantidadB ;
public:
    Book() ;
    Book(string, string, string, string, string) ;
    /* =====================================================
        * Constructor con sobrecarga
        *
        * Entradas
        *        ISBN     : ISBN del libro
        *        Titulo   : Nombre del libro
        *        Autor    : Nombre del autor del libro
        *        Año      : Año de publicación del libro
        *        Cantidad : Cantidad de libros en Biblioteca
        * Salidas
        *        Instancia de la Clase Book
        * Restricciones
        *        Datos deben ser coherentes
    * ================================================ */

    void insertar(string, string, string, string, string) ;
    void mostrar() ;
    string buffering() ;
    string getIsbn() ;
    string getTitulo() ;
    string getAutor() ;
    string getYear() ;
    string getCantidad() ;
    string getEditor() ;
    string getRegion() ;

} ;

#endif // BOOK_H
 
