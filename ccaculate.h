#ifndef CCACULATE_H
#define CCACULATE_H
#include <QObject>
#include <QStandardItemModel>
class CCaculate : public QObject
{
    Q_OBJECT
public:
    explicit CCaculate(QObject *parent = nullptr);
    QList<QList<QStandardItemModel>> m_ltCardData;
    QList<QList<QStandardItemModel>> m_ltComboData;
protected:
    int m_arnDeck[60];
signals:

};

#endif // CCACULATE_H
