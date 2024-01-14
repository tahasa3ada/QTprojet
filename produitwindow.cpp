#include "produitwindow.h"
#include "ui_produitwindow.h"
#include "mainwindow.h"
#include <QString>
#include <QtSql>
#include "produit.h"
ProduitWindow::ProduitWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ProduitWindow)
{
    ui->setupUi(this);
}

ProduitWindow::~ProduitWindow()
{
    delete ui;
}

void ProduitWindow::on_pushButton_clicked()
{
    MainWindow *mainW = new MainWindow(this);
        this->hide();
       mainW->show();
}

void ProduitWindow::on_pushButton_2_clicked()
{
    //ui->label_10->setText("taha");
       int  q=ui->lineEdit->text().toInt();
       float p=ui->lineEdit_2->text().toFloat();
       int cdf=ui->lineEdit_9->text().toInt();
    produit pr(ui->lineEdit_8->text(),ui->lineEdit_7->text(),q,p,cdf);

   // ui->label_3->setText(f.getNom());

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

                insertQuery.prepare("INSERT INTO produit (nom, description,prix,quantite_entree_stock,idfourni ) VALUES(:nom,:description , :prix, :quantite, :idfourni)");
                insertQuery.bindValue(":nom", pr.getNom());
                insertQuery.bindValue(":description", pr.getDescription());
                insertQuery.bindValue(":prix", pr.getPrix());
                insertQuery.bindValue(":quantite", q);
                insertQuery.bindValue(":idfourni",cdf);

                ui->label_10->setText("PRODUIT BIEN AJOUTE");
                // Check if the query is executed successfully
                if (insertQuery.exec())
                {
                    qDebug() << "User data inserted successfully";
                    // Commit the transaction if the query is successful
                    DB_Connect.commit();
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
