#ifndef CMD_H
#define CMD_H

#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <stdlib.h>
#include <vector>

#include <filereader.h>
#include <filewriter.h>
#include <mstorage.h>
#include <queue.h>
#include <nodo.h>

using namespace std ;

class NodoLog {
public:
    // Registros que soporta el Nodo
    string comm = "" ;
    // Puntero al siguiente Nodo
    NodoLog *siguiente = NULL;
} ;

class CMD{
private:
    string File = "" ;
    string CMDbuffer = "" ;
    bool exitF = false;
    vector<Book> myStorage ;
    FileReader fr = NULL ;
    FileWriter fw = NULL ;
    MStorage mStorage = MStorage() ;

    Nodo node = Nodo() ;
    Queue queue = Queue() ;
    NodoLog* cmdlog = NULL ;
public:
    CMD() ;
    void exit();
    void start();
    void load(string);
    void save() ;
    void save(string);
    void ls();
    void BDinsert(string);
    void BDdelete(string);
    void get(string,string);
    void back(string);
    void pqueue();
    void clear();
    void addlog(string);
    void log();
    string exelog(int);
    string getparam(string);
    void purifyBuff();
} ;

#endif // CMD_H
