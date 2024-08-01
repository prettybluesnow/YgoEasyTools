#ifndef CCOMBOADD_H
#define CCOMBOADD_H

#include <QWidget>
#include "Drive/chandsimit.h"
#include <QComboBox>

namespace Ui {
class CComboAdd;
}

class CComboAdd : public QWidget
{
    Q_OBJECT

public:
    explicit CComboAdd(QWidget *parent = nullptr, CHandsImit *pImit = nullptr);
//    CComboAdd(CHandsImit *pImit = nullptr);
    ~CComboAdd();

private slots:
    void on_AddCombo_clicked();

    void on_cancel_clicked();

private:
    Ui::CComboAdd *ui;
    CHandsImit *m_pImit;

signals:
    void signalUpdateComboTable();
};





#endif // CCOMBOADD_H
