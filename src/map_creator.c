//
// Created by noe on 05/11/2021.
//
//
// Created by noe on 05/11/2021.
//
#include "../header/map_creator.h"

int getMapSize(int level){
    if(level==1){
        return 12;
    }else if(level==2){
        return 15;
    }else{
        return 20;
    }
}

int *** listMapGenerator(Monstre* listMonstreMap,ressource* listRessourceMap,Player *player){
    int **map1= createMap(1,listMonstreMap,listRessourceMap,player);
    int **map2= createMap(2,listMonstreMap,listRessourceMap,player);
    int **map3= createMap(3,listMonstreMap,listRessourceMap,player);
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
            if(map[x][y]<10 && map[x][y]>=0){
                printf(" ");
            }
            printf("%d ",map[x][y]);
        }
        printf("\n");
    }
    printf("--------------------\n");
}

//crée une carte et la retourne
int ** createMap(int level,Monstre* listMonstreMap,ressource* listRessourceMap,Player *player){
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
    map=fillItems(map,level,listRessourceMap);
    map=fillMob(map,level,listMonstreMap);
    map=fillOther(map,level,player,listRessourceMap);
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
int **fillMob(int **map, int mapLevel,Monstre* listMonstreMap){
    //determine le nb de mob
    Monstre* monstreBase=getMobBase();
    int nbMob = 0;
    if (mapLevel == 1)
        nbMob = 10;
    else if (mapLevel == 2)
        nbMob = 13;
    else if (mapLevel == 3)
        nbMob = 17;
    else
        nbMob = -1;

    int i = 0,b=0,c=0;
    while(listMonstreMap[c].id!=-1){
        c++;
    }
    srand(time(0));
    int randomMonster=0,x=0,y=0;
    while (i < nbMob)
    {
        randomMonster = ( rand() % 25 ) + 12;
        x = rand()% (getMapSize(mapLevel));
        y = rand()% (getMapSize(mapLevel));
        while(monstreBase[b].id!=randomMonster&&b<100)b++;
        if (map[x][y] == 0 && monstreBase[b].Level==mapLevel /*&& monstres[randomMonster].lvlvalue == mapLevel*/)
        {
            map[x][y] = randomMonster;
            listMonstreMap[c+i]=monstreBase[b];
            listMonstreMap[c+i].position_x=x;
            listMonstreMap[c+i].position_y=y;
            listMonstreMap[c+i].zone=mapLevel;
            listMonstreMap[c+i+1].id=-1;
            i++;
        }
        b=0;
    }
    return map;
}

//remplis la map avec les items
int **fillItems(int **map, int mapLevel,ressource* listRessourceMap){
    srand(time(0));
    char ***listMapBasse=maps(),***listItemBasse=creatData();
    int x;
    int y;
    int cpt = 0;
    int typeItem = 3 * mapLevel,c=0,b=0,a=0;
    while(listRessourceMap[c].id!=-1){
        c++;
    }
    int *numbersOfMapObjects = (int *)malloc(sizeof(int)*3);
    numbersOfMapObjects[0] =(rand()%(10))+3;
    numbersOfMapObjects[1] =(rand()%(10))+3;
    numbersOfMapObjects[2] =(rand()%(10))+3;
    for (int i = 0; i < 3; i++){
        while(atoi(listMapBasse[b][0])!=typeItem)b++;
        while(strcmp(listItemBasse[a][0],listMapBasse[b][3])!=0)a++;
        while (cpt < numbersOfMapObjects[i])
        {
            x = rand()% (getMapSize(mapLevel));
            y = rand()% (getMapSize(mapLevel));
            if (map[x][y] == 0)
            {
                map[x][y] = typeItem;
                listRessourceMap[c]= getOneRessource(atoi(listItemBasse[a][0]));
                listRessourceMap[c].pos_x=x;
                listRessourceMap[c].pos_y=y;
                listRessourceMap[c].lvl=mapLevel;
                listRessourceMap[c+1].id=-1;
                c++;
                cpt++;
            }
        }
        cpt = 0;
        typeItem++;
        b=0;
        a=0;
    }
    return map;
}

int** fillOther(int **map, int mapLevel,Player *player,ressource* listRessourceMap){
    if(mapLevel==1){
        map= fillOtherMap1(map,mapLevel,player,listRessourceMap);
    }else if(mapLevel==2){
        map= fillOtherMap2(map,mapLevel,listRessourceMap);
    }else if(mapLevel==3){
        map= fillOtherMap3(map,mapLevel,listRessourceMap);
    }
    return map;
}

int** fillOtherMap1(int **map, int mapLevel,Player *player,ressource* listRessourceMap){
    int x,y,cpt=0,o=0;
    srand(time(0));
    while(cpt<3) {
        x = rand() % (getMapSize(mapLevel));
        y = rand() % (getMapSize(mapLevel));
        if (map[x][y] == 0) {
            if(cpt==0) {
                map[x][y] = 1;
                player->position_joueur[0]=1;
                player->position_joueur[1]=x;
                player->position_joueur[2]=y;
            }else if(cpt==1) {
                map[x][y] = -2;
                while(listRessourceMap[o].id!=-1)o++;
                listRessourceMap[o].id=-2;
                listRessourceMap[o].idMap=-2;
                listRessourceMap[o].pos_x=x;
                listRessourceMap[o].pos_y=y;
                listRessourceMap[o].lvl=1;
                listRessourceMap[o+1].id =-1;
            }else if(cpt==2) {
                map[x][y] = 2;
            }
            cpt++;
        }
    }
    return map;
}

int** fillOtherMap2(int **map, int mapLevel,ressource* listRessourceMap){
    int x,y,cpt=0,o;
    srand(time(0));
    while(cpt<3) {
        o=0;
        x = rand() % (getMapSize(mapLevel));
        y = rand() % (getMapSize(mapLevel));
        if (map[x][y] == 0) {
            if(cpt==0) {
                map[x][y] = -2;
                while(listRessourceMap[o].id!=-1)o++;
                listRessourceMap[o].id=-2;
                listRessourceMap[o].idMap=-2;
                listRessourceMap[o].pos_x=x;
                listRessourceMap[o].pos_y=y;
                listRessourceMap[o].lvl=mapLevel;
                listRessourceMap[o+1].id =-1;
            }else if(cpt==1) {
                map[x][y] = -3;
                while(listRessourceMap[o].id!=-1)o++;
                listRessourceMap[o].id=-3;
                listRessourceMap[o].idMap=-3;
                listRessourceMap[o].pos_x=x;
                listRessourceMap[o].pos_y=y;
                listRessourceMap[o].lvl=mapLevel;
                listRessourceMap[o+1].id =-1;
            }else if(cpt==2) {
                map[x][y] = 2;
            }
            cpt++;
        }
    }
    return map;
}

int** fillOtherMap3(int **map, int mapLevel,ressource* listRessourceMap){
    int x,y,cpt=0,o;
    srand(time(0));
    while(cpt<2) {
        o=0;
        x = rand() % (getMapSize(mapLevel));
        y = rand() % (getMapSize(mapLevel));
        if (map[x][y] == 0) {
            if(cpt==0) {
                map[x][y] = -3;
                while(listRessourceMap[o].id!=-1)o++;
                listRessourceMap[o].id=-2;
                listRessourceMap[o].idMap=-2;
                listRessourceMap[o].pos_x=x;
                listRessourceMap[o].pos_y=y;
                listRessourceMap[o].lvl=mapLevel;
                listRessourceMap[o+1].id =-1;
            }else if(cpt==1) {
                map[x][y] = 2;
            }
            cpt++;
        }
    }
    return map;
}