#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QGraphicsTextItem>

#include "card.h"
#include "deck.h"
#include "defines.h"


class Player : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
private:
    int aceCount = 0;
    void addValue(const Card *); 

protected:
    int size_x = ENTITY_SIZE_X;
    int size_y = ENTITY_SIZE_Y;
    static Deck * mDeck;
    QVector<Card *> drawnCard;
    QString pName;
    int totalCardsDrawn = 0;
    int totalHandValue = 0;
    QGraphicsTextItem * scoreText;
    QGraphicsTextItem * statusText;

public:
    Player(QGraphicsItem * parent = nullptr);
    Player(int, QGraphicsItem * parent = nullptr);
    ~Player();
    QString name() const;
    int totalCount() const;
    int drawCount() const;
    void reset();
    virtual void initializeUI();
    void updateUI();

public slots:
    void hit();

signals:
};

#endif // PLAYER_H
