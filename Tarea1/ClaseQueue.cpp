#include <iostream>

using namespace std ;


class Nodo {
public:
    Nodo *siguiente ;
    string isbn, user ;

    Nodo(string isbnS, string userS){
        isbn = isbnS ; user = userS ;
        siguiente = NULL ;
    }
    Nodo(string isbnS, string userS, Nodo *p){
        isbn = isbnS ; user = userS ;
        siguiente = p ;
    }
    Nodo *frente ;
    Nodo *final ;

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
		while(pdato != final){			// ESTE VIENE DE LA BD EN REALIDAD 
	   		pdato = pdato->siguiente ;
	   		if(pdato->isbn == isbnQ){ // revisa el stock
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


int main(){
	Queue queue = Queue() ;
	
	try{
		// SE HACE UN INSERT POR VEZ, EN ESE MOMENTO SE REVISA EL STOCK Y VERIFICA QUE HAYAN EXISTENCIAS
		queue.insert("16-241-54-000", "javier") ;		
		queue.mostrar() ;

	}
	catch(Queue::Invalid){
		cout << "cola vacia" << endl ;
	}
	return 0 ;
}

/*    void borrarCola(){
    	for(; frente != NULL;){
    		Nodo *p ;
    		p = frente ;
    		frente = frente->siguiente ;
    		delete p ;
    	}
    	final = NULL ;
    } */
