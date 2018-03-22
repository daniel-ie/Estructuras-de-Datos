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


///////////////// Nodo ////////////////////
class Nodo {
public:
    string isbn, titulo, autor, year, cantidad ;
    string user ;
    Nodo *siguiente ;
/*--------------------------- Sobrecarga para  Clase Queue ----------------------------------------------*/
    Nodo(string, string) ;
    Nodo(string, string, Nodo *) ;
    Nodo *frente ;
    Nodo *final ;
/*---------------------------- Sobrecarga para  Clase Book ----------------------------------------------*/
    Nodo(string, string, string, string, string) ;
    Nodo(string, string, string, string, string, Nodo *) ;
} ;

///////////////// Book ////////////////////
class Book {
    Nodo *pdato ;
    string isbnB ="", tituloB, autorB, yearB, cantidadB ;
public:
    Book() ;
    Book(string, string, string, string, string) ;
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

/////////////// MStorage //////////////////
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


/////////////// File Reader ///////////////////////
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

////////////////// Pqueue /////////////////////////
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

/////////////////// ISBN //////////////////////////
class ISBN {
private:
    int pref, reg, edit, elem, verif ;
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
    // ISBN 13 digitos
    ISBN(int p, int r, int e, int el) ;
    // ISBN 10 digitos
    ISBN(int r, int e, int el) ;

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

