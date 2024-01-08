#include "fournisseur.h"
#include <QString>
#include <QtSql>
fournisseur::fournisseur(QString n,QString p)
{

    setNom(n);
    setprenom(p);
    // Connect to the database


}

// Getter implementations
QString fournisseur::getNom() const {
    return nom;
}
QString fournisseur::getprenom() const {
    return prenom;
}

// Setter implementations
void fournisseur::setNom(const QString &Nom) {
    nom = Nom;
}

void fournisseur::setprenom(const QString &Prenom) {
    prenom = Prenom;
}
