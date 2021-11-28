#include "../header/item.h"

Item* getItem(){
    Item* item = malloc(sizeof(item)*34);
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

Item getOneItem(int i){
    Item item;
    item.id = atoi(creatData()[i][0]);
    item.nom = creatData()[i][1];
    item.type = creatData()[i][2];
    item.durabilite = atoi(creatData()[i][3]);
    item.quantite = 0;
    item.effet = atoi(creatData()[i][5]);


    return item;
}

void itemClear(Item *p){
    p->id =0;
    p->nom ="";
    p->type ="";
    p->durabilite =0;
    p->quantite =0;
    p->effet =0;
}