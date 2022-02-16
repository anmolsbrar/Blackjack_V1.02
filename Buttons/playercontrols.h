#ifndef PLAYERCONTROLS_H
#define PLAYERCONTROLS_H

#include <QObject>
#include <QGraphicsRectItem>
#include <QPainter>
#include <QGraphicsScene>


#include <Buttons/controlbuttons.h>
#include "defines.h"

class PlayerControls : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    PlayerControls(QGraphicsItem *parent = nullptr);
    ControlButtons * standButton, * hitButton, * doubleButton;
    void enableCtrl(bool);
    void draw();
    void updateUI();

signals:

};

#endif // PLAYERCONTROLS_H
