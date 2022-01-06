#include "partieEnCours.h"

unsigned char positionSourisButtonDe(int x, int y) {
    if (x >= 1800 && x <= 1830 && y >= 160 && y <= 190) {
        return 1;
    }
    return 0;
}

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

    if(!al_install_mouse()){
        erreur("Erreur installation souris");
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

    if (!al_init_primitives_addon()) {
        printf("Erreur initialisation primitive addon\n");
    }

    if(!al_init_image_addon()){
        printf("Erreur initialisation addon");
    }

    al_init_font_addon();
    al_init_ttf_addon();

    ALLEGRO_FONT *aQuiJouer = al_load_font("../font/arial.ttf", 20, 0);
    ALLEGRO_FONT *lancerDe = al_load_font("../font/arial.ttf", 20, 0);
    ALLEGRO_FONT *pseudo = al_load_font("../font/arial.ttf", 20, 0);
    ALLEGRO_FONT *acheter = al_load_font("../font/arial.ttf", 20, 0);
    ALLEGRO_FONT *valeurDe = al_load_font("../font/arial.ttf", 20, 0);


    int Y = 160;
    for (int i = 0; i < nbJoueurs; i++) {
        al_draw_textf(pseudo, al_map_rgb(0,0,0), 1080, Y, 0,
                      "%s %d $", tabJoueur[tabordreJoueurs[i]].nomJoueur, tabJoueur[tabordreJoueurs[i]].argentJoueur);
        Y += 30;
    }

    creerRectangle(1800, 160, 1830, 190); // rectangle lancer dé

    creerRectangleVide(1080, 0, 1880, 150, 2); //invite de commande

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
    int lancerDe1 = 0, lancerDe2 = 0, valeurLancementDe1, valeurLancementDe2, valeurDeTotale, deLance = 0;

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

        al_draw_textf(aQuiJouer, al_map_rgb(0,0,0), 1090, 5, 0,
                      "C est a %s de jouer", tabJoueur[tabordreJoueurs[indiceJoueur]].nomJoueur);

        al_draw_text(lancerDe, al_map_rgb(0,0,0), 1090, 25, 0,
                     "Lancer le de");

        al_flip_display();

        int oldx = 0;
        int oldy = 0;

        while(!deLance){
            al_get_mouse_state(&mouse_state);

            if(oldx != mouse_state.x || oldy != mouse_state.y) {
                oldx = mouse_state.x;
                oldy = mouse_state.y;
            }

            if((mouse_state.buttons & 1) == 1) { // clic gauche (2^0 : 00000001)
                if (positionSourisButtonDe(event.mouse.x, event.mouse.y)){
                    valeurLancementDe1 = randomDe(nbJoueurs);
                    valeurLancementDe2 = randomDe(nbJoueurs);
                    deLance = 1;
                    al_flip_display();
                }
            }
            /*
            if (event.type == ALLEGRO_EVENT_MOUSE_AXES) {
                if (positionSouris1(event.mouse.x, event.mouse.y)) {
                    if ((event.mouse.button & 1) == 1) {
                        deLance = 1;
                    }
                }
            }*/
        }

        verifDoubleDe(valeurLancementDe1, valeurLancementDe2, tabordreJoueurs[indiceJoueur]);

        valeurDeTotale = valeurLancementDe2 + valeurLancementDe1;

        al_draw_textf(valeurDe, al_map_rgb(0,0,0), 1090, 65, 0,
                     "Dé %d", valeurDeTotale);
        al_flip_display();

        tabParametreJoueurs[indiceJoueur].numCase = (tabParametreJoueurs[indiceJoueur].numCase + valeurDeTotale) % 32; // il y a 32 case donc on ne peut pas depasser 32
        printf("num case %d\n", tabParametreJoueurs[indiceJoueur].numCase);

        if(terrain[tabParametreJoueurs[indiceJoueur].numCase].achetable == 1 && terrain[tabParametreJoueurs[indiceJoueur].numCase].vendu == 0){
            int choix = 0;

            printf("Voulez vous acheter %s (si oui tapez 1)", terrain[tabParametreJoueurs[indiceJoueur].numCase].nomTerrain);
            scanf("%d", &choix);

            //al_draw_textf(acheter, al_map_rgb(0,0,0), 1090, 45, 0, "Voulez vous acheter %s (si oui tapez 1)", terrain[tabParametreJoueurs[indiceJoueur].numCase].nomTerrain);
            if(choix == 1){
                terrain[tabParametreJoueurs[indiceJoueur].numCase].achetable = 0;
            }
        }

        al_wait_for_event(queue, &event);

        if(joueursElimine == nbJoueurs - 1){ // condition de victoire
            winner = 1;
        }

        if(event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            winner = 1;
        }
        else if (event.type == ALLEGRO_EVENT_KEY_UP && wait == -1) {
            switch (event.keyboard.keycode) {
                case ALLEGRO_KEY_ESCAPE:
                    winner = 1;
                    break;
            }
        }

    } while(!winner);

    al_flip_display();
    al_destroy_bitmap(plateau);
    al_destroy_display(display);
    al_destroy_font(aQuiJouer);
    al_destroy_font(acheter);
    al_destroy_font(lancerDe);

    al_destroy_font(pseudo);
    al_destroy_font(valeurDe);
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
        initialisation(nbJoueurs);

        if(tabParametreJoueurs[indiceJoueur].doubleDe == 0){
            indiceJoueur++;
        }

        if(indiceJoueur >= nbJoueurs && indiceJoueur < 0){
            indiceJoueur = 0;
        }

        int numJoueur = tabJoueur[tabordreJoueurs[indiceJoueur]].numJoueur;

        printf("C est a %s de jouer\n", tabJoueur[tabordreJoueurs[indiceJoueur]].nomJoueur);

        printf("Taper 1 pour lancer le premier des : ");
        scanf("%d", &lancerDe1);

        valeurLancementDe1 = randomDe(nbJoueurs);
        printf("%d\n", valeurLancementDe1);

        printf("Taper 1 pour lancer le deuxieme des : ");
        scanf("%d", &lancerDe2);

        valeurLancementDe2 = randomDe(nbJoueurs);

        printf("%d\n", valeurLancementDe2);

        verifDoubleDe(valeurLancementDe1, valeurLancementDe2, tabordreJoueurs[indiceJoueur]);

        valeurDeTotale = valeurLancementDe2 + valeurLancementDe1;
        //printf("%d\n", valeurDeTotale);


        tabParametreJoueurs[indiceJoueur].numCase = (tabParametreJoueurs[indiceJoueur].numCase + valeurDeTotale)%32; // il y a 32 case donc on ne peut pas depasser 32
        printf("%d\n", tabParametreJoueurs[indiceJoueur].numCase);

        if(terrain[tabParametreJoueurs[indiceJoueur].numCase].achetable == 1 && terrain[tabParametreJoueurs[indiceJoueur].numCase].vendu == 0){
            int choix;

            printf("Voulez vous acheter %s (si oui tapez 1)", terrain[tabParametreJoueurs[indiceJoueur].numCase].nomTerrain);
            scanf("%d", &choix);


            if(choix == 1){
                int numCase = tabParametreJoueurs[indiceJoueur].numCase;
                terrain[numCase].vendu = 1;
                tabJoueur[tabordreJoueurs[indiceJoueur]].argentJoueur -= terrain[numCase].prix;
                terrain[numCase].proprietaire = numJoueur;
            }
        }
        else if(terrain[tabParametreJoueurs[indiceJoueur].numCase].achetable == 1 && terrain[tabParametreJoueurs[indiceJoueur].numCase].vendu == 1){
            // joueur doit payer le loyer
            int prixLoyer = testSiMaison(indiceJoueur);
            tabJoueur[tabordreJoueurs[indiceJoueur]].argentJoueur -= prixLoyer;
            tabJoueur[tabordreJoueurs[terrain[tabParametreJoueurs[indiceJoueur].numCase].proprietaire]].argentJoueur += prixLoyer;
        }
        else if(terrain[tabParametreJoueurs[indiceJoueur].numCase].taxe == 1){
            printf("%s", terrain[tabParametreJoueurs[indiceJoueur].numCase].nomTerrain);
            
            tabJoueur[tabordreJoueurs[indiceJoueur]].argentJoueur -= terrain[numJoueur].frais;
        }

        else if(terrain[tabParametreJoueurs[indiceJoueur].numCase].teleportation == 1){
            switch (tabParametreJoueurs[indiceJoueur].numCase) {
                case 4:
                    tabParametreJoueurs[indiceJoueur].numCase = 12;
                    break;
                case 12:
                    tabParametreJoueurs[indiceJoueur].numCase = 20;
                    break;
                case 20:
                    tabParametreJoueurs[indiceJoueur].numCase = 28;
                    break;
                case 28:
                    tabParametreJoueurs[indiceJoueur].numCase = 4;
                    break;

            }
        }
        
        
        
        
        if(joueursElimine == nbJoueurs - 1){ // condition de victoire
            winner = 1;
        }
    } while(!winner);
}

int testSiMaison(int indiceJoueur){
    switch (terrain[tabParametreJoueurs[indiceJoueur].numCase].numMaison) {
        case 0:
            return terrain[tabParametreJoueurs[indiceJoueur].numCase].loyer;
        case 1:
            return terrain[tabParametreJoueurs[indiceJoueur].numCase].loyer1M;
        case 2:
            return terrain[tabParametreJoueurs[indiceJoueur].numCase].loyer2M;
        case 3:
            return terrain[tabParametreJoueurs[indiceJoueur].numCase].loyer3M;
        case 4:
            return terrain[tabParametreJoueurs[indiceJoueur].numCase].loyer4M;
        case 5:
            return terrain[tabParametreJoueurs[indiceJoueur].numCase].loyer1H;
    }
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