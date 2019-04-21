#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "windowwidget.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit->setValidator(new QIntValidator);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Return || event->key() == Qt::Key_Enter)
    {
        int currentRow = ui->tableWidget->currentRow();

        if(!ui->tableWidget->item(currentRow, 0))
        {
            QMessageBox::critical(this, "Error", "One or several cells is empty");
            return;
        }
        QString data = ui->tableWidget->item(currentRow, 0)->text();

        if(!ui->tableWidget->item(currentRow, 1))
        {
            QMessageBox::critical(this, "Error", "One or several cells is empty");
            return;
        }
        int key = ui->tableWidget->item(currentRow, 1)->text().toInt();

        int total = ui->tableWidget->rowCount();
        while(total)
        {
            if(total-1 == currentRow)
            {
                total--;
                continue;
            }
            if(key == ui->tableWidget->item(total-1, 1)->text().toInt())
            {
                QMessageBox::critical(this, "Error", "Номера недолжны повторяться");
                return;
            }
            total--;
        }

        ui->tableWidget->item(currentRow, 1)->setFlags(Qt::ItemIsEditable);
        tree.Add(key, data);

        int count = ui->tableWidget->rowCount() - 1;
        if(ui->tableWidget->item(count, 0) != nullptr && ui->tableWidget->item(count, 1) != nullptr)
        {
            int rowCount = ui->tableWidget->rowCount() + 1;
            ui->tableWidget->setRowCount(rowCount);
        }
    }
    else if(event->key() == Qt::Key_Delete)
    {
        int currentRow = ui->tableWidget->currentRow();
        if(ui->tableWidget->item(currentRow, 0) && ui->tableWidget->item(currentRow, 1))
        {
            tree.remove(ui->tableWidget->item(currentRow, 1)->text().toInt());
            ui->tableWidget->removeRow(currentRow);
        }
    }

    if(event->key() == Qt::Key_Delete || event->key() == Qt::Key_Return || event->key() == Qt::Key_Enter)
    {
        Queue<QString> queue;
        tree.GetNLR(queue, "Root");

        int size = queue.GetSize();
        QString treeArr[size][5];
        for(int i = 0; i < size; i++)
        {
           treeArr[i][0] = queue.GetFront().split("|").at(0);
           treeArr[i][1] = queue.GetFront().split("|").at(1);
           treeArr[i][2] = queue.GetFront().split("|").at(2);
           treeArr[i][3] = queue.GetFront().split("|").at(3);
           treeArr[i][4] = queue.GetFront().split("|").at(4);
           queue.pop_front();
        }

        ui->textEdit->clear();
        tree.GetNLR(queue);

        QString strNLR = "";
        for(int i = 0; i < size; i++)
        {
            strNLR += '\t' + queue.GetFront();
            queue.pop_front();
        }
        ui->textEdit->append("NLR: " + strNLR);

        tree.GetLNR(queue);
        QString strLNR = "";
        for(int i = 0; i < size; i++)
        {
            strLNR += '\t' + queue.GetFront();
            queue.pop_front();
        }
        ui->textEdit->append("LNR: " + strLNR);

        tree.GetLRN(queue);
        QString strLRN = "";
        for(int i = 0; i < size; i++)
        {
            strLRN += '\t' + queue.GetFront();
            queue.pop_front();
        }
        ui->textEdit->append("LRN: " + strLRN);


        ui->treeWidget->clear();

        QTreeWidgetItem *item = new QTreeWidgetItem();
        item->setText(0, treeArr[0][3] + " " + treeArr[0][0]);

        QTreeWidgetItem *child1 = new QTreeWidgetItem();
        QTreeWidgetItem *child2 = new QTreeWidgetItem();

        child1->setText(0, "data: " + treeArr[0][1]);
        child2->setText(0, "height: " + treeArr[0][2]);

        item->addChild(child1);
        item->addChild(child2);

        ui->treeWidget->addTopLevelItem(item);

        for(int i = 1; i < size; i++)
        {
            if(treeArr[i][3] == "Left:")
            {
                QList<QTreeWidgetItem* > itemList = ui->treeWidget->findItems("Root: " + treeArr[i][4], Qt::MatchFixedString);
                if(!itemList.isEmpty())
                {
                    QTreeWidgetItem *new_item   = new QTreeWidgetItem();
                    QTreeWidgetItem *new_child1 = new QTreeWidgetItem();
                    QTreeWidgetItem *new_child2 = new QTreeWidgetItem();
                    new_item->setText(0, "Left: " + treeArr[i][0]);
                    new_child1->setText(0, "data: " + treeArr[i][1]);
                    new_child2->setText(0, "height: " + treeArr[i][2]);

                    new_item->addChild(new_child1);
                    new_item->addChild(new_child2);

                    itemList.first()->addChild(new_item);
                    treeArr[i][3] = nullptr;
                    break;
                }
            }
        }

        for(int i = 1; i < size; i++)
        {
            if(treeArr[i][3] == "Right:")
            {
                QList<QTreeWidgetItem* > itemList = ui->treeWidget->findItems("Root: " + treeArr[i][4], Qt::MatchFixedString);
                if(!itemList.isEmpty())
                {
                    QTreeWidgetItem *new_item   = new QTreeWidgetItem();
                    QTreeWidgetItem *new_child1 = new QTreeWidgetItem();
                    QTreeWidgetItem *new_child2 = new QTreeWidgetItem();
                    new_item->setText(0, "Right: " + treeArr[i][0]);
                    new_child1->setText(0, "data: " + treeArr[i][1]);
                    new_child2->setText(0, "height: " + treeArr[i][2]);

                    new_item->addChild(new_child1);
                    new_item->addChild(new_child2);

                    itemList.first()->addChild(new_item);
                    treeArr[i][3] = nullptr;
                    break;
                }
            }
        }


        for(int i = 1; i < size; i++)
        {
            if(treeArr[i][3] == "Left:")
            {
                QList<QTreeWidgetItem* > itemList = ui->treeWidget->findItems("Right: " + treeArr[i][4], Qt::MatchFixedString | Qt::MatchRecursive);
                if(itemList.isEmpty()) itemList = ui->treeWidget->findItems("Left: " + treeArr[i][4], Qt::MatchFixedString | Qt::MatchRecursive);
                if(itemList.isEmpty()) continue;

                QTreeWidgetItem *new_item   = new QTreeWidgetItem();
                QTreeWidgetItem *new_child1 = new QTreeWidgetItem();
                QTreeWidgetItem *new_child2 = new QTreeWidgetItem();
                new_item->setText(0, "Left: " + treeArr[i][0]);
                new_child1->setText(0, "data: " + treeArr[i][1]);
                new_child2->setText(0, "height: " + treeArr[i][2]);

                new_item->addChild(new_child1);
                new_item->addChild(new_child2);

                itemList.first()->addChild(new_item);
                itemList.clear();

                treeArr[i][3] = nullptr;
            }
        }

        for(int i = 1; i < size; i++)
        {
            if(treeArr[i][3] == "Right:")
            {
                QList<QTreeWidgetItem* > itemList = ui->treeWidget->findItems("Right: " + treeArr[i][4], Qt::MatchFixedString | Qt::MatchRecursive);
                if(itemList.isEmpty()) itemList = ui->treeWidget->findItems("Left: " + treeArr[i][4], Qt::MatchFixedString | Qt::MatchRecursive);
                if(itemList.isEmpty()) continue;

                QTreeWidgetItem *new_item   = new QTreeWidgetItem();
                QTreeWidgetItem *new_child1 = new QTreeWidgetItem();
                QTreeWidgetItem *new_child2 = new QTreeWidgetItem();
                new_item->setText(0, "Right: " + treeArr[i][0]);
                new_child1->setText(0, "data: " + treeArr[i][1]);
                new_child2->setText(0, "height: " + treeArr[i][2]);

                new_item->addChild(new_child1);
                new_item->addChild(new_child2);

                itemList.first()->addChild(new_item);
                itemList.clear();

                treeArr[i][3] = nullptr;
            }
        }
    }
}

