#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QToolBar>
#include <QToolButton>
#include <QLineEdit>
#include <QLabel>
#include <QKeyEvent>

#include "parser.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    Parser<int> *parser;

    QToolBar *ToolBar;
    QToolButton *GenerateButton, *ClearButton, *DeleteMinus, *DeleteButton, *GetButton, *AddButton;
    QLineEdit *lineEdit_Size, *lineEdit_Items, *lineEdit_Item;
    QLabel *label_Size, *label_Items;

private slots:
    void generateButton_clicked();
    void clearButton_clicked();
    void deleteMinus_clicked();
    void deleteButton_clicked();
    void getButton_clicked();
    void addButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
