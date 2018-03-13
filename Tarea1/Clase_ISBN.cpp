#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>

using namespace std ;


class ISBN {
private:   
    bool isbn10 = false, isbn13 = false, forgetConstrStr = false ;
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

    ISBN(string s){
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

        /*cout << "parametros en string " << endl ;
        for(int i=0; i<n; i++){
            cout << i << ". " << id[i].dato << "_" << endl ;
        }
        cout << "parametros en enteros " << endl ;
        for(int i=0; i<n; i++){
            cout << i << ". " << id[i].datoInt << "_" << endl ;
        }
        cout << "parametros en enteros desagrupados " << endl << "\t> " ;
        for(int i=0; i<nn-1; i++)
            cout << id[i].datoAllInt << "_" ;*/
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


int main()
{
    //ISBN isbn = ISBN("978-84-481-5645") ;
    ISBN isbn = ISBN("978-84-8181-227") ;
    //ISBN isbn = ISBN("84-8181-227") ;
    //ISBN isbn = ISBN(1, 534, 37397, 9) ;   // 13 digitos
    //ISBN isbn = ISBN(534, 37397, 9) ;
    
    isbn ; 
    
    return 0 ;
}
