#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <random>
#include <ctime>

#include "dl_list.h"

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
    ui->lineEdit_3->clear();
    ui->lineEdit_max->clear();
    ui->lineEdit_min->clear();
    srand(static_cast<unsigned int>(time(nullptr)));

    DL_List<int> list;
    Queue<int> queue;

    QString line = "";
    int num, max = 0,min = 0;
    for(int i = 0; i < 30; i++)
    {
        num = rand()%99 - rand()%99;
        queue.push_back(num);
        line += QString::number(num) + ' ';
        if(max < num) max = num;
        else if(min > num) min = num;
    }
    ui->lineEdit_2->setText(line);

    QString rezult = "";
    while(queue.GetSize())
    {
        list.push_back(queue.GetFront());
        queue.pop_front();
        if(list.GetBack() == max || list.GetBack() == min)
        {
            while(queue.GetSize() && queue.GetFront() != max && queue.GetFront() != min)
            {
                rezult += QString::number(queue.GetFront()) + ' ';
                queue.pop_front();
            }
            if(queue.GetSize())
            {
                list.push_back(queue.GetFront());
                queue.pop_front();
            }
        }
    }
    ui->lineEdit_3->setText(rezult);
    ui->lineEdit->setText(line);
    ui->lineEdit_max->setText(QString::number(max));
    ui->lineEdit_min->setText(QString::number(min));

    line = "";
    for(int i = 0; i < list.GetSize(); i++)
        line += QString::number(list.GetData(i)) + ' ';
    ui->lineEdit_2->setText(line);
}
