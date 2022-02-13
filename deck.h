#ifndef DECK_H
#define DECK_H

#include <QString>
#include <QVector>
#include <QPixmap>

#include "card.h"

const int NUM_OF_CARDS = 52;
const int SUITS = 4;
const int FACES = 13;

class Deck
{
private:
    int currentCard = 0;
    bool isAce;
    int deckCount;
    QString dFaces[FACES] = { "Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King" };
    QString dSuits[SUITS] = { "Spades", "Clubs", "Diamonds", "Hearts" };
    QVector<Card *> deck;
public:
    Deck();
    Deck(int);
    void printDeck() const;

    void shuffle();
    Card * dealFromTop();
    int cardsDealt() const;
};

#endif // DECK_H
