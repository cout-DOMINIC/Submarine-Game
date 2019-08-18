#include "gegner.h"

//Bibliothek für sehr lange ints
#include <stdlib.h>

#include <QTimer>
#include <QGraphicsScene>
#include <QRandomGenerator>
#include <QMediaPlayer>

Gegner::Gegner(QGraphicsItem* parent): QObject(), QGraphicsPixmapItem (parent)
{
    /*
     * Random-Position
     * Dabei ist zu beachten, dass der Bereich, in dem
     * Random-Nummers berechnet werden sollen, innerhalb
     * des Bildschirms ist.. deshalb Modulo 900
     * 900 ist die maximale Pixelbreite unseres Spiel-Windows
     * Ich glaube es muss hier aber auch beachtet werden, dass
     * die Gegner auch 100 Pixel width haben.. im Test lief
     * aber alles problemlos innerhalb des Spiel-Windows
     */
    int numbers = rand() % 800;
    /*
     * X-Achse numbers und Y-Achse 0
     * Gegner starten irgendwo auf der X-Achse
     */

    setPos(numbers, 0);

    setPixmap(QPixmap(":/new/images/squid.png"));

    QTimer* timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    // Alle 50 Millisekunden bewegt sich der Gegner
    timer->start(50);
}

void Gegner::move()
{
     // Gegner bewegt sich nach unten
     setPos(x(), y() + 7);

    // Gegner wird vom Spiel gelöscht
    if(pos().y() > 800)
    {
       QMediaPlayer* sound = new QMediaPlayer();
       sound->setMedia(QUrl("qrc:/new/sounds/no.wav"));
       sound->play();
       scene()->removeItem(this);
       delete this;
    }
}
