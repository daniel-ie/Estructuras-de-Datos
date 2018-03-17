#include <iostream>
#include <fstream>  // writer
#include <string>
#include <sstream>
#include <stdlib.h>

using namespace std ;

 

class ISBN {
private:    
    int pref, reg, edit, elem, verif ;
    string ss ;
     // estructura para los parámetros
    struct ISBNparams{
        string dato, datoAllStr ;
        int datoInt, datoAllInt ;
    } ;
    // Arreglo para mantener los parametros disponibles
    ISBNparams *id ;

public:
    /***** constructores *****/
    int n;  // cantidad de parametros
    int nn; // cantidad de numeros entre todos los parametros

    ISBN(){
        id = NULL ;
    }

    ISBN(string s){
        id = NULL ;
        ss = s ;
        id = new ISBNparams[n] ;

        loadParams() ;
        printParams() ;

        // Revisa cual tipo de isb ha ingresado el usuario 
        if(s.length() > 11){    // 13 digitos
            int sumP = sumPares(id[0].datoAllStr) ;
            int sumI = sumImpares(id[0].datoAllStr) ;
            string verif13 = verificador13digitos(sumP, sumI) ;
            insertVerificador(verif13) ;
        }
        else{                   // 10 digitos
            string verif10 = verificador10digitos() ;
            insertVerificador(verif10) ;
        }            
        printParams() ;        
    }
    // ISBN 13 digitos
    ISBN(int p, int r, int e, int el){
        id = NULL ;
        pref = p ; reg = r ; edit = e ; elem = el ;

        id = new ISBNparams[n] ;

        string s ; 
        s = int2str(p) ;
        s += int2str(r) ;
        s += int2str(e) ;
        s += int2str(el) ;
        cout << "Parametros de isbn13 convertidos a un solo string = " << s << endl ;

        ss = s ;
        loadParams() ;
        printParams() ;        
            int sumP = sumPares(id[0].datoAllStr) ;
            int sumI = sumImpares(id[0].datoAllStr) ;
            string verif13 = verificador13digitos(sumP, sumI) ;
            insertVerificador(verif13) ;
        printParams() ;            
    }
    // ISBN 10 digitos
    ISBN(int r, int e, int el){
        id = NULL ;
        reg = r ; edit = e ; elem = el ;

        id = new ISBNparams[n] ;

        string s ;
        s += int2str(r) ;
        s += int2str(e) ;
        s += int2str(el) ;
        cout << "Parametros de isbn10 convertidos a un solo string = " << s << endl ;

        ss = s ;
        loadParams() ;
        printParams() ;        
            string verif10 = verificador10digitos() ;
            insertVerificador(verif10) ;
        printParams() ;            
    }

    void loadParams(){
        string temp, temp1 ;
        int k=0 ;
        for(int i=0, j=0; i<=ss.length(); i++){
            if(ss[i] == '-' || ss[i] == '\0'){                
                id[j].dato = temp ;             // load string version of params
                id[j].datoInt = str2int(temp) ; // load int version of params
                temp1 += temp ;                 // make a single string from params
                temp = "" ;
                j++ ;
            }
            else
                temp += ss[i] ;                         
            
            if(ss[i] != '-' || ss[i] == '\0'){
                char c = ss[i] ;
                id[k].datoAllInt = c - '0' ;    // load int by int                
                k++ ;
            }
            n = j ;
            nn = k ;
        }
        id[0].datoAllStr = temp1 ;              // load all params in one string
        cout << "Todos los parametros en un string = " << temp1 << endl << endl ;
    }
    void printParams(){
        cout << "Parametros concatenados en un solo string " << endl << "\t> " ;
        cout << id[0].datoAllStr << endl ;
    }
    int sumPares(string str){
        int sumP = 0 ;
        for(int i=0; i<str.length(); i++){
            if(i%2 == 0)
                sumP += str[i] - '0';
        }
        return sumP ;
    }
    int sumImpares(string str){
        int sumI = 0 ;
        for(int i=0; i<str.length(); i++){
            if(i%2 != 0)
                sumI += str[i] - '0' ;
        }
        return sumI ;
    }
    string verificador10digitos(){
        int temp=0 ; string s_temp ;
        for(int i=0; i<nn-1; i++){            
            temp += id[i].datoAllInt*(i+1) ;  // escala digito por digito
        }        
        temp %= 11 ;
        temp = temp!=10 ? temp : 1 ; // CONSULTAR QUE PASA CON DIGITO = 10
        verif = temp ;                        // actualiza la variable global verif
        s_temp = int2str(temp) ;
        cout << "Verificador de 10 digitos = " << s_temp << endl ;
        return s_temp ;
    }    
    string verificador13digitos(int pares, int impares){
        int temp = 10 - (pares+impares*3)%10 ;
        temp = temp!=10 ? temp : 1 ; // CONSULTAR QUE PASA CON DIGITO = 10
        cout << "Verficador para tipo 13 digitos = " << temp << endl ;
        verif = temp ;                        // actualiza la variable global verif
        string verif13 = int2str(temp) ;
        return verif13 ;
    }
    void insertVerificador(string s){
        char c = s[0] ;
        int x = str2int(s) ;
        id[n].dato = s ;
        id[n].datoInt = x ;
        id[nn].datoAllInt = c - '0' ;
        id[0].datoAllStr += s ;
        n +=1 ;
        //nn += 1 ;
    }
    int str2int(string s){
        stringstream convert ;
        int x ;
        convert.str(s) ;
        convert >> x ;
        return x ;
    }
    string int2str(int x){                
        stringstream convert ;
        string s ;
        convert << x ;      // convierte entero a string
        s = convert.str() ;
        return s ;
    }

} ; 
 

