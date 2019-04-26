#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

#include <random>
#include <ctime>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    parser = new Parser<int>(0);

    ui->tableWidget->verticalHeader()->setVisible(false);
    ui->tableWidget->horizontalHeader()->setVisible(false);

    ToolBar = new QToolBar("Toolbar");
    GenerateButton = new QToolButton(this);
    ClearButton = new QToolButton(this);
    DeleteMinus = new QToolButton(this);
    lineEdit_Size = new QLineEdit(this);
    lineEdit_Items = new QLineEdit(this);
    label_Size = new QLabel("Size:");
    label_Items = new QLabel("   Items:");

    lineEdit_Size->setFixedWidth(50);
    lineEdit_Size->setMinimumWidth(20);
    lineEdit_Size->setText("10");
    lineEdit_Size->setValidator(new QIntValidator);

    lineEdit_Items->setFixedWidth(50);
    lineEdit_Items->setMinimumWidth(20);
    lineEdit_Items->setText("10");
    lineEdit_Items->setValidator(new QIntValidator);

    GenerateButton->setText("Generate");
    ClearButton->setText("Clear");
    DeleteMinus->setText("Delete minus");

    ToolBar->addWidget(GenerateButton);
    ToolBar->addWidget(label_Size);
    ToolBar->addWidget(lineEdit_Size);
    ToolBar->addWidget(label_Items);
    ToolBar->addWidget(lineEdit_Items);
    ToolBar->addWidget(ClearButton);
    ToolBar->addWidget(DeleteMinus);

    addToolBar(ToolBar);

    connect(GenerateButton, SIGNAL(clicked()), this, SLOT (generateButton_clicked()));
    connect(ClearButton, SIGNAL(clicked()), this, SLOT (clearButton_clicked()));
    connect(DeleteMinus, SIGNAL(clicked()), this, SLOT (deleteMinus_clicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_F5)
    {
        ToolBar->show();
    }
}


void MainWindow::generateButton_clicked()
{
    QString line_Size = lineEdit_Size->text();
    QString line_Items = lineEdit_Items->text();
    if(line_Size == "")
    {
        QMessageBox::critical(this, "Error", "Введите размер хеша");
        return;
    }
    if(line_Size.toInt() <= 0)
    {
        QMessageBox::critical(this, "Error", "Неверное выражение");
        return;
    }

    if(line_Items == "")
    {
        QMessageBox::critical(this, "Error", "Введите размер количество ключей");
        return;
    }
    if(line_Items.toInt() <= 0)
    {
        QMessageBox::critical(this, "Error", "Неверное выражение");
        return;
    }

    ui->tableWidget->clear();
    parser->cear();

    int size = line_Size.toInt();

    ui->tableWidget->setColumnCount(size);
    for(int i = 0; i < size; i++)
    {
        ui->tableWidget->setColumnWidth(i, 20);
    }

    parser = new Parser<int>(size);

    srand(static_cast<unsigned int>(time(nullptr)));
    int items = line_Items.toInt();
    while(items)
    {
        parser->add(rand()%11 - rand()%11);
        items--;
    }
    parser->fill_tab(ui);
}

void MainWindow::clearButton_clicked()
{
    ui->tableWidget->clear();
    if(!parser->isEmpty()) parser->cear();
}

void MainWindow::deleteMinus_clicked()
{
    parser->remove_minus();
    ui->tableWidget->clear();
    parser->fill_tab(ui);
}
