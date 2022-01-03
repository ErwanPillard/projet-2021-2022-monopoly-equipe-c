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
   /* random(nombreJoueurs);*/
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


int random(int nbJoueurs) {
    int nbaleatoire;
    for (int i = 0; i < nbJoueurs; i++){
        nbaleatoire = rand() % (nbJoueurs + 1);
        printf("%d\n", nbaleatoire);
        for(int j = 0; j < nbJoueurs; j++){
            if(ordreJoueurs[j].numJoueur == nbaleatoire){
                i--;
            }
            else{
                ordreJoueurs[j].numJoueur = tabJoueur[i].numJoueur;
            }
        }
    }
    printf("\n");
    for(int i = 0; i < nbJoueurs; i++){
        printf("%d\n", ordreJoueurs[i].numJoueur);
    }
}

void ordrePassage(int nbJoueurs) {
    srand(time(NULL));
    int aleatoire;
    aleatoire = rand() % (nbJoueurs);
    printf("aleatoire : %d\n", aleatoire);
    for(int i=1;i<=nbJoueurs;i++) {
        if(aleatoire<=nbJoueurs) {
            printf("Le joueur %d est : %s\n", i, tabJoueur[aleatoire].nomJoueur);
            aleatoire++;
            printf("aleatoire 1 : %d\n", aleatoire);
            i++;
        } else if (aleatoire>nbJoueurs) {
            aleatoire = 1;
            printf("Le joueur %d est : %s\n", i, tabJoueur[aleatoire].nomJoueur);
            aleatoire++;
            printf("aleatoire 2 : %d\n", aleatoire);
            i++;
        }
    }
}


int quitter(){
    exit(EXIT_SUCCESS);
}

