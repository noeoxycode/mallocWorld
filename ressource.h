//
// Created by Jeune on 28/11/2021.
//

#ifndef MALLOCWORLD_RESSOURCE_H
#define MALLOCWORLD_RESSOURCE_H
#include <stdio.h>
#include <stdlib.h>
typedef struct ressource{
    int id;
    int idMap;
    char* nom;
    char* type; //bois rocher plante
    int tmp_reaparition;
    int resistance;
    int pos_x;
    int pos_y;
    int lvl;//
}ressource;
ressource* getRessourceBase();
ressource getOneRessource(int i);

#endif //MALLOCWORLD_RESSOURCE_H
