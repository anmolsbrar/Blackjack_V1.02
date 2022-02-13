#ifndef STARTBUTTON_H
#define STARTBUTTON_H

#include "button.h"
#include <QPixmap>

class StartButton : public Button
{
public:
    StartButton();

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event) override;
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event) override;
};

#endif // STARTBUTTON_H
