#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

const QStringList c_lsName = {"联栗炮计算", "手牌初动率"};

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->line_out->setDisabled(1);

    ui->tabWidget->setTabText(0, c_lsName.at(0));
    ui->tabWidget->setTabText(1, c_lsName.at(1));
    _WinStartInit();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btn_cacluate_clicked()
{
    QString sTotal = ui->line_total->text();
    QString sLev = ui->line_leve->text();
    bool ok1, ok2;
    nTotal = sTotal.toInt(&ok1);
    nLev = sLev.toInt(&ok2);
    if (ok1 == 0 || ok2 == 0)
    {
        ui->line_out->setText("请输入正确值");
        return;
    }
    if (nTotal >= nLev * 2 || nTotal <= nLev)
    {
        ui->line_out->setText("无解捏");
        return;
    }
    nX = nTotal - nLev;
    nY = nLev - nX;
    QString sAnswer = QString("超量:%1阶,融合:%2星捏~☆").arg(nX).arg(nY);
    ui->line_out->setText(sAnswer);
}


void MainWindow::_WinStartInit()
{
    ui->start_deckNum->clear();
    for(int i = 0; i <= 20; i++)
    {
        ui->start_deckNum->addItem(QString::number(i + 40));
    }
    ui->start_handNum->clear();
    for(int i = 0; i <= 10; i++)
    {
        ui->start_handNum->addItem(QString::number(i));
    }
    ui->start_handNum->setCurrentIndex(5);
    QStringList ltHead;
    ltHead << "卡片名称" << "投入数量";
    _WinTableReset(*ui->tableCard, ltHead);
    ltHead.clear();
    ltHead << "组合名称" << "达成率";
    _WinTableReset(*ui->tableCombo, ltHead);
}

void MainWindow::_WinTableReset(QTableWidget &tTable, QStringList &ltHeadName)
{
    tTable.setColumnCount(ltHeadName.size());
    tTable.setHorizontalHeaderLabels(ltHeadName);
    tTable.horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    tTable.verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

void MainWindow::slotUpdateCardTabel()
{
    int nRow = ui->tableCard->rowCount();
    ui->tableCard->insertRow(nRow);
    QTableWidgetItem* sChardName = new QTableWidgetItem;
    QTableWidgetItem* nDropNum = new QTableWidgetItem;
    sChardName->setText(m_tHandImit.m_ltCard.last().sChardName);
    nDropNum->setText(QString::number(m_tHandImit.m_ltCard.last().nDropNum));

    ui->tableCard->setItem(nRow, 0, sChardName);
    ui->tableCard->setItem(nRow, 1, nDropNum);
}

void MainWindow::slotUpdateComboTable()
{
    CHandsImit::SelectComo *pltCombo = &m_tHandImit.m_ltCombo.last();
    int nRow = ui->tableCombo->rowCount();
    ui->tableCombo->insertRow(nRow);
    QTableWidgetItem* sCombo = new QTableWidgetItem;
    QTableWidgetItem* fRate = new QTableWidgetItem;
    QString sComboName;
    sComboName.append(pltCombo->ltCard[0]);
    for (int i = 1; i < pltCombo->ltCard.size(); ++i)
    {
        sComboName.append("+");
        sComboName.append(pltCombo->ltCard.at(i));
    }
    sCombo->setText(sComboName);
    fRate->setText(QString::number(pltCombo->fRate,'g', 3).append("%"));

    ui->tableCombo->setItem(nRow, 0, sCombo);
    ui->tableCombo->setItem(nRow, 1, fRate);
}


void MainWindow::on_start_Clear_clicked()   // 清空
{
    QStringList ltHead;
    ltHead << "卡片名称" << "投入数量";
    _WinTableReset(*ui->tableCard, ltHead);
    ltHead.clear();
    ltHead << "组合名称" << "达成率";
    _WinTableReset(*ui->tableCombo, ltHead);
}

void MainWindow::on_start_addCard_clicked()
{
    CCardAdd *m_tCardAdd = new CCardAdd(nullptr, &m_tHandImit);
    connect(m_tCardAdd, SIGNAL(signalUpdateCardTable()), this, SLOT(slotUpdateCardTabel()));
    m_tCardAdd->show();
}

void MainWindow::on_start_addCombo_clicked()
{
    CComboAdd *m_tComboAdd = new CComboAdd(nullptr, &m_tHandImit);
    connect(m_tComboAdd, SIGNAL(signalUpdateComboTable()), this, SLOT(slotUpdateComboTable()));
    m_tComboAdd->show();
}

void MainWindow::on_start_Ok_clicked()
{
    m_tHandImit.CaculateRate(5, 40);
}
