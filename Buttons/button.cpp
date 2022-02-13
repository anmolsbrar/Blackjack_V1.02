#include "button.h"
#include <QDebug>

void Button::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    emit clicked();
}

void Button::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    pix->load(buttonHover);
    this->update();
}

void Button::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    pix->load(buttonDefault);
    this->update();
}

QPainterPath Button::shape() const
{
    return path;
}


void Button::StartSettings()
{
    size_x = 120;
    size_y = 53;
    path.addRect(0, 0, size_x, size_y);
    buttonDefault = ":Images/buttons/StartButtonDefault.png";
    buttonHover = ":Images/buttons/StartButtonHover.png";

}

void Button::ExitSettings()
{
    size_x = 80;
    size_y = 46;
    path.addRect(0,0, size_x, size_y);
    buttonDefault = ":Images/buttons/exitButtonDefault.png";
    buttonHover = ":Images/buttons/exitButtonHover.png";
}

void Button::SeatSettings()
{
    size_x = 148;
    size_y = 137;
    path.addEllipse(0,0, size_x, size_y);
    buttonDefault = ":Images/buttons/PlayerButtonDefault.png";
    buttonHover = ":Images/buttons/PlayerButtonHover.png";
}

void Button::RestartSettings()
{
    size_x = 160;
    size_y = 51;
    path.addRect(0,0, size_x, size_y);
    buttonDefault = ":Images/buttons/RestartButtonDefault.png";
    buttonHover = ":Images/buttons/RestartButtonHover.png";

}

Button::Button(QGraphicsItem *parent) : QGraphicsPixmapItem(parent)
{
}

Button::Button(ButtonType type, QGraphicsItem * parent) : QGraphicsPixmapItem(parent)
{
    if(type == START)
        StartSettings();
    else if(type == RESTART)
        RestartSettings();
    else if(type == SEAT)
        SeatSettings();
    else if(type == EXIT)
        ExitSettings();

    pix = new QPixmap(buttonDefault);

    this->setAcceptHoverEvents(true);
    this->setPixmap(*pix);
}

void Button::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(0, 0, size_x, size_y, *pix);
}
