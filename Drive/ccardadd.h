#ifndef CCARDADD_H
#define CCARDADD_H

#include <QWidget>
#include "Drive/chandsimit.h"

namespace Ui {
class CCardAdd;
}

class CCardAdd : public QWidget
{
    Q_OBJECT

public:
    explicit CCardAdd(QWidget *parent = nullptr, CHandsImit *pImit = nullptr);
    ~CCardAdd();

private slots:
    void on_btnAdd_clicked();

    void on_btnCancle_clicked();

private:
    Ui::CCardAdd *ui;
    CHandsImit *m_pImit;

signals:
    void signalUpdateCardTable();
};

#endif // CCARDADD_H
