#include "isbn.h"

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
//
