#ifndef TORPEDO_H
#define TORPEDO_H
#include <QGraphicsPixmapItem>
#include <QObject>

class Torpedo: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    Torpedo(QGraphicsItem* parent = nullptr);

private slots:
    void move();
};

#endif
