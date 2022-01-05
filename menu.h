#ifndef PROJET_2021_2022_MONOPOLY_EQUIPE_C_MENU_H
#define PROJET_2021_2022_MONOPOLY_EQUIPE_C_MENU_H

#include "stdio.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "partieEnCours.h"


#define NOMBRE_MAX_JOUEURS 6

#define LARGEUR_CONSOLE 80

typedef struct{
    int numJoueur;
    char nomJoueur[10];
    int argentJoueur;
}Joueur;

typedef struct{
    int prixAchat;
    char occupation;
    char proprietaire;
    int nbMaison;
    int nbHotel;
    char couleur;
    float loyer;
}Propriete;

void printf_center (const char* str);

Joueur tabJoueur[NOMBRE_MAX_JOUEURS];

int tabordreJoueurs[NOMBRE_MAX_JOUEURS];

int menuPrincipale();

Joueur ajouterJoueur(int i);

int randomJoueurs(int nbJoueurs, int ordreJoueurs[NOMBRE_MAX_JOUEURS]);

int  ajouterJoueursTab(int taille_logique);


void afficherRegle();
void afficherNomMembresProjet();

void initialisation();

int quitter();

void lancerNouvellePartie();

#endif