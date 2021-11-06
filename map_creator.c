//
// Created by noe on 05/11/2021.
//
//
// Created by noe on 05/11/2021.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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
            if(map[x][y]<10){
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
    map=fillItems(map,level);
    map=fillMob(map,level);
    return map;
}

//remplis la map avec les murs
int **fillWall(int **map, int mapLevel){
    //determine le nb de murs

    //place les murs
    return map;
}

//remplis la map avec les mob
int **fillMob(int **map, int mapLevel){
    //determine le nb de mob

    //place les mob
    return map;
}

//remplis la map avec les items
int **fillItems(int **map, int mapLevel){
    //determine le nb de items

    //place les items
    return map;
}