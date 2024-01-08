#ifndef PRODUIT_H
#define PRODUIT_H
#include <QString>

class produit
{
public:
    produit(QString n,QString p,int q,float pr,int codf);
    // Getters
        QString getNom() const;
        QString getDescription() const;
        int getQanti()const;
        float getPrix() const;
        int getCodf() const ;



    // Setters
       void setNom(const QString &nom);
       void seteDscription(const QString &description);
       void setQanti(const int & qattite);
       void setPrix(const float & prix);
       void setCodf(int &cdf ) ;

private:
       QString nom;
       QString dscription;
       float  prix;
       int  qattite;
       int codfour;
};

#endif // PRODUIT_H
