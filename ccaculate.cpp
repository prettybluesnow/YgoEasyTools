#include "ccaculate.h"

CCaculate::CCaculate(QObject *parent) : QObject(parent)
{
    memset(m_arnDeck, 0, sizeof (m_arnDeck));
}


