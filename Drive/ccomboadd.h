#ifndef CCOMBOADD_H
#define CCOMBOADD_H

#include <QWidget>

namespace Ui {
class CComboAdd;
}

class CComboAdd : public QWidget
{
    Q_OBJECT

public:
    explicit CComboAdd(QWidget *parent = nullptr);
    ~CComboAdd();

private:
    Ui::CComboAdd *ui;
};

#endif // CCOMBOADD_H
