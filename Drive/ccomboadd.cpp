#include "ccomboadd.h"
#include "ui_ccomboadd.h"

CComboAdd::CComboAdd(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CComboAdd)
{
    ui->setupUi(this);
}

CComboAdd::~CComboAdd()
{
    delete ui;
}
