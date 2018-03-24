#ifndef ISBN_H
#define ISBN_H

#include <iostream>
//#include <fstream>  // writer
#include <string>
#include <cstring>
#include <sstream>
#include <stdlib.h>
//#include <vector>


using namespace std ;

////////////////////////////////////////////////////
///             Clase ISBN
////////////////////////////////////////////////////
class ISBN {
private:
    //int pref, reg, edit, elem, verif ;
    int pr, pa, ed, sec, dv ;
    string isbnNoTolkens, isbnWithTolken ;
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

    string getIsbn() ;
    void loadParams() ;
    string untilToken(string &) ;
    void printParams() ;
    int sumPares(string) ;
    int sumImpares(string) ;
    string verif10digitos() ;
    string verif13digitos(int, int) ;
    string concatParams2str(int, int, int, int, int) ;
    string concatParams2str(int, int, int, int) ;
    string isbn2str(int, int, int, int, int) ;
    string isbn2str(int, int, int, int) ;
    int str2int(string) ;
    int str2int(char) ;
    string int2str(int) ;

} ;

#endif // ISBN_H
