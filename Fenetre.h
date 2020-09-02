#ifndef FENETRE_H
#define FENETRE_H
#include "QLineEdit"
#include <QMainWindow>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QLineEdit>
#include "Paquet.h"
#include "CentreControle.h"
#include "CarteMemoire.h"
#include <string.h>
#include "QString"
#include "QTextStream"
#include <iostream>
#include <QComboBox>
#include <QVector>
using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class Fenetre; }
QT_END_NAMESPACE

class Fenetre : public QMainWindow
{
    Q_OBJECT

public:
    Fenetre(QMainWindow *parent = nullptr);
    ~Fenetre();


private slots:
    void on_creer_clicked();

    void on_enregister_clicked();

    void on_afficher_clicked();

    void on_effacer_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_ok_clicked();

    void on_modifer_clicked();

    void on_chargement_clicked();


private:
    Ui::Fenetre *ui;
    //chemin d'accès où sont enregister les fichiers carte mémoire
    //const QString chemin = "C:\\Users\Emmakende\\Desktop\\Algo_L1_S2\\Carte_memoire\\CentreControle";

    // permet d'ecrire le nom d'un nouveau paquet a creer
    void ECRIRE( QLineEdit *zt,QString chaine );
    QString LIRE(QLineEdit *);
    QString VALEUR(QLineEdit *zt);
    void EFFACER(QLineEdit *zt);
};
#endif // FENETRE_H

