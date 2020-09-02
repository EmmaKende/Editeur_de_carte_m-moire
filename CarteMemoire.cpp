#include "CarteMemoire.h"


QString CarteMemoire::getNomFichier() const
{
    return nomFichier;
}

QString CarteMemoire::getQuestion() const
{
    return question;
}

QString CarteMemoire::getReponse() const
{
    return reponse;
}

CarteMemoire::CarteMemoire(QString nf, QString q, QString r): nomFichier(nf), question(q), reponse(r)
{

}

void CarteMemoire::setNomFicher(QString n)
{
    nomFichier=n;
}

void CarteMemoire::setQuestion(QString q)
{
    question=q;
}

void CarteMemoire::setReponse(QString r)
{
    reponse=r;
}

bool CarteMemoire::egalite(CarteMemoire cm) const
{
    return (nomFichier==cm.nomFichier);
}

QString CarteMemoire::affichage() const
{
    return "Question : "+question+"\n"+"Réponse : "+reponse+"\n";
}
