#include "dinasor.h"
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QTimer>
Dinasor::Dinasor()
{
    //
    QPixmap imagDI1(":/Images/Dinasor1.png");
    QPixmap scaled_imagDI1=imagDI1.scaled(60,110,Qt::KeepAspectRatio,Qt::SmoothTransformation);

    QPixmap imagDI2(":/Images/Dinasor2.png");
    QPixmap scaled_imagDI2=imagDI2.scaled(60,110,Qt::KeepAspectRatio,Qt::SmoothTransformation);

    QPixmap imagDI3(":/Images/Dinasor3.png");
    QPixmap scaled_imagDI3=imagDI3.scaled(60,110,Qt::KeepAspectRatio,Qt::SmoothTransformation);
    //
    Frame << scaled_imagDI1 << scaled_imagDI2 << scaled_imagDI3;
    setPixmap(scaled_imagDI1);
    this->setPos(55,443);
    //
    situation = "Stable";
    //
    SHandle =  new QTimer();
    connect(SHandle,&QTimer::timeout,this,&Dinasor::SCheck);
    SHandle->start(15);
    //
    is_walking=true;

}
int whatframe=0;

void Dinasor::ChangeFrame(){

    if(whatframe%10==0){
        setPixmap(Frame.at(1));
    }
    else if(whatframe%10==5){
        setPixmap(Frame.at(2));
    }
    whatframe++;
}
void Dinasor::SCheck(){
    if(is_walking==false){
        SHandle->stop();
        return;
    }
    if(situation=="Stable"){
        ChangeFrame();
    }
    else if(situation=="Up"){
        if(shetab==0){
            situation = "Down";
        }
        setPos(x(),y()-shetab);
        shetab--;
    }
    else if(situation=="Down"){
        if(shetab==15){
            this->setPos(55,434);
            situation = "Stable";
        }
        setPos(x(),y()+shetab);
        shetab++;
    }
}
