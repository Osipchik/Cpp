#include "check.h"
#include <QMessageBox>

Check::Check()
{

}

bool Check::checkIt(QString expression)
{
    int bracket = 0;
    bool chek = 0;
    for (int i = 0; i < expression.length(); i++)
    {
        if (expression[i] == '(') bracket++;
        else if (expression[i] == ')') bracket--;
        else if (expression[i] == ' ')
        {
            QMessageBox::critical(nullptr, "Error", "строка не должна содержать пробел");
            return false;
        }
        else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/')
        {
            if (i == 0 && (expression[i] == '*' || expression[i] == '/'))
            {
                QMessageBox::critical(nullptr, "Error", "неверное выражение");
                return false;
            }

            if (i == expression.length() - 1)
            {
                QMessageBox::critical(nullptr, "Error", "неверное выражение");
                return false;
            }

            if (expression[i+1] == ')')
            {
                QMessageBox::critical(nullptr, "Error", "перед закрывающей скобкой не должно быть знаков операций");
                return false;
            }

            if ((expression[i-1] < '0' || expression[i-1] > '9') && expression[i-1] != ')')
            {
                QMessageBox::critical(nullptr, "Error", "неверное выражение");
                return false;
            }
            chek = 1;
        }
        else if (expression[i] >= '0' && expression[i] <= '9') chek = 1;
        else if (expression[i] == '.')
        {
            if (expression[0] == '.')
            {
                QMessageBox::critical(nullptr, "Error", "перед точкой должно присутствовать число");
                return false;
            }

            if (expression[i-1] < '0' || expression[i-1] > '9')
            {
                QMessageBox::critical(nullptr, "Error", "перед точкой должно присутствовать число");
                return false;
            }

            if (expression[i+1] < '0' || expression[i+1] > '9')
            {
                QMessageBox::critical(nullptr, "Error", "после точки должно присутствовать число");
                return false;
            }
        }
    }

    if (bracket != 0)
    {
        QMessageBox::critical(nullptr, "Error", "число открывающих и закрывающих скобок не совпадает");
        return false;
    }

    return chek;
    //return true;
}
