#ifndef DEALER_H
#define DEALER_H

#include "player.h"
#include "deck.h"

class Dealer : public Player
{
public:
    Dealer();
    ~Dealer();
    void shuffle();
    int upCardValue() const;
    int totalDealt() const;
    void initializeUI() override;
};

#endif // DEALER_H
