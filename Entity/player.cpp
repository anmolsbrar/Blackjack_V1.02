#include "player.h"
#include "gameboard.h"

extern GameBoard * board;

Player::Player(QGraphicsItem *parent) :
    QGraphicsRectItem(parent)
{
    this->setRect(0, 0, ENTITY_SIZE_X, ENTITY_SIZE_Y);
    this->setOpacity(0.0);
}

Player::Player(int num, QGraphicsItem *parent) :
    QGraphicsRectItem(parent), pName("Player_" + QString::number(num))
{
    this->setRect(0,0, ENTITY_SIZE_X, ENTITY_SIZE_Y);
    this->setOpacity(0.0);

}

Player::~Player()
{
}

QString Player::name() const
{
    return pName;
}

int Player::handValue() const
{
    return totalHandValue;
}

int Player::drawCount() const
{
    return totalCardsDrawn;
}

void Player::reset()
{
    aceCount = 0;
    totalCardsDrawn = 0;
    totalHandValue = 0;

    for(Card * c : drawnCard)
        scene()->removeItem(c);

    scene()->removeItem(statusImg);

    drawnCard.clear();
}

void Player::initializeUI()
{
    QFont titleFont("Century Gothic",12);
    titleFont.setBold(true);

    scoreText = new QGraphicsTextItem();
    scoreText->setDefaultTextColor(Qt::white);
    scoreText->setFont(titleFont);
    scoreText->setPlainText(QString::number(totalHandValue));
    scoreText->setPos(this->x() + SCORE_OFFSET_X, this->y() + SCORE_OFFSET_Y);
    board->scene->addItem(scoreText);

    statusImg = new StatusImage();
    statusImg->setPos(this->x() + STATUS_OFFSET_X, this->y() + STATUS_OFFSET_Y);
}

void Player::addValue(const Card * hCard)
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

void Player::hit()
{
    Card * hCard = mDeck->dealFromTop();
    drawnCard.push_back(hCard);

    if(totalCardsDrawn > 0)
        hCard->setPos(drawnCard[totalCardsDrawn - 1]->x() + CARD_OFFSET_X, drawnCard[totalCardsDrawn - 1]->y() + CARD_OFFSET_Y);
    else
        hCard->setPos(this->x() + CARD_X, this->y() + CARD_Y);

    totalCardsDrawn++;
    addValue(hCard);
    updateUI();

    scene()->addItem(hCard);
}

void Player::updateUI()
{
    scoreText->setPlainText(QString::number(totalHandValue));
}

void Player::setPlayerStatus(PlayerStatus status)
{
    playerStatus = status;

    if(playerStatus == BLACKJACK)
    {
        statusImg->setStatusImage(BLACKJACK);
        statusImg->moveBy(-10, 0);
    }
    else if(playerStatus == PUSH)
        statusImg->setStatusImage(PUSH);
    else if(playerStatus == BUST)
        statusImg->setStatusImage(BUST);
    else if(playerStatus == WON)
        statusImg->setStatusImage(WON);
    else if(playerStatus == LOST)
        statusImg->setStatusImage(LOST);

    if(playerStatus != PLAYING)
        board->scene->addItem(statusImg);

}

PlayerStatus Player::getPlayerStatus() const
{
   return playerStatus;
}
