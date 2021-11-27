//
// Created by Velolime on 25/11/2021.
//

#ifndef MALLOCWORLD_MAP_CREATOR_H
#define MALLOCWORLD_MAP_CREATOR_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "monstres.h"

int ** createMap(int level,Monstre* listMonstreMap);
void displayMap(int **map,int level);
int *** listMapGenerator(Monstre* listMonstreMap);
int getMapSize(int level);
int **fillWall(int **map, int mapLevel);
int **fillItems(int **map, int mapLevel);
int **fillMob(int **map, int mapLevel,Monstre* listMonstreMap);
int **fillOther(int **map, int mapLevel);
int** fillOtherMap1(int **map, int mapLevel);
int** fillOtherMap2(int **map, int mapLevel);
int** fillOtherMap3(int **map, int mapLevel);


#endif //MALLOCWORLD_MAP_CREATOR_H
