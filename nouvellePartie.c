#include "nouvellePartie.h"

int positionSourisButtonDe(int x, int y) {
    if (x >= 1240 && x <= 1260 && y >= 10 && y <= 30) {
        return 1;
        }
    return 0;
}

int positionSourisButtonOui(int x, int y) {
    if (x >= 1240 && x <= 1260 && y >= 40 && y <= 60) {
        return 1;
    }
    return 0;
}

int positionSourisButtonNon(int x, int y) {
    if (x >= 1240 && x <= 1260 && y >= 70 && y <= 90) {
        return 1;
    }
    return 0;
}

int positionCaseDepart(int x, int y){
    if (x >= 870 && x <= 990 && y >= 590 && y <= 660) {
        return 1;
    }
    return 0;
}

void lancerNouvellePartie(){
    int nombreJoueurs = 0;
    char nomPartie[20];
    printf("Nom de la partie (20 caractere max): ");
    scanf("%s", nomPartie);
    do{
        printf("Entrez le nombre de joueurs (max 6): ");
        scanf("%d", &nombreJoueurs);
        fflush(stdout);
    }while(nombreJoueurs > 6 || nombreJoueurs < 2);

    ajouterJoueursTab(nombreJoueurs);
    randomJoueurs(nombreJoueurs, tabordreJoueurs);
    fenetreNvPartie(nombreJoueurs);
    //mainPartie(nombreJoueurs);
}

void descriptionCartes(int numCase){
    printf("Loyer $%d\n", terrain[numCase].loyer);
    printf("Avec 1 Maison $%d\n", terrain[numCase].loyer1M);
    printf("Avec 2 Maison $%d\n", terrain[numCase].loyer2M);
    printf("Avec 3 Maison $%d\n", terrain[numCase].loyer3M);
    printf("Avec 4 Maison $%d\n", terrain[numCase].loyer4M);
    printf("Avec HOTEL $%d\n", terrain[numCase].loyer1H);
    printf("Prix des maisons chacune $%d\n", terrain[numCase].prixMaison);
    printf("Prix de un hotel $%d plus 4 maisons\n", terrain[numCase].prixMaison);
    if(terrain[numCase].vendu == 1){
        printf("Proprietaire: %s\n", tabJoueur[tabordreJoueurs[terrain[numCase].proprietaire]].nomJoueur);
    } else if(terrain[numCase].vendu == 0){
        printf("Proprietaire: Banque\n");
    }
}

