#include <stdio.h>
#include "menu.h"
#include "donnees.h"
#include "actions.h"

void printMenu(){
    printf("+-----------------------------------------------------------------------------------+\n");
    printf("|                                        MENU                                       |\n");
    printf("+-----------------------------------------------------------------------------------+\n");
    printf("|1 - Afficher les donnees dans l'ordre du fichier .csv                              |\n");
    printf("|2 - Afficher les donnees en ordre croissant (selon le temps, selon le pouls)       |\n");
    printf("|3 - Afficher les donnees en ordre decroissant (selon le temps, selon le pouls)     |\n");
    printf("|4 - Rechercher et afficher les donnees pour un temps particulier                   |\n");
    printf("|5 - Afficher la moyenne de pouls dans une plage de temps donnee                    |\n");
    printf("|6 - Afficher le nombre de lignes de donnees actuellement en memoire                |\n");
    printf("|7 - Rechercher et afficher les max/min de pouls (avec le temps associe)            |\n");
    printf("|                                                                                   |\n");
    printf("|0 - Quitter l'application                                                          |\n");
    printf("+-----------------------------------------------------------------------------------+\n");
    printf("\n");
}

int choseAction(){
    int action = 0;
    do{
        printf("Quelle action souhaitez vous effectuer ?\n");
        scanf("%d",&action);
    }while(action > 7 ||action < 0);
    return action;
}
