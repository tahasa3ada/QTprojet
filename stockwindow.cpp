#include "stockwindow.h"
#include "ui_stockwindow.h"
#include "mainwindow.h"
#include "sortiewindow.h"
#include <QStandardItemModel>
#include <QtSql>
#include <QtDebug>


StockWindow::StockWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StockWindow)
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

StockWindow::~StockWindow()
{
    delete ui;
}

void StockWindow::on_pushButton_clicked()
{
 MainWindow *mainW = new MainWindow(this);
     this->hide();
    mainW->show();
}

void StockWindow::setupModel()
{
    stockmodal = new QSqlQueryModel(this);
    stockmodal->setQuery("SELECT * FROM produit");

    if (stockmodal->lastError().isValid()) {
        qDebug() << "Error executing query:" << stockmodal->lastError().text();
        // Handle the error as needed
    } else {
        // Set the model to the QTableView
        ui->tableView->setModel(stockmodal);
    }
}


/*
// userwindows.cpp
#include "userwindows.h"
#include "ui_userwindows.h"
#include <QtSql>
#include <QtDebug>
#include <QStandardItemModel>
#include "mainwindow.h"

UserWindows::UserWindows(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::UserWindows)
{
    ui->setupUi(this);

    // Connect to the database
    DB_Connect = QSqlDatabase::addDatabase("QSQLITE");
    DB_Connect.setDatabaseName("C:/Users/chari/OneDrive/Bureau/CinemaQT/database/cinema.db");
    if (!DB_Connect.open()) {
        qDebug() << "Error opening database:" << DB_Connect.lastError().text();
        // Handle the error as needed
    } else {
        qDebug() << "Connected";
    }

    // Setup the model and load data
    setupModel();
}

UserWindows::~UserWindows()
{
    delete ui;
}

void UserWindows::setupModel()
{
    filmModel = new QSqlQueryModel(this);
    filmModel->setQuery("SELECT * FROM film");

    if (filmModel->lastError().isValid()) {
        qDebug() << "Error executing query:" << filmModel->lastError().text();
        // Handle the error as needed
    } else {
        // Set the model to the QTableView
        ui->tableView->setModel(filmModel);
    }
}
*/

void StockWindow::on_pushButton_3_clicked()
{
    this->hide();
    so=new SortieWindow(this);
    so->show();
    //ui->pushButton_3->hide();
}
