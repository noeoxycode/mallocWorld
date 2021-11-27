#include "fight.h"



bool confirmation() {
    printf("Es-tu sur de ton choix ? \n");
    printf("1 : Oui    2 : Refaire mon choix\n");
    int response;
    printf("Choix :");
    scanf(" %d",&response);
    while (response != 1 && response != 2)
    {
        printf("Erreur de saisie, veuillez reessayer.\n");
        printf("1 : Oui    2 : Refaire mon choix\n");
        printf("Choix :");
        scanf(" %d",&response);
    }
    if (response == 1)
        return true;
    else
        return false;
}

int chooseArmor(Player *player) {
    //affichage de touts les items
    printf("Choisis ton armure :\n");
    //voir dans linventaire
    int verif=0;
    for (int i = 0; i < 10 ; i++)
    {
        if (strcmp( player->inventaire[i].type , "Armure")==0) {
            printf("%d : %s\n", i, player->inventaire[i].nom);
            verif++;
        }
    }
    int armure;
    if(verif!=0) {
        scanf(" %d", &armure);
        printf("Tu as choisis %s\n", player->inventaire[armure].nom);
        bool check = confirmation();
        if (check == false||strcmp(player->inventaire[armure].type,"Armure")!=0)
            chooseArmor(player);
        else
            player->armure=player->inventaire[armure].effet/100;
    }else{
        printf("Vous n'avez pas d'armure disponible.\n");
        player->armure=0;
    }
}





Item chooseWeapon(Player *player) {
    printf("Choisis ton arme :\n");
    /*for (int i=0;i<10;i++){
        printf("%d : %d",i,player->inventaire[i].durabilite);
    }*/
    int cpt = 0;
    //affichage de toutes les armes
    for (int i = 0; i < 10; i++) {
        if (strcmp(player->inventaire[i].type, "Arme") == 0 && player->inventaire[i].durabilite > 0) {
            printf("%d : %s\n", i, player->inventaire[i].nom);
            cpt++;
        }
    }
    if (cpt != 0) {
        int arme;
        scanf(" %d", &arme);
        printf("Tu as choisis %s \n", player->inventaire[arme].nom);
        //on demande si l'utilisateur est sûr de son choix, si true alors on continue, si false on refait
        bool check = confirmation();
        if (check == false||strcmp(player->inventaire[arme].type,"Arme")!=0)
            chooseWeapon(player);
        else
            player->inventaire[player->currentWeapon] = player->inventaire[arme];
    }else{
        player->currentWeapon=-1;
    }
}



Player chooseStuff(Player *player) {
    printf("Choisis ton equipement : \n");
    chooseWeapon(player);
    chooseArmor(player);
    return *player;
}

Player monsterAttack(Player *player, Monstre *monster) {
    int degat=((monster->Level * 2)*(1-player->armure));
    printf("Aie, vous subiser %d de degats.!!!\n",degat);
    player->currentHP -= ((monster->Level * 2)*(1-player->armure));

}

Player updateWeapon(Player *player) {
    player->inventaire[player->currentWeapon].durabilite -= 1;
    if (player->inventaire[player->currentWeapon].durabilite == 0){
        printf("Votre arme n'est plus itilisable ! Veuillez en choisir une autre !\n");
        //on remet l'arme dans l'inventaire
        for (int i = 0; i<10; i++){
            if (player->inventaire[i].nom == player->inventaire[player->currentWeapon].nom)
                player->inventaire[i] = player->inventaire[player->currentWeapon];
        }
        //on rappelle chooseWeapon pour attribuer la nouvelle currentWeapon
        player->inventaire[player->currentWeapon] = chooseWeapon(player);
    }
}

Monstre playerAttack(Player *player, Monstre *monster) {
    //comment se déroule le fight ?
    monster->HP -= player->inventaire[player->currentWeapon].effet;
}

int usePotion(Player *player) {
    int cpt=0;
    printf("Choisiser une potion a utiliser: \n");
    for (int i = 0; i < 10; i++) {
        if (strcmp(player->inventaire[i].type, "Soin") == 0 ) {
            printf("%d : %s soin:%d\n", i, player->inventaire[i].nom,player->inventaire[i].effet);
            cpt++;
        }
    }
    if(cpt==0){
        printf("Pas de potion disponible dans l'inventaire!\n");
        return 0;
    }else{
        int soin;
        scanf(" %d", &soin);
        printf("Tu as choisis %s \n", player->inventaire[soin].nom);
        //on demande si l'utilisateur est sûr de son choix, si true alors on continue, si false on refait
        bool check = confirmation();
        if (check == false)
            chooseWeapon(player);
        else
        player->currentHP+=player->inventaire[soin].effet;
        itemClear(&player->inventaire[soin]);
        if(player->currentHP>player->maxHP){
            player->currentHP=player->maxHP;
        }
        return 1;
    }

}

int coward(Player *player) {
    srand(time(0));
    int i=rand()%100;
    if(i<30){
        return 1;
    }else{
        return 0;
    }
}

Player updateXp(Player *player, int xp) {
    if ((player->currentExperience + xp) > player->maxExperience)
    {
        *player=niveauUp(*player);
        player->currentExperience = (player->currentExperience + xp) - player->maxExperience;
    }
    else
        player->currentExperience += xp;

}

int chooseAction(Player *player, Monstre *monster) {
    printf("Il vous reste %d HP, et %s possede %d HP \n", player->currentHP, monster->nom, monster->HP);
    int choice = -1;
    do{
        choice = -1;
        printf("Quelle action voulez-vous effectuer ?\n");
        printf("1 : Utiliser une potion \n2 : Attaquer \n3 : Fuir\n");
        while (choice < 0 || choice > 3) {
            scanf(" %d", &choice);
        }
        if(choice==2&&player->currentWeapon==-1){
            printf("Vous ne pouvez plus tapper, vous avez plus d'arme valide.\n");
        }
    }while(choice==2&&player->currentWeapon==-1);
    //choix de prendre une potion
    if (choice == 1){
        usePotion(player);
        if (monster->HP > 0)
            monsterAttack(player, monster);
    }
        //choix d'attaquer
    else if (choice == 2){
        playerAttack(player, monster);
        updateWeapon(player);
        if (monster->HP > 0) {
            monsterAttack(player, monster);
        } else {
            updateXp(player, (monster->Level * 2));
            choice = 0;
        }
    }
    else if (choice == 3) {
        int val = coward(player);
        if(val==0){
            if (monster->HP > 0)
                monsterAttack(player, monster);
        }else{
            return val;
        }
    }


}

void gameOver() {
    printf("gameOver :(");
}

int fight(Player *player, Monstre* monster) {
    printf("C'est l'heure du du du du duel !!\n");
    chooseStuff(player);
    int fuite=0;
    while ((player->currentHP > 0 && monster->HP > 0)&&fuite!=1){
        fuite=chooseAction(player, monster);
    }
    if(monster->HP == 0){
        monster->temps_reaparition=15;
        printf("Bravo vous avez vaincu %s, et vous gagner %d xp\n",monster->nom,monster->Level*2);
    }
    if (player->currentHP <= 0){
        gameOver();
    }
    if(fuite==1){
        printf("Vous prenez la fuite!\n");
        return 3;
    }
}



