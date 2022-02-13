#include "deck.h"

#include <QRandomGenerator>

Deck::Deck()
{

}

Deck::Deck(int deckCount)
{
    this->deckCount = deckCount;
    bool isAce = false;
        for (int i = 0; i < deckCount; i++)
        {
            for (int cardCount = 0; cardCount < NUM_OF_CARDS; cardCount++)
            {
                int cValue = (cardCount + 1) % 13;
                isAce = false;
                if (cValue == 1)
                {
                    cValue += 10;
                    isAce = true;
                }
                else if (cValue >= 10)
                {
                    cValue = 10;
                    isAce = false;
                }
                else if (cValue == 0)
                {
                    cValue = 10;
                    isAce = false;
                }
                QString str(":/Images/cards/front-");
                str.append(QString::number((cardCount * i + cardCount)) + ".png");
                qDebug() << str;
                deck.push_back(new Card(dFaces[cardCount % 13], dSuits[cardCount / 13], cValue, isAce, str));
            }
        }
}

void Deck::printDeck() const
{
    for(int i = 0; i < NUM_OF_CARDS * deckCount; i++) {
        qDebug() << deck.at(i)->getValue() << " " << deck.at(i)->print();
    }
}

void Deck::shuffle()
{
    currentCard = 0;
    for (int firstCard = 0; firstCard < NUM_OF_CARDS * deckCount; firstCard++)
    {
        int randCard = (QRandomGenerator::global()->generate() % NUM_OF_CARDS);
        deck.swapItemsAt(firstCard, randCard);
    }
}

Card * Deck::dealFromTop()
{
    return deck[currentCard++];
}

int Deck::cardsDealt() const
{
    return currentCard;
}
