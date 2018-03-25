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

#include <iostream>
#include <fstream>  // writer
#include <string>
#include <cstring>
#include <sstream>
#include <stdlib.h>
#include <vector>

/*#include "ISBNRef.h"
#include "Nodo1.h"
#include "Index.h"
#include "IndexVal.h"*/

#include "bd.h"
#include "isbn.h"
#include "nodo.h"
#include "book.h"
#include "queue.h"
#include "filereader.h"
#include "filewriter.h"

using namespace std ;


int main(){
    vector<Book> myStorage ;
    //FileWriter<MStorage> mymStorage ;

    FileReader fr = FileReader("/home/edgar_ie/Documents/text1.txt") ;			// ~~ load(archivo.txt)
    Book book = Book() ;
    MStorage mStorage = MStorage() ;
    Queue queue = Queue() ;
    ISBN isbn = ISBN() ;
    FileWriter fw = FileWriter("/home/edgar_ie/Documents/text2.txt") ;

/***************** Carga la BD ********************/	// ~~ save() && save(archivo.txt)
    string buffer = fr.getBuffer() ;
    mStorage.fillVector(myStorage, buffer) ;
    mStorage.getVector(myStorage) ;
/**************************************************/

/************ Creando objeto libro ****************/    // ~~ insert()
    isbn = ISBN("0-19-852663-6") ;
    book = Book(isbn.getIsbn(), "Nombre del viento", "Patrick Rothfuss", "2007", "3") ;
    book = Book(isbn.getIsbn(), "Nombre del viento", "Patrick Rothfuss", "2007", "3") ;
/**************************************************/

/********* Retornar el siguiente libro ************/    // ~~
    fr.getBuffer() ;

    string book1 = fr.next() ;
    mStorage.parser(book1)   ;
    book = Book(mStorage.getIsbnMS(), mStorage.getTituloMS(), mStorage.getAutorMS(), mStorage.getYearMS(), mStorage.getCantidadMS()) ;

    book1 = fr.next() ;
    mStorage.parser(book1) ;
    fw.fwriter(book1) ;
    book = Book(mStorage.getIsbnMS(), mStorage.getTituloMS(), mStorage.getAutorMS(), mStorage.getYearMS(), mStorage.getCantidadMS()) ;

    bool empty = fw.empty() ; // Revisa si BD esta vacia
    cout << "Base de Datos esta vacia?: " << empty << endl ;

    FileWriter fw1 = FileWriter("/home/edgar_ie/Documents/text2.txt", mStorage) ;
    //cout << "FileWriter = " << fw.mStorage.getAutorMS() ; //mStorage.getAutorMS() << endl ;
/**************************************************/

/*** Cola que maneja las solicitudes de libros ****/	// ~~ get(isbn, usuario) && back(isbn)
    string queue_isbn = "1-534-37397-9" ;
    string queue_user = "Fallas" ;

    queue.insert(queue_isbn, queue_user) ; //solicitud
    int stock = queue.inStock(myStorage) ;
    queue.mostrar(stock) ;								// ~~ pqueue()
/*************************************************/


    return	0 ;
}

// Algunos isbn's : "978-84-481-5645-7", "0-19-852663-6", "978-84-481-5645-7"
// hay un bug para isbn=0-545-01022-5
//
