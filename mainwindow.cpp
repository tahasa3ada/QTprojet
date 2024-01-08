#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    this->hide();
    st=new StockWindow(this);
    st->show();
}

void MainWindow::on_pushButton_2_clicked()
{
    this->hide();
    pr=new ProduitWindow(this);
    pr->show();
}

void MainWindow::on_pushButton_3_clicked()
{

    this->hide();
    fr=new FournisserWindow(this);
    fr->show();


}
