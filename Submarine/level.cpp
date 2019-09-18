#include "level.h"
#include <QFont>

Level::Level(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    setPlainText(QString("Level: ") + QString::number(level));
    setDefaultTextColor(Qt::white);
    setFont(QFont("arial", 25));
    setPos(x() ,y()+30);
    level = 0;
}

void Level::setLevel(int l){
     level = l;
     setPlainText(QString(" Level: ") + QString::number(level));
}