int fenetreNvPartie(int nbJoueurs) {

    int wait = -1, button1 = 0, button2 = 0;

    ALLEGRO_DISPLAY *display;
    ALLEGRO_KEYBOARD_STATE keyboard_state;
    ALLEGRO_MOUSE_STATE mouse_state;
    ALLEGRO_EVENT_QUEUE *queue = NULL;
    ALLEGRO_BITMAP *de = NULL;
    ALLEGRO_BITMAP *valide = NULL;
    ALLEGRO_BITMAP *refuse = NULL;

    ALLEGRO_EVENT event;
    ALLEGRO_TIMER *timer = NULL;

    timer = al_create_timer(3);

    if (!al_init()) {
        printf("Erreur initialisation");
    }

    if (!al_install_keyboard()) {
        erreur("Installation clavier");
    }

    if (!al_install_mouse()) {
        erreur("Erreur installation souris");
    }

    display = al_create_display(WIDTH_JEU, HEIGHT_JEU);

    if (!display) {
        printf("Erreur creation display");
    }

    al_set_window_position(display, 0, 0);
    al_set_window_title(display, "Monopoly");
    al_clear_to_color(al_map_rgb(255, 255, 255));

    queue = al_create_event_queue();
    if (!queue) {
        al_destroy_display(display);
        erreur("Création de l'event queue");
    }
    al_register_event_source(queue, al_get_display_event_source(display));
    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_mouse_event_source());

    al_set_target_backbuffer(display);

    de = al_load_bitmap("../images/Dé.png");
    valide = al_load_bitmap("../images/Accepté.png");
    refuse = al_load_bitmap("../images/refusé.png");


    if (!al_init_primitives_addon()) {
        printf("Erreur initialisation primitive addon\n");
    }

    if (!al_init_image_addon()) {
        printf("Erreur initialisation addon");
    }

    al_init_font_addon();
    al_init_ttf_addon();

    ALLEGRO_FONT *aQuiJouer = al_load_font("../font/Kiwi_Maru/KiwiMaru-Medium.ttf", 25, 0);
    ALLEGRO_FONT *lancerDe = al_load_font("../font/Kiwi_Maru/KiwiMaru-Medium.ttf", 25, 0);
    ALLEGRO_FONT *valeurDe = al_load_font("../font/Kiwi_Maru/KiwiMaru-Medium.ttf", 25, 0);
    ALLEGRO_FONT *info2 = al_load_font("../font/Kiwi_Maru/KiwiMaru-Medium.ttf", 20, 0);
    ALLEGRO_FONT *info3 = al_load_font("../font/Kiwi_Maru/KiwiMaru-Medium.ttf", 20, 0);
    ALLEGRO_FONT *info4 = al_load_font("../font/Kiwi_Maru/KiwiMaru-Medium.ttf", 20, 0);
    ALLEGRO_FONT *oui = al_load_font("../font/Kiwi_Maru/KiwiMaru-Medium.ttf", 20, 0);
    ALLEGRO_FONT *non = al_load_font("../font/Kiwi_Maru/KiwiMaru-Medium.ttf", 20, 0);
    ALLEGRO_FONT *descriptionCartes1 = al_load_font("../font/Kiwi_Maru/KiwiMaru-Medium.ttf", 20, 0);
    ALLEGRO_FONT *descriptionCartes2 = al_load_font("../font/Kiwi_Maru/KiwiMaru-Medium.ttf", 20, 0);
    ALLEGRO_FONT *descriptionCartes3 = al_load_font("../font/Kiwi_Maru/KiwiMaru-Medium.ttf", 20, 0);
    ALLEGRO_FONT *descriptionCartes4 = al_load_font("../font/Kiwi_Maru/KiwiMaru-Medium.ttf", 20, 0);
    ALLEGRO_FONT *descriptionCartes5 = al_load_font("../font/Kiwi_Maru/KiwiMaru-Medium.ttf", 20, 0);
    ALLEGRO_FONT *descriptionCartes6 = al_load_font("../font/Kiwi_Maru/KiwiMaru-Medium.ttf", 20, 0);
    ALLEGRO_FONT *descriptionCartes7 = al_load_font("../font/Kiwi_Maru/KiwiMaru-Medium.ttf", 20, 0);
    ALLEGRO_FONT *descriptionCartes8 = al_load_font("../font/Kiwi_Maru/KiwiMaru-Medium.ttf", 20, 0);


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

    ALLEGRO_BITMAP *case7 = NULL; // meme que la 23
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

    ALLEGRO_BITMAP *case15 = NULL; //meme que la 31
    case15 = al_load_bitmap("../images/case15_31.jpg");

    ALLEGRO_BITMAP *case16 = NULL;
    case16 = al_load_bitmap("../images/case16.jpg");

    ALLEGRO_BITMAP *case17 = NULL;
    case17 = al_load_bitmap("../images/case17.jpg");

    ALLEGRO_BITMAP *case18 = NULL;
    case18 = al_load_bitmap("../images/case18.jpg");

    ALLEGRO_BITMAP *case19 = NULL;
    case19 = al_load_bitmap("../images/case19.jpg");

    ALLEGRO_BITMAP *case20 = NULL;
    case20 = al_load_bitmap("../images/case20.jpg");

    ALLEGRO_BITMAP *case21 = NULL;
    case21 = al_load_bitmap("../images/case21.jpg");

    ALLEGRO_BITMAP *case22 = NULL;
    case22 = al_load_bitmap("../images/case22.jpg");

    ALLEGRO_BITMAP *case24 = NULL;
    case24 = al_load_bitmap("../images/case24.jpg");

    ALLEGRO_BITMAP *case25 = NULL;
    case25 = al_load_bitmap("../images/case25.jpg");

    ALLEGRO_BITMAP *case26 = NULL;
    case26 = al_load_bitmap("../images/case26.jpg");

    ALLEGRO_BITMAP *case27 = NULL;
    case27 = al_load_bitmap("../images/case27.jpg");

    ALLEGRO_BITMAP *case28 = NULL;
    case28 = al_load_bitmap("../images/case28.jpg");

    ALLEGRO_BITMAP *case29 = NULL;
    case29 = al_load_bitmap("../images/case29.jpg");

    ALLEGRO_BITMAP *case30 = NULL;
    case30 = al_load_bitmap("../images/case30.jpg");

    ALLEGRO_BITMAP *case32 = NULL;
    case32 = al_load_bitmap("../images/case32.jpg");

    ALLEGRO_BITMAP *pion1 = NULL;
    pion1 = al_load_bitmap("../images/pion1.png");

    ALLEGRO_BITMAP *pion2 = NULL;
    pion2 = al_load_bitmap("../images/pion2.png");

    ALLEGRO_BITMAP *pion3 = NULL;
    pion3 = al_load_bitmap("../images/pion3.png");

    ALLEGRO_BITMAP *pion4 = NULL;
    pion4 = al_load_bitmap("../images/pion4.png");

    ALLEGRO_BITMAP *pion5 = NULL;
    pion5 = al_load_bitmap("../images/pion5.png");

    ALLEGRO_BITMAP *pion6 = NULL;
    pion6 = al_load_bitmap("../images/pion6.png");

    int indiceJoueur = 0;
    int winner = 0, joueursElimine = 0;
    int lancerDe1 = 0, lancerDe2 = 0, valeurLancementDe1, valeurLancementDe2, valeurDeTotale;

    //initialisation tout les joueurs sur la case 0
    for(int i = 0; i < nbJoueurs; i++){
        tabParametreJoueurs[i].numCase = 0;
    }

    init_terrains(); // initialise les parametre des terrains

    initialiserCartes(indiceJoueur);

    initialisercommu();

    tabParametreJoueurs[0].pion = 0;
    tabParametreJoueurs[1].pion = 1;
    tabParametreJoueurs[2].pion = 2;
    tabParametreJoueurs[3].pion = 3;
    tabParametreJoueurs[4].pion = 4;
    tabParametreJoueurs[5].pion = 5;

    tabParametreJoueurs[tabParametreJoueurs[0].pion].pionX = 1330;
    tabParametreJoueurs[tabParametreJoueurs[0].pion].pionY = 915;

    tabParametreJoueurs[tabParametreJoueurs[1].pion].pionX = 1380;
    tabParametreJoueurs[tabParametreJoueurs[1].pion].pionY = 915;

    tabParametreJoueurs[tabParametreJoueurs[2].pion].pionX = 1330;
    tabParametreJoueurs[tabParametreJoueurs[2].pion].pionY = 943;

    tabParametreJoueurs[tabParametreJoueurs[3].pion].pionX = 1380;
    tabParametreJoueurs[tabParametreJoueurs[3].pion].pionY = 943;

    tabParametreJoueurs[tabParametreJoueurs[4].pion].pionX = 1330;
    tabParametreJoueurs[tabParametreJoueurs[4].pion].pionY = 971;

    tabParametreJoueurs[tabParametreJoueurs[5].pion].pionX = 1380;
    tabParametreJoueurs[tabParametreJoueurs[5].pion].pionY = 971;

    creerRectangle(1840, 15, 1870, 45); // rectangle lancer dé

        creerRectangle(1840, 60, 1870, 90); // boutton oui
        al_draw_text(oui, NOIR ,1840, 60, 0,"✔");
        creerRectangle(1840, 105, 1870, 135); // boutton non
        al_draw_text(non, NOIR ,1840, 105, 0,"X");
        creerRectangleVide(10, 0, 380, 1050, 2);

    creerRectangleVide(1480, 0, 1835, 1050, 2);

    al_draw_scaled_bitmap(de, 0, 0, 212, 212, 1840, 15, 25, 25, 0);
    al_draw_scaled_bitmap(valide, 0, 0, 138, 138, 1840, 60, 25, 25, 0);
    al_draw_scaled_bitmap(refuse, 0, 0, 147, 142, 1840, 105, 25, 25, 0);

    al_draw_bitmap(plateau, 400,0,0);

    switch (nbJoueurs) {
        case 2:
            al_draw_scaled_bitmap(pion1, 0, 0, 300,425, tabParametreJoueurs[0].pionX, tabParametreJoueurs[0].pionY,30,42,0);
            al_draw_scaled_bitmap(pion2, 0, 0, 300,425, tabParametreJoueurs[1].pionX, tabParametreJoueurs[1].pionY,30,42,0);
            al_flip_display();
            break;
        case 3:
            al_draw_scaled_bitmap(pion1, 0, 0, 300,425, tabParametreJoueurs[0].pionX, tabParametreJoueurs[0].pionY,30,42,0);
            al_draw_scaled_bitmap(pion2, 0, 0, 300,425, tabParametreJoueurs[1].pionX, tabParametreJoueurs[1].pionY,30,42,0);
            al_draw_scaled_bitmap(pion3, 0, 0, 300,425, tabParametreJoueurs[2].pionX, tabParametreJoueurs[2].pionY,30,42,0);
            al_flip_display();
            break;
        case 4:
            al_draw_scaled_bitmap(pion1, 0, 0, 300,425, tabParametreJoueurs[0].pionX, tabParametreJoueurs[0].pionY,30,42,0);
            al_draw_scaled_bitmap(pion2, 0, 0, 300,425, tabParametreJoueurs[1].pionX, tabParametreJoueurs[1].pionY,30,42,0);
            al_draw_scaled_bitmap(pion3, 0, 0, 300,425, tabParametreJoueurs[2].pionX, tabParametreJoueurs[2].pionY,30,42,0);
            al_draw_scaled_bitmap(pion4, 0, 0, 300,425, tabParametreJoueurs[3].pionX, tabParametreJoueurs[3].pionY,30,42,0);
            al_flip_display();
            break;
        case 5:
            al_draw_scaled_bitmap(pion1, 0, 0, 300,425, tabParametreJoueurs[0].pionX, tabParametreJoueurs[0].pionY,30,42,0);
            al_draw_scaled_bitmap(pion2, 0, 0, 300,425, tabParametreJoueurs[1].pionX, tabParametreJoueurs[1].pionY,30,42,0);
            al_draw_scaled_bitmap(pion3, 0, 0, 300,425, tabParametreJoueurs[2].pionX, tabParametreJoueurs[2].pionY,30,42,0);
            al_draw_scaled_bitmap(pion4, 0, 0, 300,425, tabParametreJoueurs[3].pionX, tabParametreJoueurs[3].pionY,30,42,0);
            al_draw_scaled_bitmap(pion5, 0, 0, 300,425, tabParametreJoueurs[4].pionX, tabParametreJoueurs[4].pionY,30,42,0);
            al_flip_display();
            break;
        case 6:
            al_draw_scaled_bitmap(pion1, 0, 0, 300,425, tabParametreJoueurs[0].pionX, tabParametreJoueurs[0].pionY,30,42,0);
            al_draw_scaled_bitmap(pion2, 0, 0, 300,425, tabParametreJoueurs[1].pionX, tabParametreJoueurs[1].pionY,30,42,0);
            al_draw_scaled_bitmap(pion3, 0, 0, 300,425, tabParametreJoueurs[2].pionX, tabParametreJoueurs[2].pionY,30,42,0);
            al_draw_scaled_bitmap(pion4, 0, 0, 300,425, tabParametreJoueurs[3].pionX, tabParametreJoueurs[3].pionY,30,42,0);
            al_draw_scaled_bitmap(pion5, 0, 0, 300,425, tabParametreJoueurs[4].pionX, tabParametreJoueurs[4].pionY,30,42,0);
            al_draw_scaled_bitmap(pion6, 0, 0, 300,425, tabParametreJoueurs[5].pionX, tabParametreJoueurs[5].pionY,30,42,0);
            al_flip_display();
            break;
    }

    do {
        al_wait_for_event(queue, &event);
        float yP = 15, yA = 40, yC = 65;
        //creerRectangleBlanc(11, 11, 301, 381);

        for (int i = 0; i < nbJoueurs; i++) {
            al_draw_textf(info2, NOIR, 15, yP, 0, "Pseudo: %s", tabJoueur[tabordreJoueurs[i]].nomJoueur);
            al_draw_textf(info3, NOIR, 15, yA, 0, "Argent: %d$", tabJoueur[tabordreJoueurs[i]].argentJoueur);
            al_draw_textf(info4, NOIR, 15, yC, 0, "Case: %d", tabParametreJoueurs[i].numCase + 1);
            yP += 85;
            yA += 85;
            yC += 85;
        }

        if (tabParametreJoueurs[indiceJoueur].prison == 1) {
            indiceJoueur = (indiceJoueur + 1) % nbJoueurs;
            tabParametreJoueurs[indiceJoueur].nbTourPrison++;
            if (tabParametreJoueurs[indiceJoueur].nbTourPrison >= 3) {
                tabParametreJoueurs[indiceJoueur].nbTourPrison = 0;
                tabParametreJoueurs[indiceJoueur].prison = 0;
            }
        }

        if (tabParametreJoueurs[indiceJoueur].elimine == 1) {
            indiceJoueur = (indiceJoueur + 1) % nbJoueurs;
            joueursElimine++;
        }

        int numJoueur = tabJoueur[tabordreJoueurs[indiceJoueur]].numJoueur;

        al_draw_textf(aQuiJouer, NOIR, 1490, 10, 0,
                      "%s à toi de jouer", tabJoueur[tabordreJoueurs[indiceJoueur]].nomJoueur);
        al_draw_text(lancerDe, NOIR, 1490, 45, 0,
                     "Lancer les dés");
        al_flip_display();


        int oldx = 0;
        int oldy = 0;
        while (button1 != 1 && button2 != 1) {
            ALLEGRO_EVENT event;
            al_wait_for_event(queue, &event);
            al_get_mouse_state(&mouse_state);

            if(event.type == ALLEGRO_EVENT_MOUSE_AXES) {
                if (positionCaseDepart(mouse_state.x, mouse_state.y)) {
                    creerRectangleBlanc(25, 600, 377, 1000);
                    al_draw_textf(descriptionCartes1, NOIR, 25, 600, 0,
                                  "Loyer $%d\n", terrain[tabParametreJoueurs[indiceJoueur].numCase].loyer);
                    al_draw_textf(descriptionCartes2, NOIR, 25, 630, 0,
                                  "Avec 1 Maison $%d\n", terrain[tabParametreJoueurs[indiceJoueur].numCase].loyer1M);
                    al_draw_textf(descriptionCartes3, NOIR, 25, 660, 0,
                                  "Avec 2 Maison $%d\n", terrain[tabParametreJoueurs[indiceJoueur].numCase].loyer2M);
                    al_draw_textf(descriptionCartes4, NOIR, 25, 690, 0,
                                  "Avec 3 Maison $%d\n", terrain[tabParametreJoueurs[indiceJoueur].numCase].loyer3M);
                    al_draw_textf(descriptionCartes5, NOIR, 25, 720, 0,
                                  "Avec 4 Maison $%d\n", terrain[tabParametreJoueurs[indiceJoueur].numCase].loyer4M);
                    al_draw_textf(descriptionCartes6, NOIR, 25, 750, 0,
                                  "Avec HOTEL $%d\n", terrain[tabParametreJoueurs[indiceJoueur].numCase].loyer1H);
                    al_draw_textf(descriptionCartes7, NOIR, 25, 780, 0,
                                  "Prix des maisons chacune $%d\n",
                                  terrain[tabParametreJoueurs[indiceJoueur].numCase].prixMaison);
                    al_draw_textf(descriptionCartes8, NOIR, 25, 810, 0,
                                  "Prix de un hotel $%d + 4M\n",
                                  terrain[tabParametreJoueurs[indiceJoueur].numCase].prixMaison);
                    al_flip_display();
                }
            }
            /*
            if(oldx != mouse_state.x || oldy != mouse_state.y) {
                oldx = mouse_state.x;
                oldy = mouse_state.y;
                printf("coordonnees de la souris : %d-%d\n", mouse_state.x, mouse_state.y);
            }*/
            if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
                if ((event.mouse.button & 1) && positionSourisButtonDe(mouse_state.x, mouse_state.y)) {
                    valeurLancementDe1 = random(7);
                    al_draw_textf(valeurDe, NOIR, 1490, 75, 0,
                                  "Dé 1 %d", valeurLancementDe1);
                    button1 = 1;
                    al_flip_display();
                }
            }

            if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
                if ((event.mouse.button & 1) && positionSourisButtonDe(mouse_state.x, mouse_state.y) && button1 == 1) {
                    valeurLancementDe2 = random(7);
                    al_draw_textf(valeurDe, NOIR, 1490, 105, 0,
                                  "%d", valeurLancementDe2);
                    button2 = 1;
                    al_flip_display();
                }
            }
        }
        verifDoubleDe(valeurLancementDe1, valeurLancementDe2, tabordreJoueurs[indiceJoueur]);

        if(tabParametreJoueurs[indiceJoueur].doubleDe == 3){
            vaPrison(indiceJoueur);
            tabParametreJoueurs[indiceJoueur].doubleDe = 0;
        }

        //valeurDeTotale = valeurLancementDe2 + valeurLancementDe1;

        valeurDeTotale = 1;

        // int numCase = tabParametreJoueurs[indiceJoueur].numCase

        al_draw_textf(valeurDe, NOIR, 1490, 105, 0,
                      "Avancez de %d cases", valeurDeTotale);
        al_flip_display();

        /*
         tabParametreJoueurs[indiceJoueur].numCase += valeurDeTotale;

        if(tabParametreJoueurs[indiceJoueur].numCase == 32){
            al_draw_text(valeurDe, NOIR, 1490, 150, 0,"Vous passez par la case départ recevez 200$");
            tabJoueur[tabordreJoueurs[indiceJoueur]].argentJoueur += 200;
            tabParametreJoueurs[indiceJoueur].numCase %= 32; // il y a 32 case donc on ne peut pas depasser 32
        }

        if (terrain[tabParametreJoueurs[indiceJoueur].numCase].teleportation == 1) {
            switch (tabParametreJoueurs[indiceJoueur].numCase) {
                case 4:
                    tabParametreJoueurs[indiceJoueur].numCase = 12;
                    valeurDeTotale += 7;
                    break;
                case 12:
                    tabParametreJoueurs[indiceJoueur].numCase = 20;
                    valeurDeTotale += 7;
                    break;
                case 20:
                    tabParametreJoueurs[indiceJoueur].numCase = 28;
                    valeurDeTotale += 7;
                    break;
                case 24:
                    tabParametreJoueurs[indiceJoueur].numCase = 8;
                    valeurDeTotale += 7;
                    break;
                case 28:
                    tabParametreJoueurs[indiceJoueur].numCase = 4;
                    valeurDeTotale += 7;
                    tabJoueur[tabordreJoueurs[indiceJoueur]].argentJoueur += 200;
                    break;
            }

            creerRectangleBlanc(680, 500, 1130, 550);
            al_draw_textf(valeurDe, NOIR, 681, 500, 0,"%s", terrain[tabParametreJoueurs[indiceJoueur].numCase].nomTerrain);
            al_flip_display();
            int choix = 0;
            while(!choix) {
                al_wait_for_event(queue, &event);
                al_get_mouse_state(&mouse_state);
                if(event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
                    if ((event.mouse.button & 1) && positionSourisButtonOui(mouse_state.x, mouse_state.y)){
                        choix = 1;
                    }
                }
            }
        }

        for(int i = 0; i < valeurDeTotale; i++){

            //if(tabParametreJoueurs[indiceJoueur].numCase == 4 || tabParametreJoueurs[indiceJoueur].numCase == 12 || tabParametreJoueurs[indiceJoueur].numCase == 20 || tabParametreJoueurs[indiceJoueur].numCase == 28 ){

            //}

            if(numCasePion == 0 || numCasePion == 7){
                tabParametreJoueurs[tabParametreJoueurs[indiceJoueur].pion].pionX -= 130;
            }
            if(numCasePion > 0 && numCasePion < 7){
                tabParametreJoueurs[tabParametreJoueurs[indiceJoueur].pion].pionX -= 104;
            }
            if(numCasePion == 8){
                tabParametreJoueurs[tabParametreJoueurs[indiceJoueur].pion].pionY -= 120;
            }
            if(numCasePion > 8 && numCasePion < 16){
                tabParametreJoueurs[tabParametreJoueurs[indiceJoueur].pion].pionY -= 120;
            }
            if(numCasePion == 16 || numCasePion == 23){
                tabParametreJoueurs[tabParametreJoueurs[indiceJoueur].pion].pionX += 130;
            }
            if(numCasePion > 16 && numCasePion < 23){
                tabParametreJoueurs[tabParametreJoueurs[indiceJoueur].pion].pionX += 105;
            }
            if(numCasePion == 24 && numCasePion == 31){
                tabParametreJoueurs[tabParametreJoueurs[indiceJoueur].pion].pionY += 40;
            }
            if(numCasePion > 24 && numCasePion < 31){
                tabParametreJoueurs[tabParametreJoueurs[indiceJoueur].pion].pionY += 30;
            }

            numCasePion += 1;

            if(tabParametreJoueurs[indiceJoueur].numCase == 32){
                al_draw_text(valeurDe, NOIR, 1490, 150, 0,"Vous passez par la case départ recevez 200$");
                tabJoueur[tabordreJoueurs[indiceJoueur]].argentJoueur += 200;
                tabParametreJoueurs[indiceJoueur].numCase %= 32; // il y a 32 case donc on ne peut pas depasser 32
            }
        }
        */

        /*
        for(int i = 0; i < valeurDeTotale; i++){

            //if(tabParametreJoueurs[indiceJoueur].numCase == 4 || tabParametreJoueurs[indiceJoueur].numCase == 12 || tabParametreJoueurs[indiceJoueur].numCase == 20 || tabParametreJoueurs[indiceJoueur].numCase == 28 ){

            //}

            if(tabParametreJoueurs[indiceJoueur].numCase == 0 || tabParametreJoueurs[indiceJoueur].numCase == 7){
                tabParametreJoueurs[tabParametreJoueurs[indiceJoueur].pion].pionX -= 130;
            }
            if(tabParametreJoueurs[indiceJoueur].numCase > 0 && tabParametreJoueurs[indiceJoueur].numCase < 7){
                tabParametreJoueurs[tabParametreJoueurs[indiceJoueur].pion].pionX -= 104;
            }
            if(tabParametreJoueurs[indiceJoueur].numCase == 8){
                tabParametreJoueurs[tabParametreJoueurs[indiceJoueur].pion].pionY -= 110;
            }
            if(tabParametreJoueurs[indiceJoueur].numCase > 8 && tabParametreJoueurs[indiceJoueur].numCase < 16){
                tabParametreJoueurs[tabParametreJoueurs[indiceJoueur].pion].pionY -= 120;
            }
            if(tabParametreJoueurs[indiceJoueur].numCase == 16 || tabParametreJoueurs[indiceJoueur].numCase == 23){
                tabParametreJoueurs[tabParametreJoueurs[indiceJoueur].pion].pionX += 130;
            }
            if(tabParametreJoueurs[indiceJoueur].numCase > 16 && tabParametreJoueurs[indiceJoueur].numCase < 23){
                tabParametreJoueurs[tabParametreJoueurs[indiceJoueur].pion].pionX += 105;
            }
            if(tabParametreJoueurs[indiceJoueur].numCase == 24 && tabParametreJoueurs[indiceJoueur].numCase == 31){
                tabParametreJoueurs[tabParametreJoueurs[indiceJoueur].pion].pionY += 40;
            }
            if(tabParametreJoueurs[indiceJoueur].numCase > 24 && tabParametreJoueurs[indiceJoueur].numCase < 31){
                tabParametreJoueurs[tabParametreJoueurs[indiceJoueur].pion].pionY += 30;
            }

            tabParametreJoueurs[indiceJoueur].numCase += 1;

            if(tabParametreJoueurs[indiceJoueur].numCase == 32){
                al_draw_text(valeurDe, NOIR, 1490, 150, 0,"Vous passez par la case départ recevez 200$");
                tabJoueur[tabordreJoueurs[indiceJoueur]].argentJoueur += 200;
                tabParametreJoueurs[indiceJoueur].numCase %= 32; // il y a 32 case donc on ne peut pas depasser 32
            }
        }
        */

        tabParametreJoueurs[indiceJoueur].numCase += valeurDeTotale;

        if(tabParametreJoueurs[indiceJoueur].numCase == 32){
            al_draw_text(valeurDe, NOIR, 1490, 150, 0,"Vous passez par la case départ recevez 200$");
            tabJoueur[tabordreJoueurs[indiceJoueur]].argentJoueur += 200;
            tabParametreJoueurs[indiceJoueur].numCase %= 32; // il y a 32 case donc on ne peut pas depasser 32
        }

        tabParametreJoueurs[tabParametreJoueurs[indiceJoueur].pion].pionX = terrain[tabParametreJoueurs[indiceJoueur].numCase].positionX;
        tabParametreJoueurs[tabParametreJoueurs[indiceJoueur].pion].pionY = terrain[tabParametreJoueurs[indiceJoueur].numCase].positionY;

        tabParametreJoueurs[tabParametreJoueurs[1].pion].pionX = terrain[tabParametreJoueurs[1].numCase].positionX + 50;

        tabParametreJoueurs[tabParametreJoueurs[2].pion].pionY = terrain[tabParametreJoueurs[2].numCase].positionY + 28;

        tabParametreJoueurs[tabParametreJoueurs[3].pion].pionX = terrain[tabParametreJoueurs[3].numCase].positionX + 50;
        tabParametreJoueurs[tabParametreJoueurs[3].pion].pionY = terrain[tabParametreJoueurs[3].numCase].positionY + 28;

        tabParametreJoueurs[tabParametreJoueurs[4].pion].pionY = terrain[tabParametreJoueurs[4].numCase].positionY + 56;

        tabParametreJoueurs[tabParametreJoueurs[5].pion].pionX = terrain[tabParametreJoueurs[5].numCase].positionX + 50;
        tabParametreJoueurs[tabParametreJoueurs[5].pion].pionY = terrain[tabParametreJoueurs[5].numCase].positionY + 56;


        float X = 1500, Y = 200;
        switch (tabParametreJoueurs[indiceJoueur].numCase) {
            case 0:
                al_draw_bitmap(case1, X, Y, 0);
                break;
            case 1:
                al_draw_bitmap(case2, X, Y, 0);
                break;
            case 2:
                al_draw_bitmap(case3, X, Y, 0);
                break;
            case 3:
                al_draw_bitmap(case4, X, Y, 0);
                break;
            case 4:
                al_draw_bitmap(case5, X, Y, 0);
                break;
            case 5:
                al_draw_bitmap(case6, X, Y, 0);
                break;
            case 6:
                al_draw_bitmap(case7, X, Y, 0);
                break;
            case 7:
                al_draw_bitmap(case8, X, Y, 0);
                break;
            case 8:
                al_draw_bitmap(case9, X, Y, 0);
                break;
            case 9:
                al_draw_bitmap(case10, X, Y, 0);
                break;
            case 10:
                al_draw_bitmap(case11, X, Y, 0);
                break;
            case 11:
                al_draw_bitmap(case12, X, Y, 0);
                break;
            case 12:
                al_draw_bitmap(case13, X, Y, 0);
                break;
            case 13:
                al_draw_bitmap(case14, X, Y, 0);
                break;
            case 14:
                al_draw_bitmap(case15, X, Y, 0);
                break;
            case 15:
                al_draw_bitmap(case16, X, Y, 0);
                break;
            case 16:
                al_draw_bitmap(case17, X, Y, 0);
                break;
            case 17:
                al_draw_bitmap(case18, X, Y, 0);
                break;
            case 18:
                al_draw_bitmap(case19, X, Y, 0);
                break;
            case 19:
                al_draw_bitmap(case20, X, Y, 0);
                break;
            case 20:
                al_draw_bitmap(case21, X, Y, 0);
                break;
            case 21:
                al_draw_bitmap(case22, X, Y, 0);
                break;
            case 22:
                al_draw_bitmap(case7, X, Y, 0);
                break;
            case 23:
                al_draw_bitmap(case24, X, Y, 0);
                break;
            case 24:
                al_draw_bitmap(case25, X, Y, 0);
                break;
            case 25:
                al_draw_bitmap(case26, X, Y, 0);
                break;
            case 26:
                al_draw_bitmap(case27, X, Y, 0);
                break;
            case 27:
                al_draw_bitmap(case28, X, Y, 0);
                break;
            case 28:
                al_draw_bitmap(case29, X, Y, 0);
                break;
            case 29:
                al_draw_bitmap(case30, X, Y, 0);
                break;
            case 30:
                al_draw_bitmap(case15, X, Y, 0);
                break;
            case 31:
                al_draw_bitmap(case32, X, Y, 0);
                break;
        }

        al_draw_bitmap(plateau, 400,0,0);

        switch (nbJoueurs) {
            case 2:
                al_draw_scaled_bitmap(pion1, 0, 0, 300,425, tabParametreJoueurs[0].pionX, tabParametreJoueurs[0].pionY,30,42,0);
                al_draw_scaled_bitmap(pion2, 0, 0, 300,425, tabParametreJoueurs[1].pionX, tabParametreJoueurs[1].pionY,30,42,0);
                al_flip_display();
                break;
            case 3:
                al_draw_scaled_bitmap(pion1, 0, 0, 300,425, tabParametreJoueurs[0].pionX, tabParametreJoueurs[0].pionY,30,42,0);
                al_draw_scaled_bitmap(pion2, 0, 0, 300,425, tabParametreJoueurs[1].pionX, tabParametreJoueurs[1].pionY,30,42,0);
                al_draw_scaled_bitmap(pion3, 0, 0, 300,425, tabParametreJoueurs[2].pionX, tabParametreJoueurs[2].pionY,30,42,0);
                al_flip_display();
                break;
            case 4:
                al_draw_scaled_bitmap(pion1, 0, 0, 300,425, tabParametreJoueurs[0].pionX, tabParametreJoueurs[0].pionY,30,42,0);
                al_draw_scaled_bitmap(pion2, 0, 0, 300,425, tabParametreJoueurs[1].pionX, tabParametreJoueurs[1].pionY,30,42,0);
                al_draw_scaled_bitmap(pion3, 0, 0, 300,425, tabParametreJoueurs[2].pionX, tabParametreJoueurs[2].pionY,30,42,0);
                al_draw_scaled_bitmap(pion4, 0, 0, 300,425, tabParametreJoueurs[3].pionX, tabParametreJoueurs[3].pionY,30,42,0);
                al_flip_display();
                break;
            case 5:
                al_draw_scaled_bitmap(pion1, 0, 0, 300,425, tabParametreJoueurs[0].pionX, tabParametreJoueurs[0].pionY,30,42,0);
                al_draw_scaled_bitmap(pion2, 0, 0, 300,425, tabParametreJoueurs[1].pionX, tabParametreJoueurs[1].pionY,30,42,0);
                al_draw_scaled_bitmap(pion3, 0, 0, 300,425, tabParametreJoueurs[2].pionX, tabParametreJoueurs[2].pionY,30,42,0);
                al_draw_scaled_bitmap(pion4, 0, 0, 300,425, tabParametreJoueurs[3].pionX, tabParametreJoueurs[3].pionY,30,42,0);
                al_draw_scaled_bitmap(pion5, 0, 0, 300,425, tabParametreJoueurs[4].pionX, tabParametreJoueurs[4].pionY,30,42,0);
                al_flip_display();
                break;
            case 6:
                al_draw_scaled_bitmap(pion1, 0, 0, 300,425, tabParametreJoueurs[0].pionX, tabParametreJoueurs[0].pionY,30,42,0);
                al_draw_scaled_bitmap(pion2, 0, 0, 300,425, tabParametreJoueurs[1].pionX, tabParametreJoueurs[1].pionY,30,42,0);
                al_draw_scaled_bitmap(pion3, 0, 0, 300,425, tabParametreJoueurs[2].pionX, tabParametreJoueurs[2].pionY,30,42,0);
                al_draw_scaled_bitmap(pion4, 0, 0, 300,425, tabParametreJoueurs[3].pionX, tabParametreJoueurs[3].pionY,30,42,0);
                al_draw_scaled_bitmap(pion5, 0, 0, 300,425, tabParametreJoueurs[4].pionX, tabParametreJoueurs[4].pionY,30,42,0);
                al_draw_scaled_bitmap(pion6, 0, 0, 300,425, tabParametreJoueurs[5].pionX, tabParametreJoueurs[5].pionY,30,42,0);
                al_flip_display();
                break;
        }

        if (terrain[tabParametreJoueurs[indiceJoueur].numCase].carteChance == 1){
            cartechance(indiceJoueur, nbJoueurs);
        }

        if (terrain[tabParametreJoueurs[indiceJoueur].numCase].carteCommunaute == 1){
            cartecommu(indiceJoueur, nbJoueurs);
        }

        if(terrain[tabParametreJoueurs[indiceJoueur].numCase].achetable == 1 && terrain[tabParametreJoueurs[indiceJoueur].numCase].vendu == 1){
            // joueur doit payer le loyer
            int prixLoyer = testSiMaison(indiceJoueur);
            creerRectangleBlanc(680, 500, 1130, 550);
            al_draw_textf(valeurDe, NOIR, 681, 500, 0,
                          "Vous devez payer un loyer a %s\n", tabJoueur[tabordreJoueurs[terrain[tabParametreJoueurs[indiceJoueur].numCase].proprietaire]].nomJoueur);
            al_flip_display();
            //si le propriétaire possede les 2 cartes loyer nu double
            if(terrain[tabParametreJoueurs[indiceJoueur].numCase].proprietaire == terrain[tabParametreJoueurs[indiceJoueur].numCase + 2].proprietaire || terrain[tabParametreJoueurs[indiceJoueur].numCase].proprietaire == terrain[tabParametreJoueurs[indiceJoueur].numCase - 2].proprietaire && terrain[tabParametreJoueurs[indiceJoueur].numCase].numMaison == 0){
                tabJoueur[tabordreJoueurs[indiceJoueur]].argentJoueur -= prixLoyer * 2;
                tabJoueur[tabordreJoueurs[terrain[tabParametreJoueurs[indiceJoueur].numCase].proprietaire]].argentJoueur += prixLoyer * 2;
            }
            else{
                tabJoueur[tabordreJoueurs[indiceJoueur]].argentJoueur -= prixLoyer;
                tabJoueur[tabordreJoueurs[terrain[tabParametreJoueurs[indiceJoueur].numCase].proprietaire]].argentJoueur += prixLoyer;
            }
            int choix = 0;
            while(!choix) {
                al_wait_for_event(queue, &event);
                al_get_mouse_state(&mouse_state);
                if(event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
                    if ((event.mouse.button & 1) && positionSourisButtonOui(mouse_state.x, mouse_state.y)){
                        choix = 1;
                    }
                    if ((event.mouse.button & 1) && positionSourisButtonNon(mouse_state.x, mouse_state.y)){
                        tabParametreJoueurs[indiceJoueur].elimine = 1;
                        choix = 1;
                    }
                }
            }
        }

        if(terrain[tabParametreJoueurs[indiceJoueur].numCase].achetable == 1 && terrain[tabParametreJoueurs[indiceJoueur].numCase].vendu == 0){
            int choix = 0;
            creerRectangleBlanc(680, 500, 1130, 550);
            al_draw_textf(valeurDe, NOIR, 681, 500, 0,
                          "Voulez vous acheter %s", terrain[tabParametreJoueurs[indiceJoueur].numCase].nomTerrain);
            al_flip_display();
            while(!choix) {
                al_wait_for_event(queue, &event);
                al_get_mouse_state(&mouse_state);
                if(event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
                    if ((event.mouse.button & 1) && positionSourisButtonOui(mouse_state.x, mouse_state.y)){
                        terrain[tabParametreJoueurs[indiceJoueur].numCase].vendu = 1;
                        tabJoueur[tabordreJoueurs[indiceJoueur]].argentJoueur -= terrain[tabParametreJoueurs[indiceJoueur].numCase].prix;
                        terrain[tabParametreJoueurs[indiceJoueur].numCase].proprietaire = numJoueur;
                        choix = 1;
                    }
                    if ((event.mouse.button & 1) && positionSourisButtonNon(mouse_state.x, mouse_state.y)){
                        choix = 1;
                    }
                }
            }
        }

        if(terrain[tabParametreJoueurs[indiceJoueur].numCase].taxe == 1){
            creerRectangleBlanc(680, 500, 1130, 550);
            al_draw_textf(valeurDe, NOIR, 681, 500, 0,"%s", terrain[tabParametreJoueurs[indiceJoueur].numCase].nomTerrain);
            al_flip_display();
            tabJoueur[tabordreJoueurs[indiceJoueur]].argentJoueur -= terrain[tabParametreJoueurs[indiceJoueur].numCase].frais;
            int choix = 0;
            while(!choix) {
                al_wait_for_event(queue, &event);
                al_get_mouse_state(&mouse_state);
                if(event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
                    if ((event.mouse.button & 1) && positionSourisButtonOui(mouse_state.x, mouse_state.y)){
                        choix = 1;
                    }
                    if ((event.mouse.button & 1) && positionSourisButtonNon(mouse_state.x, mouse_state.y)){
                        tabParametreJoueurs[indiceJoueur].elimine = 1;
                    }
                }
            }
        }

        if(tabParametreJoueurs[indiceJoueur].numCase == 26){
            creerRectangleBlanc(680, 500, 1130, 550);
            al_draw_textf(valeurDe, NOIR, 681, 500, 0,"%s", terrain[tabParametreJoueurs[indiceJoueur].numCase].nomTerrain);
            al_flip_display();
            tabJoueur[tabordreJoueurs[indiceJoueur]].argentJoueur += terrain[26].frais;
            int choix = 0;
            while(!choix) {
                al_wait_for_event(queue, &event);
                al_get_mouse_state(&mouse_state);
                if(event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
                    if ((event.mouse.button & 1) && positionSourisButtonOui(mouse_state.x, mouse_state.y)){
                        choix = 1;
                    }
                    if ((event.mouse.button & 1) && positionSourisButtonNon(mouse_state.x, mouse_state.y)){
                        tabParametreJoueurs[indiceJoueur].elimine = 1;
                    }
                }
            }
        }

        if (terrain[tabParametreJoueurs[indiceJoueur].numCase].teleportation == 1) {
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
                case 24:
                    tabParametreJoueurs[indiceJoueur].numCase = 8;
                    break;
                case 28:
                    tabParametreJoueurs[indiceJoueur].numCase = 4;
                    tabJoueur[tabordreJoueurs[indiceJoueur]].argentJoueur += 200;
                    break;
            }

            creerRectangleBlanc(680, 500, 1130, 550);
            al_draw_textf(valeurDe, NOIR, 681, 500, 0,"%s", terrain[tabParametreJoueurs[indiceJoueur].numCase].nomTerrain);
            al_flip_display();
            int choix = 0;
            while(!choix) {
                al_wait_for_event(queue, &event);
                al_get_mouse_state(&mouse_state);
                if(event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
                    if ((event.mouse.button & 1) && positionSourisButtonOui(mouse_state.x, mouse_state.y)){
                        choix = 1;
                    }
                }
            }
        }

        if(tabParametreJoueurs[indiceJoueur].doubleDe == 0){
            indiceJoueur = (indiceJoueur + 1) % nbJoueurs;
        }

        creerRectangleBlanc(0,0,1920,1080);

        creerRectangle(1840, 15, 1870, 45); // rectangle lancer dé

        creerRectangle(1840, 60, 1870, 90); // boutton oui
        al_draw_text(oui, NOIR ,1840, 60, 0,"OK");

        creerRectangle(1840, 105, 1870, 135); // boutton non
        al_draw_text(non, NOIR ,1840, 105, 0,"X");

        creerRectangleVide(10, 0, 380, 1050, 2);

        creerRectangleVide(1480, 0, 1835, 1050, 2);

        al_draw_bitmap(plateau, 400,0,0);

        switch (nbJoueurs) {
            case 2:
                al_draw_scaled_bitmap(pion1, 0, 0, 300,425, tabParametreJoueurs[0].pionX, tabParametreJoueurs[0].pionY,30,42,0);
                al_draw_scaled_bitmap(pion2, 0, 0, 300,425, tabParametreJoueurs[1].pionX, tabParametreJoueurs[1].pionY,30,42,0);
                al_flip_display();
                break;
            case 3:
                al_draw_scaled_bitmap(pion1, 0, 0, 300,425, tabParametreJoueurs[0].pionX, tabParametreJoueurs[0].pionY,30,42,0);
                al_draw_scaled_bitmap(pion2, 0, 0, 300,425, tabParametreJoueurs[1].pionX, tabParametreJoueurs[1].pionY,30,42,0);
                al_draw_scaled_bitmap(pion3, 0, 0, 300,425, tabParametreJoueurs[2].pionX, tabParametreJoueurs[2].pionY,30,42,0);
                al_flip_display();
                break;
            case 4:
                al_draw_scaled_bitmap(pion1, 0, 0, 300,425, tabParametreJoueurs[0].pionX, tabParametreJoueurs[0].pionY,30,42,0);
                al_draw_scaled_bitmap(pion2, 0, 0, 300,425, tabParametreJoueurs[1].pionX, tabParametreJoueurs[1].pionY,30,42,0);
                al_draw_scaled_bitmap(pion3, 0, 0, 300,425, tabParametreJoueurs[2].pionX, tabParametreJoueurs[2].pionY,30,42,0);
                al_draw_scaled_bitmap(pion4, 0, 0, 300,425, tabParametreJoueurs[3].pionX, tabParametreJoueurs[3].pionY,30,42,0);
                al_flip_display();
                break;
            case 5:
                al_draw_scaled_bitmap(pion1, 0, 0, 300,425, tabParametreJoueurs[0].pionX, tabParametreJoueurs[0].pionY,30,42,0);
                al_draw_scaled_bitmap(pion2, 0, 0, 300,425, tabParametreJoueurs[1].pionX, tabParametreJoueurs[1].pionY,30,42,0);
                al_draw_scaled_bitmap(pion3, 0, 0, 300,425, tabParametreJoueurs[2].pionX, tabParametreJoueurs[2].pionY,30,42,0);
                al_draw_scaled_bitmap(pion4, 0, 0, 300,425, tabParametreJoueurs[3].pionX, tabParametreJoueurs[3].pionY,30,42,0);
                al_draw_scaled_bitmap(pion5, 0, 0, 300,425, tabParametreJoueurs[4].pionX, tabParametreJoueurs[4].pionY,30,42,0);
                al_flip_display();
                break;
            case 6:
                al_draw_scaled_bitmap(pion1, 0, 0, 300,425, tabParametreJoueurs[0].pionX, tabParametreJoueurs[0].pionY,30,42,0);
                al_draw_scaled_bitmap(pion2, 0, 0, 300,425, tabParametreJoueurs[1].pionX, tabParametreJoueurs[1].pionY,30,42,0);
                al_draw_scaled_bitmap(pion3, 0, 0, 300,425, tabParametreJoueurs[2].pionX, tabParametreJoueurs[2].pionY,30,42,0);
                al_draw_scaled_bitmap(pion4, 0, 0, 300,425, tabParametreJoueurs[3].pionX, tabParametreJoueurs[3].pionY,30,42,0);
                al_draw_scaled_bitmap(pion5, 0, 0, 300,425, tabParametreJoueurs[4].pionX, tabParametreJoueurs[4].pionY,30,42,0);
                al_draw_scaled_bitmap(pion6, 0, 0, 300,425, tabParametreJoueurs[5].pionX, tabParametreJoueurs[5].pionY,30,42,0);
                al_flip_display();
                break;
        }

        if (joueursElimine == nbJoueurs - 1) { // condition de victoire
            winner = 1;
        }

        if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            winner = 1;
        } else if (event.type == ALLEGRO_EVENT_KEY_UP && wait == -1) {
            switch (event.keyboard.keycode) {
                case ALLEGRO_KEY_ESCAPE:
                    winner = 1;
                    break;
            }
        }

    } while (!winner);
    al_destroy_bitmap(plateau);
    al_destroy_event_queue(queue);
    al_destroy_display(display);
    al_destroy_font(aQuiJouer);
    al_destroy_font(lancerDe);
    al_destroy_font(descriptionCartes1);
    al_destroy_font(descriptionCartes2);
    al_destroy_font(descriptionCartes3);
    al_destroy_font(descriptionCartes4);
    al_destroy_font(descriptionCartes5);
    al_destroy_font(descriptionCartes6);
    al_destroy_font(descriptionCartes7);
    al_destroy_font(descriptionCartes8);
    al_destroy_font(valeurDe);
}


