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

#define NOMBRE_DE 2

int randomDe();
int fenetre();
int partieEnCours();
int doubleDe(int de1, int de2);

int fenetreNvPartie();
int lancementPartie(int nbJoueurs);

#endif //PROJET_2021_2022_MONOPOLY_EQUIPE_C_PARTIEENCOURS_H
