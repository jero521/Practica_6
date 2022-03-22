#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include "planetas.h"
#include <QDebug>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);


    static MainWindow *Pintarmain();


    planetas *Planeta_1;
    planetas *Planeta_2;
    planetas *Planeta_3;
    planetas *Planeta_4;
    planetas *Planeta_5;
    ~MainWindow();

private slots:

    //void Star();


private:
    Ui::MainWindow *ui;
    QGraphicsScene *escena;

    int v_limit;
    int h_limit;
    static MainWindow *wind;
    int numb, n=0, num_plane=0;
    double px, py, vx, vy, T=0.01, G=-9.8;
    QTimer *t;
    //QObject *bola;
};
#endif // MAINWINDOW_H
