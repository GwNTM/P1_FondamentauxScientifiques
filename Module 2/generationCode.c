#include <stdio.h>
#include <stdlib.h>
#include "generationCode.h"


// Cr�ation fonction choix
void choix (int Num)
{
    // Cr�ation du fichier param.h
    FILE *fichier = NULL;
    fichier = fopen("coeur\\param.h", "w+");

            // Retourner la valeur saisie dans le fichier cr��
            fprintf(fichier, "int parametre(){return %d;}", Num);

        // Fermer le fichier
        fclose(fichier);


}







