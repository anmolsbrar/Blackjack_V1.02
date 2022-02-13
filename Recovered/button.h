#ifndef BUTTON_H
#define BUTTON_H

#include <QObject>
#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>
#include <QBrush>
#include <QPainter>

class Button : public QObject, public QGraphicsRectItem
{
    Q_OBJECT

protected:
    QGraphicsTextItem * buttonText;
    QString buttonDefault, buttonHover;
    QPixmap * pix;

public:
    // public methods (events)
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    virtual void hoverEnterEvent(QGraphicsSceneHoverEvent *event) = 0;
    virtual void hoverLeaveEvent(QGraphicsSceneHoverEvent *event) = 0;

signals:
    void clicked();

};

#endif // BUTTON_H
