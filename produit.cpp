#include "produit.h"

produit::produit(QString n,QString d,int q,float pr,int codf)
{
 setNom(n);
 setPrix(pr);
 setQanti(q);
 seteDscription(d);
 setCodf(codf);
}

//Getter implementations
QString produit::getNom() const {
    return nom;
}
QString produit::getDescription() const {
    return dscription;
}

int produit::getQanti() const {
    return qattite;
}
int produit::getCodf() const {
    return codfour;
}
float produit::getPrix() const {
    return prix;
}
// Setter implementations
void produit::setNom(const QString &Nom) {
    nom = Nom;
}
void produit::seteDscription(const QString &Description) {
    dscription = Description;
}
void produit::setPrix(const float &Prix) {
    prix = Prix;
}
void produit::setQanti(const int &qt) {
    qattite = qt;
}
void produit::setCodf(int &cdf) {
    qattite = cdf;
}
