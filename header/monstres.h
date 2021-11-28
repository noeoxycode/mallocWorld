#ifndef MALLOCWORLD_MONSTRES_H
#define MALLOCWORLD_MONSTRES_H

#include <stdio.h>
#include <stdlib.h>

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