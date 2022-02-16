#ifndef DEFINES_H
#define DEFINES_H

#define RES_X 1280
#define RES_Y 720

#define ENTITY_SIZE_X 200
#define ENTITY_SIZE_Y 300

//card pos from player POS
#define CARD_X 5
#define CARD_Y 25

//relative to last card POS
#define CARD_OFFSET_X 25
#define CARD_OFFSET_Y 15

//scoreText size
#define SCORE_SIZE_X 36
#define SCORE_SIZE_Y 24

//scoreText POS from entity
#define SCORE_OFFSET_X ENTITY_SIZE_X/2 - SCORE_SIZE_X/2
#define SCORE_OFFSET_Y 6

//statusText size
#define STATUS_SIZE_X 95
#define STATUS_SIZE_Y 30

//statusText POS from entity
#define STATUS_OFFSET_X 100 //previously 4
#define STATUS_OFFSET_Y 60

//player control size
#define CTRL_SIZE_X 170
#define CTRL_SIZE_Y 50

//player control offset from player Pos
#define CTRL_OFFSET_X ENTITY_SIZE_X/2 - CTRL_SIZE_X/2
#define CTRL_OFFSET_Y 280

//controlButton size
#define CTRL_BTN_SIZE_X 29
#define CTRL_BTN_SIZE_Y 29

//player POS
#define PLAYER1_X 845.00
#define PLAYER1_Y 441.00
#define PLAYER2_X 564.00
#define PLAYER2_Y 479.00
#define PLAYER3_X 282.00
#define PLAYER3_Y 440.00





#endif // DEFINES_H
