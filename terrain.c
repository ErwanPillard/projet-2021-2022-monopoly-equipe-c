//
// Created by 33782 on 03/01/2022.
//

#include "terrain.h"

//initialisation terrains
int init_terrains(){
    T terrain[33];// terrain commence a la case 1

    terrain[1].achetable = 0;
    terrain[1].frais = 200.0f;

    terrain[2].prix = 60;
    terrain[2].achetable = 1;

    terrain[3].achetable = 0;

    terrain[4].prix = 60;
    terrain[4].achetable = 1;

    terrain[5].achetable = 0;

    terrain[6].prix = 100;
    terrain[6].achetable = 1;

    terrain[7].achetable = 0;

    terrain[8].prix = 100;
    terrain[8].achetable = 1;

    terrain[9].achetable = 0;

    terrain[10].prix = 140;
    terrain[10].achetable = 1;

    terrain[11].achetable = 1;

    terrain[12].prix = 140;
    terrain[12].achetable = 1;

    terrain[13].achetable = 1;

    terrain[14].prix = 180;
    terrain[14].achetable = 1;

    terrain[15].achetable = 1;

    terrain[16].prix = 200;
    terrain[16].achetable = 1;

    terrain[17].achetable = 1;

    terrain[18].prix = 220;
    terrain[18].achetable = 1;

    terrain[19].achetable = 1;

    terrain[20].prix = 220;
    terrain[20].achetable = 1;

    terrain[21].achetable = 1;

    terrain[22].prix = 240;
    terrain[22].achetable = 1;

    terrain[23].achetable = 1;

    terrain[24].prix = 260;
    terrain[24].achetable = 1;

    terrain[25].achetable = 1;

    terrain[26].prix = 280;
    terrain[26].achetable = 1;

    terrain[27].achetable = 1;

    terrain[28].prix = 300;
    terrain[28].achetable = 1;

    terrain[29].achetable = 1;

    terrain[30].prix = 400;
    terrain[30].achetable = 1;

    terrain[31].achetable = 1;

    terrain[32].prix = 450;
    terrain[32].achetable = 1;

    return terrain;
}