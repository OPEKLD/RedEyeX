#ifndef PLAYER_H_
#define PLAYER_H_

#include <gb/gb.h>
#include <stdio.h>
#include "characterStruct.c"
#include "n1char.c"

struct GameCharacter player;
UBYTE spritesize = 8;
void setUpPlayer(UINT8 x, UINT8 y, UINT8 width, UINT8 height);
void movePlayer(UINT8 x, UINT8 y);

#endif