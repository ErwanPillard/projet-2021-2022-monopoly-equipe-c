//
// Created by 33782 on 03/01/2022.
//

#ifndef PROJET_2021_2022_MONOPOLY_EQUIPE_C_TERRAIN_H
#define PROJET_2021_2022_MONOPOLY_EQUIPE_C_TERRAIN_H

typedef struct{
    int prix;
    int loyer;
    int loyer1M;
    int loyer2M;
    int loyer3M;
    int loyer4M;
    int loyer1H; //=5 maisons
    int prixMaison;
    int proprietaire;
    int achetable;
    float frais; // a payer ou à recevoir
}T;

#endif //PROJET_2021_2022_MONOPOLY_EQUIPE_C_TERRAIN_H
