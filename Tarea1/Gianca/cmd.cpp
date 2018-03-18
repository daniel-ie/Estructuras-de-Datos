#include <cstdlib>
#include <string>
#include <iostream>
#include <vector>
//Declaracion de la clase cmd junto a sus metodos y atributos
using namespace std;

enum tMando{load,save,insertar,borrar,limpiar,obtener,volver,index,ls,encolar,ordenar,log,salir};

string vToken[13]{"load","save","insert","delete","clear","get","back","index","ls","queue","sort","log","exit"};

template <class T>
class cmd{
public:
    T comand;
    tMando mandato;
    vector<T> cmdStack;
    int val;
    int loadC=0;
    int saveC=0;
    int insertC=0;
    int delC=0;
    int clearC=0;
    int getC=0;
    int backC=0;
    int indexC=0;
    int lsC=0;
    int queueC=0;
    int sortC=0;
    int logC=0;
    int exitC=0;

    static bool todosDigitos(string s){
        unsigned int i=0;
        bool ok= true;
        while(i< s.length() && ok){
            ok = s[i] >= '0' && s[i] <='9';
            i++;
        }
        return ok;
    }
    cmd(string s){
        if(s.length()>0 && todosDigitos(s)){
            mandato = salir;
            exitC++;
            val= s;

        }
        else{
            if(s.length()==1){
                switch(s[0]){
                case "load":
                    mandato= load;
                    loadC++;
                break;
                case "save":
                    mandato= save;
                    saveC++;
                break;
                case "insert":
                    mandato= insertar;
                    insertC++;
                break;
                case "delete":
                    mandato= borrar;
                    delC++;
                break;
                case "clear":
                    mandato= limpiar;
                    clearC++;
                break;
                case "get":
                    mandato= obtener;
                    getC++;
                break;
                case "back":
                    mandato= volver;
                    backC++;
                break;
                case "index":
                    mandato= index;
                    indexC++;
                break;
                case "ls":
                    mandato=ls;
                    lsC++;
                break;
                case "queue":
                    mandato= encolar;
                    queueC++;
                break;
                case "sort":
                    mandato=ordenar;
                    sortC++;
                break;
                case "log":
                    mandato= log;
                    logC++;
                break;
                case "exit":
                    mandato= salir;
                    exitC++;
                break;
                }
            }
        }
    }
    //Esta funcion agrega un objeto de tipo cmd al vector, debe ser llamada en el main
    void cargarM(cmd com){
        cmdStack.push_back(com);
    }
    void mostrarM(){
        for(int i=0;i<cmdStack.size();i++){
            cout<< cmdStack[i]<< endl;
        }
    }
};/* Esto es para el momento en que vaya a juntarlo, en cada uno de los casos se deben hacer todos los importes de todos los .h del programa y
     con una variable de cada tipo hacer el llamado, junto a un contador de variables de cada tipo 1 x tipo*/


