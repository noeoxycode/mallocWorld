#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "player.h"
#include "monstres.h"
#include "map_creator.h"
#include "turn.c"

int main() {
    Player joueur;
    printf("toto ");
    initPlayer(&joueur,"toto");
    printf("toto ");
    Monstre* listMonstreMap=malloc(sizeof (Monstre)*100);
    printf("a ");
    listMonstreMap[0].id=-1;
    Item * listItemMap=malloc(sizeof (Item)*100);
    listItemMap[0].id=-1;

    printf("toto ");
    int  ***listMap = listMapGenerator(listMonstreMap,&joueur);
    for(int i=0;listMonstreMap[i].id!=-1;i++){
        printf("%d %d\n",listMonstreMap[i].id,listMonstreMap[i].zone);
    }
    printf("toto ");
    for (int i=1;i<2;i++) {
        displayMap(listMap[i - 1], i);
    }
    Monstre* listMonstre=getMobBase();
    printf("a ");
    printf("a ");
    getPlayer(&joueur);
    printf("a \n");
    while(1) {
        displayMap(listMap[0], 1);
        PlayTurn(listMap[0], 12, 1,&joueur,listMonstreMap);
        checkRespawn(listMonstreMap,listMap[0],1);

    }
    return 0;
}