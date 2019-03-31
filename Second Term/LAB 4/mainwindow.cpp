#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <windows.h>

#include "dynamicedit.h"
#include <QLineEdit>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setlocale(LC_ALL, "ru");
    ui->lineEdit_3->setVisible(false);
}

void Clean( QLayout &oL )
{
    QLayoutItem *poLI;
    QLayout *poL;
    QWidget *poW;

    while( (poLI = oL.takeAt( 0 )) )
    {
        if( (poL = poLI->layout()) )
        {
          delete poL;
        }
        else
        if( (poW = poLI->widget()) )
        {
          delete poW;
        }
    }
}

MainWindow::~MainWindow()
{
    Clean(*ui->horizontalLayout_2);
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    //QString c = "3.1-(5.4+0.2*9.6)/7.8";

    Clean(*ui->horizontalLayout_2);
    ui->lineEdit_3->setVisible(false);

    QString expression = ui->lineEdit->text();
    Check chek;

//    RPn rpn;
//    QString convrez = rpn.ConvertToRPn(expression);
//    ui->textEdit->append(convrez);

    if (chek.checkIt(expression) == 1)
    {
        RPn rpn;
        QString convrez = rpn.ConvertToRPn(expression);
        if (convrez != "Error")
        {
            QString rez = rpn.solve(convrez);
            if (rez != "Error")
            {
                ui->lineEdit_3->setText(rez);
                ui->lineEdit_3->setVisible(true);
            }
        }

        if (ui->lineEdit_3->isVisible())
        {
            QString str = "";
            for (int i = 0; i < convrez.length()-1; i++, str = "")
            {
                if (convrez[i] != ',')
                {
                    while (convrez[i] == '.' || (convrez[i] >= '0' && convrez[i] <= '9'))
                    {
                        str += convrez[i];
                        i++;
                    }
                    if (str.isEmpty()) str = convrez[i];
                    DynamicEdit *LineEdit = new DynamicEdit(this);
                    LineEdit->setText(str);
                    ui->horizontalLayout_2->addWidget(LineEdit);

                    connect(LineEdit, SIGNAL(clicked()), this, SLOT(slotGetNumber()));
                }
            }
        }
    }
}



