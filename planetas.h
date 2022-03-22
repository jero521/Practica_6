#ifndef PLANETAS_H
#define PLANETAS_H
#include <QPainter>
#include <QGraphicsItem>
//#include "bola.h"
//#define DT 0.1

class planetas : public QGraphicsItem
{
public:
    //Posicion en x, Posicion en y, Velocidad en x, Velocidad en y, Radio, Escala de zoom inverso
    int n;
    float r, px, py, vx, vy, m;
    planetas( int num_planetas, float rad_=10, float px_=20,float py_=20, float vx_=5, float vy_=1,  float mm=5);

    void actualizar(float x,float y,float vx, float vy);

    void setPx(float newPx);
    float getPx();
    void setPy(float newPy);
    float getPy();

    float getVx();
    float getVy();


    float MASA();
    float getRad();



    //Dandole la forma circular
    QRectF boundingRect() const;
    //Funcion que pinta
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget =nullptr);

    ~planetas();



};

#endif // BOLAGRAF_H
