#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "generationCode.h"

int main()
{
    // Appel de la fonction menu
    menu();

    // Déclaration de Num
    int Num = 0;

    // Lecture et copie (dans Num) de la valeur saisie tant que la valeur est entre 23 et 0
    do{
        scanf("%d", &Num);


    }while(Num > 23 || Num < 0);
    choix (Num);


    return 0;


}
