
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
            printf("%s\n", parametreCartes[carte].nomcarte);
            tabParametreJoueurs[indiceJoueur].numCase = 8;
        }break;
        case 2:{
            printf("%s\n", parametreCartes[carte].nomcarte);
            tabParametreJoueurs[indiceJoueur].numCase = 23;
        }break;
        case 3:{
            printf("%s\n", parametreCartes[carte].nomcarte);
            tabParametreJoueurs[indiceJoueur].numCase = 9;
        }break;
        case 4:{
            printf("%s\n", parametreCartes[carte].nomcarte);
            tabParametreJoueurs[indiceJoueur].numCase = 30;
        }break;
        case 5:{
            printf("%s\n", parametreCartes[carte].nomcarte);
            tabParametreJoueurs[indiceJoueur].numCase = 15;
        }break;
        case 6:{
            printf("%s\n", parametreCartes[carte].nomcarte);
            tabParametreJoueurs[indiceJoueur].numCase = 0;
        }break;
        case 7:{
            printf("%s\n", parametreCartes[carte].nomcarte);
            tabParametreJoueurs[indiceJoueur].numCase = tabParametreJoueurs[indiceJoueur].numCase - 3;
        }break;
        case 8:{
            printf("sortez de prison\n");
        }break;
        case 9:{
            printf("%s\n", parametreCartes[carte].nomcarte);
            tabJoueur[tabordreJoueurs[indiceJoueur]].argentJoueur -= 50;
        }break;
        case 10:{
            printf("%s\n", parametreCartes[carte].nomcarte);
            tabJoueur[tabordreJoueurs[indiceJoueur]].argentJoueur += 100;

        }break;
        case 11:{
            printf("%s\n", parametreCartes[carte].nomcarte);
            tabJoueur[tabordreJoueurs[indiceJoueur]].argentJoueur -= 200;
        }break;
        case 12:{
            printf("%s\n", parametreCartes[carte].nomcarte);
            tabJoueur[tabordreJoueurs[indiceJoueur]].argentJoueur += 200;
        }break;
        case 13:{
            printf("%s\n", parametreCartes[carte].nomcarte);
            for (int i = 0; i < nbJoueurs - 1; ++i) {
                tabJoueur[tabordreJoueurs[i]].argentJoueur -= 20;
            }
            tabJoueur[tabordreJoueurs[indiceJoueur]].argentJoueur += (nbJoueurs - 1)*20;
        }break;
        case 14:{
            printf("%s\n", parametreCartes[carte].nomcarte);
        }break;
        case 15:{
            printf("%s\n", parametreCartes[carte].nomcarte);
            tabJoueur[tabordreJoueurs[indiceJoueur]].argentJoueur -= 50;
        }break;
        case 16:{
            printf("%s\n", parametreCartes[carte].nomcarte);
            tabJoueur[tabordreJoueurs[indiceJoueur]].argentJoueur += 50;
        }break;
    }

    return 0;
}

void initialisercommu(){
    strcpy(parametreCommu[1].nomcarte, "retourner a belleville");
    strcpy(parametreCommu[2].nomcarte, "aller en prison");
    strcpy(parametreCommu[3].nomcarte, "aller sur la case depart");
    strcpy(parametreCommu[4].nomcarte, "tirer une carte chance");
    strcpy(parametreCommu[5].nomcarte, "donner 20 a chaque joueur");
    strcpy(parametreCommu[6].nomcarte, "Payer 100 a la banque");
    strcpy(parametreCommu[7].nomcarte, "recevez 100 de la banque");
    strcpy(parametreCommu[8].nomcarte, "Vous trouvez 50");
    strcpy(parametreCommu[9].nomcarte, "Payer 50 a la banque");
    strcpy(parametreCommu[10].nomcarte, "aller visiter la prison");
    strcpy(parametreCommu[11].nomcarte, "recevez 200 de la banque");
    strcpy(parametreCommu[12].nomcarte, "payer 50");
    strcpy(parametreCommu[13].nomcarte, "payer 50");
    strcpy(parametreCommu[14].nomcarte, "recevez 100 de la banque");
    strcpy(parametreCommu[15].nomcarte, "payer 200");
    strcpy(parametreCommu[16].nomcarte, "recevez 50");
}

int cartecommu(int indiceJoueur, int nbJoueurs){
    int commu = randomDe(16);
    switch (commu) {
        case 1:{
            printf("%s", parametreCommu[commu].nomcarte);
            tabParametreJoueurs[indiceJoueur].numCase = 1;
        }break;
        case 2:{
            printf("aller en prison");
        }break;
        case 3:{
            printf("%s", parametreCommu[commu].nomcarte);
            tabParametreJoueurs[indiceJoueur].numCase = 0;
        }break;
        case 4:{
            printf("%s", parametreCommu[commu].nomcarte);
            cartechance(indiceJoueur,nbJoueurs);
        }break;
        case 5:{
            printf("%s", parametreCommu[commu].nomcarte);
            tabJoueur[tabordreJoueurs[indiceJoueur]].argentJoueur -= (nbJoueurs - 1)*20;
            for (int i = 0; i < nbJoueurs - 1; ++i) {
                tabJoueur[tabordreJoueurs[i]].argentJoueur += 20;
            }
        }break;
        case 6:{
            printf("%s", parametreCommu[commu].nomcarte);
            tabJoueur[tabordreJoueurs[indiceJoueur]].argentJoueur -= 100;
        }break;
        case 7:{
            printf("%s", parametreCommu[commu].nomcarte);
            tabJoueur[tabordreJoueurs[indiceJoueur]].argentJoueur += 100;
        }break;
        case 8:{
            printf("%s", parametreCommu[commu].nomcarte);
            tabJoueur[tabordreJoueurs[indiceJoueur]].argentJoueur += 50;
        }break;
        case 9:{
            printf("%s", parametreCommu[commu].nomcarte);
            tabJoueur[tabordreJoueurs[indiceJoueur]].argentJoueur -= 50;
        }break;
        case 10:{
            printf("%s", parametreCommu[commu].nomcarte);
            tabJoueur[tabordreJoueurs[indiceJoueur]].argentJoueur -= 100;
        }break;
        case 11:{
            printf("%s", parametreCommu[commu].nomcarte);
            tabJoueur[tabordreJoueurs[indiceJoueur]].argentJoueur += 200;
        }break;
        case 12:{
            printf("%s", parametreCommu[commu].nomcarte);
            tabJoueur[tabordreJoueurs[indiceJoueur]].argentJoueur -= 50;
        }break;
        case 13:{
            printf("%s", parametreCommu[commu].nomcarte);
            tabJoueur[tabordreJoueurs[indiceJoueur]].argentJoueur -= 50;
        }break;
         case 14:{
            printf("%s", parametreCommu[commu].nomcarte);
            tabJoueur[tabordreJoueurs[indiceJoueur]].argentJoueur += 100;
        }break;
         case 15:{
            printf("%s", parametreCommu[commu].nomcarte);
            tabJoueur[tabordreJoueurs[indiceJoueur]].argentJoueur -= 200;
        }break;
         case 16:{
            printf("%s", parametreCommu[commu].nomcarte);
            tabJoueur[tabordreJoueurs[indiceJoueur]].argentJoueur += 50;
        }break;

    }
}
