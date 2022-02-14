#include "player.h"




Player::Player() : Player::Person()
{
}

Player::Player(int num) : Player::Person()
{
    QFont titleFont("comic sans",20);
    pName = "Player_" + QString::number(num);


    scoreText = new QGraphicsTextItem();
    scoreText->setFont(titleFont);
    scoreText->setPlainText(QString::number(totalHandValue));
    scoreText->setPos(SCORE_OFFSET_X, SCORE_OFFSET_Y);
    scene()->addItem(scoreText);

    statusText = new QGraphicsTextItem();
    scoreText->setFont(titleFont);
    statusText->setPlainText("STATUS");
    statusText->setPos(STATUS_OFFSET_X, STATUS_OFFSET_Y);
    scene()->addItem(statusText);


}

Player::~Player()
{

}

