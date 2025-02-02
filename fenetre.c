#include "fenetre.h"


void erreur(const char *txt) {
    printf("ERREUR : %s", txt);
    exit(EXIT_FAILURE);
}

void creerRectangleBlanc(int x1, int y1, int x2, int y2) {
    al_draw_filled_rectangle(x1, y1, x2, y2, BLANC);
}

void creerRectangle(int x1, int y1, int x2, int y2) {
    al_draw_filled_rectangle(x1, y1, x2, y2, COULEURMONOP);
}

void creerRectangleVide(int x1, int y1, int x2, int y2, int epaisseur) {
    al_draw_rectangle(x1, y1, x2, y2, NOIR, epaisseur);
}

int positionSouris1(int x, int y) {
    if (x >= 442 && x <= 710 && y >= 430 && y <= 455) {
        return 1;
    }
    return 0;
}

int positionSouris2(int x, int y) {
    if (x >= 442 && x <= 710 && y >= 470 && y <= 495) {
        return 1;
    }
    return 0;
}

int positionSouris3(int x, int y) {
    if (x >= 442 && x <= 710 && y >= 510 && y <= 535) {
        return 1;
    }
    return 0;
}

int positionSouris4(int x, int y) {
    if (x >= 442 && x <= 710 && y >= 550 && y <= 575) {
        return 1;
    }
    return 0;
}

void setWindow() {

    int fin = 0, wait = -1, oldx = 0, oldy = 0;
    int x1 = 442;
    int y1 = 430;
    int x2 = 710;
    int y2 = 455;

    ALLEGRO_EVENT_QUEUE *queue = NULL;
    ALLEGRO_DISPLAY *display = NULL;
    ALLEGRO_BITMAP *imageAcceuil = NULL;
    ALLEGRO_MOUSE_STATE mouse_state;


    if (!al_init()) {
        printf("Erreur initialisation\n");
    }
    if (!al_install_keyboard()) {
        erreur("Installation clavier\n");
    }
    if (!al_init_image_addon()) {
        printf("Erreur initialisation font addon\n");
    }
    if (!al_init_primitives_addon()) {
        printf("Erreur initialisation primitive addon\n");
    }
    if (!al_install_mouse()) {
        printf("Erreur initialisation souris\n");
    }
    al_init_font_addon();
    al_init_ttf_addon();


    display = al_create_display(WIDTH_MENU, HEIGHT_MENU);
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
    al_register_event_source(queue, al_get_mouse_event_source());

    al_get_mouse_state(&mouse_state);

    al_set_target_backbuffer(display);

    imageAcceuil = al_load_bitmap("../images/imageAcceuil.jpg");

    al_draw_scaled_bitmap(imageAcceuil, 0, 0, 1300, 870, 0, 0, 1152, 648, 0);

    for (int i = 0; i < 4; i++) {
        creerRectangle(x1, y1, x2, y2);
        y1 += 40;
        y2 += 40;
    }

// texte menuPrincipal
    ALLEGRO_FONT *menu1 = al_load_font("../font/Kiwi_Maru/KiwiMaru-Medium.ttf", 15, 0);
    al_draw_text(menu1, BLANC, 465, 430, 0, "Lancer une nouvelle partie");

    ALLEGRO_FONT *menu2 = al_load_font("../font/Kiwi_Maru/KiwiMaru-Medium.ttf", 15, 0);
    al_draw_text(menu2, BLANC, 495, 470, 0, "Afficher les regles");

    ALLEGRO_FONT *menu3 = al_load_font("../font/Kiwi_Maru/KiwiMaru-Medium.ttf", 15, 0);
    al_draw_text(menu3, BLANC, 465, 512, 0, "Nom des membres du projet");

    ALLEGRO_FONT *menu4 = al_load_font("../font/Kiwi_Maru/KiwiMaru-Medium.ttf", 15, 0);
    al_draw_text(menu4, BLANC, 480, 552, 0, "Quitter partie en cours");

    al_flip_display();
//Boucle d'évènement
    do {
        ALLEGRO_EVENT event;
        al_wait_for_event(queue, &event);
        al_get_mouse_state(&mouse_state);

        if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            fin = 1;
        } else if (event.type == ALLEGRO_EVENT_KEY_UP && wait == -1) {
            switch (event.keyboard.keycode) {
                case ALLEGRO_KEY_ESCAPE :
                    fin = 1;
                    break;
            }
        }

        if ((event.mouse.button & 1) && positionSouris1(mouse_state.x, mouse_state.y)) {
            lancerNouvellePartie();
        }
        if ((event.mouse.button & 1) && positionSouris2(mouse_state.x, mouse_state.y)) {
            afficherRegle();
        }
        if ((event.mouse.button & 1) && positionSouris3(mouse_state.x, mouse_state.y)) {
            afficherNomMembresProjet();
        }
        if ((event.mouse.button & 1) && positionSouris4(mouse_state.x, mouse_state.y)) {
            quitter();
        }

    } while (!fin);

    al_destroy_display(display);
    al_destroy_event_queue(queue);
    al_destroy_font(menu1);
    al_destroy_font(menu2);
}
