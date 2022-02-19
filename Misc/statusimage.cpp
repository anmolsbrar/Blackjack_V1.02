#include "statusimage.h"


StatusImage::StatusImage(QGraphicsItem * parent) : QGraphicsRectItem(parent)
{
    pix = new QPixmap();
}

void StatusImage::setStatusImage(PlayerStatus status)
{
    tagStatus = status;
    if(status == WON)
    {
        size_x = 65;
        size_y = 110;
        this->setRect(0, 0, size_x, size_y);
        this->setRotation(0);

        pix->load(strWin);
    }
    else if(status == LOST)
    {
        size_x = 80;
        size_y = 26;
        this->setRect(0, 0, size_x, size_y);
        this->setRotation(30);
        pix->load(strLost);
    }
    else if(status == BLACKJACK)
    {
        size_x = 140;
        size_y = 42;
        this->setRect(0, 0, size_x, size_y);
        this->setRotation(0);
        pix->load(strBlackjack);
    }
    else if(status == BUST)
    {
        size_x = 80;
        size_y = 26;
        this->setRect(0, 0, size_x, size_y);
        this->setRotation(30);
        pix->load(strBust);
    }
}

void StatusImage::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setRenderHint(QPainter::Antialiasing, true);
    painter->drawPixmap(0, 0, size_x, size_y, *pix);
}
