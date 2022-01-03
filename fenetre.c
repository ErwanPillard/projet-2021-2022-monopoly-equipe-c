#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "fenetre.h"
#include <stdio.h>

int setWindow(){

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

    if(!al_init_image_addon()){
        printf("Erreur initialisation addon");
    }

    plateau = al_load_bitmap("../images/case1.jpg");

    if(plateau == NULL) printf("Le chemin est pas bon");

    al_draw_bitmap(plateau, 0,0,0);
    al_flip_display();
    al_rest(5);

    al_destroy_bitmap(plateau);
    al_destroy_display(display);


}