#ifndef PERSON_H
#define PERSON_H

#include <QObject>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QGraphicsTextItem>

#include "card.h"
#include "deck.h"
#include "Defines.h"

class Person : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
private:
    int aceCount = 0;
    void addValue(const Card *); 

protected:
    int size_x = 200;
    int size_y = 200;
    static Deck * mDeck;
    QVector<Card *> drawnCard;
    QString pName;
    int totalCardsDrawn = 0;
    int totalHandValue = 0;
    QGraphicsTextItem * scoreText;
    QGraphicsTextItem * statusText;

public:
    Person(QGraphicsItem * parent = nullptr);
    virtual ~Person() = 0;
    QString name() const;
    int totalCount() const;
    int drawCount() const;
    void reset();

public slots:
    void hit();
    void updateUI();

signals:
    void scorePing(const QString &);
};

#endif // PERSON_H
