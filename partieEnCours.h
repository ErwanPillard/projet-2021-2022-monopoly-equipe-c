//
// Created by 33782 on 27/12/2021.
//

#ifndef PROJET_2021_2022_MONOPOLY_EQUIPE_C_PARTIEENCOURS_H
#define PROJET_2021_2022_MONOPOLY_EQUIPE_C_PARTIEENCOURS_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fenetre.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include "menu.h"
#include "fenetre.h"
#include "terrain.h"

#define NOMBRE_MAX_JOUEURS 6

#define DIMENSION_PIONX 100
#define DIMENSION_PIONY 142

typedef struct{
    int pion;
    int doubleDe;
    int cartePrison;
    int numCase;
}parametreJoueur;

typedef struct{
    int positionX;
    int positionY;
}position;

parametreJoueur tabParametreJoueurs[NOMBRE_MAX_JOUEURS];

unsigned char positionSourisButtonDe(int x, int y);

int testSiMaison(int indiceJoueur);

int randomDe(int nbJoueurs);
void affectationPion(int nbJoueurs);
int affichagePion(int* pion);
int fenetre();
int partieEnCours();
void verifDoubleDe(int de1, int de2, int indiceJoueur);
void initialisation(int nbJoueurs);
int fenetreNvPartie(int nbJoueurs);
void mainPartie(int nbJoueurs);


#endif //PROJET_2021_2022_MONOPOLY_EQUIPE_C_PARTIEENCOURS_H
