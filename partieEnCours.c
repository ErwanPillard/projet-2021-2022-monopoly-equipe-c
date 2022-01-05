#include "partieEnCours.h"

int fenetreNvPartie(int nbJoueurs){

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

    al_init_font_addon();
    al_init_ttf_addon();

    int rectangleX = 1300, rectangleY = 0;

    for (int i = 0; i < nbJoueurs; i++) {
        ALLEGRO_FONT *pseudo = al_load_font("../font/arial.ttf", 20, 0);
        al_draw_textf(pseudo, al_map_rgb(0,0,0), rectangleX, rectangleY, 0,
                      "%s %d $", tabJoueur[tabordreJoueurs[i]].nomJoueur, tabJoueur[tabordreJoueurs[i]].argentJoueur);
        rectangleY += 100;
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

    ALLEGRO_BITMAP *pion1= NULL;
    pion1 = al_load_bitmap("../images/pion.png");

    ALLEGRO_BITMAP *pion2= NULL;
    pion2  = al_load_bitmap("../images/pion2.png");

    al_draw_bitmap(plateau, 10,0,0);
    al_flip_display();
    int indiceJoueur = -1;
    int winner = 0, joueursElimine = 0;
    int lancerDe1 = 0, lancerDe2 = 0, valeurLancementDe1, valeurLancementDe2, valeurDeTotale;

    do{
        ALLEGRO_EVENT event;
        al_wait_for_event(queue, &event);

        if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            winner = 1;
        }
        else if (event.type == ALLEGRO_EVENT_KEY_UP && wait == -1) {
            switch (event.keyboard.keycode) {
                case ALLEGRO_KEY_ESCAPE:
                    winner = 1;
                    break;
            }
        }
        if(tabParametreJoueurs[indiceJoueur].doubleDe == 0){
            indiceJoueur++;
        }

        if(indiceJoueur >= nbJoueurs && indiceJoueur < 0){
            indiceJoueur = 0;
        }
        printf("C est a %s de jouer\n", tabJoueur[tabordreJoueurs[indiceJoueur]].nomJoueur);

        printf("Taper 1 pour lancer le premier des : ");
        scanf("%d", &lancerDe1);

        valeurLancementDe1 = randomDe(nbJoueurs);

        printf("Taper 1 pour lancer le deuxieme des : ");
        scanf("%d", &lancerDe2);

        valeurLancementDe2 = randomDe(nbJoueurs);

        verifDoubleDe(valeurLancementDe1, valeurLancementDe2, tabordreJoueurs[indiceJoueur]);

        valeurDeTotale = valeurLancementDe2 + valeurLancementDe1;
        printf("%d\n", valeurDeTotale);

        tabParametreJoueurs[indiceJoueur].numCase = (tabParametreJoueurs[indiceJoueur].numCase + valeurDeTotale)%32; // il y a 32 case donc on ne peut pas depasser 32
        printf("%d\n", tabParametreJoueurs[indiceJoueur].numCase);

        if(joueursElimine == nbJoueurs - 1){ // condition de victoire
            winner = 1;
        }
    } while(!winner);
    al_flip_display();
    al_destroy_bitmap(plateau);
    al_destroy_display(display);
}

void mainPartie(int nbJoueurs){
    int indiceJoueur = -1;
    int winner = 0, joueursElimine = 0;
    int lancerDe1 = 0, lancerDe2 = 0, valeurLancementDe1, valeurLancementDe2, valeurDeTotale;

    //initialisation tout les joueurs sur la case 0
    for(int i = 0; i < nbJoueurs; i++){
        tabParametreJoueurs[i].numCase = 0;
    }

    init_terrains(); // initialise les parametre des terrains

    do{
        if(tabParametreJoueurs[indiceJoueur].doubleDe == 0){
            indiceJoueur++;
        }

        if(indiceJoueur >= nbJoueurs && indiceJoueur < 0){
            indiceJoueur = 0;
        }
        printf("C est a %s de jouer\n", tabJoueur[tabordreJoueurs[indiceJoueur]].nomJoueur);

        printf("Taper 1 pour lancer le premier des : ");
        scanf("%d", &lancerDe1);

        valeurLancementDe1 = randomDe(nbJoueurs);

        printf("Taper 1 pour lancer le deuxieme des : ");
        scanf("%d", &lancerDe2);

        valeurLancementDe2 = randomDe(nbJoueurs);

        verifDoubleDe(valeurLancementDe1, valeurLancementDe2, tabordreJoueurs[indiceJoueur]);

        valeurDeTotale = valeurLancementDe2 + valeurLancementDe1;
        printf("%d\n", valeurDeTotale);


        tabParametreJoueurs[indiceJoueur].numCase = (tabParametreJoueurs[indiceJoueur].numCase + valeurDeTotale)%32; // il y a 32 case donc on ne peut pas depasser 32
        printf("%d\n", tabParametreJoueurs[indiceJoueur].numCase);

        if(terrain[tabParametreJoueurs[indiceJoueur].numCase].achetable == 1 && terrain[tabParametreJoueurs[indiceJoueur].numCase].vendu == 0){
            int choix;

            printf("Voulez vous acheter %s (si oui tapez 1)", terrain[tabParametreJoueurs[indiceJoueur].numCase].nomTerrain);
            scanf("%d", &choix);

            if(choix == 1){
                terrain[tabParametreJoueurs[indiceJoueur].numCase].achetable = 0;
            }
        }



        if(joueursElimine == nbJoueurs - 1){ // condition de victoire
            winner = 1;
        }
    } while(!winner);
}


int randomDe(int nbJoueurs){
    srand(time(NULL));
    int de = 0;
    do{
        for(int i = 0; i < 10; i++){
            de = rand() % 6 + 1;
        }
    }while(de == 0);

    return de;
}

void affectationPion(int nbJoueurs){
    int numJoueur;
    for(int i = 0; i < nbJoueurs; i++){
        tabParametreJoueurs[i].pion = i + 1;
    }
}
/*
int affichagePion(int* pion){
    al_set_target_bitmap(pion);
    al_draw_scaled_bitmap(pion, 0, 0, DIMENSION_PIONX, DIMENSION_PIONY, 0, 0, 0);
}*/

void initialisation(int nbJoueurs){
    printf_center("Initialisation :\n");
    for (int i = 0; i < nbJoueurs; i++) {
        printf("Joueur %d\n", i + 1);
        printf("Pseudo :%s\n", tabJoueur[tabordreJoueurs[i]].nomJoueur);
        printf("Argent %d\n", tabJoueur[tabordreJoueurs[i]].argentJoueur);
    }
} // afficher dans la console les parametre des joueurs

void verifDoubleDe(int de1, int de2, int indiceJoueur) {
    if(de1 == de2){
        tabParametreJoueurs[indiceJoueur].doubleDe += 1;
    }

    else{
        tabParametreJoueurs[indiceJoueur].doubleDe = 0;
    }
}

