#include "gegner.h"
#include <stdlib.h>
#include "spiel.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QRandomGenerator>
#include <QMediaPlayer>

extern Spiel * spiel;

Gegner::Gegner(QGraphicsItem* parent): QObject(), QGraphicsPixmapItem (parent)
{
    int numbers = rand() % 800;
    setPos(numbers, 0);
setPixmap(QPixmap(":/new/images/fish.png"));
    if(spiel->score->getScore() > 4 && spiel->score->getScore() < 10)
    {
        setPixmap(QPixmap(":/new/images/turtle.png"));
        spiel->level->setDefaultTextColor(Qt::yellow);
        spiel->level->setLevel(1);
    }
    else if (spiel->score->getScore() >= 10 && 15 > spiel->score->getScore())
    {
        setPixmap(QPixmap(":/new/images/jellyfish.png"));
        spiel->level->setDefaultTextColor(Qt::green);
        spiel->level->setLevel(2);
        Gegner::init = false;
    }
    else if (spiel->score->getScore() >= 15)
    {
        setPixmap(QPixmap(":/new/images/squid.png"));
        spiel->level->setDefaultTextColor(Qt::magenta);
        spiel->level->setLevel(3);
        spiel->scene->setBackgroundBrush((QBrush(QImage(":/new/images/bg5.jpg"))));
    }
    QTimer* timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(10);
}

void Gegner::move()
{
     setPos(x(), y() + 1);
     if(spiel->score->getScore() > 4 && spiel->score->getScore() < 10)
     {
     setPos(x(),y()+2);
     }
     else if (spiel->score->getScore() >= 10 && 15 > spiel->score->getScore()){
         if(pos().x() >400)
         setPos(x()-1 ,y()+3);
         if(pos().x() <400)
         setPos(x()+1 ,y()+3);
     }
     else if (spiel->score->getScore() >= 15){
         setPos(x() + (rand() % 38 + (-16)),y()+3);
     }
     if(pos().y() > 800){
       spiel->score->decrease();
       QMediaPlayer* sound = new QMediaPlayer();
       sound->setMedia(QUrl("qrc:/new/sounds/no.wav"));
       sound->play();
       scene()->removeItem(this);
       delete this;
    }
}
