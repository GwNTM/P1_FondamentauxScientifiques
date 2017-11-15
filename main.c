#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "generationCode.h"

int main()
{

    menu();

    int Num = 0;
    scanf("%d", &Num);
    choix (Num);
    return 0;

}
