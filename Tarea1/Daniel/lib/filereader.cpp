#include "filereader.h"

////////////////////////////////////////////////////
///             Clase FileReader
////////////////////////////////////////////////////
FileReader::FileReader(const char *file){
    BD_file = file ;
}
void FileReader::writer(string s){
    string buffer = s ;
    ofstream BD(BD_file, ios_base::app) ;
    if(BD.is_open()){
        BD << buffer  ; //"Hola soberanos! Saludos y congratulaciones!" ;
        BD.close() ;
    }
    else
        cout << "Can't open file" << endl;
}
string FileReader::next(){
    string buf = nextBookBuf ; //FileReader::getBuffer() ;
    string oneBook = untilTokenFR(buf) ;
    return oneBook ;
}
string FileReader::untilTokenFR(string &tira){
    string tilT = "", temp ;
    int i ;
    for(i=0; i<tira.length() && tira[i]!=';'; i++){ // get first token
        tilT += tira[i] ;
    }
    for(; i<tira.length(); i++){ // Clean tira from first token
        temp += tira [i+2] ;
    }
    tira = temp ;
    nextBookBuf = temp ;
    return tilT ;
}
void FileReader::reader(){
        ifstream BD(BD_file) ;
        string line ;
        if(BD.is_open()){
            while(getline(BD,line))
                cout << line << endl ;
            BD.close();
        }
        else
            cout << "Can't open file" << endl ;
}
string FileReader::getBuffer(){
        ifstream BD(BD_file)  ;
        string buffer, line   ;
        if(BD.is_open()){
            while(getline(BD, line)){
                buffer += line ;
                buffer += "\n" ;
            }
            BD.close() ;
        }
        else
            cout << "Can't open file" << endl ;
        nextBookBuf = buffer ;
    return buffer ;
}
//
