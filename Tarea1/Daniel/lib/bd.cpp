#include <iostream>
#include <fstream>  // writer
#include <string>
#include <cstring>
#include <sstream>
#include <stdlib.h>
#include <vector>

#include "bd.h"


////////////////////////////////////////////////////
///             Clase Nodo
////////////////////////////////////////////////////
/*--------------------------- Sobrecarga para  Clase Queue ----------------------------------------------*/
Nodo::Nodo(string isbn, string user){
    this->isbn = isbn ; this->user = user ;
    siguiente = NULL ;
}
Nodo::Nodo(string isbn, string user, Nodo *p){
    this->isbn = isbn ; this->user = user ;
    siguiente = p ;
}
/*---------------------------- Sobrecarga para  Clase Book ----------------------------------------------*/
Nodo::Nodo(string isbn, string titulo, string autor, string year, string cantidad){
    this->isbn = isbn ;
    this->titulo = titulo ;
    this->autor = autor ;
    this->year = year ;
    this->cantidad = cantidad ;
    siguiente = NULL ;
}
Nodo::Nodo(string isbn, string titulo, string autor, string year, string cantidad, Nodo *p){
    this->isbn = isbn ;
    this->titulo = titulo ;
    this->autor = autor ;
    this->year = year ;
    this->cantidad = cantidad ;
    siguiente = p ;
}

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
        Book newBook(mStorage.getIsbn(), mStorage.getTitulo(), mStorage.getAutor(), mStorage.getYear(), mStorage.getCantidad()) ;
        newMyStorage.push_back(newBook) ;
    }
}
void MStorage::getVector(vector<Book> &newMyStorage){
    unsigned int size = newMyStorage.size() ;
    for(unsigned int i=0; i<4; i++){
        cout << "V ==> ISBN = [" << newMyStorage[i].getIsbn() << ", " << newMyStorage[i].getTitulo() << "]" << endl ;
    }
}
string MStorage::getIsbn(){
    return isbn ;
}
string MStorage::getTitulo(){
    return titulo ;
}
string MStorage::getAutor(){
    return autor ;
}
string MStorage::getYear(){
    return year ;
}
string MStorage::getCantidad(){
    return cantidad ;
}

void MStorage::setIsbn(string isbnM){isbn = isbnM ;}
void MStorage::setTitulo(string tituloM){titulo = tituloM ;}
void MStorage::setAutor(string autorM){autor = autorM ;}
void MStorage::setYear(string yearM){year = yearM ;}
void MStorage::setCantidad(string cantidadM){cantidad = cantidadM ;}
MStorage::~MStorage(){}


////////////////////////////////////////////////////
///             Clase FileReader
////////////////////////////////////////////////////
FileReader::FileReader(const char *file){
    BD_file = file ;
}
void FileReader::writer(string s){
    string buffer = s ;
    ofstream BD(BD_file, ios_base::app) ;
    if(BD.is_open()){
        BD << buffer  ; //"Hola soberanos! Saludos y congratulaciones!" ;
        BD.close() ;
    }
    else
        cout << "Can't open file" << endl;
}

