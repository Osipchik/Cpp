#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QToolBar>
#include <QToolButton>
#include <QLineEdit>
#include <QLabel>
#include <QKeyEvent>

//#include "hash.h"
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
    QToolBar *ToolBar;
    QToolButton *GenerateButton, *ClearButton, *DeleteMinus;
    QLineEdit *lineEdit_Size, *lineEdit_Items;
    QLabel *label_Size, *label_Items;

    Parser<int> *parser;

private slots:
    void generateButton_clicked();
    void clearButton_clicked();
    void deleteMinus_clicked();

private:
    Ui::MainWindow *ui;

    virtual void keyPressEvent(QKeyEvent *event);
};

#endif // MAINWINDOW_H
