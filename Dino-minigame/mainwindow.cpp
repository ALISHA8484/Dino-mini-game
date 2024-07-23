#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QGraphicsView(parent)
{
    //
    //
    view = new QGraphicsScene(this);
    setScene(view);
    setFixedSize(800,600);
    setSceneRect(0,0,700,500);
    //

}

MainWindow::~MainWindow()
{

}
