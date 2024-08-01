#include "ccardadd.h"
#include "ui_ccardadd.h"

CCardAdd::CCardAdd(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CCardAdd)
{
    ui->setupUi(this);
}

CCardAdd::~CCardAdd()
{
    delete ui;
}
