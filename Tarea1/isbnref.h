#ifndef ISBNREF_H
#define ISBNREF_H

typedef class Node * enlace;
class Node
{
public:
    enlace siguiente, anterior;
    Node() {
        siguiente= nullptr;
        anterior= nullptr;
    }
};

class ISBNRef
{
    //All data here.
    enlace front, end;
public:
    ISBNRef() {
        front= nullptr;
        end= nullptr;
    }
    void insert(){
        if(front==nullptr){
            front= new Node();
            end= front;
        }
        else{
            front=new Node();
            front->siguiente->anterior=front;
        }

    }
};
#endif // ISBNREF_H
