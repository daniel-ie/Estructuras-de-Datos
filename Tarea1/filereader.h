//
#ifndef FILEREADER_H
#define FILEREADER_H
#include <vector>
#include <fstream>
#include <iostream>


using namespace std;

class FileReader  
{
private:
    std::vector<string> dataUsage;
    ifstream fileOpener;
public:
    FileReader();
    void dataCatcher();

};

#endif // FILEREADER_H
