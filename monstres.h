//
// Created by Velolime on 22/11/2021.
//

#ifndef MALLOCWORLD_MONSTRES_H
#define MALLOCWORLD_MONSTRES_H

#include <stdio.h>

typedef struct Monstre{
    int id;
    char* nom;
    int HP;
    int Level;
    int temps_reaparition;
    int position_x;
    int position_y;
    int zone;
}Monstre;
Monstre *getMobBase();

#endif //MALLOCWORLD_MONSTRES_H
