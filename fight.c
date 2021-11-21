#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "player.c"
#include "monstres.c"

bool confirmation () {
    printf("Es-tu sûr de ton choix ? ");
    printf("1 : Oui    2 : Refaire mon choix");
    int response;
    scanf("%d",&response);
    while (response != 1 && response != 2)
    {
        printf("Erreur de saisie, veuillez reessayer.");
        printf("1 : Oui    2 : Refaire mon choix");
        scanf("%d",&response);
    }
    if (response = 1)
        return true;
    else
        return false;
}

int chooseArmor (Player player) {
    //affichage de touts les items
    printf("Choisis ton armure :");
    //voir dans linventaire
    for (int i = 0; i < 10 ; i++)
    {
        if (player.inventaire[i].nom && player.inventaire[i].type == "Armure")
            printf("%d : %d", i, player.inventaire[i].nom);
    }
    int armure;
    scanf("%d", &armure);
    printf("Tu as choisis %d",  player.inventaire[armure].nom);
    bool check = confirmation();
    if (check == false)
        chooseArmor(player);
    else
        return player.inventaire[armure].effet;
}

Item chooseWeapon (Player player) {
    printf("Choisis ton arme :");
    //affichage de toutes les armes
    for (int i = 0; i < 10 ; i++)
    {
        if (player.inventaire[i].nom && player.inventaire[i].type == "Arme" && player.inventaire[i].durabilite > 0)
            printf("%d : %d", i, player.inventaire[i].nom);
    }
    int arme;
    scanf("%d", &arme);
    printf("Tu as choisis %d " , player.inventaire[arme].nom);
    //on demande si l'utilisateur est sûr de son choix, si true alors on continue, si false on refait
    bool check = confirmation();
    if (check == false)
        chooseWeapon(player);
    else
        return player.inventaire[arme];
}

void chooseStuff (Player player)
{
    printf("Choisis ton équipement : ");
    player.currentWeapon = chooseWeapon(player);
    player.armure = chooseArmor(player);
}

Player monsterAttack (Player player, Monstre monster){
    player.currentHP -= (monster.niveau * 2);
}

Monstre playerAttack (Player player, Monstre monster){
    //comment se déroule le fight ?
    monster.HP -= player.currentWeapon.effet;
    return monster;

}

Player updateWeapon (Player player){
    player.currentWeapon.durabilite -= 1;
    if (player.currentWeapon.durabilite == 0){
        printf("Votre arme n'est plus itilisable ! Veuillez en choisir une autre !");
        //on remet l'arme dans l'inventaire
        for (int i = 0; i<10; i++){
            if (player.inventaire[i].nom == player.currentWeapon.nom)
                player.inventaire[i] = player.currentWeapon;
        }
        //on rappelle chooseWeapon pour attribuer la nouvelle currentWeapon
        player.currentWeapon = chooseWeapon(player);
    }
    return player;
}

Player usePotion (Player player){
    return player;
}

Player coward (Player player) {
    return player;
}

Player chooseAction (Player player, Monstre monster){
    printf("Il vous reste %d HP, et %d possède %d HP", player.currentHP, monster, monster.HP);
    int choice = 0;
    printf("Quelle action voulez-vous effectuer ?");
    printf("1 : Utiliser  une potion /n 2 : Attaquer /n 3 : Fuir");
    while (choice != 1 & choice != 2 & choice != 3)
        choice = scanf(choice);
    if (choice == 1)
    {
        player = usePotion(player);
        if (monster.HP > 0)
            player = monsterAttack(player, monster);
    }
    else if (choice == 2)
    {
        monster = playerAttack(player, monster);
        player = updateWeapon(player);
        if (monster.HP > 0)
            player = monsterAttack(player, monster);
    }
    else if (choice == 3)
        player = coward(player);
}

void exitFight(){

}

void gameOver(){

}

void fight (Player player, Monstre monster)
{
    printf("C'est l'heure du du du du duel !!");
    chooseStuff(player);
    while (player.currentHP > 0 || monster.HP > 0)
        player = chooseAction(player, monster);
    if (player.currentHP > 0)
        exitFight();
    else
        gameOver();
}