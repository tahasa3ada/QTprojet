#ifndef HISTORIQUESORTIE_H
#define HISTORIQUESORTIE_H
#include <QString>

#include <QMainWindow>
#include <QSqlQueryModel>

namespace Ui {
class historiquesortie;
}

class historiquesortie : public QMainWindow
{
    Q_OBJECT

public:
    explicit historiquesortie(QWidget *parent = nullptr);
    ~historiquesortie();

private slots:
    void on_pushButton_clicked();

private:
    Ui::historiquesortie *ui;
    QSqlQueryModel *stockmodal;
     void setupModel();
};

#endif // HISTORIQUESORTIE_H
