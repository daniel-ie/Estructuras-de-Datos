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

using namespace std ;


int main(){

    vector<Book> myStorage ;

    FileReader fr = FileReader("/home/edgar_ie/Documents/text1.txt") ;			// ~~ load(archivo.txt)
    Book book = Book() ;
    MStorage mStorage = MStorage() ;
    Queue queue = Queue() ;
    ISBN isbn = ISBN() ;

/***************** Carga la BD ********************/	// ~~ save() && save(archivo.txt)
    string buffer = fr.getBuffer() ;
    mStorage.fillVector(myStorage, buffer) ;
    mStorage.getVector(myStorage) ;
/**************************************************/

/************ Creando objeto libro ****************/    // ~~ insert()
    isbn = ISBN("0-534-37397") ;
    book = Book(isbn.wholeIsbn(), "Nombre del viento", "Patrick Rothfuss", "2007", "3") ;
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

