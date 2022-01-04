//
// Created by 33782 on 27/12/2021.
//

#include "partieEnCours.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fenetre.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

int fenetreNvPartie(){

    int fin = 0, wait = -1;

    int numCase = 2;

    ALLEGRO_DISPLAY* display;
    ALLEGRO_KEYBOARD_STATE keyboard_state;
    ALLEGRO_MOUSE_STATE mouse_state;
    ALLEGRO_EVENT_QUEUE *queue = NULL;
    ALLEGRO_EVENT event;

    if(!al_init()){
        printf("Erreur initialisation");
    }

    if (!al_install_keyboard()) {
        erreur("Installation clavier");
    }

    display = al_create_display(WIDTH, HEIGHT);

    if(!display){
        printf("Erreur creation display");
    }

    al_set_window_position(display,0,0);
    al_set_window_title(display, "Monopoly");
    al_clear_to_color(al_map_rgb(255, 255, 255));

    queue = al_create_event_queue();
    if (!queue) {
        al_destroy_display(display);
        erreur("Création de l'event queue");
    }
    al_register_event_source(queue, al_get_display_event_source(display));
    al_register_event_source(queue, al_get_keyboard_event_source());

    al_set_target_backbuffer(display);


    if(!al_init_image_addon()){
        printf("Erreur initialisation addon");
    }
    ALLEGRO_BITMAP *plateau = NULL;
    plateau = al_load_bitmap("../images/plateau.jpg");

    ALLEGRO_BITMAP *case1 = NULL;
    case1 = al_load_bitmap("../images/case1.jpg");

    ALLEGRO_BITMAP *case2 = NULL;
    case2 = al_load_bitmap("../images/case2.jpg");

    ALLEGRO_BITMAP *case3 = NULL;
    case3 = al_load_bitmap("../images/case3.jpg");

    ALLEGRO_BITMAP *case4 = NULL;
    case4 = al_load_bitmap("../images/case4.jpg");

    ALLEGRO_BITMAP *case5 = NULL;
    case5 = al_load_bitmap("../images/case5.jpg");

    ALLEGRO_BITMAP *case6 = NULL;
    case6 = al_load_bitmap("../images/case6.jpg");

    ALLEGRO_BITMAP *case7 = NULL;
    case7 = al_load_bitmap("../images/case7_23.jpg");

    ALLEGRO_BITMAP *case8 = NULL;
    case8 = al_load_bitmap("../images/case8.jpg");

    ALLEGRO_BITMAP *case9 = NULL;
    case9 = al_load_bitmap("../images/case9.jpg");

    ALLEGRO_BITMAP *case10 = NULL;
    case10 = al_load_bitmap("../images/case10.jpg");

    ALLEGRO_BITMAP *case11 = NULL;
    case11 = al_load_bitmap("../images/case11.jpg");

    ALLEGRO_BITMAP *case12 = NULL;
    case12 = al_load_bitmap("../images/case12.jpg");

    ALLEGRO_BITMAP *case13 = NULL;
    case13 = al_load_bitmap("../images/case13.jpg");

    ALLEGRO_BITMAP *case14 = NULL;
    case14 = al_load_bitmap("../images/case14.jpg");

    ALLEGRO_BITMAP *case15 = NULL;
    case15 = al_load_bitmap("../images/case15_31.jpg");

    ALLEGRO_BITMAP *case16 = NULL;
    case16 = al_load_bitmap("../images/case16.jpg");

    ALLEGRO_BITMAP *case17= NULL;
    case17 = al_load_bitmap("../images/case17.jpg");

    al_draw_bitmap(plateau, 10,0,0);

    al_flip_display();
    while(!fin){
        //evenement
        al_flip_display();

        ALLEGRO_EVENT event;
        al_wait_for_event(queue, &event);

        if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            fin = 1;
        }
        else if (event.type == ALLEGRO_EVENT_KEY_UP && wait == -1) {
            switch (event.keyboard.keycode) {
                case ALLEGRO_KEY_ESCAPE:
                    fin = 1;
                    break;
            }
        }

        al_flip_display();
    }

    al_destroy_bitmap(plateau);
    al_destroy_display(display);
}

void mainPartie(int nbJoueurs){
    int indiceJoueur = 0;
    int winner = 0, joueursElimine = 0;
    int lancerDe = 0, valeurLancementDe1, valeurLancementDe2;

    do{
        if(indiceJoueur >= nbJoueurs, indiceJoueur < 0){
            indiceJoueur = 0;
        }
        printf("C'est à %s de jouer", tabJoueur[tabordreJoueurs[indiceJoueur]].nomJoueur);

        if(joueursElimine == nbJoueurs - 1){ // condition de victoire
            winner = 1;
        }

        printf("Taper 1 pour lancer les dés : ");
        scanf("%d", &lancerDe);
        valeurLancementDe1 = randomDe(nbJoueurs);
        valeurLancementDe2 = randomDe(nbJoueurs);
        verifDoubleDe(valeurLancementDe1, valeurLancementDe2, tabordreJoueurs[i]);

        if(tabParametreJoueurs[indiceJoueur].doubleDe != 0){
            indiceJoueur--;
        }
        else{
            indiceJoueur++;
        }
    } while(!winner);
}


int randomDe(int nbJoueurs){
    srand(time(NULL));
    int de;
    for(int i = 0; i < 15; i++){
        de = rand() % nbJoueurs;
    }

    return de;
}

/*
int randomDe(){
    srand(time(NULL));
    int somme = 0, de1, de2, calcul = 0, resultat;
    for (int i = 0; i < 2; i++) {
        somme += (rand() % 6) + 1;
        de1 = calcul;
        calcul = somme;
    }
    de2 = somme - de1;
    printf("%d %d\n", de1, de2);
    resultat = doubleDe(de1, de2);

    return resultat;
}*/


void verifDoubleDe(int de1, int de2, int indiceJoueur) {
    if(de1 == de2){
        tabParametreJoueurs[indiceJoueur].doubleDe += 1;
    }
}