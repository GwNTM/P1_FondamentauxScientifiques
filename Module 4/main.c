#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "donnees.h"
#include "actions.h"

int main()
{
    int action = -1;
    File *file = NULL;
    file = initialisation();

    readDonnees(file);

    while(action != 0){
        printMenu();
        action = choseAction();
        getAction(action, file);
    }

    return 0;
}
