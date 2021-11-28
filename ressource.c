//
// Created by Jeune on 28/11/2021.
//
#include "ressource.h"

ressource* getRessourceBase(){
    ressource* tab= malloc(sizeof (ressource)*9);
    tab[0].nom="sapin";tab[0].id=5;tab[0].idMap=5;
    tab[1].nom="pierre";tab[1].id=6;tab[1].idMap=4;
    tab[2].nom="herbe";tab[2].id=7;tab[2].idMap=3;
    tab[3].nom="hetre";tab[3].id=16;tab[3].idMap=8;
    tab[4].nom="fer";tab[4].id=17;tab[4].idMap=7;
    tab[5].nom="lavande";tab[5].id=18;tab[5].idMap=6;
    tab[6].nom="chene";tab[6].id=27;tab[6].idMap=11;
    tab[7].nom="diamant";tab[7].id=28;tab[7].idMap=10;
    tab[8].nom="chanvre";tab[8].id=29;tab[8].idMap=9;
    for(int i=0;i<9;i++){
       tab[i].pos_x=0;
       tab[i].pos_y=0;
       tab[i].lvl=0;
       tab[i].resistance=(i/3)+1;
       tab[i].tmp_reaparition=0;
       if(i==0||i==3||i==6)tab[i].type="bois";
       if(i==1||i==4||i==7)tab[i].type="rocher";
       if(i==2||i==5||i==8)tab[i].type="plante";
    }
    return tab;
}

ressource getOneRessource(int i){
    int x=0;
    ressource* list=getRessourceBase(),res;
    while(list[x].id!=i)x++;
    res.id=list[x].id;
    res.idMap=list[x].idMap;
    res.nom=list[x].nom;
    res.type=list[x].type;
    res.resistance=list[x].resistance;
    res.pos_x=list[x].pos_x;
    res.pos_y=list[x].pos_y;
    res.tmp_reaparition=list[x].tmp_reaparition;
    res.lvl=list[x].lvl;
    return res;
}


