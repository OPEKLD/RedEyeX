#include "textHandler.h"

void initWin()
{
    font_init();
    min_font = font_load(font_min); // 36 tile
    font_set(min_font);
}

void setUpHUD()
{

}

void addAdditionalText(UINT8 x, UINT8 y)
{
    move_win(x, y);
}