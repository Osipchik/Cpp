#ifndef RPN_H
#define RPN_H

#include <QString>
#include <stack.h>

class RPn
{
private:
    Stack<QChar> stack;
    Stack<QString> queue;

public:
    RPn();
    QString ConvertToRPn(QString c);
    QString solve(QString expression);
};

#endif // RPN_H
