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

    QVector<Card *> drawnCard;

public:
    enum PlayerStatus {WON, LOST, BUST, PUSH, BLACKJACK, PLAYING};
    Player(QGraphicsItem * parent = nullptr);
    Player(int, QGraphicsItem * parent = nullptr);
    ~Player();
    QString name() const;
    int handValue() const;
    int drawCount() const;
    void reset();
    virtual void initializeUI();
    void updateUI();
    void setPlayerStatus(PlayerStatus);
    PlayerStatus getPlayerStatus() const;

protected:
    QString pName;
    int totalCardsDrawn = 0;
    int totalHandValue = 0;
    static Deck * mDeck;

    QGraphicsTextItem * scoreText;
    QGraphicsTextItem * statusText;
    PlayerStatus playerStatus;

public slots:
    void hit();

signals:
};

#endif // PLAYER_H
