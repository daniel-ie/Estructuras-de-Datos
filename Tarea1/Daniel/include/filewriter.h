#ifndef FILEWRITER_H
#define FILEWRITER_H

#include <iostream>
#include <fstream>  // writer
//#include <ofstream>
#include <string>
#include <cstring>
#include <sstream>
#include <stdlib.h>
#include <vector>

#include "mstorage.h"
//#include "filewriter.h"

using namespace std ;

////////////////////////////////////////////////////
///             Clase FileWriter
////////////////////////////////////////////////////
class FileWriter:public MStorage {
private:
    const char *BD_file1 ;
    //MStorage mStorage ;
    //string isbn, titulo, autor, year, cantidad, content ;
    //string buffer, nextBookBuf ;
public:
    //FileWriter() ;
    FileWriter():MStorage(){}
    FileWriter(const char *) ;
    FileWriter(const char *, string) ;
    FileWriter(const char *, MStorage &) ;
/*    FileWriter(const char *file, MStorage &mStorage):MStorage(){
        BD_file1 = file ;
        //MStorage mStorage ; //= mStorage1 ;
        cout << "testX= " << mStorage.getAutorMS() << endl ;
    }
*/
    //FileWriter(const char *, MStorage &):MStorage(){}
    void fwriter(string) ;
    bool empty() ;
    //string getBuffer() ;
    //string next() ;
    //string untilTokenFR(string &) ;

} ;

#endif // FILEWRITER_H
