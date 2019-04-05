#ifndef NEWLINE_H
#define NEWLINE_H
#include <QString>
#include "dl_list.h"

class NewLine
{
private:
    //dlList<int> list;
    QString line = "";
public:
    QString getLine(dlList<int> &getlist, int index, int iterator);
};

#endif // NEWLINE_H
