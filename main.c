#include <stdio.h>
#include "item.h"
#include "player.h"
#include "monstres.h"
#include "map_creator.h"
#include "turn.c"

int main() {
    int  ***listMap = listMapGenerator();
    for (int i=1;i<2;i++) {
        displayMap(listMap[i - 1], i);
        printf("--------------------\n");
    }
    Monstre* listMonstre=getMobBase();
    Player joueur;
    initPlayer(&joueur,"toto");
    getPlayer(&joueur);
    while(1) {
        displayMap(listMap[0], 1);
        PlayTurn(listMap[0], 12, 1,&joueur,&listMonstre);
    }
    return 0;
}