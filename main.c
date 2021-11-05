#include <stdio.h>
#include "map_creator.c"
int main() {
    int  **map = createMap(12, 12);
    displayMap(map, 12, 12);
    return 0;
}
