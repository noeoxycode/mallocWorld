//
// Created by noe on 05/11/2021.
//
//
// Created by noe on 05/11/2021.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "save.h"
//#include "monstres.c"
int ** createMap(int level);
void displayMap(int **map,int level);
int *** listMapGenerator();
int getMapSize(int level);
int **fillWall(int **map, int mapLevel);
int **fillItems(int **map, int mapLevel);
int **fillMob(int **map, int mapLevel);

int getMapSize(int level){
    if(level==1){
        return 12;
    }else if(level==2){
        return 15;
    }else{
        return 20;
    }
}

int *** listMapGenerator(){
    int **map1= createMap(1);
    int **map2= createMap(2);
    int **map3= createMap(3);
    int ***listMap= malloc(sizeof(int**)*3);
    listMap[0]=map1;
    listMap[1]=map2;
    listMap[2]=map3;
    return listMap;
}

//prend une map en param et l'affiche
void displayMap(int **map,int level){
    int size=getMapSize(level);
    for(int y=0;y<size;y++){
        for(int x=0;x<size;x++){
            if(map[x][y]<10 &&map[x][y]!=-1){
                printf(" ");
            }
            printf("%d ",map[x][y]);
        }
        printf("\n");
    }
}

//crée une carte et la retourne
int ** createMap(int level){
    int size= getMapSize(level);
    int** map=malloc(sizeof(int*)*size);
    for(int x=0;x<size;x++){
        map[x]=malloc(sizeof(int)*size);
    }
    for(int y=0;y<size;y++){
        for(int x=0;x<size;x++){
            map[y][x]=0;
        }
    }
    map=fillWall(map,level);
    printf("test 1");
    map=fillItems(map,level);
    printf("test 2");
    map=fillMob(map,level);
    printf("test 3");
    return map;
}

//remplis la map avec les murs
int **fillWall(int **map, int mapLevel){
    //determine le nb de murs
    srand(time(0));
    int x;
    int y;
    int nbMurs = rand() % (mapLevel * 10)+1;
    int i = 0;
    while (i < nbMurs)
    {
        x = rand() % getMapSize(mapLevel);
        y = rand() % getMapSize(mapLevel);
        if (map[x][y] == 0)
        {
            if (map[x][y-1] != -1 || map[x][y+1] != -1)
            {
                map[x][y] = -1;
                i++;
            }

        }
    }
    //place les murs
    return map;
}

//remplis la map avec les mob
int **fillMob(int **map, int mapLevel){
    //determine le nb de mob
    int nbMob = 0;
    if (mapLevel == 1)
        nbMob = 10;
    else if (mapLevel == 2)
        nbMob = 13;
    else if (mapLevel == 3)
        nbMob = 17;
    else
        nbMob = -1;

    int i = 0;
    srand(time(0));
    int randomMonster=0,x=0,y=0;
    while (i < nbMob)
    {
        randomMonster = ( rand() % 15 ) + 12;
        x = rand()% (getMapSize(mapLevel));
        y = rand()% (getMapSize(mapLevel));
        if (map[x][y] == 0 /*&& monstres[randomMonster].lvlvalue == mapLevel*/)
        {
            map[x][y] = randomMonster;
            i++;
        }
    }
    return map;
}

//remplis la map avec les items
int **fillItems(int **map, int mapLevel){
    srand(time(0));
    int x;
    int y;
    int cpt = 0;
    int typeItem = 3 * mapLevel;
    int *numbersOfMapObjects = (int *)malloc(sizeof(int)*3);
    numbersOfMapObjects[0] =rand()% (10);
    numbersOfMapObjects[1] =rand()% (10);
    numbersOfMapObjects[2] =rand()% (10);
    for (int i = 0; i < 3; i++)
    {
        while (cpt < numbersOfMapObjects[i])
        {
            x = rand()% (getMapSize(mapLevel));
            y = rand()% (getMapSize(mapLevel));
            if (map[x][y] == 0)
            {
                map[x][y] = typeItem;
                cpt++;
            }
        }
        cpt = 0;
        typeItem++;
    }
    return map;
}