
#ifndef MALLOCWORLD_PNJ_H
#define MALLOCWORLD_PNJ_H

#include <stdio.h>
#include <string.h>
#include "player.h"
#include "item.h"

void optionPnj();

void reparerOutil(Player *p);

Item coffre(Player *p);

void creation();

Item remettreAuPnj(Player *p,Item *itemPnj);

Item recupererAuPnj(Player *p,Item *itemPnj);

Item listItem_N1();

Item listItem_N2();

Item listItem_N3();

void crafItem(Player *p,Item *itemPnj);

#endif //MALLOCWORLD_PNJ_H
