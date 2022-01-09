//
// Created by 33782 on 27/12/2021.
//

#ifndef PROJET_2021_2022_MONOPOLY_EQUIPE_C_NOUVELLEPARTIE_H
#define PROJET_2021_2022_MONOPOLY_EQUIPE_C_NOUVELLEPARTIE_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include "menu.h"
#include "fenetre.h"
#include "terrain.h"
#include "chance.h"

#define NOMBRE_MAX_JOUEURS 6
#define WIDTH_JEU 1920
#define HEIGHT_JEU 1080

#define DIMENSION_PIONX 100
#define DIMENSION_PIONY 142

typedef struct{
    int numJoueur;
    char nomJoueur[15];
    int argentJoueur;
}Joueur;

Joueur tabJoueur[NOMBRE_MAX_JOUEURS];

int tabordreJoueurs[NOMBRE_MAX_JOUEURS];

typedef struct{
    int pion;
    float pionX;
    float pionY;
    int doubleDe;
    int cartePrison;
    int numCase;
    int nbTourPrison;
    int prison;
    int elimine;
}parametreJoueur;

parametreJoueur tabParametreJoueurs[NOMBRE_MAX_JOUEURS];

int positionSourisButtonDe(int x, int y);

int positionCaseDepart(int x, int y);

int positionSourisButtonOui(int x, int y);

int positionSourisButtonNon(int x, int y);

void vaPrison(int indiceJoueur);

int testSiMaison(int indiceJoueur);

void lancerNouvellePartie();

int random(int nb);

void verifDoubleDe(int de1, int de2, int indiceJoueur);

void initialisation(int nbJoueurs);

void descriptionCartes(int numCase);

int fenetreNvPartie(int nbJoueurs);

void mainPartie(int nbJoueurs);

void ajouterJoueur(int i);

int randomJoueurs(int nbJoueurs, int ordreJoueurs[NOMBRE_MAX_JOUEURS]);

void ajouterJoueursTab(int taille_logique);

void afficherRegle();

void afficherNomMembresProjet();

int quitter();

void printf_center (const char* str);

#endif //PROJET_2021_2022_MONOPOLY_EQUIPE_C_NOUVELLEPARTIE_H
