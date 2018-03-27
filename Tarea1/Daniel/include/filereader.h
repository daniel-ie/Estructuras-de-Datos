#ifndef FILEREADER_H
#define FILEREADER_H

#include <iostream>
#include <fstream>  // writer
#include <string>
#include <cstring>
#include <sstream>
#include <stdlib.h>
#include <vector>


using namespace std ;

////////////////////////////////////////////////////
///             Clase FileReader
////////////////////////////////////////////////////
class FileReader {
private:
    const char *BD_file ;
    //string BD_file ;
    string isbn, titulo, autor, year, cantidad, content ;
    string buffer, nextBookBuf ;
public:
    FileReader() ;
    FileReader(const char *) ;
    //FileReader(string) ;
    void writer(string) ;
    void reader() ;
    string getBuffer() ;
    string next() ;
    string untilTokenFR(string &) ;

} ;

#endif // FILEREADER_H
