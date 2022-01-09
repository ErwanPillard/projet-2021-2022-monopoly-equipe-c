//
// Created by 33782 on 03/01/2022.
//

#include "terrain.h"

//initialisation terrains
void init_terrains(){

    terrain[0].achetable = 0;
    strcpy(terrain[0].nomTerrain, "CASE DEPART");
    terrain[0].frais = 200;
    terrain[0].positionX = 1330;
    terrain[0].positionY = 915;

    terrain[1].prix = 60;
    terrain[1].loyer = 2;
    terrain[1].loyer1M = 10;
    terrain[1].loyer2M = 30;
    terrain[1].loyer3M = 90;
    terrain[1].loyer4M = 160;
    terrain[1].loyer1H = 250;
    terrain[1].achetable = 1;
    strcpy(terrain[1].nomTerrain, "Boulevard de belleville");
    terrain[1].positionX = 1200;
    terrain[1].positionY = 915;
    terrain[1].doublon = 3;

    terrain[2].frais = 100;
    terrain[2].taxe = 1;
    strcpy(terrain[2].nomTerrain, "Taxe d'habitation payez 100$");
    terrain[2].positionX = 1096;
    terrain[2].positionY = 915;

    terrain[3].prix = 60;
    terrain[3].loyer = 4;
    terrain[3].loyer1M = 20;
    terrain[3].loyer2M = 60;
    terrain[3].loyer3M = 180;
    terrain[3].loyer4M = 320;
    terrain[3].loyer1H = 450;
    terrain[3].achetable = 1;
    strcpy(terrain[3].nomTerrain, "Rue Lecourbe");
    terrain[3].positionX = 992;
    terrain[3].positionY = 915;
    terrain[3].doublon = 1;


    terrain[4].achetable = 0;
    terrain[4].teleportation = 1;
    strcpy(terrain[4].nomTerrain, "Avancez la case 13");
    terrain[4].positionX = 888;
    terrain[4].positionY = 915;

    terrain[5].prix = 100;
    terrain[5].loyer = 6;
    terrain[5].loyer1M = 30;
    terrain[5].loyer2M = 90;
    terrain[5].loyer3M = 270;
    terrain[5].loyer4M = 400;
    terrain[5].loyer1H = 550;
    terrain[5].achetable = 1;
    strcpy(terrain[5].nomTerrain, "Rue de Vaugirard");
    terrain[5].positionX = 784;
    terrain[5].positionY = 915;
    terrain[5].doublon = 7;



    terrain[6].achetable = 0;
    terrain[6].carteCommunaute = 1;
    strcpy(terrain[6].nomTerrain, "Tirez une carte communaute");
    terrain[6].positionX = 680;
    terrain[6].positionY = 915;

    terrain[7].prix = 100;
    terrain[7].loyer = 6;
    terrain[7].loyer1M = 30;
    terrain[7].loyer2M = 90;
    terrain[7].loyer3M = 270;
    terrain[7].loyer4M = 400;
    terrain[7].loyer1H = 550;
    terrain[7].achetable = 1;
    strcpy(terrain[7].nomTerrain, "Rue de courcel");
    terrain[7].positionX = 576;
    terrain[7].positionY = 915;
    terrain[7].doublon = 5;


    terrain[8].achetable = 0;
    strcpy(terrain[8].nomTerrain, "Visite de la prison");
    terrain[8].positionX = 446;
    terrain[8].positionY = 915;


    terrain[9].prix = 140;
    terrain[9].loyer = 10;
    terrain[9].loyer1M = 50;
    terrain[9].loyer2M = 150;
    terrain[9].loyer3M = 450;
    terrain[9].loyer4M = 625;
    terrain[9].loyer1H = 750;
    terrain[9].achetable = 1;
    strcpy(terrain[9].nomTerrain, "Boulevard de la Villette");
    terrain[9].positionX = 446;
    terrain[9].positionY = 860;
    terrain[9].doublon = 11;


    terrain[9].positionY = 790;

    terrain[10].taxe = 1;
    terrain[10].frais = 100;
    strcpy(terrain[10].nomTerrain, "Impot sur la fortune payez 100$");
    terrain[10].positionX = 446;
    terrain[10].positionY = 685;

    terrain[11].prix = 140;
    terrain[11].loyer = 10;
    terrain[11].loyer1M = 50;
    terrain[11].loyer2M = 150;
    terrain[11].loyer3M = 450;
    terrain[11].loyer4M = 625;
    terrain[11].loyer1H = 750;
    terrain[11].achetable = 1;
    strcpy(terrain[11].nomTerrain, "Avenue de Neuilly");
    terrain[11].positionX = 446;
    terrain[11].positionY = 580;
    terrain[11].positionY = 750;
    terrain[11].doublon = 9;


    terrain[12].achetable = 0;
    terrain[12].teleportation = 1;
    strcpy(terrain[12].nomTerrain, "Avancez a la case 21");
    terrain[12].positionX = 446;
    terrain[12].positionY = 475;

    terrain[13].prix = 180;
    terrain[13].loyer = 12;
    terrain[13].loyer1M = 60;
    terrain[13].loyer2M = 180;
    terrain[13].loyer3M = 500;
    terrain[13].loyer4M = 700;
    terrain[13].loyer1H = 900;
    terrain[13].achetable = 1;
    strcpy(terrain[13].nomTerrain, "Rue du Paradis");
    terrain[13].positionX = 446;
    terrain[13].positionY = 370;
    terrain[13].doublon = 15;


    terrain[14].achetable = 0;
    terrain[14].carteChance = 1;
    strcpy(terrain[14].nomTerrain, "Tirez une carte chance");
    terrain[14].positionX = 446;
    terrain[14].positionY = 265;

    terrain[15].prix = 200;
    terrain[15].loyer = 14;
    terrain[15].loyer1M = 70;
    terrain[15].loyer2M = 200;
    terrain[15].loyer3M = 550;
    terrain[15].loyer4M = 750;
    terrain[15].loyer1H = 950;
    terrain[15].achetable = 1;
    strcpy(terrain[15].nomTerrain, "Rue Mozart");
    terrain[15].positionX = 446;
    terrain[15].positionY = 160;

    terrain[15].doublon = 13;


    terrain[16].achetable = 0;
    strcpy(terrain[16].nomTerrain, "Free Parking");
    terrain[16].positionX = 446;
    terrain[16].positionY = 25;

    terrain[17].prix = 220;
    terrain[17].loyer = 14;
    terrain[17].loyer1M = 70;
    terrain[17].loyer2M = 200;
    terrain[17].loyer3M = 550;
    terrain[17].loyer4M = 750;
    terrain[17].loyer1H = 950;
    terrain[17].achetable = 1;
    strcpy(terrain[17].nomTerrain, "Boulevard Saint-Michel");
    terrain[17].positionX = 576;
    terrain[17].positionY = 25;
    terrain[17].doublon = 19;


    terrain[18].frais = 200;
    terrain[18].taxe = 1;
    strcpy(terrain[18].nomTerrain, "Taxe sur les produits de luxe payez 200$");
    terrain[18].positionX = 680;
    terrain[18].positionY = 25;

    terrain[19].prix = 220;
    terrain[19].loyer = 16;
    terrain[19].loyer1M = 80;
    terrain[19].loyer2M = 220;
    terrain[19].loyer3M = 600;
    terrain[19].loyer4M = 800;
    terrain[19].loyer1H = 1000;
    terrain[19].achetable = 1;
    strcpy(terrain[19].nomTerrain, "Place Pigalle");
    terrain[19].doublon = 17;

    terrain[19].positionX = 784;
    terrain[19].positionY = 25;

    terrain[20].achetable = 0;
    terrain[20].teleportation = 1;
    strcpy(terrain[20].nomTerrain, "Avancez a la case 29");
    terrain[20].positionX = 888;
    terrain[20].positionY = 25;

    terrain[21].prix = 240;
    terrain[21].loyer = 18;
    terrain[21].loyer1M = 90;
    terrain[21].loyer2M = 250;
    terrain[21].loyer3M = 700;
    terrain[21].loyer4M = 875;
    terrain[21].loyer1H = 1050;
    terrain[21].achetable = 1;
    strcpy(terrain[21].nomTerrain, "Avenue de Matignon");
    terrain[21].doublon = 23;

    terrain[21].positionX = 992;
    terrain[21].positionY = 25;

    terrain[22].achetable = 0;
    terrain[22].carteCommunaute = 1;
    strcpy(terrain[22].nomTerrain, "Tirez une carte communaute");
    terrain[22].positionX = 1096;
    terrain[22].positionY = 25;

    terrain[23].prix = 260;
    terrain[23].loyer = 20;
    terrain[23].loyer1M = 100;
    terrain[23].loyer2M = 300;
    terrain[23].loyer3M = 750;
    terrain[23].loyer4M = 925;
    terrain[23].loyer1H = 1100;
    terrain[23].achetable = 1;
    strcpy(terrain[23].nomTerrain, "Avenue Henri-Martin");
    terrain[23].positionX = 1200;
    terrain[23].positionY = 25;
    terrain[23].doublon = 21;


    terrain[24].achetable = 0;
    terrain[24].teleportation = 1;
    strcpy(terrain[24].nomTerrain, "Allez en prison");
    terrain[24].positionX = 1330;
    terrain[24].positionY = 25;

    terrain[25].prix = 280;
    terrain[25].loyer = 26;
    terrain[25].loyer1M = 130;
    terrain[25].loyer2M = 390;
    terrain[25].loyer3M = 900;
    terrain[25].loyer4M = 1100;
    terrain[25].loyer1H = 1275;
    terrain[25].achetable = 1;
    strcpy(terrain[25].nomTerrain, "Avenue Foch");
    terrain[25].positionX = 1330;
    terrain[25].positionY = 160;
    terrain[25].doublon = 27;


    terrain[26].achetable = 0;
    terrain[26].frais = 50;
    strcpy(terrain[26].nomTerrain, "Vous trouver 50$ par terre");
    terrain[26].positionX = 1330;
    terrain[26].positionY = 265;

    terrain[27].prix = 300;
    terrain[27].loyer = 28;
    terrain[27].loyer1M = 150;
    terrain[27].loyer2M = 450;
    terrain[27].loyer3M = 1000;
    terrain[27].loyer4M = 1200;
    terrain[27].loyer1H = 1400;
    terrain[27].achetable = 1;
    strcpy(terrain[27].nomTerrain, "Boulevard des Capucines");
    terrain[27].positionX = 1330;
    terrain[27].positionY = 370;

    terrain[27].doublon = 25;


    terrain[28].achetable = 0;
    terrain[28].teleportation = 1;
    strcpy(terrain[28].nomTerrain, "Avancez a la case 5. Vous passez par la case de depart recevez 200$");
    terrain[28].positionX = 1330;
    terrain[28].positionY = 475;


    terrain[29].prix = 400;
    terrain[29].loyer = 35;
    terrain[29].loyer1M = 175;
    terrain[29].loyer2M = 500;
    terrain[29].loyer3M = 1100;
    terrain[29].loyer4M = 1300;
    terrain[29].loyer1H = 1500;
    terrain[29].achetable = 1;
    strcpy(terrain[29].nomTerrain, "Avenue des Champs-Elysees");
    terrain[29].positionX = 1330;
    terrain[29].positionY = 580;
    terrain[29].doublon = 31;


    terrain[30].achetable = 0;
    terrain[30].carteChance = 1;
    strcpy(terrain[30].nomTerrain, "Tirez une carte chance");
    terrain[30].positionX = 1330;
    terrain[30].positionY = 685;

    terrain[31].prix = 450;
    terrain[31].loyer = 50;
    terrain[31].loyer1M = 200;
    terrain[31].loyer2M = 600;
    terrain[31].loyer3M = 1400;
    terrain[31].loyer4M = 1700;
    terrain[31].loyer1H = 2000;
    terrain[31].achetable = 1;
    strcpy(terrain[31].nomTerrain, "Rue de la paix");
    terrain[31].positionX = 1330;
    terrain[31].positionY = 790;
    terrain[31].doublon = 29;

}
