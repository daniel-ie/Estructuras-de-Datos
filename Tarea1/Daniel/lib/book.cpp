#include "book.h"

////////////////////////////////////////////////////
///             Clase Book
////////////////////////////////////////////////////
Book::Book(){
    pdato = NULL ;
}
Book::Book(string isbnB, string tituloB, string autorB, string yearB, string cantidadB){
    pdato = NULL ;
    this->isbnB       = isbnB ;
    this->tituloB     = tituloB ;
    this->autorB      = autorB ;
    this->yearB       = yearB ;
    this->cantidadB   = cantidadB ;
    insertar(isbnB, tituloB, autorB, yearB, cantidadB) ;
    mostrar() ;
}
void Book::insertar(string isbnB, string tituloB, string autorB, string yearB, string cantidadB){
    pdato = new Nodo(isbnB, tituloB, autorB, yearB, cantidadB, pdato) ;
}
void Book::mostrar(){
    cout << "Book = [" ;
    if(pdato){
        cout << pdato->isbn     << ", " ;
        cout << pdato->titulo   << ", " ;
        cout << pdato->autor    << ", " ;
        cout << pdato->year     << ", " ;
        cout << pdato->cantidad ;
        for(Nodo *q = pdato->siguiente; q; q=q->siguiente){
            cout << pdato->isbn     << ", " ;
            cout << pdato->titulo   << ", " ;
            cout << pdato->autor    << ", " ;
            cout << pdato->year     << ", " ;
            cout << pdato->cantidad ;
        }
    }
    cout << "]\n" ;
}
string Book::buffering(){
    string buffer ;
    buffer += isbnB     ;   buffer += " " ;
    buffer += tituloB   ;   buffer += " " ;
    buffer += autorB    ;   buffer += " " ;
    buffer += yearB     ;   buffer += " " ;
    buffer += cantidadB ;   buffer += "\n" ;
    return buffer ;
}
string Book::getIsbn(){
    return pdato->isbn ;
}
string Book::getTitulo(){
    return pdato->titulo ;
}
string Book::getAutor(){
    return  pdato->autor;
}
string Book::getYear(){
    return  pdato->year;
}
string Book::getCantidad(){
    return  pdato->cantidad ;
}
string Book::getEditor(){
    return  "Editor_Test_Data";//pdato->autor;
}
string Book::getRegion(){
    return  "Region_Test_Data";//pdato->autor;
}
