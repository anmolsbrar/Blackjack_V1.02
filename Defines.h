#ifndef DEFINES_H
#define DEFINES_H

#define RES_X 1280 //Game size/resolution
#define RES_Y 720

#define ENTITY_SIZE_X 200 //Entity size
#define ENTITY_SIZE_Y 300

#define CARD_X 5 //card pos from player POS
#define CARD_Y 25

#define CARD_OFFSET_X 25 //relative to last card POS
#define CARD_OFFSET_Y 15

#define SCORE_SIZE_X 36 //scoreText size
#define SCORE_SIZE_Y 24

#define SCORE_OFFSET_X ENTITY_SIZE_X/2 - SCORE_SIZE_X/2 //scoreText POS from entity
#define SCORE_OFFSET_Y 6

#define STATUS_SIZE_X 95 //statusText size
#define STATUS_SIZE_Y 30

#define STATUS_OFFSET_X 4  //statusText POS from entity   /previously 4
#define STATUS_OFFSET_Y 50

#define CTRL_SIZE_X 170 //player control size
#define CTRL_SIZE_Y 50

#define CTRL_OFFSET_X ENTITY_SIZE_X/2 - CTRL_SIZE_X/2 //player control offset from player Pos
#define CTRL_OFFSET_Y 280

#define CTRL_BTN_SIZE_X 29 //controlButton size
#define CTRL_BTN_SIZE_Y 29

#define PLAYER1_X 845 //player POS
#define PLAYER1_Y 441
#define PLAYER2_X 564
#define PLAYER2_Y 479
#define PLAYER3_X 282
#define PLAYER3_Y 440

#define EXIT_BTN_X 1170 //Exit button POS
#define EXIT_BTN_Y 30

enum PlayerStatus {WON, LOST, BUST, PUSH, BLACKJACK, PLAYING};



#endif // DEFINES_H
