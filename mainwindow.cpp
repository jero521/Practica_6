#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <math.h>
#include "planetas.h"
#define g 6.6738*(pow(10,-11))


bool j= true;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    escena = new QGraphicsScene;


    //dimensiones de la escena
    h_limit=1;
    v_limit=1;
    escena->setSceneRect(0,0,h_limit,v_limit);
    escena->addRect(escena->sceneRect());
    //constuyendo la escena
    ui->graphicsView->setScene(escena);

    //Fondo
    QImage Fondo(":/space.png");
    QBrush b3(Fondo);
    ui->graphicsView->setBackgroundBrush(b3);


   // QImage SOl(":/SOL.png");

    //Se forman los planetas
    Planeta_1 = new  planetas(1,800,0,0,0,0,50000);
    Planeta_2 = new planetas(2,70,-500,0,0,-2,70);
    Planeta_3 = new planetas(3,70,500,0,0,2,70);
    Planeta_4 = new planetas(4,70,0,-500,2,0,70);
    Planeta_5 = new planetas(5,70,0,500,-2,0,70);


    //planetas( int num_planetas, float rad_=10, float px_=20,float py_=20, float vx_=5, float vy_=1,  float mm=5);


    escena->addItem(Planeta_1);
    escena->addItem(Planeta_2);
    escena->addItem(Planeta_3);
    escena->addItem(Planeta_4);
    escena->addItem(Planeta_5);

    t = new QTimer(this);


    connect(t,SIGNAL(timeout()),this,SLOT(Actualizar()));

    //wind=this;



}
//Funcion para iniciar y para la ejecucion
void MainWindow::on_Button_clicked()
{
    if(j==true){
    t->start(15);
    j=false;
    }
    else{
        t->stop();
    }

}



MainWindow::~MainWindow()
{
    delete ui;
    delete Planeta_1;
    delete Planeta_2;
    delete Planeta_3;
    delete Planeta_4;
    delete Planeta_5;
    delete t;
    delete escena;

}



void MainWindow::Actualizar()
{
    //SOL


    float p1[5]={Planeta_1->getPx(),Planeta_1->getPy(),Planeta_1->getVx(),Planeta_1->getVy(),Planeta_1->MASA()};

    //Planetas
    float p2[5]={Planeta_2->getPx(),Planeta_2->getPy(),Planeta_2->getVx(),Planeta_2->getVy(),Planeta_2->MASA()};
    float p3[5]={Planeta_3->getPx(),Planeta_3->getPy(),Planeta_3->getVx(),Planeta_3->getVy(),Planeta_3->MASA()};
    float p4[5]={Planeta_4->getPx(),Planeta_4->getPy(),Planeta_4->getVx(),Planeta_4->getVy(),Planeta_4->MASA()};
    float p5[5]={Planeta_5->getPx(),Planeta_5->getPy(),Planeta_5->getVx(),Planeta_5->getVy(),Planeta_5->MASA()};

    float x,y,velocidadx=Planeta_2->getVx(),velocidady=Planeta_2->getVy(),Ax,Ay;
    float oldvelocidadx=velocidadx,oldvelocidady=velocidady;
    float posxx;
    float posyy;


    //*******************************Planeta 1*******************************************//



    x=p2[0];
    y=p2[1];

    posxx=x;
    posyy=y;

    //Newton's laws
    //Ax=G[1]*Planeta_1->MASA()/pow(Planeta_2->getRad(),2);
    Ax=G[0]/Planeta_2->getRad();
    Ay=G[1]/Planeta_2->getRad();
    //Ay=G[1]*Planeta_1->MASA()/pow(Planeta_2->getRad(),2);

    velocidadx=oldvelocidadx+ Ax;
    velocidady=oldvelocidady+ Ay;

    Planeta_2->setVx(velocidadx);
    Planeta_2->setVy(velocidady);

    x=posxx+ T *velocidadx;
    y=posyy+ T *velocidady;
    Planeta_2->setPos(x,-y);
    Planeta_2->actualizar(x,y,velocidadx,velocidady);



    //*******************************Planeta 2*******************************************//


   velocidadx=Planeta_3->getVx(),velocidady=Planeta_3->getVy();

   oldvelocidadx=velocidadx,oldvelocidady=velocidady;



    x=p3[0];
    y=p3[1];

    posxx=x;
    posyy=y;

    //Newton's laws
    Ax=G[1]*Planeta_1->MASA()/pow(Planeta_2->getRad(),2);

    Ay=G[1]*Planeta_1->MASA()/pow(Planeta_2->getRad(),2);

    velocidadx=oldvelocidadx+ Ax;
    velocidady=oldvelocidady+ Ay;

    Planeta_3->setVx(velocidadx);
    Planeta_3->setVy(velocidady);

    x=posxx+ T *velocidadx;
    y=posyy+ T *velocidady;
    Planeta_3->setPos(x,-y);
    Planeta_3->actualizar(x,y,velocidadx,velocidady);



    //*******************************Planeta 3*******************************************//
    velocidadx=Planeta_4->getVx(),velocidady=Planeta_4->getVy();

    oldvelocidadx=velocidadx,oldvelocidady=velocidady;


    x=p4[0];
    y=p4[1];

    posxx=x;
    posyy=y;

    //Newton's laws
    Ax=G[1]*Planeta_1->MASA()/pow(Planeta_3->getRad(),2);

    Ay=G[1]*Planeta_1->MASA()/pow(Planeta_3->getRad(),2);

    velocidadx=oldvelocidadx+ Ax;
    velocidady=oldvelocidady+ Ay;

    Planeta_4->setVx(velocidadx);
    Planeta_4->setVy(velocidady);

    x=posxx+ T *velocidadx;
    y=posyy+ T *velocidady;
    Planeta_4->setPos(x,-y);
    Planeta_4->actualizar(x,y,velocidadx,velocidady);



    //*******************************Planeta 4*******************************************//

   velocidadx=Planeta_5->getVx(),velocidady=Planeta_5->getVy();

   oldvelocidadx=velocidadx,oldvelocidady=velocidady;


    x=p5[0];
    y=p5[1];

    posxx=x;
    posyy=y;

    //Newton's laws
    Ax=G[0]*Planeta_1->MASA()/pow(Planeta_5->getRad(),2);

    Ay=G[1]*Planeta_1->MASA()/pow(Planeta_5->getRad(),2);

    velocidadx=oldvelocidadx+ Ax;
    velocidady=oldvelocidady+ Ay;

    Planeta_5->setVx(velocidadx);
    Planeta_5->setVy(velocidady);

    x=posxx+ T *velocidadx;
    y=posyy+ T *velocidady;
    Planeta_5->setPos(x,-y);
    Planeta_5->actualizar(x,y,velocidadx,velocidady);


}









