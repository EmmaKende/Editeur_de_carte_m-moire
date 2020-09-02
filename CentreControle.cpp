#include "CentreControle.h"

QVector<Paquet> CentreControle::getListePaquet() const
{
    return listePaquet;
}

void CentreControle::setListePaquet(QVector<Paquet> l)
{
    listePaquet=l;
}

void CentreControle::ajouter(Paquet p)
{
    QString const chemin("CentreControle/"+p.getNomDossier());
    QDir().mkdir(chemin);
    listePaquet.push_back(p);
}

Paquet CentreControle::creerPaquet(QString n)
{
    QString const chemin("CentreControle/"+n);
    QDir().mkpath(chemin);
    Paquet paquet(n);
    listePaquet.push_back(paquet);
    return paquet;
}

void CentreControle::supprimerPaquet(Paquet p)
{
    int indexe;
    for(indexe=0; indexe<listePaquet.size(); indexe++) {
        if (p.getNomDossier()==listePaquet[indexe].getNomDossier()) break;
    }
    listePaquet.erase(listePaquet.begin()+indexe);
    QString const chemin(nom+"CentreControle/"+p.getNomDossier());
    QDir dossier(chemin);
    dossier.removeRecursively();
}
Paquet CentreControle::recherchePaquet(QString nomDossier) {

    for(int i(0); i<listePaquet.size(); i++) {
        if (listePaquet[i].getNomDossier()==nomDossier) {
            return listePaquet[i];
        }
    }
    Paquet p(nomDossier);
    return p;
}

QStringList CentreControle::listeDossier(const QString& p_path)
{
    QDir l_path(p_path);
    l_path.setFilter(QDir::AllDirs); // On ne récupère que les dossiers
    return l_path.entryList();
}


void CentreControle::chargementGlobale() {
    QStringList dossiers = listeDossier("CentreControle");
    for(int i(0); i<dossiers.size(); i++) {
        if(dossiers[i]!="."&&dossiers[i]!="..") listePaquet.push_back(Paquet(dossiers[i]));
    }

    for(int i(0); i< listePaquet.size(); i++) {
        QStringList fichiers = listePaquet[i].listeFichier("CentreControle/"+dossiers[i]);
        CarteMemoire cm("", "", "");
        for(int j(0); j<fichiers.size(); j++) {
            listePaquet[i].chargerCarteMemoire(cm, fichiers[j]);
            listePaquet[i].ajouter(cm);
        }
    }
}

bool CentreControle::unicite(QString n) {
    for(int i(0); i<listePaquet.size(); i++) {
        if (listePaquet[i].getNomDossier()==n) return false;
    }
    return true;
}
