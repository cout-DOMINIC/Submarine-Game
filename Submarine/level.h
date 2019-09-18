#ifndef LEVEL_H
#define LEVEL_H
#include <QGraphicsTextItem>

class Level: public QGraphicsTextItem
{

public:
    Level(QGraphicsItem *parent = nullptr);
    int level;

void setLevel(int l);
};

#endif
