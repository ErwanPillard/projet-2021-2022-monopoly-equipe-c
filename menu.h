//
// Created by 33782 on 11/12/2021.
//

#ifndef PROJET_2021_2022_MONOPOLY_EQUIPE_C_MENU_H
#define PROJET_2021_2022_MONOPOLY_EQUIPE_C_MENU_H

#define NOMBRE_MAX_JOUEURS 10


typedef struct{
    int numJoueur;
    char nomJoueur[10];
    float argentJoueur;


}Joueur;

Joueur tabJoueur[NOMBRE_MAX_JOUEURS];

int menuPrincipale();

int lancerNouvellePartie();

Joueur ajouterJoueur(int i);
int  ajouterJoueursTab(int taille_logique);

void afficherRegle();
void afficherNomMembresProjet();

int quitter();

#endif //PROJET_2021_2022_MONOPOLY_EQUIPE_C_MENU_H
