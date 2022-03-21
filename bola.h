#ifndef BOLA_H
#define BOLA_H

#include <QGraphicsItem>
#include <QPainter>
#include <QTimer>

class bola:public  QObject, public  QGraphicsItem
{
    Q_OBJECT
public:
    int r=4;
    float px, py, y0;
    float vely=0, ay, yd;
    bola();
    QRectF boundingRect() const;
    void paint (QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    ~bola();

public slots:
    void mover();
};

#endif // BOLA_H
