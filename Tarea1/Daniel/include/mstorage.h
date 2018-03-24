#ifndef MSTORAGE_H
#define MSTORAGE_H

#include <iostream>
//#include <fstream>  // writer
#include <string>
#include <cstring>
#include <sstream>
#include <stdlib.h>

#include "mstorage.h"
#include "book.h"

using namespace std ;

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

    string getIsbnMS() ;
    string getTituloMS() ;
    string getAutorMS() ;
    string getYearMS() ;
    string getCantidadMS() ;

    /*void setIsbn(string) ;
    void setTitulo(string) ;
    void setAutor(string) ;
    void setYear(string) ;
    void setCantidad(string) ;*/

    ~MStorage() ;

} ;

#endif // MSTORAGE_H
