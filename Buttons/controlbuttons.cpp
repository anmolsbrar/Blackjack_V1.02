#include "controlbuttons.h"

ControlButtons::ControlButtons(ControlType type) : controlType(type)
{
    size_x = CTRL_BTN_SIZE_X;
    size_y = CTRL_BTN_SIZE_Y;

    setButton();

    path.addRect(0, 0, size_x, size_y);
    pix = new QPixmap(buttonDefault);

    setAcceptHoverEvents(true);
    setPixmap(*pix);
}

void ControlButtons::setButton()
{
    if(controlType == HIT)
    {
        buttonDefault = ":Images/buttons/hitButtonActive.png";
        buttonInactive = ":Images/buttons/hitButtonGrey.png";
        buttonHover = ":Images/buttons/hitButtonHover.png";
    }
    else if(controlType == STAND)
    {
        buttonDefault = ":Images/buttons/standButtonActive.png";
        buttonInactive = ":Images/buttons/standButtonGrey.png";
        buttonHover = ":Images/buttons/standButtonHover.png";
    }
    else if(controlType == DOUBLE)
    {
        buttonDefault = ":Images/buttons/doubleButtonActive.png";
        buttonInactive = ":Images/buttons/doubleButtonGrey.png";
        buttonHover = ":Images/buttons/doubleButtonHover.png";
    }
}

void ControlButtons::setActive(bool active)
{
    isActive = active;
    if(active)
    {
        pix->load(buttonDefault);
        setAcceptHoverEvents(true);
    }
    else
    {
        pix->load(buttonInactive);
        setAcceptHoverEvents(false);

    }
    update();
}

QPainterPath ControlButtons::shape() const
{
    return path;
}

void ControlButtons::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(isActive)
        emit clicked();
}