void MainWindow::on_DeleteButton_clicked()
{
    if(ui->tableWidget->rowCount() <= 1)
    {
        QMessageBox::about(this, "About", "Дерево не имеет элементов");
        return;
    }
    int key = ui->lineEdit->text().toInt();
    tree.remove_branch(key);

    Queue<QString> queue;
    tree.GetNLR(queue, "Root");

    int size = queue.GetSize();
    if(size == 0)
    {
        ui->tableWidget->setRowCount(0);
        ui->tableWidget->setRowCount(1);
        ui->treeWidget->clear();
        return;
    }
    QString treeArr[size][5];
    for(int i = 0; i < size; i++)
    {
       treeArr[i][0] = queue.GetFront().split("|").at(0);
       treeArr[i][1] = queue.GetFront().split("|").at(1);
       treeArr[i][2] = queue.GetFront().split("|").at(2);
       treeArr[i][3] = queue.GetFront().split("|").at(3);
       treeArr[i][4] = queue.GetFront().split("|").at(4);
       queue.pop_front();
    }

    ui->tableWidget->setRowCount(size);
    for(int i = 0; i < size; i++)
    {
        ui->tableWidget->item(i, 0)->setText(treeArr[i][1]);
        ui->tableWidget->item(i, 1)->setText(treeArr[i][0]);
    }

    ui->treeWidget->clear();

    QTreeWidgetItem *item = new QTreeWidgetItem();
    item->setText(0, treeArr[0][3] + " " + treeArr[0][0]);

    QTreeWidgetItem *child1 = new QTreeWidgetItem();
    QTreeWidgetItem *child2 = new QTreeWidgetItem();

    child1->setText(0, "data: " + treeArr[0][1]);
    child2->setText(0, "height: " + treeArr[0][2]);

    item->addChild(child1);
    item->addChild(child2);

    ui->treeWidget->addTopLevelItem(item);

    for(int i = 1; i < size; i++)
    {
        if(treeArr[i][3] == "Left:")
        {
            QList<QTreeWidgetItem* > itemList = ui->treeWidget->findItems("Root: " + treeArr[i][4], Qt::MatchFixedString);
            if(!itemList.isEmpty())
            {
                QTreeWidgetItem *new_item   = new QTreeWidgetItem();
                QTreeWidgetItem *new_child1 = new QTreeWidgetItem();
                QTreeWidgetItem *new_child2 = new QTreeWidgetItem();
                new_item->setText(0, "Left: " + treeArr[i][0]);
                new_child1->setText(0, "data: " + treeArr[i][1]);
                new_child2->setText(0, "height: " + treeArr[i][2]);

                new_item->addChild(new_child1);
                new_item->addChild(new_child2);

                itemList.first()->addChild(new_item);
                treeArr[i][3] = nullptr;
                break;
            }
        }
    }

    for(int i = 1; i < size; i++)
    {
        if(treeArr[i][3] == "Right:")
        {
            QList<QTreeWidgetItem* > itemList = ui->treeWidget->findItems("Root: " + treeArr[i][4], Qt::MatchFixedString);
            if(!itemList.isEmpty())
            {
                QTreeWidgetItem *new_item   = new QTreeWidgetItem();
                QTreeWidgetItem *new_child1 = new QTreeWidgetItem();
                QTreeWidgetItem *new_child2 = new QTreeWidgetItem();
                new_item->setText(0, "Right: " + treeArr[i][0]);
                new_child1->setText(0, "data: " + treeArr[i][1]);
                new_child2->setText(0, "height: " + treeArr[i][2]);

                new_item->addChild(new_child1);
                new_item->addChild(new_child2);

                itemList.first()->addChild(new_item);
                treeArr[i][3] = nullptr;
                break;
            }
        }
    }


    for(int i = 1; i < size; i++)
    {
        if(treeArr[i][3] == "Left:")
        {
            QList<QTreeWidgetItem* > itemList = ui->treeWidget->findItems("Right: " + treeArr[i][4], Qt::MatchFixedString | Qt::MatchRecursive);
            if(itemList.isEmpty()) itemList = ui->treeWidget->findItems("Left: " + treeArr[i][4], Qt::MatchFixedString | Qt::MatchRecursive);
            if(itemList.isEmpty()) continue;

            QTreeWidgetItem *new_item   = new QTreeWidgetItem();
            QTreeWidgetItem *new_child1 = new QTreeWidgetItem();
            QTreeWidgetItem *new_child2 = new QTreeWidgetItem();
            new_item->setText(0, "Left: " + treeArr[i][0]);
            new_child1->setText(0, "data: " + treeArr[i][1]);
            new_child2->setText(0, "height: " + treeArr[i][2]);

            new_item->addChild(new_child1);
            new_item->addChild(new_child2);

            itemList.first()->addChild(new_item);
            itemList.clear();

            treeArr[i][3] = nullptr;
        }
    }

    for(int i = 1; i < size; i++)
    {
        if(treeArr[i][3] == "Right:")
        {
            QList<QTreeWidgetItem* > itemList = ui->treeWidget->findItems("Right: " + treeArr[i][4], Qt::MatchFixedString | Qt::MatchRecursive);
            if(itemList.isEmpty()) itemList = ui->treeWidget->findItems("Left: " + treeArr[i][4], Qt::MatchFixedString | Qt::MatchRecursive);
            if(itemList.isEmpty()) continue;

            QTreeWidgetItem *new_item   = new QTreeWidgetItem();
            QTreeWidgetItem *new_child1 = new QTreeWidgetItem();
            QTreeWidgetItem *new_child2 = new QTreeWidgetItem();
            new_item->setText(0, "Right: " + treeArr[i][0]);
            new_child1->setText(0, "data: " + treeArr[i][1]);
            new_child2->setText(0, "height: " + treeArr[i][2]);

            new_item->addChild(new_child1);
            new_item->addChild(new_child2);

            itemList.first()->addChild(new_item);
            itemList.clear();

            treeArr[i][3] = nullptr;
        }
    }
}
