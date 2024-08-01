#include "ccardadd.h"
#include "ui_ccardadd.h"
#include <QMessageBox>


CCardAdd::CCardAdd(QWidget *parent, CHandsImit *pImit) :
    QWidget(parent),
    ui(new Ui::CCardAdd)
{
    ui->setupUi(this);
//    this->setWindowModality(Qt::ApplicationModal);
    ui->dropNum->setCurrentIndex(2);
    if (pImit != nullptr)   this->m_pImit = pImit;
    else                    this->m_pImit = nullptr;
}

CCardAdd::~CCardAdd()
{
    delete ui;
}

void CCardAdd::on_btnAdd_clicked()
{
    QString sCardName = ui->cardName->text();
    int nDrop = ui->dropNum->currentIndex() + 1;
    if (!(sCardName.size() > 0))  return;
    int nRes = m_pImit->AddCard(sCardName, nDrop);
    QMessageBox tErrorMsg;
    switch (nRes)
    {
    case 0:
        emit signalUpdateCardTable();
        break;
    case 1:
        tErrorMsg.setText("真的要带这么多key卡么?");
        tErrorMsg.exec();
        break;
    case 2:
        tErrorMsg.setText("已经有这张卡辣!");
        tErrorMsg.exec();
        break;
    }
}

void CCardAdd::on_btnCancle_clicked()
{
    this->~CCardAdd();
}
