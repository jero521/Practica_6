#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <math.h>
#include "planetas.h"




MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    escena = new QGraphicsScene;


    //dimensiones de la escena
    h_limit=1   ;
    v_limit=1;
    escena->setSceneRect(0,0,h_limit,v_limit);
    escena->addRect(escena->sceneRect());
    //constuyendo la escena
    ui->graphicsView->setScene(escena);

    //Fondo
    QImage Fondo(":/space.png");
    QBrush b3(Fondo);
    ui->graphicsView->setBackgroundBrush(b3);

    //Se forman los planetas
    Planeta_1 = new  planetas(1,200,0,0,0,0,50000);
    Planeta_2 = new planetas(2,70,-5000,0,0,-2,70);
    Planeta_3 = new planetas(3,70,5000,0,0,2,70);
    Planeta_4 = new planetas(4,70,0,-5000,2,0,70);
    Planeta_5 = new planetas(5,70,0,5000,-2,0,70);


    escena->addItem(Planeta_1);
    escena->addItem(Planeta_2);
    escena->addItem(Planeta_3);
    escena->addItem(Planeta_4);
    escena->addItem(Planeta_5);


    t = new QTimer(this);
    t->stop();
    connect(t,SIGNAL(timeout()),this,SLOT(Star()));
    t->start(15);
    //wind=this;



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








