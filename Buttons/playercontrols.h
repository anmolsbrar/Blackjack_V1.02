#ifndef PLAYERCONTROLS_H
#define PLAYERCONTROLS_H

#include <QObject>
#include <QGraphicsRectItem>
#include <QPainter>
#include <QGraphicsScene>


#include <Buttons/controlbuttons.h>

class PlayerControls : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    PlayerControls(QGraphicsItem *parent = nullptr);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    ControlButtons * standButton, * hitButton, * doubleButton;
    void enableCtrl(bool);
    void draw();

signals:

};

#endif // PLAYERCONTROLS_H
