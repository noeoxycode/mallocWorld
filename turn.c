//
// Created by Velolime on 17/11/2021.
//

#include "../header/turn.h"



int *getPlayerPos(int ** map,int size){
    printf("in player pos %d %d, ",map[0][0],size);
    int* pos=malloc(sizeof(int)*2);
    for (int y = 0; y < size; y++) {
        for (int x = 0; x < size; x++) {
            if (map[x][y] == 1) {
                pos[0] = x;
                pos[1] = y;
                return pos;
            }
        }
    }
    pos[0]=-1;
    pos[1]=-1;
    return pos;
}

void printChoise(int num, char *dir, int lvl) {
    Monstre* listMobBasse=getMobBase();
    ressource *ressourceBase=getRessourceBase();
    int a=0;
    if(num==-5){
        printf("Deplacement impossible, bordure vers %s\n",dir);
    }else if(num==-3){
        printf("Prendre le portail vers la zone");
        if(lvl==3){
            printf("2\n");
        }else{
            printf("3\n");
        }
    }else if(num==-2){
        printf("Prendre le portail vers la zone");
        if(lvl==2){
            printf("1\n");
        }else{
            printf("2\n");
        }
    }else if(num==-1) {
        printf("Deplacement impossible, mur vers %s\n",dir);
    }else if(num==0) {
        printf("Deplacement vers %s\n",dir);
    }else if(num==2) {
        printf("Interagire avec le pnj\n");
    }else if(num>2&&num<12) {
        while(ressourceBase[a].idMap!=num)a++;
        printf("Recolte de la ressource: %s\n",ressourceBase[a].nom);
    }else if(num>11) {
        while(listMobBasse[a].id!=num)a++;
        printf("Affronter le monstre: %s\n",listMobBasse[a].nom);
    }
}

int *getPlayerAround(int **map, int size,Player *player) {
    int pos[2]={player->position_joueur[1],player->position_joueur[2]};
    int* around=malloc(sizeof(int)*4);
    if(pos[1]!=0){
        around[0]=map[pos[0]][pos[1]-1];
    }else{
        around[0]=-5;
    }
    if(pos[0]!=size-1){
        around[1]=map[pos[0]+1][pos[1]];
    }else{
        around[1]=-5;
    }
    if(pos[1]!=size-1){
        around[2]=map[pos[0]][pos[1]+1];
    }else{
        around[2]=-5;
    }
    if(pos[0]!=0){
        around[3]=map[pos[0]-1][pos[1]];
    }else{
        around[3]=-5;
    }
    return around;
}



int userChoise(int* aroun,int lvl){
    int c=0;
    char dir[4][10]={"le haut","la droite","le bas","la gauche"};
    printf("\nAction possible :\n");
    for (int i=0;i<4;i++){
        printf("- %d: ",i+1);
        printChoise(aroun[i],dir[i],lvl);
    }
    printf("Choix de votre action :");
    scanf("%d",&c);
    return c;
}

int **move(int** map,int dir,Player* player) {
    map[player->position_joueur[1]][player->position_joueur[2]] = 0;
    if (dir % 2 == 0) {
        player->position_joueur[1] += (dir - 3) * -1;
    } else {
        player->position_joueur[2] += (dir - 2);
    }
    map[player->position_joueur[1]][player->position_joueur[2]] = 1;
    return map;
}


int ** PlayTurn(int **map, int size,int lvl,Player *player,Monstre* monstreList,ressource* ressourceList){
    int mobCpt=0;
    int vaPos[]={player->position_joueur[1], player->position_joueur[2]};
    int *arou= getPlayerAround(map,size,player);
    int choix=userChoise(arou,lvl);
    if(choix==1){
        vaPos[1]-=1;
    }else if(choix==2){
        vaPos[0]+=1;
    }else if(choix==3){
        vaPos[1]+=1;
    }else if(choix==4){
        vaPos[0]-=1;
    }
    printf("%d %d\n",choix,arou[choix-1]);
    if(arou[choix-1]==0){
        map=move(map,choix,player);
    }else if(arou[choix-1]>=12){
        for (int i=0;monstreList[i+1].id!=-1;i++){
            if(monstreList[i].position_x==vaPos[0]&&monstreList[i].position_y==vaPos[1]&&monstreList[i].zone==lvl){
                mobCpt=i;
            }
        }
        if(3!=fight(player,&monstreList[mobCpt]))map = move(map, choix, player);
    }else if(arou[choix-1]==2){
        //pnj()
    }else if(arou[choix-1]<12&&arou[choix-1]>2){
        for (int i=0;ressourceList[i+1].id!=-1;i++){
            if(ressourceList[i].pos_x==vaPos[0]&&ressourceList[i].pos_y==vaPos[1]&&ressourceList[i].lvl==lvl){
                mobCpt=i;
            }
        }
        if(3!=recoltea(player,&ressourceList[mobCpt]))map = move(map, choix, player);
        //recolte()
    }
    return map;
}
void checkMobRespawn(Monstre* listMob,int** map,int lvl){
    for(int i=0;listMob[i].id!=-1;i++){
        if(listMob[i].temps_reaparition!=0){
            listMob[i].temps_reaparition-=1;
        }else {
            if (lvl == listMob[i].zone) {
                if (map[listMob[i].position_x][listMob[i].position_y] == 0) {
                    map[listMob[i].position_x][listMob[i].position_y] = listMob[i].id;
                }
            }
        }
    }

}
void checkOtherRespawn(ressource * listOther,int** map,int lvl){
    for(int i=0;listOther[i].id!=-1;i++){
        if(listOther[i].tmp_reaparition!=0){
            listOther[i].tmp_reaparition-=1;
        }else {
            if (lvl == listOther[i].lvl) {
                if (map[listOther[i].pos_x][listOther[i].pos_y] == 0) {
                    map[listOther[i].pos_x][listOther[i].pos_y] = listOther[i].idMap;
                }
            }
        }
    }
}