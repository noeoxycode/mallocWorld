#include <stdio.h>
#include "../header/item.h"
#include "../header/player.h"
#include "../header/monstres.h"
#include "../header/map_creator.h"
#include "../header/turn.h"
#include "../header/ressource.h"

int main() {
    Player joueur;
    initPlayer(&joueur,"toto");
    Monstre* listMonstreMap=malloc(sizeof (Monstre)*100);
    listMonstreMap[0].id=-1;
    ressource * listItemMap=malloc(sizeof (ressource)*100);
    listItemMap[0].id=-1;
    int  ***listMap = listMapGenerator(listMonstreMap,listItemMap,&joueur);
    printf("tot");
    for(int i=0;listItemMap[i].id!=-1;i++){
        //printf("%d %s %s %d %d %d\n",listItemMap[i].id,listItemMap[i].nom,listItemMap[i].type,listItemMap[i].pos_x,listItemMap[i].pos_y,listItemMap[i].resistance);
    }
    for (int i=1;i<2;i++) {
        displayMap(listMap[i - 1], i);
    }
    Monstre* listMonstre=getMobBase();
    getPlayer(&joueur);
    while(1) {
        displayMap(listMap[0], 1);
        printf("toto");
        PlayTurn(listMap[0], 12, 1,&joueur,listMonstreMap,listItemMap);
        checkMobRespawn(listMonstreMap,listMap[0],1);
        checkOtherRespawn(listItemMap,listMap[0],1);

    }
    return 0;
}