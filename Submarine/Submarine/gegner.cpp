#include "gegner.h"
#include <stdlib.h>
#include <QTimer>
#include <QGraphicsScene>
#include <QRandomGenerator>
#include <QMediaPlayer>

Gegner::Gegner(QGraphicsItem* parent): QObject(), QGraphicsPixmapItem (parent)
{
    int numbers = rand() % 800;
    setPos(numbers, 0);
    setPixmap(QPixmap(":/new/images/squid.png"));

    QTimer* timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50);
}

void Gegner::move()
{
    setPos(x(), y() + 7);

    if(pos().y() > 800)
    {
       QMediaPlayer* sound = new QMediaPlayer();
       sound->setMedia(QUrl("qrc:/new/sounds/no.wav"));
       sound->play();
       scene()->removeItem(this);
       delete this;
    }
}
