#include "rpn.h"

RPn::RPn()
{

}


QString RPn::ConvertToRPn(QString c)
{
    QString temp = "";
    QString rezult = "";


        for (int i = 0; i < c.length(); i++)
        {
            if (c[i] >= '0' && c[i] <= '9')
            {
                while ((c[i] >= '0' && c[i] <= '9') || c[i] == '.')
                {
                    rezult += c[i];
                    i++;
                }
                rezult +=  ',';
            }

            if ((c[i] == '+' || c[i] == '-' || c[i] == '*' || c[i] == '/') && stack.GetSize() == 0) stack.push_Top(c[i]);
            else if ((c[i] == '+' || c[i] == '-') && (stack.GetSize() != 0) && (stack.GetTop() == '+' || stack.GetTop() == '-'))
            {
                rezult += stack.GetTop() + ',';
                stack.pop_Top();
                stack.push_Top(c[i]);
            }
            else if (c[i] == '(') stack.push_Top(c[i]);
            else if ((c[i] == '*' || c[i] == '/') && stack.GetTop() == '(') stack.push_Top(c[i]);
            else if (c[i] == ')')
            {
                while (stack.GetTop() != '(')
                {
                    rezult += stack.GetTop() + ',';
                    stack.pop_Top();
                }
                stack.pop_Top();
            }
            else if ((c[i] == '*' || c[i] == '/') && (stack.GetTop() == '*' || stack.GetTop() == '/'))
            {
                rezult += stack.GetTop() + ',';
                stack.pop_Top();
                stack.push_Top(c[i]);
            }
            else if ((c[i] == '*' || c[i] == '/') && (stack.GetTop() == '+' || stack.GetTop() == '-')) stack.push_Top(c[i]);
            else if ((c[i] == '+' || c[i] == '-') && (stack.GetTop() == '*' || stack.GetTop() == '/'))
            {
                while (stack.GetSize() && stack.GetTop() != '(')
                {
                    rezult += stack.GetTop() + ',';
                    stack.pop_Top();
                }
                stack.push_Top(c[i]);
            }
            else if (stack.GetTop() == '(') stack.push_Top(c[i]);
        }

        while (stack.GetSize())
        {
            rezult += stack.GetTop() + ',';
            stack.pop_Top();
        }
        stack.clear();

        return rezult;

}


QString RPn::solve(QString expression)
{
    QString str = "";
    for (int i = 0; i < expression.length(); i++, str = "")
    {
        while (expression[i] != ',')
        {
            str += expression[i];
            i++;
        }
        queue.push_back(str);
    }

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
