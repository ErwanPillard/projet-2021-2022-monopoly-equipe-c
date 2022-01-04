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
#include "menu.h"
#include "fenetre.h"

#define NOMBRE_DE 2

typedef struct{
    int doubleDe;
    int cartePrison;
}parametreJoueur;

parametreJoueur tabParametreJoueurs[NOMBRE_MAX_JOUEURS];

int randomDe(int nbJoueurs);
int fenetre();
int partieEnCours();
void verifDoubleDe(int de1, int de2, int indiceJoueur);

int fenetreNvPartie();


#endif //PROJET_2021_2022_MONOPOLY_EQUIPE_C_PARTIEENCOURS_H
