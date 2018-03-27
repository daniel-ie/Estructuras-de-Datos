#include "mstorage.h"
#include "book.h"

////////////////////////////////////////////////////
///             Clase MStorage
////////////////////////////////////////////////////
//MStorage::MStorage():Book(){}
string MStorage::parser(string buf){
    content = buf ;
    isbn = "" ; titulo = "" ; autor = "" ; year = "" ; cantidad = "" ;
    int i=0, j=0 ;

    for(i=0, j=0; i<buf.length(); i++){
        if(content[i] != ','){
            if(j == 0)
                isbn        += content[i] ; // +1 debido al espacio despues de la coma
            else if(j == 1)
                titulo      += content[i] ;
            else if(j == 2)
                autor       += content[i] ;
            else if(j == 3)
                year        += content[i] ;
            else if(j == 4)
                cantidad    += content[i] ;
        }
        else{
            if(content[i+1] == ' ')  // equivalente a: ', '
                i++ ;
            j++ ;
        }
        if(content[i+1] == '\n')
            break ;
    }
    size_t pos = buf.find('\n') ;
    string r = buf.erase(0, pos+1) ;
    return r ;
}
void MStorage::fillVector(vector<Book> &newMyStorage, string buffer){
    MStorage mStorage ;
    for(int i=0; buffer != ""; i++){
        buffer = mStorage.parser(buffer) ;
        if(buffer == "")
            break ;
        Book newBook(mStorage.getIsbnMS(), mStorage.getTituloMS(), mStorage.getAutorMS(), mStorage.getYearMS(), mStorage.getCantidadMS()) ;
        newMyStorage.push_back(newBook) ;
    }
}
void MStorage::getVector(vector<Book> &newMyStorage){
    size_t size = newMyStorage.size() ;
    for(int i=0; i<size; i++){
        cout << "Vector ==> [" ;
        cout << (newMyStorage.begin()+i)->Book::getIsbn()       << ", " ;
        cout << (newMyStorage.begin()+i)->Book::getTitulo()     << ", " ;
        cout << (newMyStorage.begin()+i)->Book::getAutor()      << ", " ;
        cout << (newMyStorage.begin()+i)->Book::getYear()       << ", " ;
        cout << (newMyStorage.begin()+i)->Book::getCantidad()   ;
        cout <<  "]" << endl ;
    }

}
string MStorage::getIsbnMS(){
    return isbn ;
}
string MStorage::getTituloMS(){
    return titulo ;
}
string MStorage::getAutorMS(){
    return autor ;
}
string MStorage::getYearMS(){
    return year ;
}
string MStorage::getCantidadMS(){
    return cantidad ;
}

/*void MStorage::setIsbn(string isbnM){isbn = isbnM ;}
void MStorage::setTitulo(string tituloM){titulo = tituloM ;}
void MStorage::setAutor(string autorM){autor = autorM ;}
void MStorage::setYear(string yearM){year = yearM ;}
void MStorage::setCantidad(string cantidadM){cantidad = cantidadM ;}*/
MStorage::~MStorage(){}
