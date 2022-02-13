#include "player.h"


Player::Player(int num)
{
    pName = "Player_" + QString::number(num);
    scoreText = new QGraphicsTextItem();
    statusText = new QGraphicsTextItem();

    scoreText->setPos(this->x() + 100, this->y());
    statusText->setPos(this->x() + 50, this->y());
}

Player::~Player()
{

}

