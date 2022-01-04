#include "partieEnCours.h"

int fenetreNvPartie(){
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
    al_clear_to_color(al_map_rgb(255, 255, 255));

    ALLEGRO_BITMAP *plateau = NULL;


    if(!al_init_image_addon()){
        printf("Erreur initialisation addon");
    }

    plateau = al_load_bitmap("../images/plateau.jpg");


    if(plateau == NULL) printf("Le chemin est pas bon");

    al_draw_bitmap(plateau, 10,0,0);

    al_flip_display();
    al_rest(5);

    al_destroy_bitmap(plateau);
    al_destroy_display(display);
}
/*
int lancementPartie(int nbJoueurs){
    int lancementDe = 0, numJoueurEnCours;
    numJoueurEnCours = rand() % nbJoueurs;
    fenetreNvPartie(); // ouvre la fenetre de la nouvelle partie
    while(!lancementDe){

        printf("C'est au joueur %s", );
    }

}*/

int randomDe(){
    int result = 0;
    srand(time(NULL));
    for(int i = 0; i <= NOMBRE_DE; i++){
        result += rand() % 6;
    }
    return result;
}

