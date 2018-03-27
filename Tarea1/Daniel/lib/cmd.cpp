#include "cmd.h"
#include "nodo.h"
#include "queue.h"
#include <string>
#include <cstring>

/*#include <filereader.h>
#include <filewriter.h>
#include <mstorage.h>
#include <queue.h>*/

////////////////////////////////////////////////////
///             Clase CMD
////////////////////////////////////////////////////

CMD::CMD(){
}

void CMD::start(){
    cout << "*****TEST_START*****" << endl ;
    //load("/home/edgar_ie/Documents/text2.txt");

/*************************************************/
    cout << "*****TEST_END*****" << endl;
    cout << "CMD START" << endl;

    string instrucc="\n ***********************************\n"
                    "       Commandos para el sistema\n"
                    "load (fichero)\n"
                    "save\n"
                    " (fichero)\n"
                    "index -[r|e|a|y]\n"
                    "ls\n"
                    "ls -[r|e|a|y] (valor)\n"
                    "insert (isbn;título;autor;año;cantidad)\n"
                    "delete (isbn)\n"
                    "clear\n"
                    "get (isbn;usuario)\n"
                    "back (isbn)"
                    "pqueue\n"
                    "sort -método\n"
                    "log\n"
                    "x.....x\n"
                    "exit\n"
                    "H\n"
                    "***********************************************\n\n";

    cout << instrucc << endl;
    cout << "Ingrese un comando:" << endl;

    string command      = "" ;
    string param        = "" ;
    bool    automated   = false ;
    string  next_comm   = "" ;

    while(!exitF){
        if(!automated){
            cout << ">>";
            getline(cin, command);
        }
        else{
            automated = false ;
            command=next_comm ;
        }
        if(command.compare("exit")==0){
            exit();
        }
        else if(command.compare("H")==0){
            cout<< instrucc <<endl;
        }
        else if( command.find( "load", 0 ) != string::npos){
            param = getparam(command);
            if(param.compare("")==0){
                cout << "Error en el comando 'load'" <<endl;
            }
            else{
                //addlog("load ("+param+")");
                load(param);
            }
        }
        else if(command.compare("save")==0){
            //addlog("save");
            save();
        }
        else if( command.find( "save", 0 ) != string::npos){
            param = getparam(command);
            if(param.compare("")==0){
                cout << "Error en el comando 'save'" <<endl;
            }
            else{
                //addlog("save ("+param+")");
                save(param);
            }
        }
        else if( command.find( "insert", 0 ) != string::npos){
            param = getparam(command);
            if(param.compare("")==0){
                cout << "Error en el comando 'insert'" <<endl;
            }
            else{
                //addlog("insert ("+param+")");
                BDinsert(param);
            }
        }
        else if( command.find( "get", 0 ) != string::npos){
            param = getparam(command);
            if(param.compare("")==0){
                cout << "Error en el comando 'get'" <<endl;
            }
            else{
                //addlog("get ("+param+")");
                string isbn=param.substr(0,param.find(","));
                string name=param.substr(param.find(",")+1);
                get(isbn,name);
            }
        }
        else if( command.find( "back", 0 ) != string::npos){
            param = getparam(command);
            if(param.compare("")==0){
                cout << "Error en el comando 'back'" << endl ;
            }
            else{
                //addlog("back ("+param+")");
                back(param);
            }
        }
        else if(command.compare("pqueue")==0){
            //cout<< "pendiente pqueue" <<endl;
            //param = getparam(command) ;
            if(param.compare("")==0){
                cout << "Error en el comando 'back'" << endl ;
            }
            else{
                //addlog("back ("+param+")");
                pqueue();
            }
        }

        command = "" ;
    }
}
void CMD::load(string file){
    cout << "Loading file: " +file <<endl ;
    File = file ;
    fr = FileReader(File.c_str()) ;
    CMDbuffer += fr.getBuffer() ;
    mStorage.fillVector(myStorage, CMDbuffer) ;
    mStorage.getVector(myStorage);
}
void CMD::save(){
    cout << "salva1?" << endl ;
    if(File.compare("") != 0){
        purifyBuff() ;
        fr.writer(CMDbuffer.c_str()) ;
    }
    else{
        cout << "Ningún archivo cargado" <<endl ;
    }
}
void CMD::save(string file){
    cout << "salva?" << endl ;
    if(file.compare("") != 0){
        cout<< "Saving to: "+file <<endl;
        purifyBuff();
        FileWriter(file.c_str(), CMDbuffer) ;
        File = file;
    }
    else{
        cout<< "Ningún nombre de archivo especificado" <<endl;
    }
}
string CMD::getparam(string com){
    string r = "" ;
    std::size_t pos1 = com.find("(") ;
    std::size_t pos2 = com.find(")") ;

    if(pos1 != string::npos && pos2 != string::npos){
        r = com.substr(pos1+1,pos2-pos1-1) ;
    }

    return r;
}
void CMD::BDinsert(string libro){
    mStorage.parser(libro);
    Book newBook(mStorage.getIsbnMS(), mStorage.getTituloMS(), mStorage.getAutorMS(), mStorage.getYearMS(), mStorage.getCantidadMS()) ;
    myStorage.push_back(newBook);
    CMDbuffer.append(libro+"\n");
    //falta:update_Index
}
void CMD::get(string queue_isbn,string queue_user){
    cout << "Haciendo solicitud del libro: " << queue_isbn << endl ;
    int cant = queue.inStock(myStorage) ;
    string queue_prestar = cant>0 ? "Asignado":"No disponible" ;
    node = Nodo(queue_isbn, queue_user, queue_prestar) ;
    queue.enQueue(node) ;
}
void CMD::back(string queue_isbn){
    //falta revisar disponibilidad
    //**queue.registraSolicitud(queue_isbn, "-back") ;
}
void CMD::pqueue(){
    queue.displayQueue() ;
    //queue.pqueue() ;
}
void CMD::purifyBuff(){
    size_t size = CMDbuffer.size();
    int contador=0;
    string tmp="";
    while(contador<size)
    {
        if(CMDbuffer[contador]==';')
        {
            tmp+=CMDbuffer[contador];
            tmp+='\n';
        }
        else if(CMDbuffer[contador]!='\n')
        {
            tmp+=CMDbuffer[contador];
        }
        contador=contador+1;
    }
    CMDbuffer=tmp;
}
void CMD::exit(){
    exitF = true ;
}
