#ifndef PRODUITWINDOW_H
#define PRODUITWINDOW_H

#include <QMainWindow>

namespace Ui {
class ProduitWindow;
}

class ProduitWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ProduitWindow(QWidget *parent = nullptr);
    ~ProduitWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::ProduitWindow *ui;
};

#endif // PRODUITWINDOW_H
