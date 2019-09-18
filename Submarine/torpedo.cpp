#include "torpedo.h"
#include "score.h"
#include "submarine.h"
#include <QTimer>
#include <QGraphicsScene>
#include "gegner.h"
#include "spiel.h"
#include <QList>

extern Spiel * spiel;

Torpedo::Torpedo(QGraphicsItem* parent): QObject(),  QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/new/images/torpedo.png"));
    QTimer* timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50);
}

void Torpedo::move()
{
    QList<QGraphicsItem*> itemsZerstoeren = collidingItems();
    for(int i = 0; i < itemsZerstoeren.size(); i++){
        if(typeid(*(itemsZerstoeren[i])) == typeid(Gegner))
        {
            QMediaPlayer* sounds = new QMediaPlayer();
            sounds->setMedia(QUrl("qrc:/new/sounds/shred.wav"));
            sounds->play();
            spiel->score->increase();
            scene()->removeItem(itemsZerstoeren[i]);
            scene()->removeItem(this);
            delete itemsZerstoeren[i];
            delete this;
            return;
        }
    }
    setPos(x(), y()-15);
    if(pos().y() < -50)
    {
        scene()->removeItem(this);
        delete this;
    }
}
