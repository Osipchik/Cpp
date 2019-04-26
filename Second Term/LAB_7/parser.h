#ifndef PARSER_H
#define PARSER_H

//#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "hash.h"

template<typename T>
class Parser : public Hash<T>
{
public:
    Parser(int size);
    void fill_tab(Ui::MainWindow *ui);
    bool isEmpty() { return Hash<T>::size; }
    void remove_minus();
};

#endif // PARSER_H

template<typename T>
Parser<T>::Parser(int size) : Hash<T> (size)
{

}

template<typename T>
void Parser<T>::fill_tab(Ui::MainWindow *ui)
{
    Stack<typename::HashItem<T>> copyArr;
    int arr_item_size, copy_size;
    for(int i = 0; i < Hash<T>::size; i++, arr_item_size = 0)
    {
        arr_item_size = Hash<T>::array[i].GetSize();
        if(arr_item_size)
        {
            if(arr_item_size > ui->tableWidget->rowCount()) ui->tableWidget->setRowCount(arr_item_size);
            while(arr_item_size)
            {
                copyArr.push_Top(Hash<T>::array[i].GetTop());
                ui->tableWidget->setItem(arr_item_size - 1, i, new QTableWidgetItem(QString::number(Hash<T>::array[i].GetTop().key)));
                Hash<T>::array[i].pop_Top();
                arr_item_size--;
            }
            copy_size = copyArr.GetSize();
            while(copy_size)
            {
                Hash<T>::array[i].push_Top(copyArr.GetTop());
                copyArr.pop_Top();
                copy_size--;
            }
        }
    }
}

template<typename T>
void Parser<T>::remove_minus()
{
    Stack<typename::HashItem<T>> copyArr;
    int arr_item_size, copy_size;
    for(int i = 0; i < Hash<T>::size; i++, arr_item_size = 0)
    {
        arr_item_size = Hash<T>::array[i].GetSize();
        if(arr_item_size)
        {
            while(arr_item_size)
            {
                copyArr.push_Top(Hash<T>::array[i].GetTop());

                Hash<T>::array[i].pop_Top();
                arr_item_size--;
            }
            copy_size = copyArr.GetSize();
            while(copy_size)
            {
                copy_size--;
                if(copyArr.GetTop().key < 0) continue;

                Hash<T>::array[i].push_Top(copyArr.GetTop());
                copyArr.pop_Top();
            }
        }
    }
}
