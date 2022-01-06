//
// Created by 33782 on 03/01/2022.
//

#ifndef PROJET_2021_2022_MONOPOLY_EQUIPE_C_TERRAIN_H
#define PROJET_2021_2022_MONOPOLY_EQUIPE_C_TERRAIN_H

#include "string.h"

typedef struct{
    char nomTerrain[50];
    int prix;
    int numMaison;
    int carteChanceCommu;
    int teleportation;
    int taxe;
    int loyer;
    int loyer1M;
    int loyer2M;
    int loyer3M;
    int loyer4M;
    int loyer1H; //=5 maisons
    int prixMaison;
    int vendu;
    int achetable;
    int proprietaire;
    int frais; // a payer ou à recevoir
}T;

void init_terrains();

T terrain[33];// terrain commence a la case 1

#endif //PROJET_2021_2022_MONOPOLY_EQUIPE_C_TERRAIN_H
