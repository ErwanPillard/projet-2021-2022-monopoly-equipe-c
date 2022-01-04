//
// Created by 33782 on 27/12/2021.
//

#include "partieEnCours.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fenetre.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

int fenetre(){
    ALLEGRO_DISPLAY* display;
    ALLEGRO_KEYBOARD_STATE keyboard_state;
    ALLEGRO_MOUSE_STATE mouse_state;


    if(!al_init()){
        printf("Erreur initialisation");
    }

    display = al_create_display(WIDTH, HEIGHT);

    if(!display){
        printf("Erreur creation display");
    }

    al_set_window_position(display,0,0);
    al_set_window_title(display, "Monopoly");

    ALLEGRO_BITMAP *plateau = NULL;
    ALLEGRO_BITMAP *case1 = NULL;
    ALLEGRO_BITMAP *case2 = NULL;


    if(!al_init_image_addon()){
        printf("Erreur initialisation addon");
    }

    plateau = al_load_bitmap("../images/plateaumilieu.jpg");
    case1 = al_load_bitmap("../images/case1.jpg");
    case2 = al_load_bitmap("../images/case2.jpg");



    if(plateau == NULL) printf("Le chemin est pas bon");

    al_draw_bitmap(plateau, 636,216,0);
    al_draw_scaled_bitmap(case1,0, 0, 303, 303,1284, 864, 180, 180, 0);
    al_draw_scaled_bitmap(case2,0, 0, 342, 517,1192, 864, 92, 180, 0);

    al_flip_display();
    al_rest(5);

    al_destroy_bitmap(plateau);
    al_destroy_display(display);
}

int partieEnCours(){
    fenetre(); // ouvre la fenetre de la nouvelle partie
    randomDe();
}

void randomDe(){
    srand(time(NULL));
    int somme = 0, de1, de2, calcul = 0, resultat;
    for (int i = 0; i < 2; i++) {
        somme += (rand() % 6) + 1;
        de1 = calcul;
        calcul = somme;
    }
    de2 = somme - de1;
    printf("%d %d\n", de1, de2);
    resultat = doubleDe(de1, de2);
    if(resultat==1) {
        randomDe();
    }
}


int doubleDe(int de1, int de2) { //pb double : tps s'écoule trop vite pas le tps de relancer même tirage jusqu'à changement de seconde (peut-être relancer dé via interface ?)
    if (de1==de2) {
        return 1;
    }else {
        return 0;
    }
}