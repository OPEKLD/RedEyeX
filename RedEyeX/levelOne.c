#include "levelOne.h"

void startLevelOne()
{
    set_bkg_data(37, 48, spaceTiles);
    set_bkg_tiles(0, 0, 40, 18, SpaceMap);
}

void updateLOne()
{
    scroll_bkg(1,0);
}