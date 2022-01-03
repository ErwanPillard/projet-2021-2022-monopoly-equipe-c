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
}

int randomDe(){
    int result = 0;
    srand(time(NULL));
    result = rand() % 6;
    return result;
}

int lancerDesDe() {
    int de1, de2, lancer, nbDouble = 1;
    de1 = randomDe();
    de2 = randomDe();
    lancer = de1 + de2;
    if(doubleDe(de1, de2)) {
        nbDouble++;
        lancerDesDe();
        if(nbDouble=3){
            //aller en prison
        }
    }
    return lancer;
}


int doubleDe(int de1, int de2) {
    if(de1 = de2) {
        printf("double");
        return 1;
    }
    else {
        return 0;
    }
}