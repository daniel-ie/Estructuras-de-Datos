#include <iostream>
#include <string>

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
public:
    /***** constructores *****/

    // ISBN 13 digitos
    /*ISBN<T>(int pref, int reg, int edit, int elem, int verif){
    }
    // ISBN 10 digitos
    ISBN<T>(int reg, int edit, int elem, int verif){
    }*/
    int sumP=0, sumI=0 ;
    ISBN<T>(){
    }

    void verificador13(int n){
        sum_Pares_Impares(n) ;        
        verif = 10 - (sumP*3+sumI)%10 ;        
        cout << "verficador=" << verif << endl ;
    }
    void verificador10(int n){
        int i, sum=0 ;
        for(i=9; n>0; i--){
            sum += i * (n%10) ;            
            n /= 10 ;               
        }    
        sum %= 11 ;
        //cout << "verif10=" << sum << endl ;
    }

    // Obtiene sumatoria de posiciones pares e impares del numero ingresado
    void sum_Pares_Impares(int n){        
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

} ;
 

int main()
{
    //ISBN<int> isbn13 = ISBN<int>(int pref, int reg, int edit, int elem, int verif) ;    // Constructor objeto year
    //ISBN<int> isbn10 = ISBN<int>(int reg, int edit, int elem, int verif) ;   // objeto autor       
    ISBN<int> isbn = ISBN<int>() ;

    isbn.verificador10(1111111111) ;// 102 revisar para v=10

    //cout << "suma = " << sum << endl ;
    
    return 0 ;
}
