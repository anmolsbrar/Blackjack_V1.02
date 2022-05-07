#include "gameboard.h"

GameBoard::GameBoard(QGraphicsView * parent) : QGraphicsView(parent)
{
    setLayout();
}

void GameBoard::setLayout()
{
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,RES_X,RES_Y);

    QBrush brush(QPixmap(":/Images/Background.png"));
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

    QGraphicsRectItem * rect = new QGraphicsRectItem(0,0, 1280, 720);
    QBrush brush(blurPix(QPixmap(":/Images/Background.png")));
    rect->setBrush(brush);

    scene->clear();

    //Start Button settings
    int x_startButton = this->width()/2 - startButton->boundingRect().width()/2;
    int y_startButton = scene->height()/2 - startButton->boundingRect().height()/2;
    startButton->setPos(x_startButton, y_startButton);
    QObject::connect(startButton, &Button::clicked, this, &GameBoard::playerMenu);
    scene->addItem(startButton);

    exitButton();
}

void GameBoard::playerMenu()
{
    scene->clear();

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
    //exit Button
    exitButton();

    scene->addItem(player3Button);
}

void GameBoard::startGameScreen()
{
    scene->clear();

    exitButton();

    initPlayers(); // ****** initialize players ******

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
    int y_restartButton = 230;
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

   // if(Player::mDeck)

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
            user->setPlayerStatus(PLAYING);
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
        player->setPlayerStatus(BLACKJACK);
    else if(score > 21)
        player->setPlayerStatus(BUST);
    else if(score <= 21)
        player->setPlayerStatus(PLAYING);
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
    PlayerStatus pStatus;
    int playerScore;
    int dealerScore = dealer->handValue();

    for(int i = 0; i < players.size() - 1; i++)
    {
        pStatus = players[i]->getPlayerStatus();
        playerScore = players[i]->handValue();
        if(pStatus == BUST)
            continue;
        else
        {
            if(pStatus == PLAYING)
            {
                if(dealer->getPlayerStatus() == BUST)
                {
                    players[i]->setPlayerStatus(WON);
                    continue;
                }

                if(playerScore > dealerScore)
                    players[i]->setPlayerStatus(WON);
                else if(playerScore == dealerScore)
                    players[i]->setPlayerStatus(PUSH);
                else
                    players[i]->setPlayerStatus(LOST);
            }
            else if(pStatus == BLACKJACK && dealer->getPlayerStatus() == BLACKJACK)
                players[i]->setPlayerStatus(PUSH);
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

void GameBoard::exitButton()
{
    Button * exitButton = new Button(Button::EXIT);
    //Exit button settings
    int x_exitButton = EXIT_BTN_X;
    int y_exitButton = EXIT_BTN_Y;
    exitButton->setPos(x_exitButton, y_exitButton);
    QObject::connect(exitButton, &Button::clicked, this, &GameBoard::close);
    scene->addItem(exitButton);
}

QPixmap GameBoard::blurPix(const QPixmap & inImg)
{
    QLabel * label = new QLabel();
    //label->setBaseSize(1280, 720);
    label->setPixmap(inImg);

    QGraphicsBlurEffect blur;
    blur.setBlurHints(QGraphicsBlurEffect::QualityHint);
    blur.setBlurRadius(3);

    label->setGraphicsEffect(&blur);

    QPixmap outImg(1280, 720);
    QPainter painter(&outImg);
    painter.end();
    label->render(&outImg, QPoint(0,0), QRegion(0,0,1280,720, QRegion::Rectangle));

    return outImg;
}
