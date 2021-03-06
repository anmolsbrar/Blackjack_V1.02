#include "card.h"
#include <QPixmap>
#include <QPainter>


Card::Card():
    face("Joker"), suit("Joker"), ace(false), value(0),  facePng(":/images/cards/joker.bmp")
{
    this->setRect(0,0, 71, 98);
}

Card::Card(const QString & iFace, const QString & iSuit, int iValue, bool iAce, QString iPix) :
    face(iFace), suit(iSuit), ace(iAce), value(iValue), facePng(iPix)
{
    this->setRect(0,0, 71, 98);
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
    painter->setRenderHint(QPainter::Antialiasing, true);
    painter->drawPixmap(0,0, 70, 98, pix);
    //QBrush brush = QBrush(pix);
    //brush.setStyle(Qt::NoBrush);
   // painter->setBrush(brush);
    //painter->drawRoundedRect(this->boundingRect(), 3, 3);
}
