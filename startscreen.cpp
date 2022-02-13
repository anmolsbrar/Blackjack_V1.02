#include "startscreen.h"

startScreen::startScreen(QObject *parent) : QObject(parent)
{
    startButton->move(400,300);
    startButton->setText("Start");
    startButton->setFocus();
    board->addWidget(startButton);
    //startButton->set
}
