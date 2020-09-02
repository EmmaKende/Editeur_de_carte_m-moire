#include "Fenetre.h"
#include "CarteMemoire.h"
#include "CentreControle.h"
#include "Paquet.h"

#include <QApplication>
#include <QDebug>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Fenetre w;
    w.show();

    return a.exec();
}
