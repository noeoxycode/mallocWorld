//
// Created by noe on 05/11/2021.
//
//
// Created by noe on 05/11/2021.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//prend une map en param et l'affiche
void displayMap(int **map,int height,int width){
    for(int y=0;y<height;y++){
        for(int x=0;x<width;x++){
            printf("%d ",map[x][y]);
        }
        printf("\n");
    }
}

//crée une carte et la retourne
int ** createMap(int height,int width){
    int** map=malloc(sizeof(int*)*height);
    for(int x=0;x<width;x++){
        map[x]=malloc(sizeof(int)*width);
    }
    for(int y=0;y<height;y++){
        for(int x=0;x<width;x++){
            map[y][x]=0;
        }
    }
    return map;
}

//remplis la map avec les murs
int **fillWall(int **map, int mapLevel){
    //determine le nb de murs

    //place les murs
}

//remplis la map avec les mob
int **fillMob(int **map, int mapLevel){
    //determine le nb de mob

    //place les mob
}

//remplis la map avec les items
int **fillItems(int **map, int mapLevel){
    //determine le nb de items

    //place les items
}