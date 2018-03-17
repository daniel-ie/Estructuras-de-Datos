#include "FileReader.h"
#include <iostream>

using namespace std;

FileReader::FileReader(){}

void FileReader::leer(){
	    archivo.open("file.txt",ios::in);

	    if(archivo.is_open()){
	        string linea;
	        while(getline(archivo,linea)){
                cout<<linea<<endl;
	        }
	        archivo.close();
	    }
}

FileReader::~FileReader(){}
