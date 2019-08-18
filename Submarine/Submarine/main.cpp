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

    // neue Scene erstellt auf dem Heap
    QGraphicsScene* neueScene = new QGraphicsScene();

    // neue View erstellt auf dem Heap
    QGraphicsView* neueView = new QGraphicsView(neueScene);
    neueView->show();

    // neuen Spiele erstellt auf dem Heap
    Submarine* submarine = new Submarine();

    // Bild für mein Submarine
    submarine->setPixmap(QPixmap(":/new/images/submarine.png"));
    neueScene->addItem(submarine);

    /*
     * Unser Objekt muss auf das KeyEvent reagieren
     * ABER, ein QGraphicsItem kann nur auf EIN KeyEvent zur gleichen Zeit reagieren!
     * Und um das zu realisieren, brauchen wir ein FOCUSED-Item bzw. unser Item
     * muss FOCUSED werden
     */
    submarine->setFlag(QGraphicsItem::ItemIsFocusable);
    submarine->setFocus();

    // Der View eine fixe Größe gegeben
    neueView->setFixedSize(1200, 800);

    /*
     * Meiner Scene die selbe Größe wie View geben
     * Parameterliste (0, 0 <- vom View (linke, obere Ecke von View)
     * - von da aus, soll die Größe von Scene definiert werden)
     * Die letzten beiden Parameter sind dann die Größe von Scene
     * bzw. die selbe Größe wie View
     */
    neueScene->setSceneRect(0, 0, 1200, 800);

    /*
     * Scrollen unserer View (Up & Down) ausgeschaltet
     * Warum? Sobald unser Torpedo das obere Ende erreicht hat,
     * wurde nach oben gescrollt automatisch.
     * Deshalb das Scrollen ausgeschaltet.
     */
    neueView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    neueView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // Hintergrundbild
    QBrush brush(QBrush(QImage(":/new/images/underSea.jpg")));
    neueScene->setBackgroundBrush(brush);

    /*
     * Position vom Submarine-Objekt muss definiert werden
     * Da die Größe der View und Scene definiert wurde,
     * landet das Submarine-Objekt in der linken oberen Ecke
     * Warum? Das Objekt wird an die selbe Position gepackt,
     * wie die Scene (automatisch). Das ist eine Voreinstellung
     * Jedes Mal, wenn ein neues Item zur Scene hinzugefügt wird,
     * landet es bei den 0, 0 Koordinaten von Scene
     */
    submarine->setPos(neueView->width()/2, neueView->height()/1.2);
    /*
     * Position vom Objekt
     * Um das Objekt mittig zu setzen, nehmen wir die Hälfte der width
     * von der View, also width geteilt durch 2. width() und height()
     * sind Member-Funktionen
     * Die Höhe durch ausprobieren definiert.. geht bestimmt auch noch
     * anders
     */

    /*
     * Gegner erzeugen
     * Die Gegner werden in submarine.cpp erzeugt
     * in der main.cpp haben wir submarine.h inkludiert,
     * also haben wir Zugriff auf die Gegner und auf die
     * spawn()-Member-Function
     */
    QTimer* timer = new QTimer();

    /*
     * Nach einem timeout(), passiert ein spawn()
     */
    QObject::connect(timer, SIGNAL(timeout()), submarine, SLOT(spawn()));
    timer->start(2200);

    // Hintergrundmusik
    QMediaPlayer* sounds = new QMediaPlayer();
    sounds->setMedia(QUrl("qrc:/new/sounds/submarine.mp3"));
    sounds->play();

    // Highscore zur Scene hinzufügen
    Highscore* highscore = new Highscore();
    neueScene->addItem(highscore);

    return a.exec();
}
