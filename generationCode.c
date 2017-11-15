#include <stdio.h>
#include <stdlib.h>

void choix (int Num)
{

    FILE *fichier = NULL;
    fichier = fopen("arduino\\param.h", "w+");

    if (fichier == NULL)
    {
        printf("Le fichier n'a pas pu etre ouvert");
        exit(EXIT_FAILURE);
    }
    switch (Num)

{
    // Allumer toutes les LEDs
    case (1):
        fprintf(fichier, "int parametre(){return 1;}");
        break;

    // Allumer les LEDs en mode chenille
    case (2):
        fprintf(fichier, "int parametre(){return 2;}");
        break;

    // Allumer 1 LED sur 2
    case (3):
        fprintf(fichier, "int parametre(){return 3;}");
        break;

    // Allumer 1 LED sur 3
    case (4):
        fprintf(fichier, "int parametre(){return 4;}");
        break;

    // Allumer 1 LED sur 4
    case (5):
        fprintf(fichier, "int parametre(){return 5;}");
        break;

    // Allumer 1 LED sur 5
    case (6):
        fprintf(fichier, "int parametre(){return 6;}");
        break;

    // Allumer 1 LED sur 6
    case (7):
        fprintf(fichier, "int parametre(){return 7;}");
        break;

    // Allumer 1 LED sur 7
    case (8):
        fprintf(fichier, "int parametre(){return 8;}");
        break;

    // Allumer 1 LED sur 8
    case (9):
        fprintf(fichier, "int parametre(){return 9;}");
        break;

    // Allumer 1 LED sur 9
    case (10):
        fprintf(fichier, "int parametre(){return 10;}");
        break;

    // Allumer 1 LED sur 10
    case (11):
        fprintf(fichier, "int parametre(){return 11;}");
        break;


    default :
        printf ("Entrez une valeur entre 1 et 11 \n");
    break;
    fclose(fichier);
}


}







