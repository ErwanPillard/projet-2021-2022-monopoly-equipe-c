
#include "menu.h"
#include "fenetre.h"
#include "partieEnCours.h"
int main(){
    setWindow();
    //fenetreNvPartie();

    switch(menuPrincipale()){
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

    return 0;
}