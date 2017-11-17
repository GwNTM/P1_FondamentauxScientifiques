#include <stdio.h>
#include "menu.h"
#include "donnees.h"
#include "actions.h"

// Création de la fonction printMenu
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

// Création de la fonction choseAction
int choseAction(){
    // Initialisation
    int action = 0;

    // Faire tant que la valeur saisie est entre 0 et 8 (compris)
    do{
        // Affichage du message sur la console
        printf("Quelle action souhaitez vous effectuer ?\n");
        // Lecture et copie (dans action) de la valeur saisie
        scanf("%d",&action);
        // Si la valeur saisie n'est pas dans l'intervalle afficher le message sur la console
        if(action > 8 || action < 0){
            printf("Erreur, cette action n'existe pas !\n");
        }
    }while(action > 8 ||action < 0);

    // Retourner la valeur saisie par l'utilisateur
    return action;
}
