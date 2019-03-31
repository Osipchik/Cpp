#include "rpn.h"

RPn::RPn()
{

}


QString RPn::ConvertToRPn(QString c)
{
    QString RPn = "";
    QString rezult = "";

    for (int i = 0; i < c.length(); i++)
    {
        if (c[i] >= '0' && c[i] <= '9')
        {
            while ((c[i] >= '0' && c[i] <= '9') || c[i] == '.')
            {
                RPn += c[i];
                i++;
            }
            queue.push_back(RPn);
            rezult += RPn + ',';
            RPn = "";
        }
        if (stack.GetSize() == 0) stack.push_Top(c[i]);
        else if ((c[i] == '+' || c[i] == '-') && (stack.GetTop() == '/' || stack.GetTop() == '*'))
        {
            while (stack.GetSize())
            {
                RPn += stack.GetTop();
                queue.push_back(RPn);
                RPn = "";
                stack.pop_Top();
            }
            stack.push_Top(c[i]);
        }
        else if ((c[i] == '+' || c[i] == '-') && (stack.GetTop() == '+' || stack.GetTop() == '-'))
        {
            RPn += stack.GetTop();
            queue.push_back(RPn);
            rezult += RPn + ',';
            RPn = "";
            stack.pop_Top();
            stack.push_Top(c[i]);
        }
        else if ((c[i] == '*' || c[i] == '/') && (stack.GetTop() == '+' || stack.GetTop() == '-'))
        {
            stack.push_Top(c[i]);
        }
        else if ((c[i] == '*' || c[i] == '/') && (stack.GetTop() == '*' || stack.GetTop() == '/'))
        {
            RPn += stack.GetTop();
            queue.push_back(RPn);
            rezult += RPn + ',';
            RPn = "";
            stack.pop_Top();
            stack.push_Top(c[i]);
        }
        else if ((c[i] == '+' || c[i] == '-') && (stack.GetTop() == '*' || stack.GetTop() == '/'))
        {
            RPn += stack.GetTop();
            queue.push_back(RPn);
            rezult += RPn + ' ';
            RPn = "";
            stack.pop_Top();
            stack.push_Top(c[i]);
        }
        else if ((c[i] == '*' || c[i] == '/' || c[i] == '+' || c[i] == '-') && stack.GetTop() == '(') stack.push_Top(c[i]);
        else if (c[i] == '(') stack.push_Top(c[i]);
        else if (c[i] == ')')
        {
            while (stack.GetTop() != '(')
            {
                RPn += stack.GetTop();
                queue.push_back(RPn);
                rezult += RPn + ',';
                RPn = "";
                stack.pop_Top();
            }
            stack.pop_Top();
        }
    }

    while (stack.GetSize())
        {
            RPn += stack.GetTop();
            queue.push_back(RPn);
            rezult += RPn + ',';
            RPn = "";
            stack.pop_Top();
        }
    stack.clear();

    return rezult;
}


QString RPn::solve()
{
    double b, a, rez;
    QString sign = "";
    Stack<double> nstack;

    while (queue.GetSize())
    {
        sign = queue.GetHead();


        if (sign[0] >= '0' && sign[0] <= '9')
        {
            nstack.push_Top(queue.GetHead().toDouble());
        }
        else if (sign[0] == '*')
        {
            b = nstack.GetTop();
            nstack.pop_Top();
            a = nstack.GetTop();
            nstack.pop_Top();
            rez = a * b;
            nstack.push_Top(rez);
        }
        else if (sign[0] == '/')
        {
            b = nstack.GetTop();
            nstack.pop_Top();
            a = nstack.GetTop();
            nstack.pop_Top();
            rez = a / b;
            nstack.push_Top(rez);
        }
        else if (sign[0] == '+')
        {
            b = nstack.GetTop();
            nstack.pop_Top();
            a = nstack.GetTop();
            nstack.pop_Top();
            rez = a + b;
            nstack.push_Top(rez);
        }
        else if (sign[0] == '-')
        {
            b = nstack.GetTop();
            nstack.pop_Top();
            a = nstack.GetTop();
            nstack.pop_Top();
            rez = a - b;
            nstack.push_Top(rez);
        }
        queue.pop_Head();
    }

    return QString("%1").arg(nstack.GetTop());
}
