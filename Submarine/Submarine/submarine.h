#ifndef SUBMARINE_H
#define SUBMARINE_H
#include <QGraphicsPixmapItem>
#include <QMediaPlayer>

/*
 * Jede Klasse, die SIGNALS und SLOTS benutzen soll,
 * muss von QObject abgeleitet werden
 */
#include <QObject>

/*
 * KeyEvent importieren, da Objekte sonst nicht auf
 * Eingaben reagieren können
 */
#include <QKeyEvent>

class Submarine: public QObject, public QGraphicsPixmapItem
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

    //Konstruktor
    Submarine(QGraphicsItem* parent = nullptr);

    /*
     * Die Member-Function (keyPressEvent) "erlaubt" meinem Player-Objekt
     * auf meine Tastatur zu reagieren, wenn gedrückt wird
     */
    void keyPressEvent(QKeyEvent* event);

    QMediaPlayer* torpedoSound;

private slots:

    // Member-Function um Gegner zu erzeugen
    void spawn();

    // Member-Function, wenn der Submarine stirbt
    void die();

};

#endif // SUBMARINE_H
