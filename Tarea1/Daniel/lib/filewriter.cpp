#include "filewriter.h"
#include "mstorage.h"

////////////////////////////////////////////////////
///             Clase FileWriter
////////////////////////////////////////////////////
FileWriter::FileWriter(const char *file){
    BD_file1 = file ;
    //MStorage mStorage ;
    //cout << "test = " << mStorage.getAutorMS() << endl ;
} //:MStorage(){}
FileWriter::FileWriter(const char *file, MStorage &mStorage){
    BD_file1 = file ;
 //   MStorage mStorage ; //= mStorage1 ;
    cout << "test = " << mStorage.getAutorMS() << endl ;
}
void FileWriter::fwriter(string s){
    string buffer = s ;
    ofstream BD(BD_file1, ios_base::app) ;
    if(BD.is_open()){
        buffer += "\n" ;
        BD << buffer  ;
        BD.close() ;
    }
    else
        cout << "Can't open file" << endl;
}
bool FileWriter::empty(){
    bool empty = false ;
    ifstream BD(BD_file1) ;
    if(BD.is_open()){
        BD.seekg(0, ios::end) ;
        size_t size = BD.tellg() ;
        if(size == 0)
            empty = true ;
        else
            empty = false ;
        BD.close() ;
    }
    return empty ;
}

/*
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
*/
//
