#ifndef TORPEDO_H
#define TORPEDO_H
#include <QGraphicsPixmapItem>

/*
 * Jede Klasse, die SIGNALS und SLOTS benutzen soll,
 * muss von QObject abgeleitet werden
 */
#include <QObject>

class Torpedo: public QObject, public QGraphicsPixmapItem
{
    /*
     * QObject-Makro
     * Damit unser Torpedo-Objekt auch etwas mit SIGNALS UND SLOTS
     * anfangen kann
     * WICHTIG FÜR MAC-USER mit "architecture x86_64"
     * In der Pro File folgendes hinzufügen: CONFIG -= x86_64
     */
     Q_OBJECT

public:

    //Konstruktor vom Torpedo
    Torpedo(QGraphicsItem* parent = nullptr);

private slots:
    void move();
};

#endif // TORPEDO_H
