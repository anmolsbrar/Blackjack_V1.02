#include "startbutton.h"

StartButton::StartButton()
{
    this->setRect(0,0, 120, 53);

    buttonDefault = ":Images/buttons/StartButtonDefault.png";
    buttonHover = ":Images/buttons/StartButtonHover.png";

    pix = new QPixmap(buttonDefault);

    this->setAcceptHoverEvents(true);
}

void StartButton::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(0, 0, 120, 53, *pix);
}

void StartButton::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    pix->load(buttonHover);
    this->update();
}

void StartButton::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    pix->load(buttonDefault);
    this->update();
}
