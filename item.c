#include "item.h"

Item* getItem(){
    char*** listData=creatData();
    Item* item = malloc(sizeof(item)*34);
    for(int i = 0;i < 34;i++){

        item[i].id = atoi(listData[i][0]);
        item[i].nom = listData[i][1];
        item[i].type = listData[i][2];
        item[i].durabilite = atoi(listData[i][3]);
        item[i].quantite = atoi(listData[i][4]);
        item[i].effet = atoi(listData[i][5]);

    }
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