#include "mainwindow.h"
#include "cloud.h"
#include "cactus.h"
#include <QRandomGenerator>
#include "ground.h"
#include <QList>
#include <QFont>
using namespace std;

int MainWindow::score=0;
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
    addScore = new QTimer();
    connect(addScore,&QTimer::timeout,this,&MainWindow::Scorehandle);
    addScore->start(750);
    //
    checkClouds=new QTimer();
    connect(checkClouds,&QTimer::timeout,this,&MainWindow::creatCloud);
    checkClouds->start(20);
    //
    checkCactus = new QTimer();
    connect(checkCactus,&QTimer::timeout,this,&MainWindow::creatCactus);
    checkCactus->start(6000);
    //
    Ground* G = new Ground();
    view->addItem(G);
    checkGround = new QTimer();
    connect(checkGround,&QTimer::timeout,this,&MainWindow::creatGround);
    checkGround->start(5);
    //
    D = new Dinasor();
    view->addItem(D);
    //
    LoseCheck = new QTimer();
    connect(LoseCheck,&QTimer::timeout,this,&MainWindow::LoseHandle);
    LoseCheck->start(10);
    //
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
void MainWindow::creatGround(){
    if(Ground::empty==true){
        Ground* newG = new Ground();
        newG->setPos(890,480);
        view->addItem(newG);
        Ground::empty=false;
    }
}

void MainWindow::Scorehandle(){
    MainWindow::score++;
    foreach(QGraphicsItem *item,scene()->items()){

        QGraphicsTextItem* txt =dynamic_cast<QGraphicsTextItem*>(item);
        if(txt){
            view->removeItem(item);

        }
    }
    QGraphicsTextItem *scoreTextItem = new QGraphicsTextItem();
    QString PrintScore= ("Your Score : " + QString::number(score));
    scoreTextItem->setPlainText(PrintScore);
    scoreTextItem->setDefaultTextColor(Qt::black);
    scoreTextItem->setFont(QFont("Arial", 14));
    scoreTextItem->setPos(-10, 200);

    view->addItem(scoreTextItem);

    if(Ground::speed<20){
        Cactus::speed+=0.1;
        Ground::speed+=0.1;
        return;
    }

}
void MainWindow::LoseHandle(){

    foreach(QGraphicsItem *item,scene()->items()){
        QPointF dinasor_pos = D->pos();
        Cactus* cactus =dynamic_cast<Cactus*>(item);
        if(cactus){
            if(cactus->x()>=D->x()-10&&cactus->x()<=D->x()+10){
                if(dinasor_pos.y()>384){
                    Lose();
                }
            }
        }
    }
}

void MainWindow::Lose(){
    checkCactus->stop();
    checkClouds->stop();
    checkGround->stop();
    LoseCheck->stop();
    addScore->stop();
    Ground::speed=0;
    Cactus::speed=0;

    foreach(QGraphicsItem *item,scene()->items()){
        Cloud* cloud =dynamic_cast<Cloud*>(item);
        if(cloud){
            cloud->set_Speed(0);
        }
    }
    D->set_walking(false);
    QGraphicsTextItem* textItem = view->addText("You Lose!");
    textItem->setPos(200, 300);
    QFont font("Arial", 60);
    textItem->setFont(font);
    QBrush redBrush(Qt::red);
    textItem->setDefaultTextColor(Qt::red);

}

MainWindow::~MainWindow()
{

}
