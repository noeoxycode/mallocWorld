//
// Created by noe on 22/11/2021.
//

#ifndef MALLOCWORLD_ITEM_H
#define MALLOCWORLD_ITEM_H
#include <stdio.h>
#include <stdlib.h>
#include "Data_creator.c"
typedef struct Item{
    int id;
    char* nom;
    char* type; //Arme Outil Ressources de craft Soin Armure
    int durabilite;
    int quantite;
    int effet;// degat ou restance d'armure ou soin
}Item;

Item* getItem();

#endif //MALLOCWORLD_ITEM_H
