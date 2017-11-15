#include <stdio.h>
#include "menu.h"
#include "donnees.h"
#include "actions.h"

void getAction(int action, File *file){
    int temps = 0, min = 0,max = 0;
    if(file != NULL){
        switch (action){
            case 1:
                printOrdre(file);
                break;
            case 2:
                printCroissant(file);
                break;
            case 3:
                printDecroissant(file);
                break;
            case 4:
                printf("Pour quel instant voulez vous obtenir la valeur du pouls ?");
                scanf("%d",&temps);
                printPoulsTemps(file,temps);
                break;
            case 5:
                printf("Indiquez la plage de temps voulu !");
                scanf("%d %d",&min,&max);
                printMoyenne(file,min,max);
                break;
            case 6:
                printNbLigne(file);
                break;
            case 7:
                printMinMax(file);
                break;
            default:
                break;

        }
    }
}

void printOrdre(File *file){
    Element *actuel = file->premier;
    actuel = actuel->suivant;
    while(actuel != NULL){
        printf("Le pouls est de %d a l'instant %d\n",actuel->Mesure.pouls,actuel->Mesure.temps);
        actuel = actuel->suivant;
    }
}

void printCroissant(File *file){
    int size = 0;
    Element *actuel = file->premier;
    actuel = actuel->suivant;
    while(actuel != NULL){
        size ++;
        actuel = actuel->suivant;
    }
    mesure tab[size];
    int i;
    actuel = file->premier;
    actuel = actuel->suivant;
    for(i = 0;i<size;i++){
        tab[i] = actuel->Mesure;
        actuel = actuel->suivant;
    }
    tri_bulle_croissant(size, tab);
    for(i = 0;i<size;i++){
        printf("Le pouls est de %d a l'instant %d\n",tab[i].pouls,tab[i].temps);
    }
}

void printDecroissant(File *file){
    int size = 0;
    Element *actuel = file->premier;
    actuel = actuel->suivant;
    while(actuel != NULL){
        size ++;
        actuel = actuel->suivant;
    }
    mesure tab[size];
    int i;
    actuel = file->premier;
    actuel = actuel->suivant;
    for(i = 0;i<size;i++){
        tab[i] = actuel->Mesure;
        actuel = actuel->suivant;
    }
    tri_bulle_decroissant(size, tab);
    for(i = 0;i<size;i++){
        printf("Le pouls est de %d avec a l'instant %d\n",tab[i].pouls,tab[i].temps);
    }
}

void printPoulsTemps(File *file, int temps){
    Element *actuel = file->premier;
    actuel = actuel->suivant;
    while(actuel != NULL && actuel->Mesure.temps != temps){
        actuel = actuel->suivant;
    }

    if(actuel == NULL){
        printf("Erreur, ce temps n'a pas été enregistré !");
    }else{
        printf("Le pouls est de %d a l'instant %d",actuel->Mesure.pouls,temps);
    }
}

void printMoyenne(File *file, int min, int max){
    int size = 0, totalPouls = 0, poulsMoyen = 0;
    Element *actuel = file->premier;
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
            printf("Le pouls moyen est de %d", poulsMoyen);
        }
    }
}

void printNbLigne(File *file){
    int size = 0;
    Element *actuel = file->premier;
    actuel = actuel->suivant;
    while(actuel != NULL){
        size ++;
        actuel = actuel->suivant;
    }
    printf("Il y a %d valeur enregistre pour le moment !",size);
}

void printMinMax(File *file){
    int min = 500, max = 0;
    Element *actuel = file->premier;
    actuel = actuel->suivant;

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

            printf("Le pouls minimum est %d a l'instant %d et le pouls maximum est %d a l'instant %d\n",minMesure.pouls,minMesure.temps,maxMesure.pouls,maxMesure.temps);
        }
    }
}

void tri_bulle_croissant(int size, mesure tab[]){
    int change;
    mesure temp;
    do{
        int i;
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

