#include "torpedo.h"
#include "highscore.h"
#include "submarine.h"
#include <QTimer>
#include <QGraphicsScene>
#include "gegner.h"

// Für unsere QList<QGraphicsItem*> itemsZerstoeren = collidingItems();
#include <QList>

Torpedo::Torpedo(QGraphicsItem* parent): QObject(),  QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/new/images/torpedo.png"));
    QTimer* timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    /*
     * Alle 50 Millisekunden wird timeout() gesendet
     * bzw. alle 50 Millisekunden, bewegt sich der Torpedo
     */
    timer->start(50);
}

void Torpedo::move()
{
    /*
     * *****BUG*****
     * Highscore-Objekt erstellen (siehe weiter unten)
     */
    Highscore* highscore = new Highscore();

    /*
     * Wenn der Torpedo einen Gegner trifft, dann sollen
     * beide (Gegner und Torpedo) zerstört werden
     * Die Member-Function collidingItems(), returns eine
     * Liste von Pointer zu allen QGraphicsItems
     * Diese Liste enthält alle Items, die miteinander
     * kollidieren
     */
    QList<QGraphicsItem*> itemsZerstoeren = collidingItems();

    /*
     * Jetzt müssen wir durch die Liste gehen und checken, ob
     * Objekte miteinander kollidieren
     * itemsZerstoeren.size() hier gehen wir durch alle Elemente durch
     */
    for(int i = 0; i < itemsZerstoeren.size(); i++){

        /*
         * Wenn die Typ-ID im Array von itemsZerstoeren die Selbe Typ-ID,
         * wie die vom Gegner ist, dann werden beide Items removed und gelöscht.
         * Um das Objekt aber zu bekommen, müssen wir dereferenzieren,
         * da der Pointer NUR die Speicheradresse vom Objekt enthält
         */

        if(typeid(*(itemsZerstoeren[i])) == typeid(Gegner))
        {

            // Sobald ein Gegner getroffen wird, kommt der "Klatsch" Sound
            QMediaPlayer* sounds = new QMediaPlayer();
            sounds->setMedia(QUrl("qrc:/new/sounds/shred.wav"));
            sounds->play();

            /*
             * *****BUG*****
             * Wenn mein Torpedo einen Gegner trifft, soll ein
             * neues Highscore-Objekt erstellt werden und wird
             * zur Scene hinzugefügt
             * Dabei soll der Highscore increasen, wenn getroffen
             * wird
             */
            highscore->increase();

            // Selbe ID? Dann wird zuerst der Gegner und dann this (Torpedo) removed
            scene()->removeItem(itemsZerstoeren[i]);
            scene()->removeItem(this);
            delete itemsZerstoeren[i];
            delete this;

            /*
             * Wozu ein return?
             * Codes laufen sequenziell ab
             * Wenn wir den Torpedo oben (bei Kollidierung) löschen,
             * weiß der Compiler weiter unten im Code nicht mehr, was mit dem
             * Torpedo geschen soll, denn wir haben den ja schon gelöscht
             * Um das zu umgehen returnen wir einfach
             */
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
