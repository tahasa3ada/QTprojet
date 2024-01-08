#ifndef FOURNISSERWINDOW_H
#define FOURNISSERWINDOW_H

#include <QMainWindow>

namespace Ui {
class FournisserWindow;
}

class FournisserWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit FournisserWindow(QWidget *parent = nullptr);
    ~FournisserWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::FournisserWindow *ui;
};

#endif // FOURNISSERWINDOW_H
