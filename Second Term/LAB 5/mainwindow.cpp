#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <random>
#include <ctime>
//#include "dl_list.h"
#include "newline.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->generateButton, SIGNAL(clicked()), this, SLOT (generateButton_clicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::generateButton_clicked()
{
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    srand(static_cast<unsigned int>(time(nullptr)));

    dlList<int> list;
    NewLine newline;

    QString line = "";
    int num, max = 0,min = 0, max_i = 0, min_i = 0;
    for(int i = 0; i < 30; i++)
    {
        num = rand()%99 - rand()%99;
        list.push_back(num);
        line += QString::number(num) + ' ';
        if(max < num)
        {
            max = num;
            max_i = i;
        }
        else if(min > num)
        {
            min = num;
            min_i = i;
        }
    }
    ui->lineEdit->setText(line);
    ui->lineEdit_max->setText(QString::number(max));
    ui->lineEdit_min->setText(QString::number(min));
    int iterator = max_i > min_i ? (max_i - min_i) : (min_i - max_i);
    int index = min_i < max_i ? min_i+1 : max_i+1;
    ui->lineEdit_2->setText(newline.getLine(list, index, iterator));
}
