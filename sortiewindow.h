#ifndef SORTIEWINDOW_H
#define SORTIEWINDOW_H

#include <QMainWindow>

namespace Ui {
class SortieWindow;
}

class SortieWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SortieWindow(QWidget *parent = nullptr);
    ~SortieWindow();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::SortieWindow *ui;

};

#endif // SORTIEWINDOW_H
