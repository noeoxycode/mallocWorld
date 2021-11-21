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

Item* getItem(){
    Item* item = malloc(sizeof(item)*34);;
    for(int i = 0;i < 34;i++){
        item[i].id = atoi(creatData()[i][0]);
        item[i].nom = creatData()[i][1];
        item[i].type = creatData()[i][2];
        item[i].durabilite = atoi(creatData()[i][3]);
        item[i].quantite = atoi(creatData()[i][4]);
        item[i].effet = atoi(creatData()[i][5]);

    }
    return item;
}