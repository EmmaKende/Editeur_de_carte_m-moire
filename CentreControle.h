#ifndef CENTRECONTROLE_H
#define CENTRECONTROLE_H

#include <QString>
#include <QFile>
#include "CarteMemoire.h"
#include "Paquet.h"
#include <QVector>
#include <QDir>
#include <QStringList>

class CentreControle
{
    //Cette classe basera tout sont travail sur le dossier CentreControle qui a été créé pour l'occasion à l'interieur du projet
    //Dans les faits on aura besoin que d'une seule instance de cette classe
    private:
        QString nom;
        QVector<Paquet> listePaquet;

    public:
        QVector<Paquet> getListePaquet() const;

        //On se contentera ici du contructeur par défaut

        void setListePaquet(QVector<Paquet> l);
        void ajouter(Paquet p);

        Paquet creerPaquet(QString n);
        void supprimerPaquet(Paquet p);
        Paquet recherchePaquet(QString nomDossier);
        QStringList listeDossier(const QString& p_path);
        void chargementGlobale();

        bool unicite(QString n);
};



#endif // CENTRECONTROLE_H
