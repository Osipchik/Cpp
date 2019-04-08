#ifndef NEWLINE_H
#define NEWLINE_H
#include <QString>
#include "dl_list.h"

class NewLine
{
private:
    QString line = "";
public:
    QString getLine(DL_List<int> &getlist, int index, int iterator);
};

#endif // NEWLINE_H
