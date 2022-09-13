#ifndef PLAYER_H_
#define PLAYER_H_

#include <gb/gb.h>
#include <stdio.h>
#include "characterStruct.c"
#include "n1char.c"
#include "bullet.c"

struct GameCharacter player;
UINT8 laserXs[11];
UINT8 initXs[11];
UINT8 laserYs[11];
BYTE laserExists = 0;
UBYTE spritesize = 8;
UINT8 lives = 3;
UINT8 index = 0;
UINT8 pHealth = 5;
UINT8 pMaxHealth = 5;
UINT8 laserIndex = 4;
void setUpPlayer(UINT8 x, UINT8 y, UINT8 width, UINT8 height);
void movePlayer(UINT8 x, UINT8 y);
void fire();
void updateLaser();

#endif