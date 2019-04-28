#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <random>
#include <ctime>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    parser = new Parser<int>(0);
    ToolBar = new QToolBar("Toolbar");

    GenerateButton = new QToolButton(this);
    ClearButton = new QToolButton(this);
    DeleteMinus = new QToolButton(this);
    DeleteButton = new QToolButton(this);
    GetButton = new QToolButton(this);
    AddButton = new QToolButton(this);

    lineEdit_Size = new QLineEdit(this);
    lineEdit_Items = new QLineEdit(this);
    lineEdit_Item = new QLineEdit(this);

    label_Size = new QLabel("Size:");
    label_Items = new QLabel("   Items:");

    lineEdit_Size->setFixedWidth(50);
    lineEdit_Size->setMinimumWidth(20);
    lineEdit_Size->setText("10");
    //lineEdit_Size->setValidator(new QIntValidator);

    lineEdit_Items->setFixedWidth(50);
    lineEdit_Items->setMinimumWidth(20);
    lineEdit_Items->setText("10");
    //lineEdit_Items->setValidator(new QIntValidator);

    lineEdit_Item->setFixedWidth(50);
    lineEdit_Item->setMinimumWidth(20);
    //lineEdit_Item->setValidator(new QIntValidator);

    GenerateButton->setText("Generate");
    ClearButton->setText("Clear");
    DeleteMinus->setText("Del minus");
    DeleteButton->setText("Delete");
    GetButton->setText("Get Hash");
    AddButton->setText("Add item");

    ToolBar->addWidget(GenerateButton);
    ToolBar->addWidget(label_Size);
    ToolBar->addWidget(lineEdit_Size);
    ToolBar->addWidget(label_Items);
    ToolBar->addWidget(lineEdit_Items);
    ToolBar->addWidget(ClearButton);
    ToolBar->addWidget(DeleteMinus);
    ToolBar->addWidget(DeleteButton);
    ToolBar->addWidget(GetButton);
    ToolBar->addWidget(AddButton);
    ToolBar->addWidget(lineEdit_Item);

    addToolBar(Qt::LeftToolBarArea, ToolBar);

    connect(GenerateButton, SIGNAL(clicked()), this, SLOT (generateButton_clicked()));
    connect(ClearButton, SIGNAL(clicked()), this, SLOT (clearButton_clicked()));
    connect(DeleteMinus, SIGNAL(clicked()), this, SLOT (deleteMinus_clicked()));
    connect(DeleteButton, SIGNAL(clicked()), this, SLOT (deleteButton_clicked()));
    connect(GetButton, SIGNAL(clicked()), this, SLOT (getButton_clicked()));
    connect(AddButton, SIGNAL(clicked()), this, SLOT (addButton_clicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::generateButton_clicked()
{
    int items = lineEdit_Items->text().toInt();
    int size = lineEdit_Size->text().toInt();

    parser = new Parser<int>(1 + size);
    parser->clear();

    srand(static_cast<unsigned int>(time(nullptr)));
    while(items)
    {
        parser->add(rand()%11 - rand()%11);
        items--;
    }
    ui->textEdit->clear();
    parser->fill_textEdit(ui);
}


void MainWindow::clearButton_clicked()
{
    ui->textEdit->clear();
    //if(parser->isEmpty()) parser->clear();
}


void MainWindow::deleteMinus_clicked()
{
    ui->textEdit->clear();
    parser->DeleteMinus();
    parser->fill_textEdit(ui);
}


void MainWindow::deleteButton_clicked()
{
    ui->textEdit->clear();
    int key = lineEdit_Item->text().toInt();
    parser->remove(key);
    parser->fill_textEdit(ui);
}


void MainWindow::getButton_clicked()
{
    int key = lineEdit_Item->text().toInt();
    if(parser->isEmpty())
       QMessageBox::about(this, "Hash Code", "Hash code: " + QString::number(parser->GetHashCode(key)));
}


void MainWindow::addButton_clicked()
{
    int key = lineEdit_Item->text().toInt();
    parser->add(key);
    ui->textEdit->clear();
    parser->fill_textEdit(ui);
}
