#ifndef HIGHSCORE_H
#define HIGHSCORE_H
#include <QGraphicsTextItem>

class Highscore: public QGraphicsTextItem
{

public:
    Highscore(QGraphicsItem *parent = nullptr);
    void increase();
    int getHighscore();
    int highscore;
};

#endif
