
#include "menu.h"
#include "fenetre.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <assert.h>
#include <stdio.h>


int main(){
    setWindow();
    int choixMenu;
    choixMenu = menuPrincipale();
    switch (choixMenu) {
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