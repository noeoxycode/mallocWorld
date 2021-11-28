#include <stdio.h>
#include "map_creator.c"
#include "save.c"
#include "save.h"
int main() {
    int  ***listMap = listMapGenerator();
    for (int i=1;i<4;i++) {
        displayMap(listMap[i - 1], i);
        printf("--------------------\n");
        writeMapInFile(listMap);
    }

    return 0;
}
