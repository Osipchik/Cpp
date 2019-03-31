
#include "dynamicedit.h"

DynamicEdit::DynamicEdit(QWidget *parent) :
    QLineEdit (parent)
{
    ResID++;
    editID = ResID;
}

DynamicEdit::~DynamicEdit()
{

}

int DynamicEdit::getID()
{
    return editID;
}

int DynamicEdit::ResID = 0;
