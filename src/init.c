//
// Created by Velolime on 28/11/2021.
//

#include "../header/init.h"
void welcome () {
    printf("Bienvenue dans malloc World !\n Que souaitez-vous faire ?\n 1 : Nouvelle partie\n 2 : Charger une partie\n 3 : Quitter\n");
    int response = 0;
    scanf("%d", &response);
    while (response != 1 && response != 2&& response != 3)
    {
        scanf("%d", &response);
    }
    if (response == 1) {
        gameInit();
    }else if (response ==  2) {
        //loadGame();}
    }
}


void gameInit(){
    Player joueur;
    initPlayer(&joueur,"toto");
    Monstre* listMonstreMap=malloc(sizeof (Monstre)*100);
    listMonstreMap[0].id=-1;
    ressource * listItemMap=malloc(sizeof (ressource)*100);
    listItemMap[0].id=-1;
    int  ***listMap = listMapGenerator(listMonstreMap,listItemMap,&joueur);
    int level=1,res=0;
    while(res!=10) {
        checkMobRespawn(listMonstreMap,listMap[level-1],level);
        checkOtherRespawn(listItemMap,listMap[level-1],level);
        displayMap(listMap[level-1], level);
        res=PlayTurn(&listMap[level-1], getMapSize(level), &level,&joueur,listMonstreMap,listItemMap);
        if(res==6){
            //WriteInFile(listMap,&joueur);
        }
        listMap[level-1][joueur.position_joueur[1]][joueur.position_joueur[2]]=1;

    }
    printf("Fin de partit");




}