void FileReader::reader(){
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
string FileReader::getBuffer(){
        ifstream BD(BD_file)  ;
        string buffer, line   ;
        if(BD.is_open()){
            while(getline(BD, line)){
                buffer += line ;
                buffer += "\n" ;
            }
            BD.close() ;
        }
        else
            cout << "Can't open file" << endl ;
    return buffer ;
}


////////////////////////////////////////////////////
///             Clase Queue
////////////////////////////////////////////////////
//Queue::Invalid{} ;
Queue::Queue():MStorage(){
    pdato = NULL ;
    frente = NULL ;
    final = NULL ;
}
Queue::Queue(string isbnQ, string userQ):MStorage(){
    pdato = NULL ;
    frente = NULL ;
    final = NULL ;
    this->isbnQ = isbnQ ;
    this->userQ = userQ ;

    //stock() ;
    insert(isbnQ, userQ) ; //isbnQ, userQ) ;
    //inStock() ;
    //mostrar() ;
}

void Queue::insert(string isbnQ, string userQ){
    this->isbnQ = isbnQ ;
    this->userQ = userQ ;

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
    //inStock() ;
}
void Queue::mostrar(int stockCant){ // será el comando queue
    if(final == NULL){
        cout << "list is empty" << endl  ;
        return ;
    }

    string stockResult ;
    if(stockCant>0)
        stockResult = "Asignado" ;
    else
        stockResult = "No asignado" ;

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
int Queue::inStock(vector<Book> &newMyStorage){
    int cant = 0 ;
    unsigned int size = newMyStorage.size() ;
    for(unsigned int i=0; i<size; i++){
        if(newMyStorage[i].getIsbn() == isbnQ)  // revisa si el libro esta en existencias
            cant += 1 ;
    }
    return cant ;
}

////////////////////////////////////////////////////
///             Clase ISBN
////////////////////////////////////////////////////
ISBN::ISBN(){
        id = NULL ;
}
ISBN::ISBN(string s){
        id = new ISBNparams[n] ;
        isbnWithTolken = s ;
        string tira = isbnWithTolken ;
        int dvCopy ;

        // Revisa cual tipo de isbn ha ingresado el usuario
        if(s.length() > 13){                               // 13 digitos
            // Setear los parametros en enteros  //loadParams() ;
            pr    = str2int(untilToken(tira)) ;
            pa    = str2int(untilToken(tira)) ;
            ed    = str2int(untilToken(tira)) ;
            sec   = str2int(untilToken(tira)) ;
            dv    = str2int(untilToken(tira)) ; dvCopy = dv ;

            isbnWithTolken = isbn2str(pr, pa, ed, sec, dv) ;
            // Genera un isbn sin tokens para operarlo
            isbnNoTolkens = concatParams2str(pr, pa, ed, sec, dv) ;
            int sumP = sumPares(isbnNoTolkens) ;
            int sumI = sumImpares(isbnNoTolkens) ;
            string verif13 = verif13digitos(sumP, sumI) ;            
            if(str2int(verif13) != dvCopy)
                cout << "Enviar error de digito verificador!!!!!!!!" << endl ;
        }
        else{                                             // 10 digitos
            // Setear los parametros en enteros  //loadParams() ;
            pa    = str2int(untilToken(tira)) ;
            ed    = str2int(untilToken(tira)) ;
            sec   = str2int(untilToken(tira)) ;
            dv    = str2int(untilToken(tira)) ; dvCopy = dv ;
            isbnWithTolken = isbn2str(pa, ed, sec, dv);
            // Genera un isbn sin tokens para operarlo
            isbnNoTolkens = concatParams2str(pa, ed, sec, dv) ;
            string verif10 = verif10digitos() ;
            if(str2int(verif10) != dvCopy)
                cout << "Enviar error de digito verificador!!!!!!" << endl ;
        }
        printParams() ;
}
    // ISBN 13 digitos
ISBN::ISBN(int pr, int pa, int ed, int sec, int dv){
        id = new ISBNparams[n] ;
        int dvCopy ;
        this->pr    = pr ;
        this->pa    = pa ;
        this->ed    = ed ;
        this->sec   = sec ;
        this->dv    = dv ;  dvCopy = dv ;

        isbnWithTolken = isbn2str(pr, pa, ed, sec, dv);
        string isbnNoTolkens = concatParams2str(pr, pa, ed, sec, dv) ;
        this->isbnNoTolkens = isbnNoTolkens ;
        int sumP = sumPares(isbnNoTolkens) ;
        int sumI = sumImpares(isbnNoTolkens) ;
        string verif13 = verif13digitos(sumP, sumI) ;
        if(str2int(verif13) != dvCopy)
            cout << "Enviar error de digito verificador" << endl ;
}
    // ISBN 10 digitos
ISBN::ISBN(int pa, int ed, int sec, int dv){
        id = new ISBNparams[n] ;
        int dvCopy ;
        this->pa = pa ;
        this->ed = ed ;
        this->sec = sec ;
        this->dv = dv ; dvCopy = dv ;

        isbnWithTolken = isbn2str(pa, ed, sec, dv);
        // Genera un isbn sin tokens para operarlo
        isbnNoTolkens = concatParams2str(pa, ed, sec, dv) ;
        string verif10 = verif10digitos() ;
        if(str2int(verif10) != dvCopy)
            cout << "Enviar error de digito verificador!!!!!!" << endl ;
}
void ISBN::loadParams(){
    string tira = isbnWithTolken ;
    // Pasa a entero los valores de los parametros del isbn
    pr    = str2int(untilToken(tira)) ;
    pa    = str2int(untilToken(tira)) ;
    ed    = str2int(untilToken(tira)) ;
    sec   = str2int(untilToken(tira)) ;
    dv    = str2int(untilToken(tira)) ;
}
string ISBN::untilToken(string &tira){
    string tilT = "", temp ;
    int i ;
    for(i=0; i<tira.length() && tira[i]!='-' && tira[i]!=' '; i++){ // get first token
        tilT += tira[i] ;
    }
    for(; i<tira.length(); i++){ // Clean tira from first token
            temp += tira [i+1] ;
    }
    tira = temp ;
    return tilT ;
}

string ISBN::verif10digitos(){
    int temp=0 ; string s_temp ;
    string aux = isbnNoTolkens ;
    int digit = 0 ;
    for(int i=0, j=10 ; i<isbnNoTolkens.length(); i++, j--){
        digit = ISBN::str2int(aux[i]) ;  //cout << "DigitX = " << digit*j << endl ;
        temp += digit*j ;                // escala digito por digito
    }
    temp %= 11 ;
    temp = 11 - temp ;
    temp = (temp!=10) ? temp:1 ;
    dv = temp ;                        // actualiza la variable global verif
    s_temp = int2str(temp) ;
    cout << "Verificador de 10 digitos = " << s_temp << endl ;
    return s_temp ;
}
string ISBN::verif13digitos(int pares, int impares){
    int temp = 10 - (pares+impares*3)%10 ;
    temp = (temp!=10) ? temp:1 ;
    cout << "Verficador para tipo 13 digitos = " << temp << endl ;
    dv = temp ;                        // actualiza la variable global verif
    string verif13 = int2str(temp) ;
    return verif13 ;
}
int ISBN::sumPares(string str){
    int sumP = 0 ;
    for(int i=0; i<str.length(); i++){
        if(i%2 == 0)
            sumP += str[i] - '0';
    }
    return sumP ;
}
int ISBN::sumImpares(string str){
    int sumI = 0 ;
    for(int i=0; i<str.length(); i++){
        if(i%2 != 0)
            sumI += str[i] - '0' ;
    }
    return sumI ;
}
string ISBN::getIsbn(){
    return isbnWithTolken ;
}
string ISBN::isbn2str(int pr, int pa, int ed, int sec, int dv){
    string s ;
    s  = ISBN::int2str(pr)  ; s += '-' ;
    s += ISBN::int2str(pa)  ; s += '-' ;
    s += ISBN::int2str(ed)  ; s += '-' ;
    s += ISBN::int2str(sec) ; s += '-' ;
    s += ISBN::int2str(dv) ; // Se concatenan los parametros en un solo string
    return s ;
}
string ISBN::isbn2str(int pa, int ed, int sec, int dv){
    string s ;
    s  = ISBN::int2str(0)   ; s += '-' ;
    s += ISBN::int2str(pa)  ; s += '-' ;
    s += ISBN::int2str(ed)  ; s += '-' ;
    s += ISBN::int2str(sec) ; s += '-' ;
    s += ISBN::int2str(dv) ; // Se concatenan los parametros en un solo string
    return s ;
}
string ISBN::concatParams2str(int pr, int pa, int ed, int sec, int dv){
    string s ;
    s  = ISBN::int2str(pr)  ;
    s += ISBN::int2str(pa)  ;
    s += ISBN::int2str(ed)  ;
    s += ISBN::int2str(sec) ;
    //s += ISBN::int2str(dv) ; // Se concatenan los parametros en un solo string
    return s ;
}
string ISBN::concatParams2str(int pa, int ed, int sec, int dv){
    string s ;
    s += ISBN::int2str(pa)  ;
    s += ISBN::int2str(ed)  ;
    s += ISBN::int2str(sec) ;
    //s += ISBN::int2str(dv) ; // Se concatenan los parametros en un solo string
    return s ;
}
int ISBN::str2int(string s){
    stringstream convert ;
    int x ;
    convert.str(s) ;
    convert >> x ;
    return x ;
}
int ISBN::str2int(char c){
    stringstream convert, isbnWithTolken ;
    string target ;
    isbnWithTolken << c ;
    isbnWithTolken >> target ;

    int x ;
    convert.str(target) ;
    convert >> x ;
    return x ;
}
string ISBN::int2str(int x){
    stringstream convert ;
    string s ;
    convert << x ;      // convierte entero a string
    s = convert.str() ;
    return s ;
}

void ISBN::printParams(){
    cout << "Parametros concatenados en un solo string " << endl << "\t> " ;
    cout << isbnNoTolkens << endl ;
}
