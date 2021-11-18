#include <stdio.h>
#include "map_creator.c"
int main() {
    int  ***listMap = listMapGenerator();
    for (int i=1;i<4;i++) {
        displayMap(listMap[i - 1], i);
        printf("--------------------\n");
    }

    return 0;
}
