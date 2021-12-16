#include <stdio.h>

#include <allegro5/allegro.h>

#include "menu.h"



int main(){
    ALLEGRO_DISPLAY* display = NULL;

    assert(al_init());

    display = al_create_display(400, 600);
    assert(display != NULL);

    al_set_window_title(display, "Monopoly");
    al_flip_display();
}
