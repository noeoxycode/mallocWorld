
#ifndef MALLOCWORLD_SAVE_H
#define MALLOCWORLD_SAVE_H
#include "player.c"
int writeMapInFile(int*** map);

int writePlayerInFile(Player *p);

void afficherMap(int*** map);

void freeMap(int** map);

void writeInMapRead(int** mapRead, int* saveInteger, int row);

#endif //MALLOCWORLD_SAVE_H