void ajouterJoueur(int i){
    printf("Entrez le pseudo du joueur %d:\n ", i + 1);
    scanf("%s", tabJoueur[i].nomJoueur);
    tabJoueur[i].argentJoueur = 1500; // argent initiale du joueur
    tabJoueur[i].numJoueur = i; // on affecte le num 0 au joueur 1, ect...
}

void  ajouterJoueursTab(int taille_logique){
    Joueur parametreJ;
    for(int i = 0; i < taille_logique; i++){
        ajouterJoueur(i);
    }
}

void afficherRegle(){
    printf("Regles :\n"
           "\n"
           "Debut :\n"
           "-\tChaque joueur dispose de 1500 € chacun \n"
           "-\tLa banque à un fond illimite et elle fera toutes les transactions autres qu’entre les joueurs comme avec les cartes ou l’achat de terrain\n"
           "-\tChaque fois qu’un joueur passe par la case depart, il reçoit 200 €\n"
           "-\tSi un joueur passe par cette case avec le lancer de de et qu’il atterrit sur une case carte lui ordonnant d’aller à une autre case et qu’il repasse par la case depart, alors il reçoit  deux fois 200 € de la part de la banque\n"
           "-\tObjectif est que tous les autres joueurs soient faillite \n"
           "De :\n"
           "-\tSi vous faites un double-double, avancer du nombre case et relancer les des\n"
           "-\tOr si cela arrive 3 fois d’affilé, vous allez directement en prison\n"
           "Entree de Prison :\n"
           "-\tPeu importe où il se trouve, il ne recevra pas les 200 € de la case depart\n"
           "-\tSi vous faites 3 doubles-doubles d’affiles\n"
           "-\tSi vous piochez une carte « Aller en prison »\n"
           "-\tSi vous arrivez sur la case 25 (case 9 = visite de la prison)\n"
           "Sortir de Prison :\n"
           "-\tJoueur peut acheter ou vendre même si le joueur est en prison\n"
           "-\tFaire un double-double dans ses 3 prochains tours (même si double-double, il ne rejoue pas)\n"
           "-\tUtilise sa carte « sortir de prison » en l’obtenant ou en l’achetant à un autre joueur\n"
           "-\tPayez 50 € à la banque\n"
           "-\tPayez 50 € si après les 3 tours tentant de faire un double-double, cela est un echec\n"
           "Propriete :\n"
           "-\tLorsque vous arrivez sur une case avec une propriete, des informations affichent avec son prix d’achat mais aussi le prix de loyer\n"
           "-\tVous pouvez acheter la propriété si elle n’est pas acheter au prix indique\n"
           "-\tSi elle est déjà prise par un autre joueur, alors vous devez lui donner le montant indique. Attention, si de l’immobilier est dessus alors le loyer devient plus couteux\n"
           "-\tOn peut revendre sa propriété à la banque à la moitié de son prix acheté\n"
           "Immobiliers (maisons et hôtels) :\n"
           "-\tVous pouvez acheter des maisons et des hôtels lorsque vous le voulez lors de la partie\n"
           "-\tLorsque le propriétaire à 4 maisons sur une même propriété, il peut le remplacer par un hôtel. Attention toutefois, on peut mettre qu’un hôtel sur une même propriété\n"
           "Hypothèque :\n"
           "-\tUn joueur peut hypothéquer une propriété à la banque si elle n’est pas améliorer c’est-à-dire sans bien immobilier dessus. S’il y a des bâtiments, il faut donc les revendre à moitié prix avant d’hypothéquer\n"
           "-\tAucun loyer ne peut être perçu si la propriété est hypothéquée\n"
           "-\tUn autre joueur peut acheter ce bien hypothéqué mais il le récupère avec son hypothèque. Ainsi, il y a 3 possibilités : \n"
           "1.\til lève tout de suite l’hypothèque en ajoutant 10 % en plus\n"
           "2.\ts’il ne la lève pas directement, il doit payer un intérêt de 10 % à la banque\n"
           "3.\ts’il la lève plus tard, il doit payer l’intérêt et additionner avec le prix de l’hypothèque\n"
           "Faillites d’un joueur :\n"
           "-\tUn joueur est en faillite lorsqu’il ne peut plus payer certaines contraintes comme la pioche d’une carte lui demandant de payer à la banque des frais\n"
           "-\tIl doit revendre tous ses biens immobiliers à moitié prix \n"
           "-\tAinsi le jeu est terminé pour ce joueur qui sort du jeu\n"
           "-\tLorsqu’il ne reste plus qu’un joueur qui n’a pas fait faillite, il est alors le gagnant de la partie");
}

