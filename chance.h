#ifndef PROJET_2021_2022_MONOPOLY_EQUIPE_C_CHANCE_H
#define PROJET_2021_2022_MONOPOLY_EQUIPE_C_CHANCE_H

#include "partieEnCours.h"
#include "menu.h"
#include <stdio.h>
#include <malloc.h>
#include <time.h>
#include <stdlib.h>

#define NOMBRE_CARTES 16

typedef struct {
    char nomcarte[50];
    int apayer;
}carte;

carte parametreCartes[NOMBRE_CARTES];

int cartechance (int indiceJoueur);
void initialiserCartes();

#endif //PROJET_2021_2022_MONOPOLY_EQUIPE_C_CHANCE_H
