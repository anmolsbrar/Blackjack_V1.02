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

int Dealer::upCardValue() const
{
    return drawnCard.at(0)->getValue();
}

void Dealer::initializeUI()
{
    QFont titleFont("comic sans",20);


    scoreText = new QGraphicsTextItem();
    scoreText->setFont(titleFont);
    scoreText->setPlainText(QString::number(totalHandValue));
    scoreText->setPos(this->x() + SCORE_OFFSET_X, this->y() + SCORE_OFFSET_Y);
    board->scene->addItem(scoreText);
    //scene()->addItem(scoreText);

    statusText = new QGraphicsTextItem();
    statusText->setFont(titleFont);
    statusText->setPlainText("STATUS");
    statusText->setPos(this->x() + STATUS_OFFSET_X, this->y() + STATUS_OFFSET_Y);
    board->scene->addItem(statusText);
}
