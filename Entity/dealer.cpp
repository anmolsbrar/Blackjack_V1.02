#include "dealer.h"

Dealer::Dealer()
{
    pName = "Dealer";

}

Dealer::~Dealer()
{
    delete mDeck;
}

void Dealer::shuffle()
{
    mDeck->shuffle();
}

int Dealer::upCardValue() const
{
    return drawnCard.at(0)->getValue();
}
