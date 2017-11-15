#include <stdio.h>
#include "menu.h"
#include "donnees.h"
#include "actions.h"

void getAction(int action, File *file){
    int temps = 0, min = 0,max = 0;
    Element *actuel = file->premier;
    actuel = actuel->suivant;

    if(file != NULL){
        switch (action){
            case 1:
                printOrdre(actuel);
                break;
            case 2:
                printCroissant(file,actuel);
                break;
            case 3:
                printDecroissant(file,actuel);
                break;
            case 4:
                printPoulsTemps(actuel);
                break;
            case 5:
                printMoyenne(file,actuel);
                break;
            case 6:
                printNbLigne(actuel);
                break;
            case 7:
                printMinMax(file,actuel);
                break;
            default:
                break;

        }
    }
}

void printOrdre(Element *actuel){
    while(actuel != NULL){
        printf("Le pouls est de %d a %d secondes\n",actuel->Mesure.pouls,actuel->Mesure.temps);
        actuel = actuel->suivant;

    }
}

void printCroissant(File *file,Element *actuel){
    int size = 0,i;

    while(actuel != NULL){
        size ++;
        actuel = actuel->suivant;
    }

    mesure tab[size];

    actuel = file->premier;
    actuel = actuel->suivant;

    for(i = 0;i<size;i++){
        tab[i] = actuel->Mesure;
        actuel = actuel->suivant;
    }

    tri_bulle_croissant(size, tab);

    for(i = 0;i<size;i++){
        printf("Le pouls est de %d a %d secondes\n",tab[i].pouls,tab[i].temps);
    }
}

void printDecroissant(File *file,Element *actuel){
    int size = 0,i;

    while(actuel != NULL){
        size ++;
        actuel = actuel->suivant;
    }

    mesure tab[size];

    actuel = file->premier;
    actuel = actuel->suivant;

    for(i = 0;i<size;i++){
        tab[i] = actuel->Mesure;
        actuel = actuel->suivant;
    }

    tri_bulle_decroissant(size, tab);

    for(i = 0;i<size;i++){
        printf("Le pouls est de %d avec a %d secondes \n",tab[i].pouls,tab[i].temps);
    }
}

void printPoulsTemps(Element *actuel){
    int temps;
    printf("A quel moment voulez vous obtenir la valeur du pouls ?");
    scanf("%d",&temps);

    while(actuel != NULL && actuel->Mesure.temps != temps){
        actuel = actuel->suivant;
    }

    if(actuel == NULL){
        printf("Erreur, ce temps n'a pas été enregistré !\n");
    }else{
        printf("Le pouls est de %d a %d secondes\n",actuel->Mesure.pouls,temps);
    }
}

void printMoyenne(File *file,Element *actuel){

    int size = 0, totalPouls = 0, poulsMoyen = 0,temp = 0, min,max;

    printf("Indiquez la plage de temps voulu !");
    scanf("%d %d",&min,&max);

    Element *elem = NULL;

    if(min > max){
        temp = min;
        min = max;
        max = temp;
    }

    if(min <= actuel->Mesure.temps)min = actuel->Mesure.temps;

    while(actuel != NULL){
        elem = actuel;
        actuel = actuel->suivant;
    }

    if(max >= elem->Mesure.temps)max = elem->Mesure.temps;

    actuel = file->premier;
    actuel = actuel->suivant;

    while(actuel->Mesure.temps < min && actuel != NULL){
        actuel = actuel->suivant;
    }

    if(actuel != NULL){

        while(actuel->Mesure.temps < max && actuel != NULL){
            totalPouls+=actuel->Mesure.pouls;
            size++;
            actuel = actuel->suivant;
        }

        if(actuel != NULL){

            totalPouls+=actuel->Mesure.pouls;
            size++;
            actuel = actuel->suivant;
            poulsMoyen = totalPouls/size;
            printf("Le pouls moyen entre %d et %d est de %d\n",min,max,poulsMoyen);

        }else{
            printf("Erreur, ce temps n'a pas été enregistré !\n");
        }
    }else{
        printf("Erreur, ce temps n'a pas été enregistré !\n");
    }
}

void printNbLigne(Element *actuel){
    int size = 0;

    while(actuel != NULL){
        size ++;
        actuel = actuel->suivant;
    }

    printf("Il y a %d valeur enregistre pour le moment !\n",size);
}

void printMinMax(File *file,Element *actuel){
    int min = 500, max = 0;

    while(actuel != NULL){
        if(min > actuel->Mesure.pouls){
            min = actuel->Mesure.pouls;
        }
        if(max < actuel->Mesure.pouls){
            max = actuel->Mesure.pouls;
        }
        actuel = actuel->suivant;
    }

    actuel = file->premier;
    actuel = actuel->suivant;

    while(actuel->Mesure.pouls != min && actuel != NULL){
        actuel = actuel->suivant;
    }

    if(actuel != NULL){

        mesure minMesure = actuel->Mesure ;

        actuel = file->premier;
        actuel = actuel->suivant;

        while(actuel->Mesure.pouls != max && actuel!= NULL){
            actuel = actuel->suivant;
        }

        if(actuel != NULL){
            mesure maxMesure = actuel->Mesure ;

            printf("Le pouls minimum est %d a %d secondes et le pouls maximum est %d a %d secondes\n",minMesure.pouls,minMesure.temps,maxMesure.pouls,maxMesure.temps);
        }
    }
}

void tri_bulle_croissant(int size, mesure tab[]){
    int change,i;
    mesure temp;
    do{
        change = 0;
        for(i = 0;i<size-1;i++){
            if(tab[i].pouls > tab[i+1].pouls){
                temp = tab[i];
                tab[i] = tab[i+1];
                tab[i+1] = temp;
                change = 1;
            }
        }
    }while(change == 1);
}

void tri_bulle_decroissant(int size, mesure tab[]){
    int change;
    mesure temp;
    do{
        int i;
        change = 0;
        for(i = 0;i<size-1;i++){
            if(tab[i].pouls < tab[i+1].pouls){
                temp = tab[i];
                tab[i] = tab[i+1];
                tab[i+1] = temp;
                change = 1;
            }
        }
    }while(change == 1);
}

