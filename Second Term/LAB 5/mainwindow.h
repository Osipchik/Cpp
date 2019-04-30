#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "dl_list.h"

#include <memory>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    DL_List<int> *list;

    //std::shared_ptr<DL_List<int>> list();

private slots:
    void on_pushButton_clicked();

    void on_GetFront_clicked();

    void on_popFront_clicked();

    void on_GetSize_clicked();

    void on_Clear_clicked();

    void on_Add_clicked();

    void on_Done_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
