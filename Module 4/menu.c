#include <stdio.h>
#include "menu.h"
#include "donnees.h"
#include "actions.h"

void printMenu(){
    printf("     ___________________________________________________________________________________ \n");
    printf("    |                                                                                   |\n");
    printf("    |                                        MENU                                       |\n");
    printf("    |___________________________________________________________________________________|\n");
    printf("    |                                                                                   |\n");
    printf("    |    1 - Afficher les donnees dans l'ordre du fichier .csv                          |\n");
    printf("    |    2 - Afficher les donnees dans l'ordre inverse du fichier .csv                  |\n");
    printf("    |    3 - Afficher les donnees en ordre croissant (selon le pouls)                   |\n");
    printf("    |    4 - Afficher les donnees en ordre decroissant (selon le pouls)                 |\n");
    printf("    |    5 - Rechercher et afficher les donnees pour un temps particulier               |\n");
    printf("    |    6 - Afficher la moyenne de pouls dans une plage de temps donnee                |\n");
    printf("    |    7 - Afficher le nombre de lignes de donnees actuellement en memoire            |\n");
    printf("    |    8 - Rechercher et afficher les max/min de pouls                                |\n");
    printf("    |                                                                                   |\n");
    printf("    |    0 - Quitter l'application                                                      |\n");
    printf("    |___________________________________________________________________________________|\n");
    printf("\n");
}
int choseAction(){
    int action = 0;
    do{
        printf("Quelle action souhaitez vous effectuer ?\n");
        scanf("%d",&action);
        if(action > 8 ||action < 0){
            printf("Erreur, cette action n'existe pas !\n");
        }
    }while(action > 8 ||action < 0);
    return action;
}
