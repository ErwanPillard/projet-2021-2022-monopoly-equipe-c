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

    switch(choixMenu){
        case 1:
            lancerNouvellePartie();
            break;
        case 2:
            afficherRegle();
            break;
        case 3:
            afficherNomMembresProjet();
            break;
        case 4:
            quitter();
            break;
    }
}


