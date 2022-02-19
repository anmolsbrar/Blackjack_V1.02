#include "dealer.h"

#include "gameboard.h"

extern GameBoard * board;

Dealer::Dealer() : Player()
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
