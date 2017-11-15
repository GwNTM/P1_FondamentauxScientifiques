#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "donnees.h"
#include "actions.h"

int main()
{
    File *file = NULL;
    file = initialisation();

    readDonnees(file);

    int action = 0;
    do{
        printMenu();
        action = choseAction();
        getAction(action, file);
    }while(action != 0);

    return 0;
}
