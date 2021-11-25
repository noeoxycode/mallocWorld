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
        if (check == false)
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
    //affichage de toutes les armes
    for (int i = 0; i < 10 ; i++)
    {
        if (strcmp( player->inventaire[i].type , "Arme")==0 && player->inventaire[i].durabilite > 0)
            printf("%d : %s\n", i, player->inventaire[i].nom);
    }
    int arme;
    scanf(" %d", &arme);
    printf("Tu as choisis %s " , player->inventaire[arme].nom);
    //on demande si l'utilisateur est sûr de son choix, si true alors on continue, si false on refait
    bool check = confirmation();
    if (check == false)
        chooseWeapon(player);
    else
        player->currentWeapon=player->inventaire[arme];
}



Player chooseStuff(Player *player) {
    printf("Choisis ton equipement : \n");
    chooseWeapon(player);
    chooseArmor(player);
    return *player;
}

Player monsterAttack(Player *player, Monstre *monster) {
    printf("aie!!!\n");
    player.currentHP -= ((monster.Level * 2)*(1-player.armure));
    return player;
}

Player updateWeapon(Player *player) {
    player.currentWeapon.durabilite -= 1;
    if (player.currentWeapon.durabilite == 0){
        printf("Votre arme n'est plus itilisable ! Veuillez en choisir une autre !\n");
        //on remet l'arme dans l'inventaire
        for (int i = 0; i<10; i++){
            if (player.inventaire[i].nom == player.currentWeapon.nom)
                player.inventaire[i] = player.currentWeapon;
        }
        //on rappelle chooseWeapon pour attribuer la nouvelle currentWeapon
        player.currentWeapon = chooseWeapon(&player);
    }
    return player;
}

Monstre playerAttack(Player *player, Monstre *monster) {
    //comment se déroule le fight ?
    monster.HP -= player.currentWeapon.effet;
    return monster;

}

Player usePotion(Player *player) {
    return player;
}

Player coward(Player *player) {
    return player;
}

Player updateXp(Player *player, int xp) {
    if ((player.currentExperience + xp) > player.maxExperience)
    {
        player = niveauUp(player);
        player.currentExperience = (player.currentExperience + xp) - player.maxExperience;
    }
    else
        player.currentExperience += xp;
    return player;
}

Player chooseAction(Player *player, Monstre *monster) {
    printf("Il vous reste %d HP, et %s possede %d HP\n", player.currentHP, monster.nom, monster.HP);
    int choice = -1;
    printf("Quelle action voulez-vous effectuer ?\n");
    printf("1 : Utiliser  une potion \n2 : Attaquer \n3 : Fuir\n");
    while  (choice < 0 || choice > 3){
        scanf(" %d",&choice);
    }
    //choix de prendre une potion
    if (choice == 1){
        player = usePotion(player);
        if (monster.HP > 0)
            player = monsterAttack(player, monster);
    }
        //choix d'attaquer
    else if (choice == 2){
        monster = playerAttack(player, monster);
        player = updateWeapon(player);
        if (monster.HP > 0) {
            player = monsterAttack(player, monster);
        }else{
            player = updateXp(player, (monster.Level * 2));
            choice = 0;
        }
    }
    else if (choice == 3)
        coward(player);

}

void gameOver() {
    printf("gameOver :(");
}

void fight(Player *player, Monstre *monster) {
    printf("C'est l'heure du du du du duel !!\n");
    chooseStuff(player);
    getPlayer(player);
    while (player->currentHP > 0 || monster->HP > 0)
        chooseAction(player, monster);
    if (player->currentHP <= 0)
        gameOver();
}



