#include "ccomboadd.h"
#include "ui_ccomboadd.h"
#include <QMessageBox>

CComboAdd::CComboAdd(QWidget *parent, CHandsImit *pImit) :
    QWidget(parent),
    ui(new Ui::CComboAdd)
{
    ui->setupUi(this);
    m_pImit = pImit;
    QStringList ltCards;
    for(CHandsImit::SelectCard Card : m_pImit->m_ltCard)
    {
        ltCards.append(Card.sChardName);
    }
    ui->Box1->addItems(ltCards);
    ui->Box2->addItems(ltCards);
    ui->Box3->addItems(ltCards);
}

CComboAdd::~CComboAdd()
{
    delete ui;
}


void CComboAdd::on_AddCombo_clicked()
{
    QStringList ltCards;

    if(ui->Box1->currentIndex() != 0)   ltCards.append(ui->Box1->currentText());
    if(ui->Box2->currentIndex() != 0)   ltCards.append(ui->Box2->currentText());
    if(ui->Box3->currentIndex() != 0)   ltCards.append(ui->Box3->currentText());

    int nRes = m_pImit->AddCombo(ltCards);
    QMessageBox tErrorMsg;
    switch (nRes)
    {
    case 0:
        emit signalUpdateComboTable();
        break;
    case 1:
        tErrorMsg.setText("帅! 这么会开发combo!");
        tErrorMsg.exec();
        break;
    case 2:
        tErrorMsg.setText("combo重复了捏");
        tErrorMsg.exec();
        break;
    }
}

void CComboAdd::on_cancel_clicked()
{
    this->~CComboAdd();
}
