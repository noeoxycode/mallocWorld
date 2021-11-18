#include <stdio.h>
#include "monstres.c"
#include "item.c"

int main() {

    Monstre* monstre = momo();
    printf("%d\n",monstre[1].HP);


    Item* item = getItem();
    printf("%d \n%s \n%s \n%d \n%d \n%d \n",
           item[0].id,item[0].nom,item[0].type,item[0].durabilite,item[0].quantiter,item[0].effet);
    printf("%d ",item[4].quantiter);
}
