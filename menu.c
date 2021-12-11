//
// Created by 33782 on 11/12/2021.
//

#include "menu.h"
#include "stdio.h"

void ajouterJoueur(int taille_logique){
    nvJoueur parametreJ;

    for(int i = 0; i < taille_logique; i++){
        printf("Entrez le pseudo du joueur %d: ", i + 1);
        scanf("%c", &parametreJ.nomJoueur);
        parametreJ.argentJoueur = 1500; // argent initiale du joueur
        tabNomJoueurs[i] = parametreJ;
    }
}


void lancerNouvellePartie(){
    nvJoueur parametreJ;
    int nombreJoueurs = 0;
    printf("Entrez le nombre de joueur: ");
    scanf("%d", &nombreJoueurs);
    ajouterJoueur(nombreJoueurs);
}

void afficherRegle(){

}

void afficherNomMembreProjet(){

}

int quitterJeu(){
    printf("A bientot...");
    exit(0);
}

int menuPrincipale(){


}