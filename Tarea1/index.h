#ifndef INDEX_H
#define INDEX_H
#include <node.h>

using namespace std;
typedef class Node* enlace;

class Node
{
public:
    enlace siguiente;
    Node(){
        siguiente=NULL;
    }

};


class Index{
    enlace elemento;

public:
    Index(){
        elemento=NULL;
    }
    void insert(/*ClaseLibro*/int x){
        enlace index= new Node(x);
        index->siguiente= elemento;
        elemento= index;
    }
};

#endif // INDEX_H
