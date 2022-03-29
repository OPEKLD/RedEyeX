#include <gb/gb.h>
#include <stdio.h>
#include "player.c"
#include "maths.c"

BYTE gameRunning = 0;

void gameLoop();
void checkInput();

void main()
{
    DISPLAY_ON;
    //waitpad(J_START);
    setUpPlayer(80, 130, 16, 16);
    
    SHOW_SPRITES;

    gameLoop();
}

void gameLoop()
{
    gameRunning = 1;
    while (gameRunning)
    {
        checkInput();

        performantdelay(2);
    }
}

void checkInput()
{
    switch(joypad())
    {
    case J_RIGHT:
        movePlayer(2, 0);
        break;
    case J_LEFT:
        movePlayer(-2, 0);
        break;
    case J_UP:
        movePlayer(0, -2);
        break;
    case J_DOWN:
        movePlayer(0, 2);
        break;
    }
}