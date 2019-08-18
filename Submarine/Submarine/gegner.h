/*
 * Die gegner.h Headerfile ist vom Code
 * her das Selbe, wie torpedo.h
 * Deswegen keine weitere Erklärungen hier.
 * DRY wird leider nicht eingehalten, aber
 * das war so die beste und einfachste
 * Lösung für uns
 */

#ifndef GEGNER_H
#define GEGNER_H

#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QObject>

class Gegner: public QObject, public QGraphicsPixmapItem
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
    Gegner(QGraphicsItem* parent = nullptr);

private slots:
    void move();
};

#endif // GEGNER_H
