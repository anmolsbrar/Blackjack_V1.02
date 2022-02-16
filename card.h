#ifndef CARD_H
#define CARD_H

#include <QGraphicsRectItem>

class Card : public QGraphicsRectItem
{
private:
    QString face, suit;
    bool ace;
    int value;
    QString facePng;

public:
    Card();
    Card(const QString&, const QString&, int, bool, QString);

    //public members
    QString print() const;
    int getValue() const;
    bool isAce() const;
    void drawBackground(QPainter *);
    void paint(QPainter* , const QStyleOptionGraphicsItem *, QWidget *);
};

#endif // CARD_H
