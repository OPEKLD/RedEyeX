#include "player.h"

void movePlayer(UINT8 x, UINT8 y)
{   
    player.x += x;
    player.y += y;
    move_sprite(player.spritids[0], player.x, player.y);
    move_sprite(player.spritids[1], player.x + spritesize, player.y);
    move_sprite(player.spritids[2], player.x, player.y + spritesize);
    move_sprite(player.spritids[3], player.x + spritesize, player.y + spritesize);
}

void setUpPlayer(UINT8 x, UINT8 y, UINT8 width, UINT8 height)
{
    set_sprite_data(0, 4, n1);
    
    player.x = x;
    player.y = y;
    player.width = width;
    player.height = height;

    // load sprites for ship
    set_sprite_tile(0, 0);
    player.spritids[0] = 0;
    set_sprite_tile(1, 1);
    player.spritids[1] = 1;
    set_sprite_tile(2, 2);
    player.spritids[2] = 2;
    set_sprite_tile(3, 3);
    player.spritids[3] = 3;

    movePlayer(0, 0);
}