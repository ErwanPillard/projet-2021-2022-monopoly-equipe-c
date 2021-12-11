//
// Created by 33782 on 11/12/2021.
//

#ifndef PROJET_2021_2022_MONOPOLY_EQUIPE_C_MENU_H
#define PROJET_2021_2022_MONOPOLY_EQUIPE_C_MENU_H

#define NOMBRE_MAX_JOUEURS 10

void exit(int status);

typedef struct{
    char nomJoueur;
    float argentJoueur;

}nvJoueur;

nvJoueur tabNomJoueurs[NOMBRE_MAX_JOUEURS];

void lancerNouvellePartie();

void ajouterJoueur(int taille_logique);

int quitterJeu();

int menuPrincipale();

#endif //PROJET_2021_2022_MONOPOLY_EQUIPE_C_MENU_H
