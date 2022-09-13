#include <gb/gb.h>
#include <stdio.h>
#include "player.c"
#include "maths.c"
#include "textHandler.c"
#include "logo.c"
#include "logoTilesReal.c"
#include "levelOne.c"
#include "characterStruct.c"

BYTE gameRunning = 0;
// ~~~ GAME STATES ~~~
// 1 - Main Menu
// 2 - Prelevel Cutscene
// 3 - In game level
// 4 - Game Over
// 5 - Continue Password Screen
UINT8 gameState = 1; 
UINT8 currentLevel = 1;
BYTE fireCoolDown = 0;
UINT8 numOfLoops = 0;

void gameLoop();
void checkInput();
void mainMenuInput();
void levelHandler();
void levelUpdater();

void main()
{
    DISPLAY_ON;
    initWin();
    gameLoop();
}

void gameLoop()
{
    gameRunning = 1;
    while (gameRunning)
    {   
        switch(gameState)
        {
        case 1:
            mainMenuInput();
            break;
        case 3:
            checkInput();
            levelUpdater();
            if (laserExists == 1)
            {
                updateLaser();
            }
            break;
        }

        performantdelay(2);
        if (fireCoolDown == 1)
        {
            numOfLoops++;
            if (numOfLoops >= 15)
            {
                fireCoolDown = 0;
                numOfLoops = 0;
            }
        }
    }
}

void mainMenuInput()
{
    unsigned char phrase[] = 
    {
        0x19, 0x10, 0x22, 0x00, 0x12, 0x0C, 0x18, 0x10
    };
    UINT8 i;
    size_t size = sizeof(phrase) / sizeof(phrase[0]);
    set_bkg_data(36, 51, LogoTiles);
    set_bkg_tiles(4, 2, 10, 9, tempLogo);
    SHOW_BKG;
    set_win_tiles(0,0,8,1,phrase);
    addAdditionalText(50, 100);
    SHOW_WIN;
    switch(joypad())
    {
    case J_START:
        setUpPlayer(80, 130, 16, 16);
        SHOW_SPRITES;
        gameState = 3;
        HIDE_WIN;
        set_bkg_tiles(4, 2, 10, 9, whiteOut);
        for (i = 0; i < size; i++)
        {
            phrase[i] = 0x00;
        }
        set_win_tiles(0, 0, 8, 1, phrase);
        levelHandler();
        break;
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
    case J_A:
        if (fireCoolDown == 0)
        {
            fire();
        }
        fireCoolDown = 1;
    }
}

void levelHandler()
{
    switch(currentLevel)
    {
    case 1:
        startLevelOne();
        break;
    }
}

void levelUpdater()
{
    switch(currentLevel)
    {
    case 1:
        updateLOne();
        break;
    }
}