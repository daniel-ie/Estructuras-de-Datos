#include <iostream>
#include <string>
#include <vector>

using namespace std ;

template <class T, int Max=31>
class Stack{
private:
	std::vector<T> pool ;	
public:
	Stack(){
		pool.reserve(Max) ;
	}
	class Invalid{} ;

	bool is_valid(){
		if(isEmpty()){
			throw Invalid{} ;		
			return false ;
		}
		return true ;
	}
	void clear(){
		pool.clear() ;
	}
	int size(){
		return pool.size() ; 
	}
	bool isEmpty() const{
		return pool.empty() ;
	}
	T &top(){
		return pool.back() ;
	}
	T pop(){
		T data = pool.back() ;
		pool.pop_back() ;
		return data ;
	}
	void push(const T &data){
		pool.push_back(data) ;
	}

} ; 


int main(){
	Stack<string, 30> s = Stack<string, 30>() ;

	std::string str("()") ;

	try{
		for(unsigned i=0; i<str.length(); i++){
			if(str.at(i) == '(')
				s.push("(") ;
			else if(str.at(i) == ')' && s.is_valid()){
					s.pop() ;
			}

		}
		if(s.isEmpty())
			cout << "Secuencia de elemento está bien formada." << endl ;
		else
			cout << "Secuencia de elemento no esta bien formada." << endl ;
	}
	catch(Stack<string, 30>::Invalid){
		cout << "Secuencia de elemento no esta bien formada." << endl ;
	}
 
	return 0 ;
}
