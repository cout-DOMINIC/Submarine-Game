#ifndef SPIEL_H
#define SPIEL_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "submarine.h"
#include "score.h"
#include "level.h"

class Spiel: public QGraphicsView{
public:
    Spiel();
    QGraphicsScene * scene;
    Submarine * submarine;
    Score * score;
    Level * level;

public slots:
    void spawn();
};

#endif
