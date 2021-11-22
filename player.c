#include "player.h"

void getPlayer(Player *p){
    printf("Nom : %s\ncurrentHP : %d\nmaxHP : %d\n"
           "experience : %d\nniveau : %d\narmure : %f\ndegat : %d\ninventaire : ",
           p->Nom,p->currentHP,p->maxHP,
           p->currentExperience,p->niveau,p->armure,p->currentWeapon.effet);
    for(int i=0;i<10;i++){
        printf("%d \n",p->inventaire[i].id);
    }
}

void initPlayer(Player *p,char* nom){
    Item* listItem=getItem();
    p -> Nom = nom;
    p -> currentHP = 100;
    p -> maxHP = 100;
    p -> niveau = 1;
    p -> maxExperience = 10;
    for (int i=0;i<4;i++) {
        p->inventaire[i] = listItem[i];
    }
}

Player niveauUp(Player p){
    if (p.currentExperience == p.maxExperience){
        switch (p.niveau) {
            case 1:
                p.niveau = 2;
                p.maxHP = 110;
                p.currentHP = 110;
                p.currentExperience = 0;
                p.maxExperience = 10;
                printf("\n LVL UP : 2 \n");

                break;

            case 2:
                p.niveau = 3;
                p.maxHP = 130;
                p.currentHP = 130;
                p.currentExperience = 0;
                p.maxExperience = 10;
                printf("\n LVL UP : 3 \n");

                break;

            case 3:
                p.niveau = 4;
                p.maxHP = 160;
                p.currentHP = 160;
                p.currentExperience = 0;
                p.maxExperience = 10;
                printf("\n LVL UP : 4 \n ");

                break;

            case 4:
                p.niveau = 5;
                p.maxHP = 200;
                p.currentHP = 200;
                p.currentExperience = 0;
                p.maxExperience = 10;
                printf("\n LVL UP : 5 \n");
                break;

            case 5:
                p.niveau = 6;
                p.maxHP = 250;
                p.currentHP = 250;
                p.currentExperience = 0;
                p.maxExperience = 10;
                printf("\n LVL UP : 6 \n");

                break;

            case 6:
                p.niveau = 7;
                p.maxHP = 300;
                p.currentHP = 300;
                p.currentExperience = 0;
                p.maxExperience = 10;
                printf("\n LVL UP : 7 \n ");

                break;

            case 7:
                p.niveau = 8;
                p.maxHP = 350;
                p.currentHP = 350;
                p.currentExperience = 0;
                p.maxExperience = 10;
                printf("\n LVL UP : 8 \n");

                break;

            case 8:
                p.niveau = 9;
                p.maxHP = 425;
                p.currentHP = 425;
                p.currentExperience = 0;
                p.maxExperience = 10;
                printf("\n LVL UP : 9 \n");

                break;

            case 9:
                p.niveau = 10;
                p.maxHP = 500;
                p.currentHP = 500;
                p.currentExperience = 0;
                p.maxExperience = 10;
                printf("\n LVL UP : 10 \n ");

                break;

            default:
                break;
        }
        if (p.niveau == 10){
            printf("Vous avez atteint le niveau MAX");
        }
        return p;
    }
}