void afficherNomMembresProjet(){
    printf("Membres du projet:\n"
           "Erwan\n"
           "Theo\n"
           "Lucas\n"
           "Constantin");
}

int randomJoueurs(int nbJoueurs, int tabordreJoueurs[NOMBRE_MAX_JOUEURS]){ //fonction pour melanger l'ordre des joueurs
    int random;
    for(int h = 0; h < NOMBRE_MAX_JOUEURS; h++){
        tabordreJoueurs[h] = 7;
    }
    srand(time(NULL));
    for (int i = 0; i < nbJoueurs; i++) {
        int ok = 0;
        int validation = 0;
        do{
            random = rand() % (nbJoueurs);
            for (int j = 0; j < nbJoueurs; j++){
                if(random != tabordreJoueurs[j]){
                    validation += 1;
                }
            }
            if(validation == nbJoueurs){
                ok = 1;
            }
            else{
                validation = 0;
            }
        } while(ok != 1);
        tabordreJoueurs[i] = random;
    }
}

void printf_center (const char* str)
{
    unsigned int n;
    for (n = 0; n < (LARGEUR_CONSOLE-strlen(str)) / 2; n++)
    {
        putchar(' ');
    }
    printf("%s", str);
} //fonction pour centrer du texte sur la console

void mainPartie(int nbJoueurs){
    int indiceJoueur = 0;
    int winner = 0, joueursElimine = 0;
    int lancerDe1 = 0, lancerDe2 = 0, valeurLancementDe1, valeurLancementDe2, valeurDeTotale;

    //initialisation tout les joueurs sur la case 0
    for(int i = 0; i < nbJoueurs; i++){
        tabParametreJoueurs[i].numCase = 0;
    }

    init_terrains(); // initialise les parametre des terrains

    initialiserCartes(indiceJoueur);
    initialisercommu();

    do{
        initialisation(nbJoueurs);

        if(tabParametreJoueurs[indiceJoueur].prison == 1){
            indiceJoueur = (indiceJoueur + 1) % nbJoueurs;
            tabParametreJoueurs[indiceJoueur].nbTourPrison++;
            if(tabParametreJoueurs[indiceJoueur].nbTourPrison >= 3){
                tabParametreJoueurs[indiceJoueur].nbTourPrison = 0;
                tabParametreJoueurs[indiceJoueur].prison = 0;
            }
        }

        if(indiceJoueur >= nbJoueurs && indiceJoueur < 0){
            indiceJoueur = 0;
        }

        int numJoueur = tabJoueur[tabordreJoueurs[indiceJoueur]].numJoueur;

        printf("\nC est a %s de jouer\n", tabJoueur[tabordreJoueurs[indiceJoueur]].nomJoueur);

        printf("Si vous souhaitez acceder au menu tapez 0\n");
        printf("Taper 1 pour lancer le premier des : ");
        scanf("%d", &lancerDe1);

        if(lancerDe1 == 0){
            menuPrincipale();
        }
        else {
            valeurLancementDe1 = random(7);//618 550 931 582
            printf("De 1: %d\n", valeurLancementDe1);

            printf("Taper 1 pour lancer le deuxieme des : ");
            scanf("%d", &lancerDe2);

            valeurLancementDe2 = random(7);
            printf("De 2: %d\n", valeurLancementDe2);

        }

        verifDoubleDe(valeurLancementDe1, valeurLancementDe2, indiceJoueur);

        valeurDeTotale = valeurLancementDe2 + valeurLancementDe1;

        printf("Nombre de: %d\n", valeurDeTotale );

        if(tabParametreJoueurs[indiceJoueur].doubleDe == 3){
            vaPrison(indiceJoueur);
            tabParametreJoueurs[indiceJoueur].doubleDe = 0;
        }

        tabParametreJoueurs[indiceJoueur].numCase += valeurDeTotale;

        if(tabParametreJoueurs[indiceJoueur].numCase >= 32){
            printf("Vous passez par la case depart recevez 200$\n");
            tabJoueur[tabordreJoueurs[indiceJoueur]].argentJoueur += 200;
            tabParametreJoueurs[indiceJoueur].numCase %= 32; // il y a 32 case donc on ne peut pas depasser 32
        }

        printf("\n%s\n",terrain[tabParametreJoueurs[indiceJoueur].numCase].nomTerrain);

        if(terrain[tabParametreJoueurs[indiceJoueur].numCase].achetable == 1 && terrain[tabParametreJoueurs[indiceJoueur].numCase].vendu == 0){
            descriptionCartes(tabParametreJoueurs[indiceJoueur].numCase);
            int choix;
            printf("Voulez vous acheter %s (si oui tapez 1)", terrain[tabParametreJoueurs[indiceJoueur].numCase].nomTerrain);
            scanf("%d", &choix);


            if(choix == 1){
                terrain[tabParametreJoueurs[indiceJoueur].numCase].vendu = 1;
                tabJoueur[tabordreJoueurs[indiceJoueur]].argentJoueur -= terrain[tabParametreJoueurs[indiceJoueur].numCase].prix;
                terrain[tabParametreJoueurs[indiceJoueur].numCase].proprietaire = numJoueur;
            }
        }
        if(terrain[tabParametreJoueurs[indiceJoueur].numCase].achetable == 1 && terrain[tabParametreJoueurs[indiceJoueur].numCase].vendu == 1){
            // joueur doit payer le loyer
            int prixLoyer = testSiMaison(indiceJoueur);
            printf("Vous devez payer un loyer a %s\n", tabJoueur[tabordreJoueurs[terrain[tabParametreJoueurs[indiceJoueur].numCase].proprietaire]].nomJoueur);
            //si le propriétaire pocède les 2 cartes loyer nu double
            if(terrain[tabParametreJoueurs[indiceJoueur].numCase].proprietaire == terrain[tabParametreJoueurs[indiceJoueur].numCase + 2].proprietaire || terrain[tabParametreJoueurs[indiceJoueur].numCase].proprietaire == terrain[tabParametreJoueurs[indiceJoueur].numCase - 2].proprietaire && terrain[tabParametreJoueurs[indiceJoueur].numCase].numMaison == 0){
                tabJoueur[tabordreJoueurs[indiceJoueur]].argentJoueur -= prixLoyer * 2;
                tabJoueur[tabordreJoueurs[terrain[tabParametreJoueurs[indiceJoueur].numCase].proprietaire]].argentJoueur += prixLoyer * 2;
            }
            else{
                tabJoueur[tabordreJoueurs[indiceJoueur]].argentJoueur -= prixLoyer;
                tabJoueur[tabordreJoueurs[terrain[tabParametreJoueurs[indiceJoueur].numCase].proprietaire]].argentJoueur += prixLoyer;
            }
        }
        if(terrain[tabParametreJoueurs[indiceJoueur].numCase].taxe == 1){
            int choix;
            printf("TAPEZ 1 POUR PAYER\n");
            scanf("%d", &choix);
            tabJoueur[tabordreJoueurs[indiceJoueur]].argentJoueur -= terrain[tabParametreJoueurs[indiceJoueur].numCase].frais;
        }

        if(tabParametreJoueurs[indiceJoueur].numCase == 26){
            tabJoueur[tabordreJoueurs[indiceJoueur]].argentJoueur += terrain[26].frais;
        }

        if (terrain[tabParametreJoueurs[indiceJoueur].numCase].teleportation == 1) {
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
                case 24:
                    tabParametreJoueurs[indiceJoueur].numCase = 8;
                    break;
                case 28:
                    tabParametreJoueurs[indiceJoueur].numCase = 4;
                    break;
            }
        }

        if (terrain[tabParametreJoueurs[indiceJoueur].numCase].carteChance == 1){
            cartechance(indiceJoueur, nbJoueurs);
        }

        if (terrain[tabParametreJoueurs[indiceJoueur].numCase].carteCommunaute == 1){
            cartecommu(indiceJoueur, nbJoueurs);
        }

        if(tabParametreJoueurs[indiceJoueur].doubleDe == 0){
            indiceJoueur = (indiceJoueur + 1) % nbJoueurs;
        }

        if (joueursElimine == nbJoueurs - 1) { // condition de victoire
            winner = 1;
        }
    } while(!winner);
}

