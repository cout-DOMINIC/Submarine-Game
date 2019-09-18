#ifndef GEGNER_H
#define GEGNER_H
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QObject>

class Gegner: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
bool init;
public:
    Gegner(QGraphicsItem* parent = nullptr);

private slots:
    void move();
};

#endif
