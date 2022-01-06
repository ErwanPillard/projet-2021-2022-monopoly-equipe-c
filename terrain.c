//
// Created by 33782 on 03/01/2022.
//

#include "terrain.h"

//initialisation terrains
void init_terrains(){

    terrain[0].achetable = 1;
    strcpy(terrain[0].nomTerrain, "CASE DEPART");
    terrain[0].frais = 200;

    terrain[1].prix = 60;
    terrain[1].achetable = 1;
    strcpy(terrain[1].nomTerrain, "Boulevard de belleville");

    terrain[2].frais = -100;
    terrain[2].taxe = 1;

    terrain[3].prix = 60;
    terrain[3].achetable = 1;

    terrain[4].achetable = 0;

    terrain[5].prix = 100;
    terrain[5].achetable = 1;

    terrain[6].achetable = 0;

    terrain[7].prix = 100;
    terrain[7].achetable = 1;

    terrain[8].achetable = 0;

    terrain[9].prix = 140;
    terrain[9].achetable = 1;

    terrain[10].achetable = 1;

    terrain[11].prix = 140;
    terrain[11].achetable = 1;

    terrain[12].achetable = 1;

    terrain[13].prix = 180;
    terrain[13].achetable = 1;

    terrain[14].achetable = 1;

    terrain[15].prix = 200;
    terrain[15].achetable = 1;

    terrain[16].achetable = 1;

    terrain[17].prix = 220;
    terrain[17].achetable = 1;

    terrain[18].achetable = 1;

    terrain[19].prix = 220;
    terrain[19].achetable = 1;

    terrain[20].achetable = 1;

    terrain[21].prix = 240;
    terrain[21].achetable = 1;

    terrain[22].achetable = 1;

    terrain[23].prix = 260;
    terrain[23].achetable = 1;

    terrain[24].achetable = 1;

    terrain[25].prix = 280;
    terrain[25].achetable = 1;

    terrain[26].achetable = 1;

    terrain[27].prix = 300;
    terrain[27].achetable = 1;

    terrain[28].achetable = 1;

    terrain[29].prix = 400;
    terrain[29].achetable = 1;

    terrain[30].achetable = 1;

    terrain[31].prix = 450;
    terrain[31].achetable = 1;
}