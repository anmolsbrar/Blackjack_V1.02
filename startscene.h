#ifndef STARTSCENE_H
#define STARTSCENE_H

#include <QGraphicsScene>
#include <QObject>
#include <QPushButton>
#include <QGraphicsScene>


class startScene : public QGraphicsScene
{
    Q_OBJECT
public:
    QGraphicsScene * scene;
    QPushButton * startButton;
    startScene(QObject *parent = nullptr);
    void ShowScene();
    void HideScene();
};

#endif // STARTSCENE_H
