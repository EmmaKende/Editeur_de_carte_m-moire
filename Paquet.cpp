#include "Paquet.h"
#include "CarteMemoire.h"

using namespace std;

QString Paquet::getNomDossier() const
{
    return nomDossier;
}

QVector<CarteMemoire> Paquet::getListeCarteMemoire() const
{
    return listeCarteMemoire;
}

Paquet::Paquet(QString n): nomDossier(n)
{

}

void Paquet::setNomDossier(QString n)
{
    nomDossier=n;
}

void Paquet::setListeCarteMemoire(QVector<CarteMemoire> l)
{
    listeCarteMemoire=l;
}

CarteMemoire Paquet::creerCarteMemoire(QString nf, QString q, QString r)
{
    QString const chemin("CentreControle/"+nomDossier+"/"+nf);
    QFile fichier(chemin);
    QTextStream flux(&fichier);
    if(fichier.open(QIODevice::WriteOnly)) {
        flux << q <<endl;
        flux << r <<endl;
        fichier.close();
    }
    else {
        QTextEdit zoneTexte;
        zoneTexte.setText("ERREUR: concernant l'ouverture d'un fichier pour la création d'une carte mémoire.");
        zoneTexte.setGeometry(100,100,400,100);
        zoneTexte.setReadOnly(true);
        zoneTexte.show();
    }
    CarteMemoire cm(nf, q, r);
    listeCarteMemoire.push_back(cm);
    return cm;
}

void Paquet::chargerCarteMemoire(CarteMemoire& c, QString nf)
{
    QString const chemin("CentreControle/"+nomDossier+"/"+nf);
    QFile fichier(chemin);
    QTextStream flux(&fichier);
    QString question, reponse;
    if(fichier.open(QIODevice::ReadOnly|QIODevice::Text)) {
        question=flux.readLine();
        reponse=flux.readLine();
        c.setNomFicher(nf);
        c.setQuestion(question);
        c.setReponse(reponse);
    }
    else {
        QTextEdit zoneTexte;
        zoneTexte.setText("ERREUR: Impossible d'ouvrir un fichier pour le chargement d'une carte mémoire.");
        zoneTexte.setGeometry(100,100,400,100);
        zoneTexte.setReadOnly(true);
        zoneTexte.show();
    }
}

void Paquet::supprimerCarteMemoire(CarteMemoire c)
{
    int indexe;
    for(indexe=0; indexe<listeCarteMemoire.size(); indexe++) {
        if (c.egalite(listeCarteMemoire[indexe])) break;
    }
    listeCarteMemoire.erase(listeCarteMemoire.begin()+indexe);
    QString const chemin("CentreControle/"+nomDossier+"/"+c.getNomFichier());
    QFile::remove(chemin);
}

void Paquet::ajouter(CarteMemoire cm)
{
    listeCarteMemoire.push_back(cm);
}

void Paquet::affichagePaquet() const
{
    for(int i(0); i<listeCarteMemoire.size(); i++) {
        listeCarteMemoire[i].affichage();
    }
}

void Paquet::modifierCarteMemoire(CarteMemoire& c, QString q, QString r)
{
    c.setQuestion(q);
    c.setReponse(r);
    QString const chemin("CentreControle/"+nomDossier+"/"+c.getNomFichier());
    QFile fichier(chemin);
    QTextStream flux(&fichier);
    if(fichier.open(QIODevice::WriteOnly)) {
        flux << q <<endl;
        flux << r <<endl;
        fichier.close();
    }
    else {
        QTextEdit zoneTexte;
        zoneTexte.setText("ERREUR: Impossible d'ouvrir un fichier pour la modification d'une carte mémoire.");
        zoneTexte.setGeometry(100,100,400,100);
        zoneTexte.setReadOnly(true);
        zoneTexte.show();
    }
}
CarteMemoire Paquet::rechercheCarteMemoire(QString nomFichier) {
    for(int i(0); i<listeCarteMemoire.size(); i++) {
        if (listeCarteMemoire[i].getNomFichier()==nomFichier) {
            return listeCarteMemoire[i];
        }
    }
    CarteMemoire cm(nomFichier, "", "");
    return cm;
}

QStringList Paquet::listeFichier(const QString& p_path)
{
    QDir l_path(p_path);
    l_path.setFilter(QDir::Files);
    return l_path.entryList();
}

bool Paquet::unicite(QString n) {
    for(int i(0); i<listeCarteMemoire.size(); i++) {
        if (listeCarteMemoire[i].getNomFichier()==n) return false;
    }
    return true;
}
