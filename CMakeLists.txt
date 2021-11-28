cmake_minimum_required(VERSION 3.20)
project(mallocWorld C)

set(CMAKE_C_STANDARD 99)

add_executable(mallocWorld main.c item.c player.c monstres.c map_creator.c fight.c Data_creator.c ressource.c recolte.c)
