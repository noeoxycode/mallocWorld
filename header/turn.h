#ifndef MALLOCWORLD_TURN_H
#define MALLOCWORLD_TURN_H

#include <stdlib.h>
#include <stdio.h>
#include "../header/player.h"
#include "../header/fight.h"
#include "../header/monstres.h"
#include "../header/ressource.h"
int *getPlayerPos(int ** map,int size);
int * getPlayerAround(int **map, int size,Player* player);
void printChoise(int num,char*dir,int lvl);
int userChoise(int* aroun,int lvl);
int **move(int** map,int dir,Player* player);
int ** PlayTurn(int **map, int size,int lvl,Player *player,Monstre* monstreList,ressource* ressourceList);
void checkMobRespawn(Monstre* listMob,int** map,int lvl);
void checkOtherRespawn(ressource * listOther,int** map,int lvl);
#endif //MALLOCWORLD_TURN_H
