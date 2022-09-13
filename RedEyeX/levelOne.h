#ifndef LEVELONE_H_
#define LEVELONE_H_

#include <gb/gb.h>
#include "SpaceMap.c"
#include "SpaceTiles.c"

UINT16 distance;
BYTE onBoss;
void startLevelOne();
void updateLOne();
void spawnEnemyWaves();
UINT8 endLevel();

#endif