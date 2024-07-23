#ifndef DINASOR_H
#define DINASOR_H
#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QTimer>
#include <QList>
#include <QKeyEvent>
class Dinasor : public QObject , public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Dinasor();
    QList<QPixmap> Frame;
    void ChangeFrame();
    QString situation;
    void set_walking(bool TF){
        is_walking = TF;
        return;
    }
public slots:
    void SCheck();
private:
    QTimer* SHandle;
    int shetab=15;
    bool is_walking;
};

#endif // DINASOR_H
