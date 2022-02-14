#ifndef PLAYER_H
#define PLAYER_H

#include "person.h"

#define CARD_X 5
#define CARD_Y 25
#define CARD_OFFSET_X 25
#define CARD_OFFSET_Y 15

class Player : public Person
{
public:
    Player();
    Player(int);
    ~Player();
};

#endif // PLAYER_H
