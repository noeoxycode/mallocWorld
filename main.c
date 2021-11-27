#include <stdio.h>
#include "item.h"
#include "player.h"
#include "monstres.h"
#include "map_creator.h"
#include "turn.c"

int main() {
    Monstre* listMonstreMap=malloc(sizeof (Monstre)*150);
    listMonstreMap[0].id=-1;
    Item * listItemMap=malloc(sizeof (Monstre)*150);
    listMonstreMap[0].id=-1;

    int  ***listMap = listMapGenerator(listMonstreMap);
    for(int i=0;listMonstreMap[i].id!=-1;i++){
        printf("%d %d\n",listMonstreMap[i].id,listMonstreMap[i].zone);
    }
    for (int i=1;i<1;i++) {
        displayMap(listMap[i - 1], i);
        printf("--------------------\n");
    }
    Monstre* listMonstre=getMobBase();
    Player joueur;
    initPlayer(&joueur,"toto");
    getPlayer(&joueur);
    while(1) {
        displayMap(listMap[0], 1);
        printf("--------------------\n");
        PlayTurn(listMap[0], 12, 1,&joueur,listMonstreMap);
        checkRespawn(listMonstreMap,listMap[0],1);

    }
    return 0;
}