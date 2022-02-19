#ifndef CONTROLBUTTONS_H
#define CONTROLBUTTONS_H

#include <QObject>
#include <QPixmap>
#include <QPainter>
#include <QGraphicsItem>

#include <Buttons/button.h>

class ControlButtons : public Button
{
    Q_OBJECT


public:
    enum ControlType {STAND, HIT, DOUBLE};
    ControlButtons(ControlType);
    void setActive(bool);
    QPainterPath shape() const override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

private:
    ControlType controlType;
    void setButton();
    bool isActive;

signals:
};

#endif // CONTROLBUTTONS_H
