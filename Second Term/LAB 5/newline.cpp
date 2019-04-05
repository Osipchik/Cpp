#include "newline.h"

QString NewLine::getLine(dlList<int> &getlist, int index, int iterator)
{
    for(int i = 0; i < iterator-1; i++)
        getlist.remove(index);

    for(int i = 0; i < getlist.GetSize(); i++)
        line += QString::number(getlist.GetData(i)) + ' ';

    return line;
}
