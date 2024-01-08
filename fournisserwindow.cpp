#include "fournisserwindow.h"
#include"fournisseur.h"
#include "ui_fournisserwindow.h"
#include "mainwindow.h"
#include <QDebug>
#include <QtSql>

FournisserWindow::FournisserWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FournisserWindow)
{
    ui->setupUi(this);
}

FournisserWindow::~FournisserWindow()
{
    delete ui;
}

void FournisserWindow::on_pushButton_clicked()
{
    MainWindow *mainW = new MainWindow(this);
        this->hide();
       mainW->show();
}

void FournisserWindow::on_pushButton_2_clicked()
{
    fournisseur f(ui->lineEdit->text(),ui->lineEdit_2->text());
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
                   ui->label_3->setText(f.getNom());
                // Use a QSqlQuery object to perform the database operations
                QSqlQuery insertQuery(DB_Connect);

                // Use a transaction to ensure data consistency
                DB_Connect.transaction();

                insertQuery.prepare("INSERT INTO fournisseurs (nom, prenom) VALUES(:nom, :prenom )");
                insertQuery.bindValue(":nom", f.getNom());
                insertQuery.bindValue(":prenom", f.getprenom());


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
