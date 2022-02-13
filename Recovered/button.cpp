#include "button.h"
#include <QDebug>

void Button::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    emit clicked();
}
