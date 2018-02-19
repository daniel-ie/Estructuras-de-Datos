#include <iostream>

using namespace std ;

// Clase fecha
class Trabajador{
public:
    class Invalid{} ;

    Trabajador(int pot1, int pot2) ; // constructor

    // Prints parametrizados
    void llene(int a){
        cout << "Llene la olla de (" << a << ") litros.\n" ;
    }
    void llene_con(int a, int b){ // origen, destino
        if(b > 0)
            cout << "Llene la olla de (" << b << ") litros con la olla de (" << a << ") litros.\n" ;
        else // b=0 es la olla final
            cout << "Pase lo que tenga la olla de (" << a << ") litros a la olla final\n" ;
    }
    void bote(int a){
        cout << "Bote el contenido de la olla de (" << a << ") litros\n" ;
    }

private:
    int pot1, pot2 ;
    bool is_valid() ;
} ;

// Define la referencia para Trabajador()
Trabajador::Trabajador(int pot11, int pot22){
    pot1 = pot11 ;
    pot2 = pot22 ;
    if(!is_valid()) // chequea la validacion
        throw Invalid{} ;
}
bool Trabajador::is_valid(){ // condiones para validar
    if(pot1 < pot2) // valida que el pichel1 sea mas grande que pichel2
        return false ;
    else
        return true ;
}

// Funcion que llama la Clase y valida
void PotsWork(int liters){
    int pot1 = 11, pot2 = 5 ;
    try{
        Trabajador Pots {pot1, pot2} ;

        int i = 0, pot = 0, n = 0, toOne = 0 ;
        bool multiplo = false ;

/* ------- Calcula las iteraciones para llegar a 1 Litro ---------- */
        while(1){
            if(pot1-pot2*toOne == 1)
                break ;
            toOne++ ;
        }

/* ------------- Prioridad multiplo de algun pichel --------------- */
        if((liters % pot1) == 0){
            pot = pot1 ;
            n = liters/pot ;
            multiplo = true ;
        }
        else if((liters % pot2) == 0){
            pot = pot2 ;
            n = liters/pot ;
            multiplo = true ;
        }
/* ------------ Algoritmo para comandar instrucciones ------------- */
        if(multiplo == true){
            for(i=0; i<n; i++){
                Pots.llene(pot) ;
                Pots.llene_con(pot, 0) ;
            }
            cout << "\n" ;
        }

        if(multiplo == false){
            for(i=0; i<=pot1; i++){
                if((pot1-pot2*i) < liters){  // 6, 7 litros
                    // +BaseMayor
                    Pots.llene(pot1) ;
                    for(int f=0; f<(pot1-pot2*(i+1)); f++){
                        Pots.llene_con(pot1, pot2) ;
                        Pots.bote(pot2) ;
                    }
                    Pots.llene_con(pot1, 0) ;
                    cout << ", +" << pot1-pot2*i << "\n\n" ;

                    // +1 litros
                    for(int g=0; g<(liters-(pot1-pot2*i)); g++){
                        Pots.llene(pot1) ;
                        for(int h=0; h<toOne; h++){
                            Pots.llene_con(pot1, pot2) ;
                            Pots.bote(pot2) ;
                        }
                        Pots.llene_con(pot1, 0) ;
                        cout << ", +1 \n" ;
                    }
                    break ;
                }
                else if((pot1-pot2*i) == liters){  // 5 y 1 litros
                    Pots.llene(pot1) ;
                    for(int m=0; m<i; m++){
                        Pots.llene_con(pot1, pot2) ;
                        Pots.bote(pot2) ;
                    }
                    Pots.llene_con(pot1, 0) ;
                    cout << ", +" << pot1-pot2*i << "\n" ;
                    break ;
                }
            }
        }
/* ---------------------------------------------------------------- */

    }
    catch(Trabajador::Invalid){
        //error("Invalid date!") ;
        cout << "Invalid date \n" ;
    }
}

int main()
{
    // Funcion que llama la clase Trabajador
    PotsWork(7) ;

    return 0 ;
}
