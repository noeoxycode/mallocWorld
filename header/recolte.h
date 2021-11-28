//
// Created by Jeune on 28/11/2021.
//

#ifndef MALLOCWORLD_RECOLTE_H
#define MALLOCWORLD_RECOLTE_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include "ressource.h"
#include "player.h"

int recoltea(Player *player,ressource* matiere);
int choose(Player *player,ressource *matiere);
int checkPlace(Player *player,ressource *matiere);
int use(Player *player,ressource *matiere,int choix,int place);
char* getOutilName(ressource *matiere);

#endif //MALLOCWORLD_RECOLTE_H
