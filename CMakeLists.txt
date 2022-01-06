cmake_minimum_required(VERSION 3.17)
project(projet-2021-2022-monopoly-equipe-c C)

set(CMAKE_C_STANDARD 11)

add_executable(projet-2021-2022-monopoly-equipe-c main.c menu.c menu.h fenetre.c fenetre.h partieEnCours.c partieEnCours.h terrain.c terrain.h chance.h)

IF(WIN32)
    target_link_libraries(projet-2021-2022-monopoly-equipe-c -lmingw32 -lallegro-5.0.10-monolith-md-debug)
ELSE()
    INCLUDE_DIRECTORIES(/usr/local/Cellar/allegro/5.2.6.0/include)
    LINK_DIRECTORIES(/usr/local/Cellar/allegro/5.2.6.0/lib)
    file(GLOB LIBRARIES "/usr/local/Cellar/allegro/5.2.6.0/lib/*.dylib")
    message("LIBRARIES = ${LIBRARIES}")
    TARGET_LINK_LIBRARIES(projet-2021-2022-monopoly-equipe-c ${LIBRARIES})
ENDIF(WIN32)