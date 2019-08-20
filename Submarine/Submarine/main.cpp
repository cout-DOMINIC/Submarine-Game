#include <QApplication>
#include <QGraphicsScene>
#include "submarine.h"
#include <QGraphicsView>
#include "highscore.h"
#include <QMediaPlayer>
#include <QBrush>
#include <QImage>
#include <QTimer>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QGraphicsScene* neueScene = new QGraphicsScene();
    QGraphicsView* neueView = new QGraphicsView(neueScene);
    neueView->show();

    Submarine* submarine = new Submarine();
    submarine->setPixmap(QPixmap(":/new/images/submarine.png"));
    neueScene->addItem(submarine);
    submarine->setFlag(QGraphicsItem::ItemIsFocusable);
    submarine->setFocus();

    neueView->setFixedSize(1200, 800);
    neueScene->setSceneRect(0, 0, 1200, 800);
    neueView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    neueView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    QBrush brush(QBrush(QImage(":/new/images/underSea.jpg")));
    neueScene->setBackgroundBrush(brush);

    submarine->setPos(neueView->width()/2, neueView->height()/1.2);
    QTimer* timer = new QTimer();

    QObject::connect(timer, SIGNAL(timeout()), submarine, SLOT(spawn()));
    timer->start(2200);

    QMediaPlayer* sounds = new QMediaPlayer();
    sounds->setMedia(QUrl("qrc:/new/sounds/submarine.mp3"));
    sounds->play();

    Highscore* highscore = new Highscore();
    neueScene->addItem(highscore);

    return a.exec();
}
