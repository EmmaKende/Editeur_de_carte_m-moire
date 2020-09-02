#ifndef CARTEMEMOIRE_H
#define CARTEMEMOIRE_H


#include <QString>

class CarteMemoire
{
    //Dans les faits une carte mémoire sera représentée par un fichier txt basique dont à la première ligne
    //on aura la question; à la deuxième ligne on aura la réponse; et la dernière caractéristique sera le nom du fichier.

    private:
        QString nomFichier;
        QString question;   //on se restraint ici à des questions et réponses assez simples qui ne comprendront pas de sauts à la ligne
        QString reponse;    //simples qui ne comprendront pas de sauts à la ligne par exemple ou encore plusieurs paragraphes

    public:
        QString getNomFichier() const;
        QString getQuestion() const;
        QString getReponse() const;

        CarteMemoire(QString nf, QString q, QString r);

        void setNomFicher(QString n);
        void setQuestion(QString q);
        void setReponse(QString r);

        bool egalite(CarteMemoire cm) const;  //test de l'égalité entre deux objets CarteMemoire en  se basant sur l'égalité des attributs

        QString affichage() const;
};


#endif // CARTEMEMOIRE_H
