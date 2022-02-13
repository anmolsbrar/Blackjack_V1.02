#ifndef STARTSCREEN_H
#define STARTSCREEN_H

#include <QObject>
#include <QPushButton>
#include <QGraphicsScene>

class startScreen : public QObject
{
    Q_OBJECT
public:
    QPushButton * startButton = new QPushButton;
    startScreen(QObject *parent = nullptr);
    void ShowScene();
    void HideScene();

signals:

};

#endif // STARTSCREEN_H