class Nodo {
public:
    string isbn, titulo, autor, year, cantidad ;
    string user ;
    Nodo *siguiente ;

    Nodo(string isbnS, string userS){
        isbn = isbnS ; user = userS ;
        siguiente = NULL ;
    }
    Nodo(string isbnS, string userS, Nodo *p){
        isbn = isbnS ; user = userS ;
        siguiente = p ;
    }

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
    
    Nodo *frente ;
    Nodo *final ;

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
        BD_file = "text1.txt" ;
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

class Queue {
    Nodo *pdato ; 
    Nodo *frente ; 
    Nodo *final ;
    string isbnQ, userQ ;
public:
    class Invalid{} ;

    Queue(){
        pdato = NULL ;
        frente = NULL ;
        final = NULL ;
    }
    Queue(string isbnS, string userS){
        pdato = NULL ;
        frente = NULL ;
        final = NULL ;

        isbnQ = isbnS ;
        userQ = userS ;

        //stock() ;
//        insert() ; //isbnQ, userQ) ;
        //mostrar() ;
    }

    void insert(string s1, string s2){
        isbnQ = s1 ;
        userQ = s2 ;

        pdato = new Nodo(isbnQ, userQ, pdato) ;
        pdato->isbn = isbnQ ; pdato->user = userQ ;
        if(final == NULL){
            final = pdato ;
            pdato->siguiente = final ;
        }
        else{
            pdato->siguiente = final->siguiente ;
            final->siguiente = pdato ;
            final = pdato ;
        }
    }
    void mostrar(){ // será el comando queue        
        if(final == NULL){
            cout << "list is empty" << endl  ;
            return ;
        }       
        string stockResult = stock() ;
        pdato = final->siguiente ;
         
        cout << "ISBN     " << string(15, ' ') ; 
        cout << "Usuario  " << string(15, ' ') ; 
        cout << "Resultado" << string(15, ' ') ; 
        cout << endl ;
        while(pdato != final){
            cout << pdato->isbn << string(24-pdato->isbn.length(), ' ') ;  // espaceo ct
            cout << pdato->user << string(24-pdato->user.length(), ' ') ;
            cout << stockResult ;
            cout << endl ;
            pdato = pdato->siguiente ;
        }
        cout << pdato->isbn << string(24-pdato->isbn.length(), ' ') ;
        cout << pdato->user << string(24-pdato->user.length(), ' ') ;
        cout << stockResult ;
        cout << endl ;
        
    }
    string stock(){     
        // cada vez que se hace solicitud de libro debe entrar a resultado y revisar si en la lista hace match con isbn
        int ejemplares = 0 ;
        string r ;
        pdato = final->siguiente ;
        while(pdato != final){          // ESTE VIENE DE LA BD EN REALIDAD 
            pdato = pdato->siguiente ;
            if(pdato->isbn == isbnQ){   // revisa el stock
                ejemplares++ ; 
            }   
        }
        // ***EDITAR: 0 CORRESPONDE AL NUMERO DE LIBROS DISPONIBLES QUE SE OBTINEE DE LA BD (.txt)
        if(ejemplares > 1)
            r = "Asignado" ;
        else
            r = "No asignado" ;
        return r ;
    }

} ; 


int main()
{ 
    FileReader fr = FileReader() ;
    Book book = Book() ;
    Queue queue = Queue() ;
    ISBN isbn = ISBN() ;
    isbn = ISBN("978-84-8181-227") ;
    
    queue.insert("16-241-54-000", "javier") ;       
    queue.mostrar() ;

    book = Book("0-534-37397-9", "Nombre del viento", "Patrick Rothfuss", "2007", "3") ;
    fr.writer(book.buffering()) ;
       

    return 0 ;
} 
