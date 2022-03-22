#include "planetas.h"

planetas::planetas(int num_planetas , float rad_, float px_,float py_, float vx_, float vy_, float mm)
{
    m=mm;  //masa
    r=rad_/10;  //radio
    n=num_planetas; //numero de planetas
    px = px_/10; //posicion en x
    py = py_/10; //posicion en y
    setPos(px,-py);
    vx = vx_; //velocidad en x
    vy = vy_; //velocidad en y


}
void planetas::actualizar(float x, float y, float vxx, float vyy){
    px = x/10;
    py = y/10;
    vx = vxx;
    vy = vyy;
}

//Se le da la nueva posicon a x
void planetas::setPx(float newPx){

    px=newPx;

}

float planetas::getPx()
{
    return px=20;
}

//Se le da la posicion de y
float planetas::getPy()
{
    return py=20;
}

//Se le da la nueva posicion a y
void planetas::setPy(float newPy)
{
    py = newPy;
}

//Se le da la velocidad de x
float planetas::getVx()
{
    return vx;
}



//Se le da la velocidad de y
float planetas::getVy()
{
    return vy;
}


//Se le radio
float planetas::getRad()
{
    return r=10;
}


//Masa
float planetas::MASA()
{
    return m;
}

QRectF planetas::boundingRect() const
{
    return QRectF (-r,-r,2*r,2*r);
}

//Dandole el color y la forma circular a los planetas

void planetas::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){

    if(n==1){
        painter->setBrush(Qt::green);
        painter->drawEllipse(boundingRect());
    }

    else if (n==2){
        painter->setBrush(Qt::blue);
        painter->drawEllipse(boundingRect());
    }
    else if (n==3){
        painter->setBrush(Qt::yellow);
        painter->drawEllipse(boundingRect());
    }
    else if (n==4){
        painter->setBrush(Qt::red);
        painter->drawEllipse(boundingRect());
    }

    else{
        painter->setBrush(Qt::cyan);
        painter->drawEllipse(boundingRect());

    }

}



planetas::~planetas()
{

}
