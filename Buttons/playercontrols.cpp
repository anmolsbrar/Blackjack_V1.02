#include "playercontrols.h"

#include "gameboard.h"

extern GameBoard * board;

PlayerControls::PlayerControls(QGraphicsItem *parent) : QGraphicsRectItem(parent)
{
    this->setRect(0,0, CTRL_SIZE_X, CTRL_SIZE_Y);

    hitButton = new ControlButtons(ControlButtons::HIT);
    standButton = new ControlButtons(ControlButtons::STAND);
    doubleButton = new ControlButtons(ControlButtons::DOUBLE);

    hitButton->setParent(this);
    standButton->setParent(this);
    doubleButton->setParent(this);

   // this->setPos()
    board->scene->addItem(hitButton);
    board->scene->addItem(standButton);
    board->scene->addItem(doubleButton);
}


void PlayerControls::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
   // painter->drawRoundedRect(this->boundingRect(), 20, 20);
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

void PlayerControls::updateUI()
{
    standButton->setPos(this->x(), this->y());
    hitButton->setPos(this->x() + this->boundingRect().width() - CTRL_BTN_SIZE_X, this->y());
    doubleButton->setPos(this->x() + this->boundingRect().width()/2 - CTRL_BTN_SIZE_X/2,this->y() + this->boundingRect().height() - CTRL_BTN_SIZE_Y);

    standButton->update();
    hitButton->update();
    doubleButton->update();
}

