//
// Created by 33782 on 20/12/2021.
//
#include <allegro5/allegro.h>

#include "fenetre.h"

int setWindow(){
    ALLEGRO_DISPLAY* display = NULL;

    assert(al_init());

    display = al_create_display(1920, 1080);
    assert(display != NULL);

    al_set_window_title(display, "Monopoly");

    al_rest(10);
}