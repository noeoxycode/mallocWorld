//
// Created by Velolime on 25/11/2021.
//

#ifndef MALLOCWORLD_FIGHT_H
#define MALLOCWORLD_FIGHT_H
#include "player.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "monstres.h"
bool confirmation ();
int chooseArmor (Player *player);
Item chooseWeapon (Player *player);
Player monsterAttack (Player *player, Monstre *monster);
Monstre playerAttack (Player *player, Monstre *monster);
Player updateWeapon (Player *player);
Player usePotion (Player *player);
Player coward (Player *player);
Player updateXp(Player *player, int xp);
Player chooseAction (Player *player, Monstre *monster);
void gameOver();
void fight (Player *player, Monstre *monster);
Player chooseStuff (Player *player);

#endif //MALLOCWORLD_FIGHT_H
