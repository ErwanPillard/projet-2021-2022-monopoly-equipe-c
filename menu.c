#include "menu.h"
#include "stdio.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


int menuPrincipale(){
    int choixMenu = 0;
    do{
        printf("Lancer une nouvelle partie 1\n"
               "Afficher les regles 2\n"
               "Afficher le nom des membres du projet 3\n"
               "Quitter partie en cours 4\n");
        scanf("%d", &choixMenu);
    }while(choixMenu < 1 || choixMenu > 4);
}

Joueur ajouterJoueur(int i){
    Joueur parametreJ;
    printf("Entrez le pseudo du joueur %d: ", i + 1);
    scanf("%s", parametreJ.nomJoueur);
    parametreJ.argentJoueur = 1500.0f; // argent initiale du joueur
    parametreJ.numJoueur = i; // on affecte le num 0 au joueur 1, ect...
    return parametreJ;
}

int  ajouterJoueursTab(int taille_logique){
    Joueur parametreJ;
    for(int i = 0; i < taille_logique; i++){
        parametreJ = ajouterJoueur(i);
        tabJoueur[i] = parametreJ;
    }
}

int lancerNouvellePartie(){
    int nombreJoueurs = 0, premierJoueur;
    char nomPartie[20];
    printf("Nom de la partie (20 caractere max): ");
    scanf("%s", nomPartie);
    printf("Entrez le nombre de joueurs (max 10) ");
    scanf("%d", &nombreJoueurs);
    ajouterJoueursTab(nombreJoueurs);
    ordrePassage(nombreJoueurs);
    }

void afficherRegle(){
// texte avec la mise en forme pour afficher les règles du monopoly
}

void afficherNomMembresProjet(){
    printf("Membres du projet:\n"
           "Erwan\n"
           "Theo\n"
           "Lucas\n"
           "Constantin");
}


void ordrePassage(int nbJoueurs) {
    srand(time(NULL));
    int aleatoire, numero = 1, i, resultat;
    aleatoire = rand() % (nbJoueurs);
    printf("Voici l'ordre de passage des joueur :\n");
    i = aleatoire;
    resultat = nbJoueurs + aleatoire;
    for(i;i<nbJoueurs;i++) {
        printf("Le joueur %d est : %s\n", numero, tabJoueur[aleatoire].nomJoueur);
        aleatoire++;
        numero++;
    }
    aleatoire = 0;
    for (i; i < resultat; i++) {
        printf("Le joueur %d est : %s\n", numero, tabJoueur[aleatoire].nomJoueur);
        aleatoire++;
        numero++;
    }
}

int quitter(){
    exit(EXIT_SUCCESS);
}

