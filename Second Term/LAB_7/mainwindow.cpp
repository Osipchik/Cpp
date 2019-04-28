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
    lineEdit_Size->setValidator(new QIntValidator);

    lineEdit_Items->setFixedWidth(50);
    lineEdit_Items->setMinimumWidth(20);
    lineEdit_Items->setText("10");
    lineEdit_Items->setValidator(new QIntValidator);

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
    connect(DeleteButton, SIGNAL(clicked()), this, SLOT (delete_clicked()));
    connect(GetButton, SIGNAL(clicked()), this, SLOT (get_clicked()));
    connect(AddButton, SIGNAL(clicked()), this, SLOT (add_clicked()));

    QPalette palette = ui->tableWidget->palette();
    palette.setBrush(QPalette::Highlight,QBrush(Qt::white));
    palette.setBrush(QPalette::HighlightedText,QBrush(Qt::black));
    ui->tableWidget->setPalette(palette);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
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
    parser->clear();

    int size = line_Size.toInt();

    parser = new Parser<int>(1 + size);

    srand(static_cast<unsigned int>(time(nullptr)));
    int items = line_Items.toInt();
    int rnd;
    while(items)
    {
        rnd = rand()%11 - rand()%11;
        parser->add(rnd);
        items--;
    }

    parser->fill_tab(ui);
    size = parser->GetSize();
    ui->tableWidget->setColumnCount(size);
}

void MainWindow::clearButton_clicked()
{
    ui->tableWidget->clear();
    if(!parser->isEmpty()) parser->clear();
}

void MainWindow::deleteMinus_clicked()
{
    parser->remove_minus();
    ui->tableWidget->clear();
    parser->fill_tab(ui);
}

void MainWindow::delete_clicked()
{
    if(lineEdit_Item->text() != "")
    {
        parser->remove(lineEdit_Item->text().toInt());
        ui->tableWidget->clear();
        parser->fill_tab(ui);
    }
}


void MainWindow::get_clicked()
{
    if(lineEdit_Item->text() != "")
    {
        QMessageBox::about(this, "Hash Code", "Hash code: " +
                           QString::number(parser->GetHashCode(lineEdit_Item->text().toInt())));
    }
}


void MainWindow::add_clicked()
{
    if(lineEdit_Item->text() != "")
    {
        parser->add(lineEdit_Item->text().toInt());
        ui->tableWidget->clear();
        parser->fill_tab(ui);
    }
}
