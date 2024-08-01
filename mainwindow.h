#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include <QComboBox>

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

private slots:
    void on_btn_cacluate_clicked();

private:
    Ui::MainWindow *ui;
    void _WinStartInit();
    void _WinTableReset(QTableWidget &tTable, QStringList &ltHeadName);
};
#endif // MAINWINDOW_H
