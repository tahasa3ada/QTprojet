#include "sortiewindow.h"
#include "ui_sortiewindow.h"
#include "mainwindow.h"
#include <QString>
#include <QtSql>
#include <QPushButton>

SortieWindow::SortieWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SortieWindow)
{
    ui->setupUi(this);
    ui->pushButton_3->hide();

}

SortieWindow::~SortieWindow()
{
    delete ui;
}

void SortieWindow::on_pushButton_2_clicked()
{
    MainWindow *mainW = new MainWindow(this);
        this->hide();
       mainW->show();
}

void SortieWindow::on_pushButton_clicked()
{

    // validation de sortie


    //ui->label_10->setText("taha");
       int  q=ui->lineEdit->text().toInt();

       int cdp=ui->lineEdit_8->text().toInt();

   // ui->label_2->setText("valide");

    QSqlDatabase DB_Connect = QSqlDatabase::addDatabase("QSQLITE");
    DB_Connect.setDatabaseName("C:/Users/tahac/Desktop/satabase/gstock.db"); // path
    if (!DB_Connect.open()) {
        qDebug() << "Error opening database:"  ;
        // Handle the error as needed
    } else {
        qDebug() << "Connected";

            // Insert user data into the database
            if (DB_Connect.isOpen())
            {

                // Use a QSqlQuery object to perform the database operations
                QSqlQuery insertQuery(DB_Connect);

                // Use a transaction to ensure data consistency
                DB_Connect.transaction();

                insertQuery.prepare(" SELECT quantite_entree_stock  FROM produit WHERE code =:idp");
                //insertQuery.bindValue(":prix", p);
                insertQuery.bindValue(":idp", cdp);

                // Check if the query is executed successfully
                if (insertQuery.exec())
                {
                    if(insertQuery.next())
                    {
                        //qDebug() << "User data inserted successfully";
                        int quantiteStock = insertQuery.value(0).toInt();

                        ui->label_2->setNum(quantiteStock);
                        // Commit the transaction if the query is successful
                        DB_Connect.commit();
                        qDebug() << "Quantite stock:" << quantiteStock;
                                // Utilisez la valeur récupérée comme nécessaire
                        if(quantiteStock>q)
                        {
                            ui->label_4->setText("QUANTITE EXIXTE DANS LE STOCK OPERATION  VALIDE");
                            // nqp : nouvelle quantité de produit
                            qtsortie=q;
                            idprod =cdp;
                            prixsortie =ui->lineEdit_2->text().toFloat();
                            ui->pushButton_3->show();
                        }
                        else
                        {
                            ui->label_4->setText("QUANTITE DEPASSE LE STOCK OPERATION NON VALIDE");

                        }

                    }else {
                        qDebug() << "No data found for code:" << cdp;
                        ui->label_3->setText("PROQUIT N'EXSISTE PAS !!!");

                    }

                }
                else
                {
                    // If the query fails, rollback the transaction
                    qDebug() << "Error inserting user data:" << insertQuery.lastError().text();
                    DB_Connect.rollback();
                }
            }
            else
            {
                qDebug() << "Database not open";
            }

            // Close the database connection after finishing the operations

        }

}

void SortieWindow::on_SortieWindow_iconSizeChanged(const QSize &iconSize)
{


}


void SortieWindow::on_pushButton_3_clicked()
{







    QSqlDatabase DB_Connect = QSqlDatabase::addDatabase("QSQLITE");
    DB_Connect.setDatabaseName("C:/Users/tahac/Desktop/satabase/gstock.db"); // path
    if (!DB_Connect.open()) {
        qDebug() << "Error opening database:"  ;
        // Handle the error as needed
    } else {
        qDebug() << "Connected";

            // Insert user data into the database
            if (DB_Connect.isOpen())
            {

                // Use a QSqlQuery object to perform the database operations
                QSqlQuery insertQuery(DB_Connect);

                // Use a transaction to ensure data consistency
                DB_Connect.transaction();

                insertQuery.prepare(" SELECT * FROM produit WHERE code =:idp");
                insertQuery.bindValue(":idp", idprod);

                // Check if the query is executed successfully
                if (insertQuery.exec())
                {
                    if(insertQuery.next())
                    {
                        //qDebug() << "User data inserted successfully";
                        QString  nom   = insertQuery.value(1).toString();
                        int qpro =insertQuery.value(4).toInt();
                        // qtsortie ;
                        int idfoursortie = insertQuery.value(5).toInt();
                        ui->label_2->setNum(insertQuery.value(0).toInt());
                        float montant =qtsortie*prixsortie;
                        // Commit the transaction if the query is successful
                        DB_Connect.commit();
                        qDebug() << "nom:" << nom;
                        qDebug() << "id fournsseur :" << idfoursortie;
                        qDebug() << "code prodiot :" << idprod;
                        qDebug() << "quantité sortie  :" << qtsortie;
                        qDebug() << "prix  sortie  :" << prixsortie;
                        qDebug() << "montan  :" << montant;
                                // Utilisez la valeur récupérée comme nécessaire
                        insertQuery.prepare("INSERT INTO historiqueSORTIE (codedrouit, codefournisseur,nom,quantiteSORTIE,prixSORTIE,MONTANT ) VALUES(:codedrouit,:codefournisseur,:nom, :quantiteSORTIE, :prixSORTIE,:MONTANT)");
                        insertQuery.bindValue(":codedrouit", idprod);
                        insertQuery.bindValue(":codefournisseur", idfoursortie);
                        insertQuery.bindValue(":nom", nom);
                        insertQuery.bindValue(":quantiteSORTIE", qtsortie);
                        insertQuery.bindValue(":prixSORTIE",prixsortie);
                        insertQuery.bindValue(":MONTANT", montant);
                        // Check if the query is executed successfully
                        if (insertQuery.exec())
                        {
                            qDebug() << "User data update successfully";
                            // Commit the transaction if the query is successful
                            int nQ=qpro-qtsortie;
                            QSqlQuery updateQuery;
                            updateQuery.prepare("UPDATE produit SET quantite_entree_stock = :nouvelleQuantite WHERE code = :idp");

                                updateQuery.bindValue(":nouvelleQuantite", nQ);
                                updateQuery.bindValue(":idp", idprod);
                                qDebug() << "novelle q :" << nQ;
                                if (updateQuery.exec()) {
                                    qDebug() << "Mise à jour réussie.";
                                } else {
                                    qDebug() << "Échec de la mise à jour. Erreur : " << updateQuery.lastError().text();
                                }
                            DB_Connect.commit();
                        }
                        else
                        {
                            // If the query fails, rollback the transaction
                            qDebug() << "Error inserting user data:" << insertQuery.lastError().text();
                            DB_Connect.rollback();
                        }

                    }else {

                        qDebug() << "No data found for code:" << idprod;

                    }
                }
                else
                {
                    // If the query fails, rollback the transaction
                    qDebug() << "Error inserting user data:" << insertQuery.lastError().text();

                    DB_Connect.rollback();
                }
            }
            else
            {
                qDebug() << "Database not open";
            }

            // Close the database connection after finishing the operations

        }

}

void SortieWindow::on_label_4_linkActivated(const QString &link)
{


}
