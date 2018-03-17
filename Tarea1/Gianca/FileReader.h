#ifndef FILEREADER_H
#define FILEREADER_H
#include <fstream>

using namespace std;

class FileReader
{
    private:
        fstream archivo;
    public:
        FileReader();
        void leer();
        virtual ~FileReader();


};

#endif // FILEREADER_H
