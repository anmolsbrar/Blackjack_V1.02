#include "exitbutton.h"

ExitButton::ExitButton()
{
    this->setRect(0,0, 70, 40);

    buttonDefault = ":Images/buttons/exitButtonDefault.png";
    buttonHover = ":Images/buttons/exitButtonHover.png";

    pix = new QPixmap(buttonDefault);

    this->setAcceptHoverEvents(true);
}

void ExitButton::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(0, 0, 70, 40, *pix);
}

void ExitButton::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    pix->load(buttonHover);
    this->update();
}

void ExitButton::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    pix->load(buttonDefault);
    this->update();
}
