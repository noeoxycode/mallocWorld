//
// Created by Velolime on 25/11/2021.
//

#ifndef MALLOCWORLD_MAP_CREATOR_H
#define MALLOCWORLD_MAP_CREATOR_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "monstres.h"
#include "player.h"
#include "ressource.h"

int ** createMap(int level,Monstre* listMonstreMap,ressource* listRessourceMap,Player *player);
void displayMap(int **map,int level);
int *** listMapGenerator(Monstre* listMonstreMap,ressource* listRessourceMap,Player *player);
int getMapSize(int level);
int **fillWall(int **map, int mapLevel);
int **fillItems(int **map, int mapLevel,ressource* listRessourceMap);
int **fillMob(int **map, int mapLevel,Monstre* listMonstreMap);
int **fillOther(int **map, int mapLevel,Player *player,ressource* listRessourceMap);
int** fillOtherMap1(int **map, int mapLevel,Player *player,ressource* listRessourceMap);
int** fillOtherMap2(int **map, int mapLevel,ressource* listRessourceMap);
int** fillOtherMap3(int **map, int mapLevel,ressource* listRessourceMap);


#endif //MALLOCWORLD_MAP_CREATOR_H
