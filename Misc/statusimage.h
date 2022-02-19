#ifndef STATUSIMAGE_H
#define STATUSIMAGE_H

#include <QGraphicsRectItem>
#include <QPainter>
#include <QImageReader>

#include "defines.h"

class StatusImage : public QGraphicsRectItem
{

public:
    StatusImage(QGraphicsItem * parent = nullptr);
    void setStatusImage(PlayerStatus);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

private:
    int size_x, size_y;
    QPixmap * pix;
    PlayerStatus tagStatus;
    QString strWin = ":/Images/status/statusWinner.png";
    QString strLost = ":/Images/status/statusLost.png";
    QString strBlackjack = ":/Images/status/statusBlackjack.png";
    QString strBust = ":/Images/status/statusBust.png";
};

#endif // STATUSIMAGE_H
