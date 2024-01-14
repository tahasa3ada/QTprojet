#include "historiquesortie.h"
#include "ui_historiquesortie.h"
#include <QtSql>
#include <QtDebug>
#include <QStandardItemModel>
#include "mainwindow.h"

historiquesortie::historiquesortie(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::historiquesortie)
{
    ui->setupUi(this);
    // Connect to the database
    QSqlDatabase DB_Connect = QSqlDatabase::addDatabase("QSQLITE");
    DB_Connect.setDatabaseName("C:/Users/tahac/Desktop/satabase/gstock.db"); // path
    if (!DB_Connect.open()) {
        qDebug() << "Error opening database:" << DB_Connect.lastError().text();
        // Handle the error as needed
    } else {
        qDebug() << "Connected";
    }

    // Setup the model and load data
    setupModel();
}
historiquesortie::~historiquesortie()
{
    delete ui;
}
void historiquesortie::setupModel()
{
    stockmodal = new QSqlQueryModel(this);
    stockmodal->setQuery("SELECT * FROM historiqueSORTIE");

    if (stockmodal->lastError().isValid()) {
        qDebug() << "Error executing query:" << stockmodal->lastError().text();
        // Handle the error as needed
    } else {
        // Set the model to the QTableView
        ui->tableView->setModel(stockmodal);
    }
}

void historiquesortie::on_pushButton_clicked()
{
    MainWindow *mainW = new MainWindow(this);
        this->hide();
       mainW->show();
}
