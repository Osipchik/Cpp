#ifndef PARSER_H
#define PARSER_H

#include "ui_mainwindow.h"
#include "hash_open.h"

template<typename T>
class Parser : public Hash_Open<T>
{
public:
    Parser(int size);
    void fill_textEdit(Ui::MainWindow *ui);
    bool isEmpty() { return Hash_Open<T>::size; }
    void DeleteMinus();
};

#endif // PARSER_H


template<typename T>
Parser<T>::Parser(int size) : Hash_Open<T>(size)
{

}


template<typename T>
void Parser<T>::fill_textEdit(Ui::MainWindow *ui)
{
    QString rez = "";
    for (int i = 0; i < Hash_Open<T>::size; i++)
    {
        if (Hash_Open<T>::hashTable[i].Delited == 0)
            ui->textEdit->append("Key: " + QString::number(Hash_Open<T>::hashTable[i].Key) +
                                 "\t Hsah code: " + QString::number(Hash_Open<T>::hashTable[i].HashCode));
    }
}

template<typename T>
void Parser<T>::DeleteMinus()
{
    for(int i = 0; i < Hash_Open<T>::size; i++)
    {
        if(Hash_Open<T>::hashTable[i].Key < 0)
        {
            Hash_Open<T>::hashTable[i].Delited = 1;
            Hash_Open<T>::hashTable[i].HashCode = 0;
        }
    }
}
