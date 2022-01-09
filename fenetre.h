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
#include "nouvellePartie.h"

#define WIDTH_MENU 1152
#define HEIGHT_MENU 648

#define NOIR al_map_rgb(0 , 0,  0)
#define BLANC al_map_rgb(255 , 255,  255)
#define MARRON al_map_rgb(154 , 74,  12)
#define GRIS al_map_rgb(136 , 133,  131)
#define VIOLET al_map_rgb(194 , 17,  225)
#define ORANGE al_map_rgb(239 , 123,  27)
#define ROUGE al_map_rgb(229 , 39,  39)
#define JAUNE al_map_rgb(231 , 193,  77)
#define BLEU al_map_rgb(42 , 85,  238)
#define VERT al_map_rgb(84 , 231,  77)


#define COULEURMONOP al_map_rgb(64, 64, 64)

void erreur(const char *txt);

int positionSouris1(int x, int y);
int positionSouris2(int x, int y);
int positionSouris3(int x, int y);
int positionSouris4(int x, int y);



void creerRectangleBlanc(int x1, int y1, int x2, int y2);
void creerRectangle(int x1, int y1, int x2, int y2);
void creerRectangleVide(int x1, int y1, int x2, int y2, int epaisseur);

void setWindow();

#endif //PROJET_2021_2022_MONOPOLY_EQUIPE_C_FENETRE_H
