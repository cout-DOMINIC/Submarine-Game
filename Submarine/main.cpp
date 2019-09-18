#include <QApplication>
#include "spiel.h"

Spiel * spiel;

int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    spiel = new Spiel();
    spiel->show();
    return a.exec();
}
