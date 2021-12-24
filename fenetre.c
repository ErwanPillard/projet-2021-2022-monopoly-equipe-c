#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <assert.h>
#include "fenetre.h"
#include "menu.h"
#include <stdio.h>

int setWindow(){
    ALLEGRO_DISPLAY* display = NULL;
    ALLEGRO_BITMAP *plateau = NULL;


    //variables
    int width = 640;
    int height = 480;
    //int isEnd = 0;

    assert(al_init());
    assert(al_init_image_addon());

    display = al_create_display(width, height);
    al_set_window_position(display,10,10);
    al_set_window_title(display, "Monopoly");

    plateau = al_load_bitmap("../images/case1.jpg");

    if(plateau == NULL) printf("Le chemin est pas bon");

    /*
    while(!isEnd){
        if(quitter() == true){
            isEnd = 1;
        }
    }
    al_destroy_bitmap(plateau);
    al_destroy_display(display);*/


}