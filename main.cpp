#include <QApplication>

#include "gameboard.h"
#include "deck.h"
#include "Entity/player.h"

GameBoard * board;
Deck * Player::mDeck = new Deck(1);

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    board = new GameBoard;
    board->show();
    return a.exec();
}
