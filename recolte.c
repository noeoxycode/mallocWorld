//
// Created by Jeune on 28/11/2021.
//

#include "recolte.h"



int recoltea(Player *player, ressource *matiere) {
    int choix=choose(player,matiere);
    int place=checkPlace(player,matiere);
    if(choix==-1||place==-1)return 3;
    int gain=use(player,matiere,choix,place);
    for(int i=0;i<10;i++){
        printf("%d %s %d %d\n",i,player->inventaire[i].nom,player->inventaire[i].quantite,player->inventaire[i].durabilite);
    }
    matiere->tmp_reaparition=
    return 1;

}

int choose(Player *player,ressource *matiere){
    printf("Quel %s voulez vous utiliser? :\n",getOutilName(matiere));
    int verif=0,checkList[10];
    bool checkOutilDurabilite,checkTypePuissance,checkPresence=false,checkPossible=false;
    for (int i = 0; i < 10 ; i++)
    {
        checkList[i]=-1;
        checkOutilDurabilite=strcmp(player->inventaire[i].type , "Outil")==0&&player->inventaire[i].durabilite>0;
        checkTypePuissance=strstr(player->inventaire[i].nom,getOutilName(matiere))&&player->inventaire[i].effet>=matiere->resistance;
        if(checkOutilDurabilite&&checkTypePuissance){
            printf("%d : %s  durabilite %d/10\n", i, player->inventaire[i].nom,player->inventaire[i].durabilite);
            checkList[verif]=i;
            verif++;
        }
    }
    int outil=-1;
    if(verif!=0) {
        while(!checkPresence) {
            printf("Choix : ");
            scanf(" %d", &outil);
            for (int i = 0; i < 10; i++)if (checkList[i] == outil)checkPresence = true;
        }
        return outil;
    }else{
        printf("Vous ne posseder pas de %s valide!\n", getOutilName(matiere));
        return -1;
    }
}
int checkPlace(Player *player,ressource *matiere) {
    int x=0;
    while(player->inventaire[x].quantite<20){
        if(player->inventaire[x].id==matiere->id||player->inventaire[x].id==0)return x;
        x++;
    }
    printf("Pas de place disponible dans l'inventaire!\n");
    return -1;
}

int use(Player *player,ressource *matiere,int choix,int place) {
    float usure[]={10,20,40};
    printf("  %f  ",usure[matiere->resistance-1]);
    srand(time(0));
    int loot=(rand()%4)+1;
    player->inventaire[choix].durabilite-=10*(usure[matiere->resistance-1]/100);
    if(player->inventaire[place].id==0)player->inventaire[place]= getOneItem(matiere->id-1);
    player->inventaire[place].quantite+=loot;
    if(player->inventaire[place].quantite>20)player->inventaire[place].quantite=20;
    return loot;
}

char* getOutilName(ressource *matiere){
    if(strcmp(matiere->type,"bois")==0)return "Hache";
    if(strcmp(matiere->type,"rocher")==0)return "Pioche";
    if(strcmp(matiere->type,"plante")==0)return "Serpe";
}


