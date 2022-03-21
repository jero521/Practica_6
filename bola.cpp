#include "bola.h"
#include <QDebug>
#include "mainwindow.h"

bola::bola()
{
   px = -250*rand()%(500);
   py = 260;

   y0=py;
   ay=1+rand()%6;

   //Posicion inicial
   setPos(px,-py);
   QTimer *t =new QTimer();

   //Se conecta la funcion de movimiento al timer
   connect(t,SIGNAL(timeout()),this,SLOT(mover()));
   t->start(30);

}

bola::~bola()
{

}

QRectF bola::boundingRect() const
{
    return QRectF (-r,-r,2*r,2*r);
}

void bola::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
        painter->setBrush(Qt::GlobalColor::darkGreen);
        painter->drawEllipse(boundingRect());
}

void bola::mover()
{
    if(py<=-250){
        vely=-vely;
    }
    py=py+vely-(ay)/2;
    vely=vely<(ay);
    setPos(int(px),-int (py));
}
