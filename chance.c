
#include "chance.h"

void initialiserCartes(){
    strcpy(parametreCartes[1].nomcarte, "aller en prison");

}

int cartechance (int indiceJoueur){

    int carte = random(16);

    switch (carte) {
        case 1:{
            printf("%s", parametreCartes[carte]);
            tabParametreJoueurs[indiceJoueur].numCase = 8;
        }break;
        case 2:{
            printf("aller avenue Henri-Martin");
        }break;
        case 3:{
            printf("aller Boulevard de la villette");
        }break;
        case 4:{
            printf("aller Rue de la paix");
        }break;
        case 5:{
            printf("aller a la gare de lyon");
        }break;
        case 6:{
            printf("aller a la case depart");
        }break;
        case 7:{
            printf("Reculez de trois case");
        }break;
        case 8:{
            printf("sortez de prison");
        }break;
        case 9:{
            printf("payer 50");
            Joueur parametreJ;
            parametreJ.argentJoueur = parametreJ.argentJoueur - 50;
        }break;
        case 10:{
            printf("Ressevez 100");
            Joueur parametreJ;
            parametreJ.argentJoueur = parametreJ.argentJoueur + 100;
        }break;
        case 11:{
            printf("payer 200");
            Joueur parametreJ;
            parametreJ.argentJoueur = parametreJ.argentJoueur - 200;
        }break;
        case 12:{
            printf("Ressevez 200");
            Joueur parametreJ;
            parametreJ.argentJoueur = parametreJ.argentJoueur + 200;
        }break;
        case 13:{
            printf("c'est votre anniversaire ressevez 20");
            Joueur parametreJ;
            parametreJ.argentJoueur = parametreJ.argentJoueur + 20;
        }break;
        case 14:{
            printf("payer 10 pour chaque maison et 20 pour chauque hotel");
        }break;
        case 15:{
            printf("payer 50 ");
            parametreJ.argentJoueur =
        }break;
        case 16:{
            printf("ressevez 50");
        }break;
    }

    return 0;
}