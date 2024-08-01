#include "chandsimit.h"
#include <QRandomGenerator>

CHandsImit::CHandsImit(QObject *parent) : QObject(parent)
{
    ImitClearList();
}

int CHandsImit::AddCard(QString sCardName, int nSelectNum)
{
    if (m_ltCard.size() > 10)   return 1;
    for(SelectCard tCard : m_ltCard)
    {
        if (!sCardName.compare(tCard.sChardName))    return 2;
    }

    SelectCard tCard;
    tCard.sChardName = sCardName;
    tCard.nDropNum = nSelectNum;
    m_ltCard.append(tCard);
    return 0;
}

int CHandsImit::AddCombo(QStringList ltCardNames)
{
    if (m_ltCombo.size() > 10)  return 1;
    int nCheck = 0;

    for (QString Str : ltCardNames)
    {
        for (int i = 0; i < Str.size(); ++i)
        {
            nCheck += Str.at(i).toLatin1();
        }
    }
    for (SelectComo tCombo : m_ltCombo)
    {
        if (tCombo.nCheck == nCheck) return 2;
    }

    SelectComo tCombo;
    tCombo.fRate = 0;
    tCombo.nCout = 0;
    tCombo.ltCard = ltCardNames;
    tCombo.nCheck = nCheck;
    m_ltCombo.append(tCombo);
    return 0;
}

void CHandsImit::CaculateRate(int nHand, int nDeck)
{
    QStringList ltDeck;
    int nErrorCode = AddCard(&ltDeck);
    for (int i = ltDeck.size(); i < nDeck; i++)
    {
        ltDeck.append("NULL");
    }
    for (int i = 0; i < m_ltCombo.size(); i++)
    {
        m_ltCombo[i].nCout = 0;
    }
    for(int i = 0; i < TRY_TIMES; i++)
    {
        QStringList ltDeckCopy = ltDeck;
        QStringList ltHand;
        for(int i = 0; i < nHand; i++)
        {
            int nRan = QRandomGenerator::global()->bounded(ltDeckCopy.size());
            QString sDraw;
            sDraw= ltDeckCopy.takeAt(nRan);
            if(QString("NULL").compare(sDraw))    ltHand.append(sDraw);
        }
        for(SelectComo &tCombo : m_ltCombo)
        {
            ScanOneCombo(ltHand, &tCombo);
        }
    }
    return;
}

int CHandsImit::AddCard(QStringList *pDeck)
{
    if(m_ltCard.size() == 0 || m_ltCombo.size() == 0)   return 1;

    for (SelectCard Card : m_ltCard)
    {
        for(int i = 0; i < Card.nDropNum; i++)
        {
            pDeck->append(Card.sChardName);
        }
    }

    return 0;
}

bool CHandsImit::ScanOneCombo(QStringList &ltHand, CHandsImit::SelectComo *pCombo)
{
    int isHas = 0;
    for (int i = 0; i < pCombo->ltCard.size(); i++)
    {
        if (ltHand.contains(pCombo->ltCard[i])) isHas++;
    }
    if (isHas == pCombo->ltCard.size())
    {
        pCombo->nCout++;
        return true;
    }
    else    return false;
}