void vaPrison(int indiceJoueur){
    tabParametreJoueurs[indiceJoueur].prison = 1;
    tabParametreJoueurs[indiceJoueur].numCase = 8;
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

int random(int nb){
    srand(time(NULL));
    int numRand = 0;
    do{
        for(int i = 0; i < 10; i++){
            numRand = rand() % nb;
        }
    }while(numRand == 0);

    return numRand;
}

void initialisation(int nbJoueurs){
    printf("------------------------------------------------Initialisation-----------------------------------------\n");
    for (int i = 0; i < nbJoueurs; i++) {
        printf("Joueur: %d Pseudo: %s Argent: %d$ Case: %d\n",
               i + 1,
               tabJoueur[tabordreJoueurs[i]].nomJoueur,
               tabJoueur[tabordreJoueurs[i]].argentJoueur,
               tabParametreJoueurs[i].numCase + 1);
    }
} // afficher dans la console les parametre des joueurs

void verifDoubleDe(int de1, int de2, int indiceJoueur) {
    if(de1 == de2){
        tabParametreJoueurs[indiceJoueur].doubleDe++;
        printf("double\n");
    }

    else if(de1 != de2){
        tabParametreJoueurs[indiceJoueur].doubleDe = 0;
    }
}

int quitter(){
    exit(EXIT_SUCCESS);
}