#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QIntValidator>
#include <random>
#include <ctime>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    hash = nullptr;
    ToolBar = new QToolBar("Toolbar");

    GenerateButton = new QToolButton(this);
    ClearButton = new QToolButton(this);
    DeleteMinus = new QToolButton(this);
    DeleteButton = new QToolButton(this);
    GetButton = new QToolButton(this);
    AddButton = new QToolButton(this);

    lineEdit_Item = new QLineEdit(this);
    lineEdit_Item->setFixedWidth(50);
    lineEdit_Item->setMinimumWidth(20);
    lineEdit_Item->setValidator(new QIntValidator);

    GenerateButton->setText("Generate");
    ClearButton->setText("Clear");
    DeleteMinus->setText("Del minus");
    DeleteButton->setText("Delete");
    GetButton->setText("Get Hash");
    AddButton->setText("Add item");

    ToolBar->addWidget(GenerateButton);
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
    connect(DeleteButton, SIGNAL(clicked()), this, SLOT (delete_clicked()));
    connect(GetButton, SIGNAL(clicked()), this, SLOT (get_clicked()));
    connect(AddButton, SIGNAL(clicked()), this, SLOT (add_clicked()));
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
    if(hash) delete hash;
    hash = new Hash<int>;

    srand(static_cast<unsigned int>(time(nullptr)));
    int rnd = 0;
    for(int i = 0; i < 13; i++)
    {
        rnd = rand()%11 - rand()%11;
        hash->add(rnd, rnd);
    }
    ui->textEdit->clear();
    ui->textEdit->append(hash->all());
}

void MainWindow::clearButton_clicked()
{
    ui->textEdit->clear();
}

void MainWindow::deleteMinus_clicked()
{
    hash->removeMinus();
    hash->removeMinus();
    ui->textEdit->clear();
    ui->textEdit->append(hash->all());
}

void MainWindow::delete_clicked()
{
    int item = lineEdit_Item->text().toInt();
    hash->remove(item);
    ui->textEdit->clear();
    ui->textEdit->append(hash->all());
}

void MainWindow::get_clicked()
{
    if(!hash)
    {
        QMessageBox::warning(this, "Warning", "хеш функция не создана");
        return;
    }
    QString str = lineEdit_Item->text();
    QStringList strList = str.split(" ");
    QMessageBox::about(this, "Hash Code", "Hash Code: " + QString::number(hash->GetHashCode(strList[0].toInt(), strList[1].toInt())));
}

void MainWindow::add_clicked()
{
    int item = lineEdit_Item->text().toInt();
    hash->add(item);
    ui->textEdit->clear();
    ui->textEdit->append(hash->all());
}
