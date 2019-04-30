#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include <random>
#include <ctime>
#include <QIntValidator>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    list = new DL_List<int>();
    ui->lineEdit->setValidator(new QIntValidator);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    ui->textEdit->clear();
    ui->lineEdit->clear();
    ui->minEdit->clear();
    ui->maxEdit->clear();
    if(list->GetSize()) list->clear();

    QString generate = "";
    int min = 1000, max = -1000;
    srand(static_cast<unsigned int>(time(nullptr)));
    for(int i = 0, rnd; i < 20; i++)
    {
        rnd = rand()%100 - rand()%100;
        list->push_back(rnd);
        min = min > rnd ? rnd : min;
        max = max < rnd ? rnd : max;
        generate += QString::number(rnd) + "  ";
    }
    ui->maxEdit->setText(QString::number(max));
    ui->minEdit->setText(QString::number(min));
    ui->textEdit->append(generate);
}



void MainWindow::on_GetFront_clicked()
{
    if(list->GetSize())
    {
        QMessageBox::about(this, "Front item", "Front item: " + QString::number(list->GetFront()));
    }
}

void MainWindow::on_popFront_clicked()
{
    int size = list->GetSize();
    if(size)
    {
        list->pop_front();
        ui->textEdit->clear();
        ui->lineEdit->clear();
        ui->minEdit->clear();
        ui->maxEdit->clear();

        QString line = "";
        int min = 0, max = 0;
        if(size-1)
        {
            min = list->GetBack();
            max = list->GetBack();
        }
        for(int i = 0, item; i < size - 1; i++)
        {
            item = list->GetData(i);
            line += QString::number(item) + "  ";
            min = min > item ? item : min;
            max = max < item ? item : max;
        }
        ui->maxEdit->setText(QString::number(max));
        ui->minEdit->setText(QString::number(min));
        ui->textEdit->append(line);
    }
}

void MainWindow::on_GetSize_clicked()
{
    QMessageBox::about(this, "Size", "Size: " + QString::number(list->GetSize()));
}

void MainWindow::on_Clear_clicked()
{
    int size = list->GetSize();
    if(size)
    {
        list->clear();
        ui->textEdit->clear();
        ui->lineEdit->clear();
        ui->minEdit->clear();
        ui->maxEdit->clear();
    }
}

void MainWindow::on_Add_clicked()
{
    list->push_back(ui->lineEdit->text().toInt());

    ui->textEdit->clear();
    ui->minEdit->clear();
    ui->maxEdit->clear();

    QString line = "";
    int min = list->GetBack(), max = list->GetBack();
    int size = list->GetSize();
    for(int i = 0, item; i < size; i++)
    {
        item = list->GetData(i);
        line += QString::number(item) + "  ";
        min = min > item ? item : min;
        max = max < item ? item : max;
    }
    ui->maxEdit->setText(QString::number(max));
    ui->minEdit->setText(QString::number(min));
    ui->textEdit->append(line);
}

void MainWindow::on_Done_clicked()
{
    int max, min;
    if(ui->maxEdit->text() != "" && ui->minEdit->text() != "")
    {
        max = ui->maxEdit->text().toInt();
        min = ui->minEdit->text().toInt();
    }
    else return;

    QString line = "";
    int size = list->GetSize();
    for(int i = 0, count = 0; i < size; i++)
    {
        int item = list->GetData(i);
        line += QString::number(item) + "  ";
        if((item == max || item == min) && count == 0)
        {
            if(i+1 < size)
            {
                i++;
                count++;
                while(list->GetData(i) != max && list->GetData(i) != min)
                {
                    if(i+1 < size && (list->GetData(i+1) == max || list->GetData(i+1) == min)) break;
                    list->remove(i);
                    size--;
                }
            }
        }
    }
    ui->textEdit->append('\n' + line);
}
