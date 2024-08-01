#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include <QComboBox>
#include "Drive/ccardadd.h"
#include "Drive/ccomboadd.h"
#include "Drive/chandsimit.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    int nTotal = 0;
    int nLev = 0;
    int nX = 0;
    int nY = 0;
    CHandsImit m_tHandImit;
private slots:
    void on_btn_cacluate_clicked();
    void on_start_Clear_clicked();

    void on_start_addCard_clicked();

    void on_start_addCombo_clicked();

    void on_start_Ok_clicked();

private:
    Ui::MainWindow *ui;
    void _WinStartInit();
    void _WinTableReset(QTableWidget &tTable, QStringList &ltHeadName);
public slots:
    void slotUpdateCardTabel();
    void slotUpdateComboTable();
};
#endif // MAINWINDOW_H
