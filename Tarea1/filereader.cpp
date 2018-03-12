#include "filereader.h"
#include <iostream>
#include <string>
#include <bdfile.txt>

using namespace std;


FileReader::FileReader(){}

void FileReader::dataCatcher(){
    string line;
    fileOpener.open("bdfile.txt");
    if(fileOpener.is_open()){
        while(getline (fileOpener,line)){
            cout<<"lol"<<line;
            dataUsage.push_back(line);
        }
        fileOpener.close();
    }
}


