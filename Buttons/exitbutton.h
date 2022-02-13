#ifndef EXITBUTTON_H
#define EXITBUTTON_H

#include "button.h"

class ExitButton : public Button
{
public:
    ExitButton();

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    void hoverEnterEvent(QGraphicsSceneHoverEvent *event) override;
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event) override;
};

#endif // EXITBUTTON_H
