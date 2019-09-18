#include "spiel.h"
#include <QApplication>
#include <QGraphicsTextItem>
#include <QFont>
#include <QTimer>
#include "gegner.h"
#include <QMediaPlayer>
#include <QImage>
#include <QGraphicsItem>
#include <QList>
#include <QGraphicsScene>

    Spiel::Spiel(){
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,1200,800);
    setBackgroundBrush(QBrush(QImage(":/imgs/bg.jpg")));
    setScene(scene);
    setFixedSize(1200,800);
    Submarine* submarine = new Submarine();
    submarine->setPixmap(QPixmap(":/new/images/submarine.png"));
    scene->addItem(submarine);
    submarine->setFlag(QGraphicsItem::ItemIsFocusable);
    submarine->setFocus();
    QBrush brush(QBrush(QImage(":/new/images/underSea.jpg")));
    scene->setBackgroundBrush(brush);
    submarine->setPos(scene->width()/2, scene->height()/1.2);
    QTimer* timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), submarine, SLOT(spawn()));
    timer->start(2200);
    QMediaPlayer* sounds = new QMediaPlayer();
    sounds->setMedia(QUrl("qrc:/new/sounds/submarine.mp3"));
    sounds->play();
    score = new Score();
    scene->addItem(score);
    level = new Level();
    level->setLevel(0);
    scene-> addItem(level);

qDebug() << level;
}


