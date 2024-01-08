#ifndef FOURNISSEUR_H
#define FOURNISSEUR_H
#include <QString>
class fournisseur
{
public:
    fournisseur(QString n,QString p);
    // Getters
        QString getNom() const;
        QString getprenom() const;
    // Setters
       void setNom(const QString &nom);
       void setprenom(const QString &prenom);
private:
       QString nom;
       QString prenom;

};

#endif // FOURNISSEUR_H
