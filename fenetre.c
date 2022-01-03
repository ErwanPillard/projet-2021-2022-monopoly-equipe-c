#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "fenetre.h"
#include <stdio.h>



void erreur(const char *txt) {
    printf("ERREUR : %s", txt);
    exit(EXIT_FAILURE);
}

int setWindow() {

    int fin = 0, wait = -1, dessin = 0;
    ALLEGRO_EVENT_QUEUE *queue = NULL;
    ALLEGRO_DISPLAY *display = NULL;
    ALLEGRO_BITMAP *imageAcceuil = NULL;
    ALLEGRO_EVENT event;

    if(!al_init()){
        printf("Erreur initialisation");
    }
    if (!al_install_keyboard()) {
        erreur("Installation clavier");
    }
    if (!al_init_image_addon()) {
        printf("Erreur initialisation addon");
    }


    display = al_create_display(WIDTH, HEIGHT);
    if (!display) {
        erreur("Création de la fenêtre");
    }
    al_set_window_title(display, "Monopoly");

    queue = al_create_event_queue();
    if (!queue) {
        al_destroy_display(display);
        erreur("Création de l'event queue");
    }
    al_register_event_source(queue, al_get_display_event_source(display));
    al_register_event_source(queue, al_get_keyboard_event_source());

    al_set_target_backbuffer(display);

    imageAcceuil = al_load_bitmap("../images/imageAcceuil.jpg");


    al_draw_scaled_bitmap(imageAcceuil, 0, 0, 1300, 870,0, 0, 1900, 1060, 0);
    al_flip_display();

    do {
        al_wait_for_event(queue, &event);

        if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            fin = 1;
        } else if (event.type == ALLEGRO_EVENT_KEY_UP && wait == -1) {
            switch (event.keyboard.keycode) {
                case ALLEGRO_KEY_ESCAPE :
                    fin = 1;
                    break;

            }
            al_flip_display();

        }
    } while (!fin);

    al_destroy_display(display);
    al_destroy_event_queue(queue);
}
