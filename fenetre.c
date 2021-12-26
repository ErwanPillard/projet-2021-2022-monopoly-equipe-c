#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <assert.h>
#include "fenetre.h"
#include <stdio.h>


int setWindow(){
    ALLEGRO_DISPLAY* display;

    if(!al_init()){
        printf("Erreur initialisation");
    }


    display = al_create_display(WIDTH, HEIGHT);

    if(!display){
        printf("Erreur création display");
    }

    al_set_window_position(display,10,10);
    al_set_window_title(display, "Monopoly");

    if(!al_init_image_addon()){
        printf("Erreur d'initialisation addon");
    }
    ALLEGRO_BITMAP *plateau = NULL;

    plateau = al_load_bitmap("../images/Capture3.PNG");

    if(plateau == NULL) printf("Le chemin est pas bon");

    al_flip_display();
    al_rest(5);
    al_destroy_bitmap(plateau);
    al_destroy_display(display);


}