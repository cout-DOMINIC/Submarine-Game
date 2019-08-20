#include "submarine.h"
#include "gegner.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QApplication>
#include <QProcess>
#include <QTimer>
#include "torpedo.h"
#include <QDebug>

Submarine::Submarine(QGraphicsItem* parent): QObject(), QGraphicsPixmapItem (parent)
{
    torpedoSound = new QMediaPlayer();
    torpedoSound->setMedia(QUrl("qrc:/new/sounds/rocket.mp3"));

    QTimer* timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(die()));
    timer->start(50);
}

void Submarine::keyPressEvent(QKeyEvent* event)
{
    qDebug() << "Du hast etwas gedrückt.";

    if (event->key() == Qt::Key_Left)
    {
        if (pos().x() > 0)
        {
            setPos(x()-25, y());
        }
    }

    else if (event->key() == Qt::Key_Right)
    {
        if (pos().x() + 100 < 1250)
        {
            setPos(x()+25, y());
        }
    }

    else if (event->key() == Qt::Key_Up)
    {
        if (pos().y() > 0)
        {
            setPos(x(), y()-25);
        }
    }

    else if (event->key() == Qt::Key_Down)
    {
        if (pos().y() + 100 < 800)
        {
            setPos(x(), y()+25);
        }
    }

    else if (event->key() == Qt::Key_Space)
    {
        Torpedo* torpedo = new Torpedo();
        torpedo->setPos(x(), y());
        scene()->addItem(torpedo);

        if (torpedoSound->state() == QMediaPlayer::PlayingState)
        {
            torpedoSound->setPosition(0);
        }
        else if (torpedoSound->state() == QMediaPlayer::StoppedState)
        {
            torpedoSound->play();
        }
    }
}

void Submarine::spawn()
{
    Gegner* gegner = new Gegner();
    scene()->addItem(gegner);
}

void Submarine::die()
{
    QList<QGraphicsItem*> itemsZerstoeren = collidingItems();
    qDebug() << "AAAAAAAAAHHHHHH";
    for(int i = 0; i<itemsZerstoeren.size();i++)
    {
    if(typeid(*(itemsZerstoeren[i])) == typeid(Gegner))
{
    scene()->removeItem(itemsZerstoeren[i]);
    scene()->removeItem(this);

    delete itemsZerstoeren[i];
    delete this;

    qApp->quit();
    QProcess::startDetached(qApp->arguments()[0], qApp->arguments());
    }

   }
}
