#include "highscore.h"
#include <QFont>

Highscore::Highscore(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    highscore = 0;

    setPlainText(QString("Highscore: ") + QString::number(highscore));
    setDefaultTextColor(Qt::red);
    setFont(QFont("arial", 25));
}

void Highscore::increase()
{
    ++highscore;
    setPlainText(QString("Highscore: ") + QString::number(highscore));
}

int Highscore::getHighscore()
{
    return highscore;
}

