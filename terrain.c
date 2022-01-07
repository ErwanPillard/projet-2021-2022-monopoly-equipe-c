//
// Created by 33782 on 03/01/2022.
//

#include "terrain.h"

//initialisation terrains
void init_terrains(){

    terrain[0].achetable = 0;
    strcpy(terrain[0].nomTerrain, "CASE DEPART");
    terrain[0].frais = 200;

    terrain[1].prix = 60;
    terrain[1].achetable = 1;
    strcpy(terrain[1].nomTerrain, "Boulevard de belleville");

    terrain[2].frais = 100;
    terrain[2].taxe = 1;
    strcpy(terrain[2].nomTerrain, "Taxe d'habitation payez 100$");

    terrain[3].prix = 60;
    terrain[3].achetable = 1;
    strcpy(terrain[3].nomTerrain, "Rue Lecourbe");

    terrain[4].achetable = 0;
    terrain[4].teleportation = 1;
    strcpy(terrain[4].nomTerrain, "Avancez la case 13");

    terrain[5].prix = 100;
    terrain[5].achetable = 1;
    strcpy(terrain[5].nomTerrain, "Rue de Vaugirard");

    terrain[6].achetable = 0;
    terrain[6].carteCommunaute = 1;
    strcpy(terrain[6].nomTerrain, "Tirez une carte communaute");

    terrain[7].prix = 100;
    terrain[7].achetable = 1;
    strcpy(terrain[7].nomTerrain, "Rue de courcel");

    terrain[8].achetable = 0;
    strcpy(terrain[8].nomTerrain, "Visite de la prison");

    terrain[9].prix = 140;
    terrain[9].achetable = 1;
    strcpy(terrain[9].nomTerrain, "Boulevard de la Villette");

    terrain[10].taxe = 1;
    terrain[10].frais = 100;
    strcpy(terrain[10].nomTerrain, "Impot sur la fortune payez 100$");

    terrain[11].prix = 140;
    terrain[11].achetable = 1;
    strcpy(terrain[11].nomTerrain, "Avenue de Neuilly");

    terrain[12].achetable = 0;
    terrain[12].teleportation = 1;
    strcpy(terrain[12].nomTerrain, "Avancez a la case 21");

    terrain[13].prix = 180;
    terrain[13].achetable = 1;
    strcpy(terrain[13].nomTerrain, "Rue du Paradis");

    terrain[14].achetable = 0;
    terrain[14].carteChance = 1;
    strcpy(terrain[14].nomTerrain, "Tirez une carte chance");

    terrain[15].prix = 200;
    terrain[15].achetable = 1;
    strcpy(terrain[15].nomTerrain, "Rue Mozart");

    terrain[16].achetable = 0;
    strcpy(terrain[16].nomTerrain, "Free Parking");

    terrain[17].prix = 220;
    terrain[17].achetable = 1;
    strcpy(terrain[17].nomTerrain, "Boulevard Saint-Michel");

    terrain[18].frais = 200;
    terrain[18].taxe = 1;
    strcpy(terrain[18].nomTerrain, "Taxe sur les produits de luxe payez 200$");

    terrain[19].prix = 220;
    terrain[19].achetable = 1;
    strcpy(terrain[19].nomTerrain, "Place Pigalle");

    terrain[20].achetable = 0;
    terrain[20].teleportation = 1;
    strcpy(terrain[20].nomTerrain, "Avancez a la case 29");

    terrain[21].prix = 240;
    terrain[21].achetable = 1;
    strcpy(terrain[21].nomTerrain, "Avenue de Matignon");

    terrain[22].achetable = 0;
    terrain[22].carteCommunaute = 1;
    strcpy(terrain[22].nomTerrain, "Tirez une carte communaute");

    terrain[23].prix = 260;
    terrain[23].achetable = 1;
    strcpy(terrain[23].nomTerrain, "Avenue Henri-Martin");

    terrain[24].achetable = 0;
    terrain[24].teleportation = 1;
    strcpy(terrain[24].nomTerrain, "Allez en prison");

    terrain[25].prix = 280;
    terrain[25].achetable = 1;
    strcpy(terrain[25].nomTerrain, "Avenue Foch");

    terrain[26].achetable = 0;
    terrain[26].frais = 50;
    strcpy(terrain[26].nomTerrain, "Vous trouver 50$ par terre");

    terrain[27].prix = 300;
    terrain[27].achetable = 1;
    strcpy(terrain[27].nomTerrain, "Boulevard des Capucines");

    terrain[28].achetable = 0;
    terrain[28].teleportation = 1;
    strcpy(terrain[28].nomTerrain, "Avancez a la case 5. Vous passez par la case de depart recevez 200$");

    terrain[29].prix = 400;
    terrain[29].achetable = 1;
    strcpy(terrain[29].nomTerrain, "Avenue des Champs-Elysees");

    terrain[30].achetable = 0;
    terrain[30].carteChance = 1;
    strcpy(terrain[30].nomTerrain, "Tirez une carte chance");

    terrain[31].prix = 450;
    terrain[31].achetable = 1;
    strcpy(terrain[31].nomTerrain, "Rue de la paix");

}