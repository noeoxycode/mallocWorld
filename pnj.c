#include "pnj.h"

void optionPnj(){
    printf("1- réparer tous ses outils/n 2- acceder au coffre/n 3- creation/n 0- partir");
    int choice = -1;
    scanf("%d",&choice);
    if(choice == 1){
        reparerOutil(Player *p);
    }
    if(choice == 2){
        coffre(Player *p);
    }
    if(choice == 3){
        creation();
    }
    if(choice == 0){
        return;
    }
}

void reparerOutil(Player *p){
    for(int i=0;i < 10;i++){
        if(strcmp(p->inventaire[i].type , "Arme")==0 && strcmp( p->inventaire[i].type , "Outil")==0){
            int id = p->inventaire[i].id;
            p->inventaire[i].durabilite = getItem[id-1].durabilite;
        }
    }
}

Item* coffre(Player *p){
    Item *itemPnj = malloc(sizeof (Item)*1000);
    printf("\n 1- remettre les objets au Pnj\n2- recuperer les objets au Pnj\n0- partire");
    int choice = -1;
    scanf("%d",&choice);
    if(choice == 1){
        remettreAuPnj(Player *p,Item *itemPnj);
    }
    if(choice ==2){
        recupererAuPnj(Player *p,Item *itemPnj);
    }
    if(choice ==0){
        return;
    }
    return itemPnj;
}

Item remettreAuPnj(Player *p,Item *itemPnj){
    int choice = -1;
    int size = 0;
    int num = 0;
    for(int i=0;i < 10;i++){
        printf("\nid: %d , nom: %s",p->inventaire[i].id,p->inventaire[i].nom);
        num++;
    }
    printf("\n choisi l'objet ce que vous voulez remettre\n");
    scanf("%d",&choice);
    for(int i=0;i < num;i++){
        if(choice == p->inventaire[i].id){
            itemPnj[size] = p->inventaire[i];
            size++;
            p->inventaire[i] = 0;
        }
    }
    return itemPnj;
}

Item recupererAuPnj(Player *p,Item *itemPnj){
    int size = 0;
    int choice = -1;
    int num = 0;
    while(itemPnj->next != null){
        printf("\n id: %d , nom: %s",itemPnj[size].id,itemPnj[size].nom);
        size++;
    }
    for(int j=0,j < 10;j++){
        if(p->inventaire[j] == null){
            break;
        }
        num++;
    }
    if(num == 10){
        printf("\nVotre inventaire deja completement,vous ne pouvez pas recuperer l'objet");
    } else{
        printf("\n choisi l'objet ce que vous voulez recuperer\n");
        scanf("%d",&choice);
        for(int i=0;i < size;i++){
            if(choice == itemPnj.id){
                if(num < 10){
                    p->inventaire[num-1] = itemPnj[i];
                    itemPnj[i] = 0;
                    num++;
                }
            }
        }
    }
    return itemPnj;
}

void creation(){
    switch(pnj dans quelle map){
        case 1 :
            void listItem_N1();
            break;
        case 2 :
            void listItem_N2();
            break;
        case 3 :
            void listItem_N3();
            break;
        default :
            printf("\n Choix non disponible \n");
    }
}

Item listItem_N1(){
    Item *itemN1 = malloc(sizeof (Item)*12);
    itemN1[0] = getItem[1];
    itemN1[1] = getItem[8];
    itemN1[2] = getItem[9];
    itemN1[3] = getItem[10];
    itemN1[4] = getItem[11];
    itemN1[5] = getItem[2];
    itemN1[6] = getItem[12];
    itemN1[7] = getItem[3];
    itemN1[8] = getItem[13];
    itemN1[9] = getItem[4];
    itemN1[10] = getItem[14];
    itemN1[11] = getItem[15];
    for(int i=0;i < 12;i++){
        printf("%s ",itemN1[i]);
    }
    return itemN1;
}

Item listItem_N2(){
    Item *itemN2 = malloc(sizeof (Item)*20);
    itemN2[0] = getItem[1];
    itemN2[1] = getItem[8];
    itemN2[2] = getItem[19];
    itemN2[3] = getItem[9];
    itemN2[4] = getItem[20];
    itemN2[5] = getItem[10];
    itemN2[6] = getItem[21];
    itemN2[7] = getItem[11];
    itemN2[8] = getItem[22];
    itemN2[9] = getItem[2];
    itemN2[10] = getItem[12];
    itemN2[11] = getItem[23];
    itemN2[12] = getItem[4];
    itemN2[13] = getItem[14];
    itemN2[14] = getItem[25];
    itemN2[15] = getItem[3];
    itemN2[16] = getItem[13];
    itemN2[17] = getItem[24];
    itemN2[18] = getItem[15];
    itemN2[19] = getItem[26];
    for(int i=0;i < 20;i++){
        printf("%s ",itemN1[i]);
    }
    return itemN2;
}

Item listItem_N3(){
    Item *itemN3 = malloc(sizeof (Item)*25);
    itemN3[0] = getItem[1];
    itemN3[1] = getItem[8];
    itemN3[2] = getItem[19];
    itemN3[3] = getItem[30];
    itemN3[4] = getItem[9];
    itemN3[5] = getItem[20];
    itemN3[6] = getItem[31];
    itemN3[7] = getItem[10];
    itemN3[8] = getItem[21];
    itemN3[9] = getItem[32];
    itemN3[10] = getItem[11];
    itemN3[11] = getItem[22];
    itemN3[12] = getItem[33];
    itemN3[13] = getItem[2];
    itemN3[14] = getItem[12];
    itemN3[15] = getItem[23];
    itemN3[16] = getItem[4];
    itemN3[17] = getItem[14];
    itemN3[18] = getItem[25];
    itemN3[19] = getItem[3];
    itemN3[20] = getItem[13];
    itemN3[21] = getItem[24];
    itemN3[22] = getItem[15];
    itemN3[23] = getItem[26];
    itemN3[24] = getItem[34];
    for(int i=0;i < 25;i++){
        printf("%s ",itemN1[i]);
    }
    return itemN3;
}

void crafItem(Player *p,Item *itemPnj){
    int choice = -1;
    printf("\nChoisir un item que vous voulez creer ");
    scanf("%d",&choice);


}



