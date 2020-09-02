#ifndef PAQUET_H
#define PAQUET_H


#include <QString>
#include <QVector>
#include <QFile>
#include <QTextStream>
#include <QTextEdit>
#include <QIODevice>
#include "CarteMemoire.h"
#include <QDir>
#include <QStringList>

class Paquet
{
    private:
        QString nomDossier;
        QVector<CarteMemoire> listeCarteMemoire;    //afin de stocker toutes les cartes mémoires du paquet

    public:
        QString getNomDossier() const;
        QVector<CarteMemoire> getListeCarteMemoire() const;

        Paquet(QString n);

        void setNomDossier(QString n);
        void setListeCarteMemoire(QVector<CarteMemoire> l);


        CarteMemoire creerCarteMemoire(QString nf, QString q, QString r);

        void chargerCarteMemoire(CarteMemoire& c, QString nf);
        //Cette fonction permet à partir d'un fichier texte de donner des valeurs
        //a chacun des attributs de l'objet CarteMemoire en parametre
        //l'attribut nf correspond au nom du fichier correspondant se trouvant dans le dossier représentant le paquet

        void supprimerCarteMemoire(CarteMemoire c);
        //Cette fonction supprime c de la liste des cartes mémoires et elle supprime aussi le fichier correspondant

        void ajouter(CarteMemoire cm); //Permet d'ajouter cm a la liste de cartes memoires

        void affichagePaquet() const;

        void modifierCarteMemoire(CarteMemoire& c, QString q, QString r);
        //En plus de la modification de l'objet CarteMemoire, cette fonction modifie aussi le contenu du fichier txt associé à cet objet.

        CarteMemoire rechercheCarteMemoire(QString nomFichier);

        QStringList listeFichier(const QString& p_path);

        bool unicite(QString n);
};

#endif // PAQUET_H
