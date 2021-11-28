cmake_minimum_required(VERSION 3.20)
project(mallocWorld C)

set(CMAKE_C_STANDARD 99)

add_executable(mallocWorld src/main.c src/item.c src/player.c src/monstres.c src/map_creator.c src/fight.c src/Data_creator.c src/ressource.c src/recolte.c src/turn.c src/init.c header/init.h)
