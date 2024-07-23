#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QGraphicsPixmapItem>
class MainWindow : public QGraphicsView
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void creatCloud();
    void creatCactus();
    void creatGround();
private:
    QGraphicsScene *view;
    QTimer* checkClouds;
    QTimer* checkCactus;
    QTimer* checkGround;
};
#endif // MAINWINDOW_H
