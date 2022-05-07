#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#define currentPlayer players[playerIndex]

#include <QGraphicsView>
#include <QGraphicsItem>
#include <QGraphicsBlurEffect>
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QVector>
#include <QTimer>
#include <QLabel>

#include "Entity/player.h"
#include "Entity/dealer.h"
#include "Buttons/playercontrols.h"
#include "Buttons/button.h"
#include "defines.h"


class GameBoard : public QGraphicsView
{
    Q_OBJECT
private:

    const int pPosMatrix[3][2] = {{820, 310},
                                  {540, 350},
                                  {256, 304}};
    enum GameState {INIT_DRAW, START, END};
    int playerIndex;
    int localPlayerPos;
    QVector<Player *> players;
    Dealer * dealer;
    Player * user;
    QTimer * gameClock;
    PlayerControls * ctrl;
    GameState state;

public:
    explicit GameBoard(QGraphicsView *parent = nullptr);
    QGraphicsScene * scene;
    void setLayout();
    void initPlayers();
    void resetGame();
    void computerPlay(Player *);
    void determineWinner();
    void dealerPlay();
    void exitButton();
    QPixmap blurPix(const QPixmap&);

public slots: 
    void mainMenu();
    void playerMenu();
    void startGameScreen();
    void game();
    void restartGame();
    void gameLoop();
    void checkHand(Player *);

signals:
    void startGame();
    void stopGame();
};

#endif // GAMEBOARD_H
