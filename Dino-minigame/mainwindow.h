#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QGraphicsPixmapItem>
#include "dinasor.h"
class MainWindow : public QGraphicsView
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    static int score;
    Dinasor* D;
    void Lose();
public slots:
    void creatCloud();
    void creatCactus();
    void creatGround();
    void Scorehandle();
    void LoseHandle();
private:
    QGraphicsScene *view;
    QTimer* checkClouds;
    QTimer* checkCactus;
    QTimer* checkGround;
    QTimer* addScore;
    QTimer* LoseCheck;
    void keyPressEvent(QKeyEvent* K);
};
#endif // MAINWINDOW_H
