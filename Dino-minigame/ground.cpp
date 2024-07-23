#include "ground.h"
#include <QDebug>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QTimer>
#include <QMutex>

double Ground::speed=3;
bool Ground::empty=false;
Ground::Ground()
{
    qDebug()<<"Ground created\n";

    QPixmap imagG (":/Images/Ground.png");
    QPixmap scaled_imagG = imagG.scaled(1000,100,Qt::KeepAspectRatio,Qt::SmoothTransformation);
    setPixmap(scaled_imagG);

    this->setPos(-100,480);


    ground_mov = new QTimer();
    connect(ground_mov,&QTimer::timeout,this,&Ground::Gmovement);
    ground_mov->start(10);

}
void Ground::Gmovement(){

    QPointF groundPos = this->pos();
    if(groundPos.x()<=-80&&clonecreated==0){
        empty=true;
        clonecreated=1;
    }
    if(groundPos.x()<-1080){
        qDebug()<<"Ground deleted\n";
        scene()->removeItem(this);
        delete(this);
        return;
    }
    setPos(x()-speed,y());

}
