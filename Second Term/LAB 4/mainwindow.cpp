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

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    //QString c = "3.1-(5.4+0.2*9.6)/7.8";

//    for(int i = 0; i < ui->horizontalLayout_2->count(); i++)
//    {
//        DynamicEdit *edit = qobject_cast<DynamicEdit*>(ui->horizontalLayout_2->itemAt(i)->widget());
//        ui->horizontalLayout_2->de
//    }

    QString expression = ui->lineEdit->text();
    Check chek;
    if (chek.checkIt(expression) == 1)
    {
        RPn rpn;
        QString convrez = rpn.ConvertToRPn(expression);
        QString rez = rpn.solve();
        ui->lineEdit_3->setText(rez);
        ui->lineEdit_3->setVisible(true);

//        QString str = "";
//        for (int i = 0; i < convrez.length()-1; i++, str = "")
//        {
//            if (convrez[i] != ',')
//            {
//                while (convrez[i] == '.' || (convrez[i] >= '0' && convrez[i] <= '9'))
//                {
//                    str += convrez[i];
//                    i++;
//                }
//                if (str.isEmpty()) str = convrez[i];
//                DynamicEdit *LineEdit = new DynamicEdit(this);
//                LineEdit->setText(str);
//                ui->horizontalLayout_2->addWidget(LineEdit);

//                connect(LineEdit, SIGNAL(clicked()), this, SLOT(slotGetNumber()));
//            }
//        }
    }

//    QLineEdit *myEdit = new QLineEdit(this);
//    myEdit->setText("3");
//    ui->verticalLayout->addWidget(myEdit);
}
