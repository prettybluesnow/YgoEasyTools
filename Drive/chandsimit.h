#ifndef CHANDSIMIT_H
#define CHANDSIMIT_H

#include <QWidget>

#define TRY_TIMES       (50000)

class CHandsImit : public QObject
{
    Q_OBJECT
public:
    explicit CHandsImit(QObject *parent = nullptr);

    void ImitClearList()    {m_ltCard.clear(); m_ltCombo.clear();}
    int AddCard(QString sCardName, int nSelectNum);
    int AddCombo(QStringList ltCardNames);

    typedef struct tagSelectCard
    {
        QString sChardName;
        int nDropNum;
    }SelectCard, *pSelectCard;

    typedef struct tagSelectCombo
    {
        QStringList ltCard;
        int nCheck;
        int nCout;
        double  fRate;
    }SelectComo, *pSelectCombo;

    QList<SelectCard>   m_ltCard;
    QList<SelectComo>   m_ltCombo;

    void CaculateRate(int nHand, int nDeck);
    int AddCard(QStringList *pDeck);
    bool ScanOneCombo(QStringList &ltHand, SelectComo *pCombo);

signals:
    void signalReflashTabel();
};

#endif // CHANDSIMIT_H
