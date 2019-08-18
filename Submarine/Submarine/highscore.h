#ifndef HIGHSCORE_H
#define HIGHSCORE_H

// Qt-Bibliothek um Texte hinzuzufügen
#include <QGraphicsTextItem>

// Klasse Highscore wird von QGraphicsTextItem abgeleitet
class Highscore: public QGraphicsTextItem
{

public:

    /*
     * Bei Default, wenn mein QGraphicsItem kein parent bekommt,
     * dann hat es auch keinen parent
     */
    Highscore(QGraphicsItem *parent = nullptr);

    // Member-Function um den Highscore zu erhöhen
    void increase();

    // getter-Methode, die den Highscore einfach returned
    int getHighscore();

    // variable deklariert
    int highscore;

};

#endif // HIGHSCORE_H
