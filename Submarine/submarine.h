#ifndef SUBMARINE_H
#define SUBMARINE_H
#include <QGraphicsPixmapItem>
#include <QMediaPlayer>
#include <QObject>
#include <QKeyEvent>

class Submarine: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    Submarine(QGraphicsItem* parent = nullptr);
    void keyPressEvent(QKeyEvent* event);
    QMediaPlayer* torpedoSound;

private slots:
    void spawn();
    void die();
};

#endif
