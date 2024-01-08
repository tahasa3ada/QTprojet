#ifndef STOCKWINDOW_H
#define STOCKWINDOW_H

#include <QMainWindow>
#include <QSqlQueryModel>
#include "sortiewindow.h"
namespace Ui {
class StockWindow;
}

class StockWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit StockWindow(QWidget *parent = nullptr);
    ~StockWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::StockWindow *ui;
    QSqlQueryModel *stockmodal;
    SortieWindow *so;
     void setupModel();

};

#endif // STOCKWINDOW_H
