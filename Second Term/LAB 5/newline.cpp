#include "newline.h"

newline::newline()
{

}

QString newline::NewLine(dlList<int> &list, int index, int iterator)
{
    QString line = "";
    while(index < iterator)
    {
        list.remove(1);
    }

    for(int i = 0; i < list.GetSize()-1; i++)
    {
        line += QString::number(list.GetData(i));
    }
    return line;
}
