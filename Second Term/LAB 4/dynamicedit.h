#ifndef DYNAMICEDIT_H
#define DYNAMICEDIT_H

#include <QLineEdit>

class DynamicEdit : public QLineEdit
{
    Q_OBJECT
public:
    explicit DynamicEdit(QWidget *parent = nullptr);
    ~DynamicEdit();
    static int ResID;
    int getID();


public slots:

private:
    int editID = 0;
};

#endif // DYNAMICEDIT_H
