#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>

using namespace std ;

template <class T>
class Nodo {
public:
    T dato ;
    Nodo *siguiente ;

    Nodo(T x){
        dato = x ;
        siguiente = NULL ;
    }
    Nodo(T x, Nodo *p){
        dato = x ;
        siguiente = p ;
    }
} ;

template <class T>  
class ISBN {
private:
    int pref, reg, edit, elem, verif ;    
    int sumP=0, sumI=0 ;
    string ss, ss1 ; //, ss13, ss10 ;
public:
    /***** constructores *****/
    
    // ISBN 13 digitos
    ISBN<T>(int p, int r, int e, int el){
        pref = p ; reg = r ; edit = e ; elem = el ; // toOneInt
        int2str(p) ;
        int2str(r) ;        
        int2str(e) ;
        int2str(el) ;

        sum_Pares_Impares() ;
        verificador13() ;
    }
    // ISBN 10 digitos
    ISBN<T>(int r, int e, int el){
        reg = r ; edit = e ; elem = el ;
        int2str(r) ;
        int2str(e) ;
        int2str(el) ;

        verificador10() ;
    }
    /*void toOneInt(int x1, int x2, int x3, int x4){
        int x = x1*
    }*/

    void int2str(int x){                
        stringstream convert ;
        int y = x ;
        convert << x ;      // convierte entero a string
        ss = convert.str() ;
        cout << "pref str = " << ss << endl ;
        ss1 += ss ;
    }
    void sum_Pares_Impares(){
        cout << "ss1=" << ss1 << endl ;
        for(int i=0; i<ss1.length(); i++){
            if(i%2 == 0)
                sumP += ss1[i] - '0';
            else
                sumI += ss1[i] - '0' ; // esta agarrando null
        }    
        cout << "pares=" << sumP << endl ;
        cout << "impares=" << sumI << endl ;
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
    /*int str2int(string s){
        stringstream convert ;
        int x ;
        convert.str(s) ;
        convert >> x ;
        return x ;
    }*/ 

} ;


int main()
{
    //ISBN<int> isbn13 = ISBN<int>(int pref, int reg, int edit, int elem, int verif) ;    // Constructor objeto year
    //ISBN<int> isbn10 = ISBN<int>(int reg, int edit, int elem, int verif) ;   // objeto autor       
    
    //ISBN<int> isbn = ISBN<int>(8, 399, 534, 397) ;
    ISBN<int> isbn = ISBN<int>(1, 234, 56789) ;

    isbn ;

    return 0 ;
}




    /*
    void sum...
        int i ;
        for(i=0; n>0; i++){
            if(i%2 == 0)
                sumP += n%10 ;
            else
                sumI += n%10 ; 
            n /= 10 ;
        }
        if(i%2 == 0) // ajusta si el length del int es impar
            intercambie(sumP, sumI) ; 
    }
    void intercambie(int &var1, int &var2){
        int temp = var1 ;
        var1 = var2 ;
        var2 = temp ;
    }


    void verificador10(){        
        int i, verif=0 ;
        for(i=9; n>0; i--){
            verif += i * (n%10) ;            
            n /= 10 ;               
        }
        verif %= 11 ;
        cout << "verificador10=" << verif << endl ;
    }    
    int getOneInt10(){
        n = reg*100000000 + edit*100000 + elem*1 ;    
        cout << "getOneInt10=" << n << endl ;        
        return n ;
    }
    int getOneInt13(){
        n = pref*1000000000 + reg*100000000 + edit*100000 + elem*1 ;
        cout << "getOneInt13=" << n << endl ;        
        return n ;
    }*/   
