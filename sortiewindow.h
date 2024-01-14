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

    void on_SortieWindow_iconSizeChanged(const QSize &iconSize);

    void on_pushButton_3_clicked();

    void on_label_4_linkActivated(const QString &link);

private:
    Ui::SortieWindow *ui;
    int idprod;  // Variable à passer entre les boutons
    int qtsortie;
    float prixsortie;

};

#endif // SORTIEWINDOW_H
