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

    printMenu();
    getAction(choseAction(), file);

    return 0;
}
