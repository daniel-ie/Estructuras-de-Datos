/*
******************************************************
* Instituto Tecnológico de Costa Rica.
* Ingeniería en Computación
* Curso     : IC-2001 Grupo 2
* Proyecto  : BD.pro
* Archivo   : bd.h
* Autor     : Edgar Daniel Chaves
* Carnet    : 2013095110
* Fecha     : 21 de Marzo de 2018
*
======================== Contenido ==================
*
* Mantiene al definición e implementación de las
* siguientes clases:
* >> Nodo
* >> Book
* >> MStorage
* >> FileReader
* >> Pqueue
* >> ISBN
*
*/


#ifndef BD_H
#define BD_H

#include <iostream>
#include <fstream>  // writer
#include <string>
#include <cstring>
#include <sstream>
#include <stdlib.h>
#include <vector>
#include "bd.h"

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

////////////////////////////////////////////////////
///             Clase MStorage
////////////////////////////////////////////////////
class MStorage:public Book {
    string isbn, titulo, autor, year, cantidad, content ;
public:
    MStorage():Book(){}
    string parser(string) ;
    void fillVector(vector<Book> &, string) ;
    void getVector(vector<Book> &) ;

    string getIsbn() ;
    string getTitulo() ;
    string getAutor() ;
    string getYear() ;
    string getCantidad() ;

    void setIsbn(string) ;
    void setTitulo(string) ;
    void setAutor(string) ;
    void setYear(string) ;
    void setCantidad(string) ;

    ~MStorage() ;

} ;

////////////////////////////////////////////////////
///             Clase FileReader
////////////////////////////////////////////////////
class FileReader {
private:
    const char *BD_file ;
    string isbn, titulo, autor, year, cantidad, content ;
    string buffer ;
public:
    FileReader(const char *) ;
    void writer(string) ;
    void reader() ;
    string getBuffer() ;

} ;

////////////////////////////////////////////////////
///             Clase Queue
////////////////////////////////////////////////////
class Queue:public MStorage{
    Nodo *pdato ;
    Nodo *frente ;
    Nodo *final ;
    string isbnQ, userQ ;
public:
    class Invalid{} ;

    //Queue():MStorage(){}
    //Queue(string, string):MStorage(){}
    Queue() ;
    Queue(string, string) ;
    void insert(string, string) ;
    void mostrar(int) ;
    int inStock(vector<Book> &) ;

} ;

////////////////////////////////////////////////////
///             Clase ISBN
////////////////////////////////////////////////////
class ISBN {
private:
    //int pref, reg, edit, elem, verif ;
    int pr, pa, ed, sec, dv ;
    string ss="", isbnInit, fullIsbn ;
    // estructura para los parámetros
    struct ISBNparams{
        string dato, datoAllStr ;
        int datoInt, datoAllInt ;
    } ;
    // Arreglo para mantener los parametros disponibles
    ISBNparams *id ;

public:
    ////////  constructores ///////
    int n=5;  // cantidad de parametros
    int nn; // cantidad de numeros entre todos los parametros

    ISBN() ;
    ISBN(string) ;    
    ISBN(int, int, int, int, int) ; // ISBN 13 digitos
    ISBN(int, int, int, int) ;      // ISBN 10 digitos

    string wholeIsbn() ;
    string getFullIsbn(string) ;
    void loadParams() ;
    void printParams() ;
    int sumPares(string) ;
    int sumImpares(string) ;
    string verificador10digitos() ;
    string verificador13digitos(int, int) ;
    void insertVerificador(string) ;
    int str2int(string) ;
    string int2str(int) ;

} ;

#endif // BD_h

