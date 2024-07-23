#include "mainwindow.h"
#include "cloud.h"
#include "cactus.h"
#include <QRandomGenerator>

int RandomGenarating(int min,int max){
    return QRandomGenerator::global()->bounded(min,max+1);
}
MainWindow::MainWindow(QWidget *parent)
    : QGraphicsView(parent)
{
    //
    view = new QGraphicsScene(this);
    setScene(view);
    setFixedSize(800,600);
    setSceneRect(0,0,700,500);
    //
    checkClouds=new QTimer();
    connect(checkClouds,&QTimer::timeout,this,&MainWindow::creatCloud);
    checkClouds->start(20);
    //
    checkCactus = new QTimer();
    connect(checkCactus,&QTimer::timeout,this,&MainWindow::creatCactus);
    checkCactus->start(6000);

}
void MainWindow::creatCloud(){
    if(Cloud::count<6  ){
        Cloud* newC = new Cloud();
        view->addItem(newC);
    }
}
void MainWindow::creatCactus(){
    Cactus* newCa= new Cactus();
    view->addItem(newCa);
    checkCactus->stop();
    checkCactus->start(RandomGenarating(Cactus::speed*300,6000));

}
MainWindow::~MainWindow()
{

}
