#include "gameboard.h"
#include <QDebug>
#include <Buttons/controlbuttons.h>
#include "QPixmap"

GameBoard::GameBoard(QGraphicsView * parent) : QGraphicsView(parent)
{
    setLayout();
}



void GameBoard::setLayout()
{
    QBrush brush(QPixmap(":/Images/Background.png"));

    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,1280,720);
    scene->setBackgroundBrush(brush);

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1280,720);
    mainMenu();

    this->setScene(scene);
}

void GameBoard::initPlayers()
{
    QString playerName = "Anmol";

    //User and player
    for(int i = 0; i < 3; i++)
    {
        if (i == localPlayerPos)
        {
            user = new Player(i);
            players.push_back(user);
           // ctrl = new PlayerControl(nullptr);

           // scene->addWidget(ctrl);
           // ctrl->move(pPosMatrix[i][0] + 10, pPosMatrix[i][1] + 170);
        }
        else
            players.push_back(new Player(i + 1));

        players[i]->setPos(pPosMatrix[i][0], pPosMatrix[i][1]);
        scene->addItem(players[i]);
    }

    //Dealer settings
    dealer = new Dealer();
    int x_dealer = this->width()/2 - dealer->boundingRect().width()/2;
    int y_dealer = 100;
    dealer->setPos(x_dealer, y_dealer);
    players.push_back(dealer);
    scene->addItem(dealer);
}

void GameBoard::initialDraw()
{
    QTimer * timer = new QTimer();
    int playerIndex = 0, currentTurn = 0;
    int totalTurns = players.size() * 2 - 2;

    QObject::connect(timer, &QTimer::timeout,[=]() mutable {
        if(currentTurn >= totalTurns)
        {
            timer->stop();
            emit startGame();
        }

        if(playerIndex > players.size() - 1)
            playerIndex = 0;
        players[playerIndex]->hit();
        playerIndex++;
        currentTurn++;
    });

    timer->setInterval(500);
    timer->start();

}

void GameBoard::resetGame()
{
    playerIndex = 0;
    state = INIT_DRAW;

    for(auto p : players)
        p->reset();
}

void GameBoard::mainMenu()
{
    Button * startButton = new Button(Button::START);
    Button * exitButton = new Button(Button::EXIT);

    scene->clear();

    //Start Button settings
    int x_startButton = this->width()/2 - startButton->boundingRect().width()/2;
    int y_startButton = scene->height()/2 - startButton->boundingRect().height()/2;
    startButton->setPos(x_startButton, y_startButton);
    QObject::connect(startButton, &Button::clicked, this, &GameBoard::playerMenu);
    scene->addItem(startButton);

    //Exit button settings
    int x_exitButton = 1170;
    int y_exitButton = 30;
    exitButton->setPos(x_exitButton, y_exitButton);
    QObject::connect(exitButton, &Button::clicked, this, &GameBoard::close);
    scene->addItem(exitButton);
}

void GameBoard::playerMenu()
{
    scene->clear();

    Button * exitButton = new Button(Button::EXIT);
    Button * player1Button = new Button(Button::SEAT);
    Button * player2Button = new Button(Button::SEAT);
    Button * player3Button = new Button(Button::SEAT);

    //player1Button settings
    float x_player1Button = 282.00;
    float y_player1Button = 440.00;
    player1Button->setPos(x_player1Button, y_player1Button);
    QObject::connect(player1Button, &Button::clicked, [=]{
        localPlayerPos = 0;
        startGameScreen();
    });
    scene->addItem(player1Button);

    //player2Button settings
    float x_player2Button = 564.00;
    float y_player2Button = 479.00;
    player2Button->setPos(x_player2Button, y_player2Button);
    QObject::connect(player2Button, &Button::clicked, [=]{
        localPlayerPos = 1;
        startGameScreen();
    });
    scene->addItem(player2Button);

    //player3Button settings
    float x_player3Button = 845.00;
    float y_player3Button = 441.00;
    player3Button->setPos(x_player3Button, y_player3Button);
    QObject::connect(player3Button, &Button::clicked, [=]{
        localPlayerPos = 2;
        startGameScreen();
    });
    scene->addItem(player3Button);

    //Exit button settings
    int x_exitButton = 1170;
    int y_exitButton = 30;
    exitButton->setPos(x_exitButton, y_exitButton);
    QObject::connect(exitButton, &Button::clicked, this, &GameBoard::close);
    scene->addItem(exitButton);
}

