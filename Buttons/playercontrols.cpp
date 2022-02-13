#include "playercontrols.h"

#include "gameboard.h"

extern GameBoard * board;

PlayerControls::PlayerControls(QGraphicsItem *parent) : QGraphicsRectItem(parent)
{
    this->setRect(0,0,100, 100);

    hitButton = new ControlButtons(ControlButtons::HIT);
    standButton = new ControlButtons(ControlButtons::HIT);
    doubleButton = new ControlButtons(ControlButtons::HIT);

    hitButton->setPos(this->boundingRect().width()/10 * 1, this->boundingRect().height()/10 * 2);
    standButton->setPos(this->boundingRect().width()/10 * 6, this->boundingRect().height()/10 * 2);
    doubleButton->setPos(this->boundingRect().width()/10 * 3.5, this->boundingRect().height()/10 * 6);

    board->scene->addItem(hitButton);
    board->scene->addItem(standButton);
    board->scene->addItem(doubleButton);
}


void PlayerControls::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawRoundedRect(this->boundingRect(), 20, 20);
}

void PlayerControls::enableCtrl(bool enable)
{
    if(enable)
    {
        hitButton->setActive(true);
        standButton->setActive(true);
        doubleButton->setActive(true);
    }
    else
    {
        hitButton->setActive(false);
        standButton->setActive(false);
        doubleButton->setActive(false);
    }
}

