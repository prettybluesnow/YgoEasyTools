#ifndef CCARDADD_H
#define CCARDADD_H

#include <QWidget>

namespace Ui {
class CCardAdd;
}

class CCardAdd : public QWidget
{
    Q_OBJECT

public:
    explicit CCardAdd(QWidget *parent = nullptr);
    ~CCardAdd();

private:
    Ui::CCardAdd *ui;
};

#endif // CCARDADD_H
