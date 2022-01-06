//
// Created by 33782 on 20/12/2021.
//

#ifndef PROJET_2021_2022_MONOPOLY_EQUIPE_C_FENETRE_H
#define PROJET_2021_2022_MONOPOLY_EQUIPE_C_FENETRE_H

#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>
#include "partieEnCours.h"

#define WIDTH 1920
#define HEIGHT 1080

#define NOIR al_map_rgb(0 , 0,  0)
#define BLANC al_map_rgb(255 , 255,  255)
#define COULEURMONOP al_map_rgb(64, 64, 64)

void erreur(const char *txt);

int positionSouris1(int x, int y);
int positionSouris2(int x, int y);
int positionSouris3(int x, int y);
int positionSouris4(int x, int y);




void creerRectangle(int x1, int y1, int x2, int y2);
void creerRectangleVide(int x1, int y1, int x2, int y2, int epaisseur);

void setWindow();

#endif //PROJET_2021_2022_MONOPOLY_EQUIPE_C_FENETRE_H
