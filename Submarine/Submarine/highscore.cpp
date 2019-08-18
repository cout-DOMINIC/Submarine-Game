#include "highscore.h"
#include <QFont>

Highscore::Highscore(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    // Den Highscore zuerst initialisieren
    highscore = 0;

    setPlainText(QString("Highscore: ") + QString::number(highscore));
    setDefaultTextColor(Qt::red);
    setFont(QFont("arial", 25));
}

void Highscore::increase()
{
    highscore++;

    /*
     * Wenn der Highscore sich erhöht, muss sich auch der
     * Text ändern bzw. die Anzahl, wie viele Gegner ich
     * getroffen habe
     */
    setPlainText(QString("Highscore: ") + QString::number(highscore));
}

int Highscore::getHighscore()
{
    return highscore;
}

