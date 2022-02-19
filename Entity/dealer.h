#ifndef DEALER_H
#define DEALER_H

#include "player.h"
#include "deck.h"
#include "defines.h"

class Dealer : public Player
{
public:
    Dealer();
    ~Dealer();
    void shuffle();
    //void initializeUI() override;
};

#endif // DEALER_H
