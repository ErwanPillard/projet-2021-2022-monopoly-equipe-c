#ifndef PROJET_2021_2022_MONOPOLY_EQUIPE_C_MENU_H
#define PROJET_2021_2022_MONOPOLY_EQUIPE_C_MENU_H

#define NOMBRE_MAX_JOUEURS 10


typedef struct{
    int numJoueur;
    char nomJoueur[10];
    float argentJoueur;
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

void ordrePassage(int nbJoueurs);
Joueur tabJoueur[NOMBRE_MAX_JOUEURS];

Joueur ordreJoueurs[NOMBRE_MAX_JOUEURS];

int menuPrincipale();

int lancerNouvellePartie();

Joueur ajouterJoueur(int i);
int randomJoueurs(int nbJoueurs);
int  ajouterJoueursTab(int taille_logique);

void afficherRegle();
void afficherNomMembresProjet();

int quitter();

#endif
