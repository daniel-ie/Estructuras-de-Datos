#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    root = NULL ;
    pPuntos = NULL ;
    levelPrev = 1 ;
    yprev = 0 ;
    bandera = false ;

}

MainWindow::~MainWindow(){
    delete ui;
}

/////////////////////////////////////////////
///////////////// Metodos ///////////////////
/////////////////////////////////////////////

void MainWindow::mapPoints(Nodo *p, bool path, int level){
    int x = 0, y = 0 ;
    if(p == 0)
        return ;

    int c = (2*d)/(pow(2, numNiveles)) ;

if(bandera==false){
    if(level-levelPrev > 0){        // bajando 1 nivel
        x = d - c*(level-1)  ;
    }
    else if(level-levelPrev < 0){   // subiendo 1 nivel
        x = d + c*(level-1)  ;
        bandera = true ;
    }
    else{
        x = xprev + c*(level-1) -15 ;
    }
}
////////////////////////////////////7
if(bandera==true){
    if(level-levelPrev < 0){        // bajando 1 nivel
        x = d - c*(level-1)  ;
    }
    else if(level-levelPrev > 0){   // subiendo 1 nivel
        x = d + c*(level-1)  ;
    }
    else{
        x = xprev - c*(level-1) +15 ;
    }
}
    y = h+30*level ;

    cout << p->dato << ", " ;
    cout << "FLAG=" << path <<  ", level=" << level ;
    cout << ", P=(" << x  << ", "  << y << "), " ;
    cout << "PrevActual = (" << levelPrev << ", " << level << ") ; " << endl ;

    levelPrev = level ;
    yprev = y ;
    xprev = x ;

    setPuntos(x, y) ;

    mapPoints(p->izq, true, level+1) ;
    mapPoints(p->der, false, level+1) ;

}
void MainWindow::setPuntos(int x, int y){
    pPuntos = new Nodo(x, y, pPuntos) ;
}


void MainWindow::paintEvent(QPaintEvent *e){
    QPainter painter(this) ; // allows to paint on window!
    QPen pen(Qt::black), dot(Qt::black) ;
    QPoint punto, puntoAux ;

    pen.setWidth(3) ;
    dot.setWidth(7) ;

    count1 = 0 ; count2 = 0 ; count3 = 0 ;
    h = 50 ; d = 650 ;  // Puntos del nodo raiz

    calcNiveles(root) ;
    mapPoints(root, true, 1) ;

//    painter.setPen(dot) ;
//    punto.setX(d) ; punto.setY(h) ; // (3, 18)
//    painter.drawPoint(punto.x(), punto.y()) ;
    //punto.setX(1298) ; punto.setY(738) ; // (1298, 738)
    //painter.drawPoint(punto.x(), punto.y()) ;

    for(Nodo *q=pPuntos; q; q=q->siguiente){
        painter.setPen(dot) ;
        punto.setX(q->px) ; punto.setY(q->py) ;
        painter.drawPoint(punto.x(), punto.y()) ;

        //painter.setPen(pen) ;
        //painter.drawLine(punto, puntoAux) ;

        //puntoAux = punto ;
    }

}
void MainWindow::calcNiveles(Nodo *h){
    numNiveles = 0 ;
    for(Nodo *q = h; q; q=q->izq){
        numNiveles +=1 ;
    }
    //cout << "Numero de niveles = " << numNiveles << endl ;
}

///////////////////////////////////////
//////////// Setea Root ///////////////
///////////////////////////////////////
void MainWindow::setRoot(Nodo *p){
    root = p ;
}

