#ifndef GROUND_H
#define GROUND_H
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QTimer>

class Ground:public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    static double speed;
    static bool empty;
    Ground();
    void Gmovement();
private:
    QTimer* ground_mov;
    int clonecreated=0;
};

#endif // GROUND_H
