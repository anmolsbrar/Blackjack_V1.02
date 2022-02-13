#ifndef DEALER_H
#define DEALER_H

#include "person.h"
#include "deck.h"

class Dealer : public Person
{
public:
    Dealer();
    ~Dealer();
    void shuffle();
    int upCardValue() const;
    int totalDealt() const;
};

#endif // DEALER_H
