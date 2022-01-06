
#include "chance.h"

void initialiserCartes(){
    strcpy(parametreCartes[1].nomcarte, "aller en prison");
    strcpy(parametreCartes[2].nomcarte, "aller avenue Henri-Martin");
    strcpy(parametreCartes[3].nomcarte, "aller Boulevard de la villette");
    strcpy(parametreCartes[4].nomcarte, "aller Rue de la paix");
    strcpy(parametreCartes[5].nomcarte, "aller a la gare de lyon");
    strcpy(parametreCartes[6].nomcarte, "aller a la case depart");
    strcpy(parametreCartes[7].nomcarte, "Reculez de trois case");
    strcpy(parametreCartes[8].nomcarte, "sortez de prison");
    strcpy(parametreCartes[9].nomcarte, "payer 50 a la banque");
    strcpy(parametreCartes[10].nomcarte, "Ressevez 100");
    strcpy(parametreCartes[11].nomcarte, "payer 200");
    strcpy(parametreCartes[12].nomcarte, "Ressevez 200");
    strcpy(parametreCartes[13].nomcarte, "c'est votre anniversaire ressevez 20 de chaque joueur");
    strcpy(parametreCartes[14].nomcarte, "payer 10 pour chaque maison et 20 pour chauque hotel");
    strcpy(parametreCartes[15].nomcarte, "payer 50");
    strcpy(parametreCartes[16].nomcarte, "ressevez 50");
}

int cartechance (int indiceJoueur, int nbJoueurs){

    int carte = random(16);

    switch (carte) {
        case 1:{
            printf("%s", parametreCartes[carte].nomcarte);
            tabParametreJoueurs[indiceJoueur].numCase = 8;
        }break;
        case 2:{
            printf("%s", parametreCartes[carte].nomcarte);
            tabParametreJoueurs[indiceJoueur].numCase = 23;
        }break;
        case 3:{
            printf("%s", parametreCartes[carte].nomcarte);
            tabParametreJoueurs[indiceJoueur].numCase = 9;
        }break;
        case 4:{
            printf("%s", parametreCartes[carte].nomcarte);
            tabParametreJoueurs[indiceJoueur].numCase = 31;
        }break;
        case 5:{
            printf("%s", parametreCartes[carte].nomcarte);
            tabParametreJoueurs[indiceJoueur].numCase = 15;
        }break;
        case 6:{
            printf("%s", parametreCartes[carte].nomcarte);
            tabParametreJoueurs[indiceJoueur].numCase = 0;
        }break;
        case 7:{
            printf("%s", parametreCartes[carte].nomcarte);
            tabParametreJoueurs[indiceJoueur].numCase = tabParametreJoueurs[indiceJoueur].numCase - 3;
        }break;
        case 8:{
            printf("sortez de prison");
        }break;
        case 9:{
            printf("%s", parametreCartes[carte].nomcarte);
            tabJoueur[tabordreJoueurs[indiceJoueur]].argentJoueur -= 50;
        }break;
        case 10:{
            printf("%s", parametreCartes[carte].nomcarte);
            tabJoueur[tabordreJoueurs[indiceJoueur]].argentJoueur += 100;

        }break;
        case 11:{
            printf("%s", parametreCartes[carte].nomcarte);
            tabJoueur[tabordreJoueurs[indiceJoueur]].argentJoueur -= 200;
        }break;
        case 12:{
            printf("%s", parametreCartes[carte].nomcarte);
            tabJoueur[tabordreJoueurs[indiceJoueur]].argentJoueur += 200;
        }break;
        case 13:{
            printf("%s", parametreCartes[carte].nomcarte);
            for (int i = 0; i < nbJoueurs - 1; ++i) {
                tabJoueur[tabordreJoueurs[i]].argentJoueur -= 20;
            }
            tabJoueur[tabordreJoueurs[indiceJoueur]].argentJoueur = (nbJoueurs - 1)*20;
        }break;
        case 14:{
            printf("%s", parametreCartes[carte].nomcarte);
        }break;
        case 15:{
            printf("%s", parametreCartes[carte].nomcarte);
            tabJoueur[tabordreJoueurs[indiceJoueur]].argentJoueur -= 50;
        }break;
        case 16:{
            printf("%s", parametreCartes[carte].nomcarte);
            tabJoueur[tabordreJoueurs[indiceJoueur]].argentJoueur += 50;

        }break;
    }

    return 0;
}