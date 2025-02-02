#ifndef PROJET_2021_2022_MONOPOLY_EQUIPE_C_CHANCE_H
#define PROJET_2021_2022_MONOPOLY_EQUIPE_C_CHANCE_H

#include "nouvellePartie.h"
#include "menu.h"
#include <stdio.h>
#include "string.h"
#include <malloc.h>
#include <time.h>
#include <stdlib.h>

#define NOMBRE_CARTES 17

typedef struct {
    char nomcarte[50];
}carte;


carte parametreCartes[NOMBRE_CARTES];

int cartechance(int indiceJoueur, int nbJoueurs);
void initialiserCartes(int indiceJoueur);
carte parametreCommu[NOMBRE_CARTES];
void initialisercommu();
int cartecommu(int indiceJoueur, int nbJoueurs);

#endif //PROJET_2021_2022_MONOPOLY_EQUIPE_C_CHANCE_H
