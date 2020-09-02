#include "Fenetre.h"
#include "ui_Fenetre.h"
#include <QTextEdit>
#include <QDebug>


CentreControle A;
Paquet paquetCourant("");
CarteMemoire carteCourante("", "", "");
int compteur(0);


Fenetre::Fenetre(QMainWindow *parent)
    : QMainWindow(parent)
    , ui(new Ui::Fenetre)
{
    ui->setupUi(this);
}


Fenetre::~Fenetre()
{
    delete ui;
}

void Fenetre::ECRIRE(QLineEdit *zt, QString chaine)
{
    zt->setText(chaine);
}
QString Fenetre::LIRE(QLineEdit *zt)
{
   return zt->text();
}
QString Fenetre::VALEUR(QLineEdit *zt)
{
    //permet de récuperer ma chaine de caractère rentrer dans le Qline
    return LIRE(zt);
}

void Fenetre::on_creer_clicked()
{//ui->ZoneTexte->setText(ui->Liste->currentItem()->text());
    QString a = ui->creer_paquet->text();
    Paquet n= A.creerPaquet(a);
    paquetCourant=n;

   EFFACER(ui->creer_paquet);
   //on affiche ici le dossier creér dans la liste déroulante des paquets
   ui->liste->addItem(a);
}

void Fenetre::on_enregister_clicked()
{
    // pour créer un carte memoire dans le dossier créer précedemment
    QString da= ui->liste->currentText();
    paquetCourant = A.recherchePaquet(da);
    QString a= ui->memoire->text() ; // on recupère le nom de la carte memoire
    QString x= ui->question->text(); // on recupère la question
    QString y= ui->reponse->text();  //on recupère la reponse


    CarteMemoire fichier= paquetCourant.creerCarteMemoire(a,x,y);
    ui->carte->addItem(a);
    QString de= ui->carte->currentText();
    carteCourante=paquetCourant.rechercheCarteMemoire(de);
}

void Fenetre::on_afficher_clicked() {
    QString da= ui->carte->currentText();
    carteCourante=paquetCourant.rechercheCarteMemoire(da);
    QString q = carteCourante.getQuestion();
    QString r =carteCourante.getReponse();
    ui->question2->setText(q);
    ui->reponse2->setText(r);
}

void Fenetre::EFFACER(QLineEdit *zt)
{
    zt->clear();
}

void Fenetre::on_effacer_clicked()
{
    EFFACER(ui->reponse);
    EFFACER(ui->question);
    EFFACER(ui->creer_paquet);
}

void Fenetre::on_pushButton_clicked()
{
    this->close();
}


void Fenetre::on_pushButton_2_clicked()
{
    on_afficher_clicked();
    paquetCourant.supprimerCarteMemoire(carteCourante);
    carteCourante =  CarteMemoire("", "", "");
    EFFACER(ui->question2);
    EFFACER(ui->reponse2);
    ui->carte->clear();
    for(int i(0); i<paquetCourant.getListeCarteMemoire().size(); i++) {
        ui->carte->addItem(paquetCourant.getListeCarteMemoire()[i].getNomFichier());
    }
}

void Fenetre::on_pushButton_3_clicked() {
    A.supprimerPaquet(paquetCourant);
    paquetCourant = Paquet("");
    EFFACER(ui->reponse);
    EFFACER(ui->question);
    EFFACER(ui->memoire);
    ui->liste->clear();
    for(int i(0); i<A.getListePaquet().size(); i++) {
        ui->liste->addItem(A.getListePaquet()[i].getNomDossier());
    }
}

void Fenetre::on_ok_clicked() {
    QString da= ui->liste->currentText();
    paquetCourant = A.recherchePaquet(da);
    ui->carte->clear();
    for(int i(0); i<paquetCourant.getListeCarteMemoire().size(); i++) {
        ui->carte->addItem(paquetCourant.getListeCarteMemoire()[i].getNomFichier());
    }
}

void Fenetre::on_modifer_clicked() {
    QString question = ui->question2->text();
    QString reponse = ui->reponse2->text();
    for(int i(0); i<paquetCourant.getListeCarteMemoire().size(); i++) {
        if(carteCourante.getNomFichier()==paquetCourant.getListeCarteMemoire()[i].getNomFichier()) paquetCourant.modifierCarteMemoire(paquetCourant.getListeCarteMemoire()[i], question, reponse);
        return;
    }
}

void Fenetre::on_chargement_clicked() {
    if (compteur==0) {
        A.chargementGlobale();
        compteur++;
        for(int i(0); i<A.getListePaquet().size(); i++) {
            ui->liste->addItem(A.getListePaquet()[i].getNomDossier());
        }
    }
}
