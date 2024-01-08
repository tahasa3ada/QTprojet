#include "sortiewindow.h"
#include "ui_sortiewindow.h"
#include "mainwindow.h"
#include <QString>
#include <QtSql>
SortieWindow::SortieWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SortieWindow)
{
    ui->setupUi(this);
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
       float p=ui->lineEdit_2->text().toFloat();
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
                        }
                        else {
                            ui->label_4->setText("QUANTITE DEPASSE LE STOCK OPERATION NON VALIDE");

                        }

                    }else {
                        qDebug() << "No data found for code:" << cdp;
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
