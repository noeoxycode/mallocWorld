#include <stdio.h>
#include "map_creator.c"
#include "turn.c"
int main() {
    int  ***listMap = listMapGenerator();
    for (int i=1;i<4;i++) {
        displayMap(listMap[i - 1], i);
        printf("--------------------\n");
    }
    PlayTurn(listMap[0],12,1);
    return 0;
}