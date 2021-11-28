//
// Created by Velolime on 22/11/2021.
//

#ifndef MALLOCWORLD_PLAYER_H
#define MALLOCWORLD_PLAYER_H

#include <stdlib.h>
#include <stdio.h>
#include "item.h"

typedef struct Player{
    char* Nom;
    int currentHP;
    int maxHP;
    int position_joueur[3];// [nbMap, x , y]
    Item inventaire[10];
    int currentExperience;
    int maxExperience;
    int niveau;
    float armure;
    int currentWeapon;
}Player;

void getPlayer(Player *p);
void initPlayer(Player *p,char* nom);
Player niveauUp(Player p);


#endif //MALLOCWORLD_PLAYER_H
