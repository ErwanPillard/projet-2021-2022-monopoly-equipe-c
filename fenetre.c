//
// Created by 33782 on 20/12/2021.
//
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "fenetre.h"

int setWindow(){
    ALLEGRO_DISPLAY* display;

    //variables
    int width = 640;
    int height = 480;
    al_init();
    al_init_image_addon();

    display = al_create_display(width, height);
    //al_clear_to_color(al_map_rgb(255, 0, 0));
    al_set_window_position(display,10,10);
    al_set_window_title(display, "Monopoly");

    ALLEGRO_BITMAP *plateau = al_load_bitmap("image/case1.jpg");

    al_draw_bitmap(plateau,0,0,0);
    al_flip_display();
    al_rest(10);
    al_destroy_bitmap(plateau);
    al_destroy_display(display);
}