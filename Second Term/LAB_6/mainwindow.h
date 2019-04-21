#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QKeyEvent>
#include <QTableWidget>
#include <QTreeWidget>

//#include "avl-tree.h"
#include "tree.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    //AVL_Tree<QString> tree;
    Tree<QString> tree;
    Queue<QString> queue;

private slots:

    void on_DeleteButton_clicked();

private:
    Ui::MainWindow *ui;

    virtual void keyPressEvent(QKeyEvent *event);
};

#endif // MAINWINDOW_H
