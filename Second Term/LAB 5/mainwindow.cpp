#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <random>
#include <ctime>
#include "dl_list.h"
//#include "newline.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    ui->textEdit->clear();
    ui->textEdit_2->clear();
    ui->textEdit_3->clear();
    srand(static_cast<unsigned int>(time(nullptr)));
    dlList<int> list;
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

    ui->textEdit->append("max: " + QString::number(max_i));
    ui->textEdit->append("min: " + QString::number(min_i));

    int iterator = max_i > min_i ? (max_i - min_i) : (min_i - max_i);
    int index = min_i < max_i ? min_i+1 : max_i+1;
    ui->textEdit_2->append("index " + QString::number(index));
    ui->textEdit_2->append("iterator" + QString::number(iterator));
    ui->textEdit_2->append("size " + QString::number(list.GetSize()));

    for(int i = 0; i < iterator-1; i++)
    {
        list.remove(index);
    }
    for(int i = 0; i < list.GetSize(); i++)
        ui->textEdit_3->append(QString::number(list.GetData(i)));
}
