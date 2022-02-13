#ifndef PLAYERBUTTON_H
#define PLAYERBUTTON_H

#include "button.h"

class PlayerButton : public Button
{
public:
    PlayerButton(QString name, QGraphicsRectItem *parent = nullptr);

    void hoverEnterEvent(QGraphicsSceneHoverEvent *event) override;
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event) override;
};

#endif // PLAYERBUTTON_H
