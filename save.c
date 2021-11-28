
#include "save.h"
#include <string.h>
//save le map
int writeMapInFile(int*** map){
    printf("Choisissez un nom que vous voulez donner à votre fichier : ");
    char name[50];
    scanf(" %s", name);
    char* filetype = ".txt";
    char* directory = "../save/";
    char* path = malloc(sizeof (char)*strlen(name)+ strlen(directory)+ strlen(filetype));
    path = strcat(path, directory);
    path = strcat(path, name);
    path = strcat(path, filetype);
    printf("%s" ,path);
    FILE* f = fopen(path, "w");
    if(f == NULL){
        return 0;
    }
    fprintf(f,"=== MAP ===\n");
    for(int level = 1;level < 4;level++) {
        fprintf(f,"-- ZONE %d--\n",level);
        for (int i = 0; i < getMapSize(level);
        i++) {
            for (int j = 0; j < getMapSize(level);
            j++) {
                fprintf(f, "%d ", map[level-1][i][j]);
            }
            fprintf(f, "\n");
        }
    }
    fclose(f);
    return 0;
}
//save le player
int writePlayerInFile(Player *p){
    FILE* f = fopen("save.txt", "w");
    if(f == NULL){
        return 0;
    }
    fprintf(f,"=== PLAYER ===\n");
    fprintf(f,"%d \n",p->niveau);
    fprintf(f,"%d/%d \n",p->currentExperience,p->maxExperience);
    fprintf(f,"%d/%d \n",p->currentHP,p->maxHP);
    fprintf(f,"--INVENTORY-- \n");
    for(int i = 0;i < 10;i++){
        //fprintf(f,"%d@%s@%d \n",p->inventaire[i].quantite,p->inventaire[i].nom,p->inventaire[i].durabilite);
    }
    fclose(f);
    return 1;
}

void afficherMap(int*** map){
    for(int level = 1;level < 4;level++) {
        for (int i = 0; i < getMapSize(level);
             i++) {
            for (int j = 0; j < getMapSize(level);
                 j++) {
                printf("%d ", map[level-1][i][j]);
            }
            printf("\n");
        }
    }
}


void writeInMapRead(int** mapRead, int* saveInteger, int row){
    for (int i = 0; i < getMapSize(); i++) {
        mapRead[row][i] = saveInteger[i];
    }
    printf("\n");
}

int** readFile(){
    int level = 0;
    char string[255] = "";
    int* saveInteger = NULL;
    FILE* f = fopen("../save/toto.txt", "r");
    int counterInt = 0;
    int row = 0;
    int** mapRead = malloc(sizeof(int*) * getMapSize(level));

    for (int i = 0; i < getMapSize(level); i++) {
        mapRead[i] = malloc(sizeof(int) * getMapSize(level));
    }

    for (int i = 0; i < getMapSize(int level); i++) {
        for (int j = 0; j < getMapSize(int level); j++) {
            mapRead[i][j] = 1;
        }
    }
    afficherMap(mapRead);

    while(fgets(string, 255, f) != NULL){

        char* stringTok = strtok(string," ");
        saveInteger = malloc(sizeof(int) * getMapSize(level));
        counterInt = 0;

        while (stringTok != NULL) {
            saveInteger[counterInt] = atoi(stringTok);
            stringTok = strtok(NULL, " ");
            counterInt += 1;
        }

        writeInMapRead(mapRead, saveInteger, row);
        row += 1;
    }

    afficherMap(mapRead);

    return mapRead;
}