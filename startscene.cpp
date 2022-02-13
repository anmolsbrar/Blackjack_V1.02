#include "startscene.h"

startScene::startScene(QObject *parent) : QGraphicsScene(parent)
{
    startButton = new QPushButton;
    startButton->move(400,300);
    startButton->setText("Start");
    startButton->setFocus();
   // scene->addItem(this);
    //startButton->set
}
