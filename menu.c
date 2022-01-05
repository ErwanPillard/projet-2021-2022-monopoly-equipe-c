#include "menu.h"

int menuPrincipale(){
    int choixMenu = 0;
    do{
        printf("Lancer une nouvelle partie 1\n"
               "Afficher les regles 2\n"
               "Afficher le nom des membres du projet 3\n"
               "Quitter partie en cours 4\n");
        scanf("%d", &choixMenu);
    }while(choixMenu < 1 || choixMenu > 4);
    return choixMenu;
}

Joueur ajouterJoueur(int i){
    Joueur parametreJ;
    printf("Entrez le pseudo du joueur %d: ", i + 1);
    scanf("%s", parametreJ.nomJoueur);
    parametreJ.argentJoueur = 1500; // argent initiale du joueur
    parametreJ.numJoueur = i; // on affecte le num 0 au joueur 1, ect...
    return parametreJ;
}

int  ajouterJoueursTab(int taille_logique){
    Joueur parametreJ;
    for(int i = 0; i < taille_logique; i++){
        tabJoueur[i] = ajouterJoueur(i);
    }
}

void lancerNouvellePartie(){
    int nombreJoueurs = 0, premierJoueur;
    char nomPartie[20];
    printf("Nom de la partie (20 caractere max): ");
    scanf("%s", nomPartie);
    printf("Entrez le nombre de joueurs (max 6) ");
    scanf("%d", &nombreJoueurs);
    ajouterJoueursTab(nombreJoueurs);
    randomJoueurs(nombreJoueurs, tabordreJoueurs);
    //fenetreNvPartie(nombreJoueurs);
    initialisation(nombreJoueurs);
    mainPartie(nombreJoueurs);
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

int randomJoueurs(int nbJoueurs, int tabordreJoueurs[NOMBRE_MAX_JOUEURS]){ //fonction pour melanger l'ordre des joueurs
    int random;
    for(int h = 0; h < NOMBRE_MAX_JOUEURS; h++){
        tabordreJoueurs[h] = 7;
    }
    srand(time(NULL));
    for (int i = 0; i < nbJoueurs; i++) {
        int ok = 0;
        int validation = 0;
        do{
            random = rand() % (nbJoueurs);
            for (int j = 0; j < nbJoueurs; j++){
                if(random != tabordreJoueurs[j]){
                    validation += 1;
                }
            }
            if(validation == nbJoueurs){
                ok = 1;
            }
            else{
                validation = 0;
            }
        } while(ok != 1);
        tabordreJoueurs[i] = random;
    }
}

void printf_center (const char* str)
{
    unsigned int n;
    for (n = 0; n < (LARGEUR_CONSOLE-strlen(str)) / 2; n++)
    {
        putchar(' ');
    }
    printf("%s", str);
} //fonction pour centrer du texte sur la console

int quitter(){
    exit(EXIT_SUCCESS);
}

