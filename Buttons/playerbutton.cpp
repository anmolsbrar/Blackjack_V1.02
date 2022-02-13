#include "playerbutton.h"


PlayerButton::PlayerButton(QString name, QGraphicsRectItem *parent)
{
    this->setRect(0,0, 100, 60);

    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::darkGray);
    this->setBrush(brush);

    //Button text settings
    buttonText = new QGraphicsTextItem(name, this);
    int x_Pos = this->boundingRect().width()/2 - buttonText->boundingRect().width()/2;
    int y_Pos = this->boundingRect().height()/2 - buttonText->boundingRect().height()/2;

    buttonText->setPos(x_Pos, y_Pos);

    this->setAcceptHoverEvents(true);
}

void PlayerButton::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::gray);
    this->setBrush(brush);
}

void PlayerButton::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::darkGray);
    this->setBrush(brush);
}
