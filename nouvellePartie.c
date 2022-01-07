#include "nouvellePartie.h"

unsigned char positionSourisButtonDe(int x, int y) {
    if (x >= 1800 && x <= 1830 && y >= 160 && y <= 190) {
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
    //fenetreNvPartie(nombreJoueurs);
    mainPartie(nombreJoueurs);
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

int fenetreNvPartie(int nbJoueurs){

    int wait = -1;

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



            if((mouse_state.buttons & 1) == 1) { // clic gauche (2^0 : 00000001)
                if (positionSourisButtonDe(event.mouse.x, event.mouse.y)){
                    valeurLancementDe1 = random(7);
                    valeurLancementDe2 = random(7);
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


void ajouterJoueur(int i){
    printf("Entrez le pseudo du joueur %d: ", i + 1);
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
// texte avec la mise en forme pour afficher les règles du monopoly
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
        fflush(stdout);

        printf("Si vous souhaitez acceder au menu tapez 0\n");
        printf("Taper 1 pour lancer le ptabJoueur[tabordreJoueurs[indiceJoueur]].numJoueurremier des : ");
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

        verifDoubleDe(valeurLancementDe1, valeurLancementDe2, tabordreJoueurs[indiceJoueur]);

        valeurDeTotale = valeurLancementDe2 + valeurLancementDe1;

        printf("Nombre de: %d\n", valeurDeTotale );

        if(tabParametreJoueurs[indiceJoueur].doubleDe == 3){
            vaPrison(indiceJoueur);
        }

        tabParametreJoueurs[indiceJoueur].numCase += valeurDeTotale;

        if(tabParametreJoueurs[indiceJoueur].numCase >= 32){
            printf("Vous passez par la case depart recevez 200$\n");
            tabJoueur[tabordreJoueurs[indiceJoueur]].argentJoueur += 200;
            tabParametreJoueurs[indiceJoueur].numCase %= 32; // il y a 32 case donc on ne peut pas depasser 32
        }

        printf("%s\n",terrain[tabParametreJoueurs[indiceJoueur].numCase].nomTerrain);

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
            printf("Vous devez payer un loyer a %s", tabJoueur[tabordreJoueurs[terrain[tabParametreJoueurs[indiceJoueur].numCase].proprietaire]].nomJoueur);
            int prixLoyer = testSiMaison(indiceJoueur);
            tabJoueur[tabordreJoueurs[indiceJoueur]].argentJoueur -= prixLoyer;
            tabJoueur[tabordreJoueurs[terrain[tabParametreJoueurs[indiceJoueur].numCase].proprietaire]].argentJoueur += prixLoyer;
        }
        if(terrain[tabParametreJoueurs[indiceJoueur].numCase].taxe == 1){
            int choix;
            printf("TAPEZ 1 POUR PAYER\n");
            scanf("%d", &choix);
            tabJoueur[tabordreJoueurs[indiceJoueur]].argentJoueur -= terrain[tabParametreJoueurs[indiceJoueur].numCase].frais;//marche pas
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
    if (tabParametreJoueurs[indiceJoueur].cartePrison == tabJoueur[tabordreJoueurs[indiceJoueur]].numJoueur ){
        int choix;
        printf("voulez vous jouez votre carte sortior de prison (1 oui)");
        scanf("%d",&choix);
        if (choix == 0){
            tabParametreJoueurs[indiceJoueur].prison = 1;
        }
        if (choix == 1){
            tabParametreJoueurs[indiceJoueur].prison = 0;
            tabParametreJoueurs[indiceJoueur].cartePrison = 7;
        }
    }

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
        printf("Joueur: %d Pseudo: %s Argent: %d$ Case: %d\n",
               i + 1,
               tabJoueur[tabordreJoueurs[i]].nomJoueur,
               tabJoueur[tabordreJoueurs[i]].argentJoueur,
               tabParametreJoueurs[i].numCase + 1);
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

int quitter(){
    exit(EXIT_SUCCESS);
}