#include "score.h"
#include <QFont>

Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    score = 0;
    setPlainText(QString("Score: ") + QString::number(score));
    setDefaultTextColor(Qt::red);
    setFont(QFont("arial", 25));
}

void Score::increase()
{
    score += 1;
    setPlainText(QString("Score: ") + QString::number(score));
}

void Score::decrease()
{
    score -= 1;
    setPlainText(QString("Score: ") + QString::number(score));
}
int Score::getScore()
{
    return score;
}