void GameBoard::startGameScreen()
{
    scene->clear();

    player1ScoreText = new QGraphicsTextItem();
    player2ScoreText = new QGraphicsTextItem();
    player3ScoreText = new QGraphicsTextItem();
    dealerScoreText = new QGraphicsTextItem();
    player1StateText = new QGraphicsTextItem();
    player2StateText = new QGraphicsTextItem();
    player3StateText = new QGraphicsTextItem();
    dealerStateText = new QGraphicsTextItem();
    Button * exitButton = new Button(Button::EXIT);

    ctrl = new PlayerControls();
    ctrl->enableCtrl(false);
    scene->addItem(ctrl);

    initPlayers(); // ****** initialize players ******

    //sets state text position
    player1StateText->setPos(players[0]->x() + players[0]->boundingRect().width()/2 - player1ScoreText->boundingRect().width()/2, players[0]->y() - 30);
    player2StateText->setPos(players[1]->x() + players[1]->boundingRect().width()/2 - player1ScoreText->boundingRect().width()/2, players[1]->y() - 30);
    player3StateText->setPos(players[2]->x() + players[2]->boundingRect().width()/2 - player1ScoreText->boundingRect().width()/2, players[2]->y() - 30);
    dealerStateText->setPos(players[3]->x() + players[3]->boundingRect().width()/2 - player1ScoreText->boundingRect().width()/2, players[3]->y() - 30);

    scene->addItem(player1ScoreText);
    scene->addItem(player2ScoreText);
    scene->addItem(player3ScoreText);
    scene->addItem(dealerScoreText);

    QFont titleFont("comic sans",20);
    //player1ScoreText settings
    player1ScoreText->setFont(titleFont);
    player1ScoreText->setPlainText(QString::number(0));
    player1ScoreText->setPos(players[0]->x() + players[0]->boundingRect().width()/2 - player1ScoreText->boundingRect().width()/2, players[0]->y() + 200);
    scene->addItem(player1ScoreText);

    //player2ScoreText settings
    player2ScoreText->setFont(titleFont);
    player2ScoreText->setPlainText(QString::number(0));
    player2ScoreText->setPos(players[1]->x() + players[1]->boundingRect().width()/2 - player1ScoreText->boundingRect().width()/2, players[1]->y() + 200);
    scene->addItem(player2ScoreText);

    //player3ScoreText settings
    player3ScoreText->setFont(titleFont);
    player3ScoreText->setPlainText(QString::number(0));
    player3ScoreText->setPos(players[2]->x() + players[2]->boundingRect().width()/2 - player1ScoreText->boundingRect().width()/2, players[2]->y() + 200);
    scene->addItem(player3ScoreText);

    //dealerScoreText settings
    dealerScoreText->setFont(titleFont);
    dealerScoreText->setPlainText(QString::number(0));
    dealerScoreText->setPos(dealer->x() + dealer->boundingRect().width()/2 - player1ScoreText->boundingRect().width()/2, dealer->y() - 30);
    scene->addItem(dealerScoreText);

    //Exit button settings
    int x_exitButton = 1170;
    int y_exitButton = 30;
    exitButton->setPos(x_exitButton, y_exitButton);
    QObject::connect(exitButton, &Button::clicked, this, &GameBoard::close);
    scene->addItem(exitButton);

    QObject::connect(this, &GameBoard::stopGame, this, &GameBoard::restartGame);

    QObject::connect(players[0], &Person::scorePing, player1ScoreText, &QGraphicsTextItem::setPlainText);
    QObject::connect(players[1], &Person::scorePing, player2ScoreText, &QGraphicsTextItem::setPlainText);
    QObject::connect(players[2], &Person::scorePing, player3ScoreText, &QGraphicsTextItem::setPlainText);
    QObject::connect(players[3], &Person::scorePing, dealerScoreText, &QGraphicsTextItem::setPlainText);

    QObject::connect(ctrl->hitButton, &Button::clicked, [=]{
        user->hit();
    });
    QObject::connect(ctrl->standButton, &Button::clicked, [=]{
        gameClock->setInterval(200);
        ctrl->enableCtrl(false);
    });


    game();
}

void GameBoard::game()
{
    resetGame();
    gameClock = new QTimer();

    QObject::connect(gameClock, &QTimer::timeout, this, &GameBoard::gameLoop);

    gameClock->start();
}

void GameBoard::restartGame()
{
    Button * restartButton = new Button(Button::RESTART);
    //ExitButton * exitButton = new ExitButton(QString("Exit"));

    //Retart Button settings
    int x_restartButton = this->width()/2 - restartButton->boundingRect().width()/2;
    int y_restartButton = this->height()/2 - restartButton->boundingRect().height()/2;
    restartButton->setPos(x_restartButton, y_restartButton);
    QObject::connect(restartButton, &Button::clicked, this, &GameBoard::game);
    scene->addItem(restartButton);
    /*
    //Exit button settings
    int x_exitButton = 720;
    int y_exitButton = 10;
    exitButton->setPos(x_exitButton, y_exitButton);
    QObject::connect(exitButton, &Button::clicked, this, &GameBoard::close);
    scene->addItem(exitButton);
    */
}

void GameBoard::gameLoop()
{
    const static int totalInitRounds = players.size() * 2 - 2;
    static int currentRound = 0;

    if((playerIndex > players.size() - 1) && state == START) //stops game after the final player(dealer)
        state = END;

    if(state == INIT_DRAW)
    {
        gameClock->setInterval(500);
        if(currentRound > totalInitRounds)
        {
            ctrl->enableCtrl(false);
            state = START;
            playerIndex = 0;
            gameClock->setInterval(1500);
        }
        else
        {
            currentPlayer->hit();
            playerIndex++;
        }
        if(playerIndex >= players.size())
            playerIndex = 0;

        currentRound++;
    }
    else if(state == START)
    {
        if(currentPlayer == user)
        {
            gameClock->setInterval(3000);
            ctrl->enableCtrl(true);
            playerIndex++;
        }
        else
        {
            ctrl->enableCtrl(false);
            gameClock->setInterval(1000);
            computerPlay(currentPlayer);
        }
    }
    else if(state == END)
    {
        gameClock->stop();
        currentRound = 0;
        emit stopGame();
    }
}

void GameBoard::computerPlay(Person * player)
{
    if(player->totalCount() < 17)
        player->hit();
    else
    {
        playerIndex++;
        gameClock->setInterval(600);
    }

}

/*
QString GameBoard::checkPlayerStatus(Person * player)
{
    int score = player->totalCount();
    if(score > 21)
        return "Bust";
    else if(score == 21 && player->drawCount() < 3)
        return "Blackjack!";

    if(player != dealer)
    {
        if(score > dealer->totalCount())
            return "Won";
        else if (score == dealer->totalCount())
            return "Push";
        else
            return "Lost";
    }
    else
        return "";
}
*/

