#include "person.h"

Person::Person(QGraphicsItem *parent) :
    QGraphicsRectItem(parent)
{
    this->setRect(0,0,200, 200);
}

Person::~Person()
{
}

QString Person::name() const
{
    return pName;
}

int Person::totalCount() const
{
    return totalHandValue;
}

int Person::drawCount() const
{
    return totalCardsDrawn;
}

void Person::reset()
{
    aceCount = 0;
    totalCardsDrawn = 0;
    totalHandValue = 0;

    emit scorePing(QString::number(0));

    for(Card * c : drawnCard)
        scene()->removeItem(c);

    drawnCard.clear();
}

void Person::addValue(const Card * hCard)
{
    if (hCard->isAce())
    {
        aceCount++;
        if (aceCount == 1)
        {
            if ((totalHandValue + hCard->getValue()) > 21)
            {
                totalHandValue++;
                aceCount = 0;
            }
            else
                totalHandValue += hCard->getValue();
        }
        else if (aceCount > 1)
            totalHandValue++;
    }
    else
    {
        if (aceCount >= 1 && ((totalHandValue + hCard->getValue()) > 21))
        {
            totalHandValue += hCard->getValue() - 10;
            aceCount = 0;
        }
        else
            totalHandValue += hCard->getValue();
    }
}

/*void Person::printValue()
{
    if (aceCount >= 1 && !(totalHandValue > 21))
        qDebug() << "Value: " << totalHandValue - 10 << " or " << totalHandValue;
    else
        qDebug() << "Value: " << totalHandValue;
}

*/

void Person::hit()
{
    Card * hCard = mDeck->dealFromTop();
    drawnCard.push_back(hCard);

    if(totalCardsDrawn > 0)
        hCard->setPos(drawnCard[totalCardsDrawn - 1]->x() + 15, drawnCard[totalCardsDrawn - 1]->y() + 15);
    else
        hCard->setPos(this->x() + 15, this->y() + 15);

    totalCardsDrawn++;
    addValue(hCard);

    qDebug() << totalHandValue;

    scene()->addItem(hCard);

    emit scorePing(QString::number(totalHandValue));
}

void Person::updateUI()
{

}


