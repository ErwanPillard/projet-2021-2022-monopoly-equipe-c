//
// Created by 33782 on 20/12/2021.
//
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <assert.h>
#include "fenetre.h"
#include "menu.h"
#include <stdio.h>

int setWindow(){
    ALLEGRO_DISPLAY* display = NULL;

    //variables
    int width = 640;
    int height = 480;
    //int isEnd = 0;

    assert(al_init());
    assert(al_init_image_addon());

    display = al_create_display(width, height);
    al_set_window_position(display,10,10);
    al_set_window_title(display, "Monopoly");

    ALLEGRO_BITMAP* plateau = al_load_bitmap("C:Users/33782/CLionProjects/projet-2021-2022-monopoly-equipe-c/images/case1.jpg");
    if(plateau == NULL) printf("Le chemin est pas bon") ;

    al_rest(10);
    /*
    while(!isEnd){
        if(quitter() == true){
            isEnd = 1;
        }
    }*/
    al_destroy_bitmap(plateau);
    al_destroy_display(display);
}