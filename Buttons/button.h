#ifndef BUTTON_H
#define BUTTON_H

#include <QObject>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsPixmapItem>
#include <QBrush>
#include <QPainter>

class Button : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

private:
    void StartSettings();
    void ExitSettings();
    void SeatSettings();
    void RestartSettings();

protected:
    int size_x, size_y;
    QString buttonDefault, buttonHover, buttonInactive;
    QPixmap * pix;
    QRect * rect;
    QPainterPath path;

public:
    enum ButtonType {START, EXIT, SEAT, RESTART};
    Button(QGraphicsItem * parent = nullptr);
    Button(ButtonType, QGraphicsItem * parent = nullptr);

    // public members
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event) override;
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event) override;
    QPainterPath shape() const override;

signals:
    void clicked();
};

#endif // BUTTON_H
