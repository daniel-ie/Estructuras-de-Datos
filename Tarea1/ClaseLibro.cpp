#include <iostream>
#include <fstream>  // writer

using namespace std ;



class Nodo {
public:
    string isbn, titulo, autor, year, cantidad ;
    Nodo *siguiente ;

    Nodo(string isbnS, string tituloS, string autorS, string yearS, string cantidadS){
        isbn = isbnS ;
        titulo = tituloS ;
        autor = autorS ;
        year = yearS ;
        cantidad = cantidadS ;
        siguiente = NULL ;
    }
    Nodo(string isbnS, string tituloS, string autorS, string yearS, string cantidadS, Nodo *p){
        isbn = isbnS ;
        titulo = tituloS ;
        autor = autorS ;
        year = yearS ;
        cantidad = cantidadS ;
        siguiente = p ;
    }
} ;

class Book {
    Nodo *pdato ;
    string isbnB, tituloB, autorB, yearB, cantidadB ;
public:
    Book(){
        pdato = NULL ;
    }
    Book(string isbnS, string tituloS, string autorS, string yearS, string cantidadS){
        pdato = NULL ;   
        
        isbnB = isbnS ;
        tituloB = tituloS ;
        autorB = autorS ;
        yearB = yearS ;
        cantidadB = cantidadS ;  

        insertar(isbnS, tituloS, autorS, yearS, cantidadS) ;
        mostrar() ;
        //buffering() ;
    }
    void insertar(string s1, string s2, string s3, string s4, string s5){
        pdato = new Nodo(s1, s2, s3, s4, s5, pdato) ;
    }
    void mostrar(){
        cout << "Book = [" ;
        if(pdato){
            cout << pdato->isbn << ", " << pdato->titulo << ", " << pdato->autor << ", " << pdato->year << ", " << pdato->cantidad ;
            for(Nodo *q = pdato->siguiente; q; q=q->siguiente)
                cout << pdato->isbn << ", " << pdato->titulo << ", " << pdato->autor << ", " << pdato->year << ", " << pdato->cantidad ;
        }
        cout << "]\n" ;
    }
    string buffering(){
        string buffer ;
        buffer += isbnB ; buffer += " " ;
        buffer += tituloB ; buffer += " " ;
        buffer += autorB ; buffer += " " ;
        buffer += yearB ; buffer += " " ;
        buffer += cantidadB ; buffer += "\n" ;
        return buffer ; 
    }

} ;

class FileReader {
    const char *BD_file ;
    string buffer ;
public:
    FileReader(){
        BD_file = "text.txt" ;
        reader() ;
    } ;

    void writer(string s){
        string buffer = s ;
        ofstream BD(BD_file, ios_base::app) ;
        if(BD.is_open()){
            BD << buffer  ; //"Hola soberanos! Saludos y congratulaciones!" ;
            BD.close() ;
        }
        else
            cout << "Can't open file" << endl;    
    }
    void reader(){
            ifstream BD(BD_file) ;
            string line ;           
            if(BD.is_open()){
                while(getline(BD,line))
                    cout << line << endl ;
                BD.close();
            }
            else
                cout << "Can't open file" << endl ;
    }

} ;


int main()
{
    FileReader fr = FileReader() ;    
    Book book = Book() ;

    book = Book("0-534-37397-9", "Nombre del viento", "Patrick Rothfuss", "2007", "3") ;
    fr.writer(book.buffering()) ;
    
    book = Book("0-534-37398-9", "Fortaleza digital", "Dan Brown", "2001", "1") ;
    fr.writer(book.buffering()) ;
    
     
    return 0 ;
} 

    /*void borrar(string s){
        Nodo *temp = pdato ;
        if(pdato){
            for(Nodo *q = pdato->siguiente; q; q=q->siguiente){
                if(q->dato == s){
                    temp = q->siguiente ;
                    delete q ;
                }
            }
        }
        else
            cout << "Dato no encontrado\n" << endl ;        
    }*/

     /*int size(){
        int s = 0 ;
        for(Nodo<T> *q = pdato; q; q = q->siguiente)
            s += 1 ;
        return s ;
    }*/
