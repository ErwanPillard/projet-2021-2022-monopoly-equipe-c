//
// Created by 33782 on 11/12/2021.
//

#include "menu.h"
#include "stdio.h"
#include <stdlib.h>

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
    parametreJ.numJoueur = i + 1;
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
    int nombreJoueurs = 0;
    char nomPartie[20];
    printf("Nom de la partie (20 caractere max): ");
    scanf("%s", nomPartie);
    printf("Entrez le nombre de joueurs (max 10) ");
    scanf("%d", &nombreJoueurs);
    ajouterJoueursTab(nombreJoueurs);
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

int quitter(){
    int choix = 0;
    printf("Etes vous sur de vouloir quitter ?");
    scanf("%d", &choix);
    if(choix == 1){
        exit(EXIT_SUCCESS);
    }
    else{
        return 0;
    }
}

