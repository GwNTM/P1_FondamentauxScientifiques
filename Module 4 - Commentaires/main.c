#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "donnees.h"
#include "actions.h"

int main()
{
    // Initialisation
    int action = -1;
    // D�claration
    File *file = NULL;
    // Remise � z�ro de la file avec la fonction initialisation
    file = initialisation();

    // Appel de la fonction readDonnees
    readDonnees(file);

    // Tant que la valeur saisie n'est pas 0
    while(action != 0){
        // Appel de la fonction menu
        printMenu();
        // Ex�cution de la fonction choseAction
        action = choseAction();
        // Appel de la fonction getAction
        getAction(action, file);
    }

    return 0;
}
