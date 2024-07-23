#include "cloud.h"
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QDebug>
#include <QRandomGenerator>
#include <QTimer>


int Cloud::count=0;


int Cloud:: Randomgeneration (int min,int max){

    return QRandomGenerator::global()->bounded(min,max+1);
}
Cloud::Cloud(QGraphicsItem* parent):QObject(),QGraphicsPixmapItem(parent)
{
    qDebug()<<"New cloud created!\n";

    QPixmap imagCl(":/Images/cloud2.png");
    QPixmap scaled_imagCl=imagCl.scaled(150,100,Qt::KeepAspectRatio,Qt::SmoothTransformation);
    setPixmap(scaled_imagCl);

    this->setPos(800,Randomgeneration(-50,50));

    speed=Randomgeneration(1,10);

    cloud_mov =new QTimer();

    connect(cloud_mov,&QTimer::timeout,this,&Cloud::Cmovement);
    cloud_mov->start(40);
    count++;
}


void Cloud::Cmovement(){
    QPointF cloudPos = this->pos();
    if(cloudPos.x()<-80){
        qDebug()<<"cloud Deleted!!\n";
        scene()->removeItem(this);
        delete(this);
        return;
    }
    setPos(x()-speed,y());
}


Cloud::~Cloud(){
    count--;
}
