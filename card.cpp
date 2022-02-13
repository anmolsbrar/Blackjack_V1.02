#include "card.h"
#include <QPixmap>
#include <QPainter>


Card::Card():
    face("Joker"), suit("Joker"), ace(false), value(0),  facePng(":/images/cards/joker.bmp")
{
    this->setCard();
}

Card::Card(const QString & iFace, const QString & iSuit, int iValue, bool iAce, QString iPix) :
    face(iFace), suit(iSuit), ace(iAce), value(iValue), facePng(iPix)
{
    this->setCard();
}


void Card::setCard()
{
    this->setRect(0,0, 71, 96);
}

QString Card::print() const
{
    return face + " of " + suit;
}
int Card::getValue() const
{
    return value;
}
bool Card::isAce() const
{
    return ace;
}

void Card::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap pix(facePng);
    painter->drawPixmap(0,0, 70, 100, pix);
}
