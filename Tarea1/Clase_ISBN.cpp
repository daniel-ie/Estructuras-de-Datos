#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>

using namespace std ;


class ISBN {
private:
    //int pref, reg, edit, elem, verif ;
    int sumP, sumI;
    string ss, ss1 ; //, temp ;
     // estructura para los parámetros
    struct ISBNparams{
        string dato, datoAll ;
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
        verificador10digitos() ;
        addVerificador() ;
        // AGREGAR EL VERIFICADOR A LA COLA DE LOS PARAMETROS
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
    }
    void printParams(){
        cout << "parametros en string " << endl ;
        for(int i=0; i<n; i++){
            cout << i << ". " << id[i].dato << endl ;
        }
        cout << "parametros en enteros " << endl ;
        for(int i=0; i<n; i++){
            cout << i << ". " << id[i].datoInt << endl ;
        }
    }
    string verificador10digitos(){
        int temp=0 ; string s_temp ;
        for(int i=0; i<nn-1; i++){            
            temp += id[i].datoAllInt*(i+1) ;    // obtiene digito por digito            
            cout << "temp1=" << temp << endl ;  //  id[i].datoAllInt << endl ;            
        }                                       // agregar condicion if(verif==10) verif=0 ;        
        cout << "Sumatoria para v10 = " << temp << endl ;
        temp %= 11 ;
        temp = temp!=10 ? temp : 0 ; // CONSULTAR QUE PASA CON DIGITO = 10
        s_temp = int2str(temp) ;
        cout << "Verificador de 10 digitos = " << s_temp << endl ;
        return s_temp ;
    }
    void addVerificador(){

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
/*int sumPares(int x){
        for(int i=0; i<str.length(); i++){
            if(i%2 == 0)
                sumP += str[i] - '0';
        }
    }
    void sumImpares(string str){
        for(int i=0; i<str.length(); i++){
            if(i%2 != 0)
                sumI += str[i] - '0' ;
        }
    }   
    void verificador13(){
        verif = 10 - (sumP*3+sumI)%10 ;
        cout << "verficador13=" << verif << endl ;
    }*/    
} ; 

int main()
{

    ISBN isbn = ISBN("6231") ;

    isbn ;
    //isbn.printParam() ;

    return 0 ;
}


    //ISBN<int> isbn13 = ISBN<int>(int pref, int reg, int edit, int elem, int verif) ;    // Constructor objeto year
    //ISBN<int> isbn10 = ISBN<int>(int reg, int edit, int elem, int verif) ;   // objeto autor       
    
    //ISBN<int> isbn = ISBN<int>(8, 399, 534, 397) ;
    //ISBN<int> isbn = ISBN<int>(1, 234, 56789) ;
        /*int pref, reg, edit, elem ;
        BookISBN(int p, int r, int e, int el){
            int pref=p, reg=r, edit=e, elem=el;
        }*/
        // sobrecargar la estructura 
        //Parametros(int r, int e, int el){
        //    int pref=p, reg=r, edit=e, elem=el ;
        //}
        //ss = s ;
        //int j, p, r, e, el ;
        //string bigS = bigString() ;
        //cout << "isbNum = " << bigS << endl ;

        //cout << p << endl ;
        //cout << r << endl ;
        //r = getParam(str) ;
        //e = getParam(str) ;
        //el = getParam(str) ;
        
        //ISBN<int> isbn = ISBN<int>(p, r, e, el) ;
        //ISBN<int> isbn = ISBN<int>(1, 234, 56789) ;             
    // ISBN 13 digitos
    /*ISBN(int p, int r, int e, int el){
        //pref = p ; reg = r ; edit = e ; elem = el ;
        string temp ;

        // llena el arreglo
        param = new Parametros ;
        param.pref = p ;
        param.reg = r ;
        param.edit = e ;
        param.elem = el ;

        temp += int2str(p) ;
        temp += int2str(r) ;        
        temp += int2str(e) ;
        temp += int2str(el) ;

        sum_Pares_Impares(temp) ;
        verificador13() ;
    }*/
    // ISBN 10 digitos
    /*ISBN(int r, int e, int el){
        reg = r ; edit = e ; elem = el ;
        string temp ;

        temp += int2str(r) ;
        temp += int2str(e) ;
        temp += int2str(el) ;

        verificador10(temp) ;
    }*/

    /*string bigString(){
        string temp ;
        for(int i=0; i<ss.length(); i++){
            if(ss[i] != '-' )
                temp += ss[i] ;
        }

        temp += int2str(pref) ;
        temp += int2str(reg) ;        
        temp += int2str(edit) ;
        temp += int2str(elem) ;

        return temp ;
    }*/
    /*
    void nextParam(){
    }*/

/*********** Metodos para obtener numero verificador  ***********/
    /*string int2str(int x){                
        stringstream convert ;
        int y = x ;
        convert << x ;      // convierte entero a string
        ss = convert.str() ;
        cout << "pref str = " << ss << endl ;
        ss1 += ss ;
        return ss1 ;
    }
    void sum_Pares_Impares(string str){
        cout << "str=" << str << endl ;
        for(int i=0; i<str.length(); i++){
            if(i%2 == 0)
                sumP += str[i] - '0';
            else
                sumI += str[i] - '0' ;
        }    
        cout << "pares=" << sumP << endl ;
        cout << "impares=" << sumI << endl ;
    }

    void sumPares(string str){
        for(int i=0; i<str.length(); i++){
            if(i%2 == 0)
                sumP += str[i] - '0';
        }
    }
    void sumImpares(string str){
        for(int i=0; i<str.length(); i++){
            if(i%2 != 0)
                sumI += str[i] - '0' ;
    }

    void verificador13(){               
        verif = 10 - (sumP*3+sumI)%10 ;        
        cout << "verficador13=" << verif << endl ;
    }
    void verificador10(){
        cout << "ss1= " << ss1 << endl ;
        int temp = 0 ;
        for(int i=0; i<ss1.length(); i++){            
            char c = ss1[i]-'0' ;
            temp += c*(i+1) ;            
        }        
        verif = temp ;    
        verif %= 11 ;   // agregar condicion if(verif==10) verif=0 ;
        cout << "New_verificador10=" << verif << endl ;        
    }
    int str2int(){
        stringstream convert ;
        int x ;
        convert.str(ss) ;
        convert >> x ;
        return x ;
    }*/
/*******************************************************************/
