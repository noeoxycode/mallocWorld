cmake_minimum_required(VERSION 3.20)
project(mallocWorld C)

set(CMAKE_C_STANDARD 99)

add_executable(mallocWorld cmake-build-debug/src/main.c cmake-build-debug/src/item.c cmake-build-debug/src/player.c cmake-build-debug/src/monstres.c cmake-build-debug/src/map_creator.c cmake-build-debug/src/fight.c cmake-build-debug/src/Data_creator.c cmake-build-debug/src/ressource.c cmake-build-debug/src/recolte.c cmake-build-debug/header/turn.h)
