#ifndef NEWLINE_H
#define NEWLINE_H
#include <QString>
#include "dl_list.h"

class newline
{
public:
    newline();

    QString NewLine(dlList<int> &list, int index, int iterator);
};

#endif // NEWLINE_H
