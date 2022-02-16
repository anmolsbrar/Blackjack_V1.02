#include "gameboard.h"

GameBoard::GameBoard(QGraphicsView * parent) : QGraphicsView(parent)
{
    setLayout();
}

void GameBoard::setLayout()
{
    QBrush brush(QPixmap(":/Images/Background.png"));

    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,RES_X,RES_Y);
    scene->setBackgroundBrush(brush);

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(RES_X,RES_Y);
    mainMenu();

    this->setScene(scene);
}

void GameBoard::initPlayers()
{
    //User and player
    for(int i = 0; i < 3; i++)
    {
        if (i == localPlayerPos)
        {
            user = new Player(i);
            players.push_back(user);

            //Player control settings
            ctrl = new PlayerControls();
            ctrl->enableCtrl(false);
            scene->addItem(ctrl);
            ctrl->setPos(pPosMatrix[i][0] + ENTITY_SIZE_X/2 - CTRL_SIZE_X/2, pPosMatrix[i][1] + ENTITY_SIZE_Y - CTRL_SIZE_Y);
            ctrl->updateUI();
        }
        else
            players.push_back(new Player(i + 1));

        players[i]->setPos(pPosMatrix[i][0], pPosMatrix[i][1]);
        players[i]->initializeUI();
        scene->addItem(players[i]);
    }

    //Dealer settings
    dealer = new Dealer();
    int x_dealer = this->width()/2 - dealer->boundingRect().width()/2;
    int y_dealer = 30;
    dealer->setPos(x_dealer, y_dealer);
    dealer->initializeUI();
    players.push_back(dealer);
    scene->addItem(dealer);
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
    float x_player1Button = PLAYER1_X;
    float y_player1Button = PLAYER1_Y;
    player1Button->setPos(x_player1Button, y_player1Button);
    QObject::connect(player1Button, &Button::clicked, [=]{
        localPlayerPos = 0;
        startGameScreen();
    });
    scene->addItem(player1Button);

    //player2Button settings
    float x_player2Button = PLAYER2_X;
    float y_player2Button = PLAYER2_Y;
    player2Button->setPos(x_player2Button, y_player2Button);
    QObject::connect(player2Button, &Button::clicked, [=]{
        localPlayerPos = 1;
        startGameScreen();
    });
    scene->addItem(player2Button);

    //player3Button settings
    float x_player3Button = PLAYER3_X;
    float y_player3Button = PLAYER3_Y;
    player3Button->setPos(x_player3Button, y_player3Button);
    QObject::connect(player3Button, &Button::clicked, [=]{
        localPlayerPos = 2;
        startGameScreen();
    });
    scene->addItem(player3Button);

    //Exit button settings
    float x_exitButton = 1170.00;
    float y_exitButton = 30.00;
    exitButton->setPos(x_exitButton, y_exitButton);
    QObject::connect(exitButton, &Button::clicked, this, &GameBoard::close);
    scene->addItem(exitButton);
}

void GameBoard::startGameScreen()
{
    scene->clear();

    Button * exitButton = new Button(Button::EXIT);

    initPlayers(); // ****** initialize players ******

    //Exit button settings
    int x_exitButton = 1170;
    int y_exitButton = 30;
    exitButton->setPos(x_exitButton, y_exitButton);
    QObject::connect(exitButton, &Button::clicked, this, &GameBoard::close);
    scene->addItem(exitButton);

    QObject::connect(this, &GameBoard::stopGame, this, &GameBoard::restartGame);


    QObject::connect(ctrl->hitButton, &Button::clicked, [=]{
        user->hit();
        checkHand(user);
    });
    QObject::connect(ctrl->standButton, &Button::clicked, [=]{
        gameClock->setInterval(200);
        ctrl->enableCtrl(false);
    });


    game();
}

void GameBoard::game()
{
    dealer->shuffle();
    resetGame();
    gameClock = new QTimer();

    QObject::connect(gameClock, &QTimer::timeout, this, &GameBoard::gameLoop);

    gameClock->start();
}

void GameBoard::restartGame()
{
    Button * restartButton = new Button(Button::RESTART);

    //Retart Button settings
    int x_restartButton = this->width()/2 - restartButton->boundingRect().width()/2;
    int y_restartButton = this->height()/2 - restartButton->boundingRect().height()/2;
    restartButton->setPos(x_restartButton, y_restartButton);
    QObject::connect(restartButton, &Button::clicked, [=]{
        game();
        scene->removeItem(restartButton);
    });
    scene->addItem(restartButton);
}

void GameBoard::gameLoop()
{
    const static int totalInitRounds = players.size() * 2 - 2;
    static int currentRound = 0;

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
            user->setPlayerStatus(Player::PLAYING);
            gameClock->setInterval(3000);
            ctrl->enableCtrl(true);
            playerIndex++;
        }
        else if(currentPlayer == dealer)
            dealerPlay();
        else
        {
            ctrl->enableCtrl(false);
            gameClock->setInterval(1000);
            computerPlay(currentPlayer);
        }
    }
    else if(state == END)
    {
        determineWinner();
        gameClock->stop();
        currentRound = 0;
        emit stopGame();
    }
}

void GameBoard::checkHand(Player * player)
{
    int score = player->handValue();

    if(score == 21 && player->drawCount() == 2)
        player->setPlayerStatus(Player::BLACKJACK);
    else if(score > 21)
        player->setPlayerStatus(Player::BUST);
    else if(score <= 21)
        player->setPlayerStatus(Player::PLAYING);
}

void GameBoard::computerPlay(Player * player)
{
    if(player->handValue() < 17)
        player->hit();
    else
    {
        playerIndex++;
        gameClock->setInterval(600);
    }
    checkHand(player);

}

void GameBoard::determineWinner()
{
    Player::PlayerStatus pStatus;
    int playerScore;
    int dealerScore = dealer->handValue();

    for(int i = 0; i < players.size() - 1; i++)
    {
        pStatus = players[i]->getPlayerStatus();
        playerScore = players[i]->handValue();
        if(pStatus == Player::BUST)
            continue;
        else
        {
            if(pStatus == Player::PLAYING)
            {
                if(playerScore > dealerScore)
                    players[i]->setPlayerStatus(Player::WON);
                else if(playerScore == dealerScore)
                    players[i]->setPlayerStatus(Player::PUSH);
                else
                    players[i]->setPlayerStatus(Player::LOST);
            }
            else if(pStatus == Player::BLACKJACK && dealer->getPlayerStatus() == Player::BLACKJACK)
                players[i]->setPlayerStatus(Player::PUSH);
        }
    }
}

void GameBoard::dealerPlay()
{
    if(dealer->handValue() < 17)
        dealer->hit();
    else
        state = END;

    checkHand(dealer);
}
