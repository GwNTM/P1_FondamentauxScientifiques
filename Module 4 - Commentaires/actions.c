#include <stdio.h>
#include "menu.h"
#include "donnees.h"
#include "actions.h"

// Cr�ation de la fonction getAction
void getAction(int action, File *file){
    // Initialisation
    int temps = 0, min = 0,max = 0;
    // Si la file n'est pas vide
    if(file != NULL){
        switch (action){
            // Si la valeur saisie est 1
            case 1:
                // Appel de la fonction printOrdre
                printOrdre(file);
                break;
            // Si la valeur saisie est 2
            case 2:
                // Appel de la fonction printInverse
                printInverse(file);
                break;
            // Si la valeur saisie est 3
            case 3:
                // Appel de la fonction printCroissant
                printCroissant(file);
                break;
            // Si la valeur saisie est 4
            case 4:
                // Appel de la fonction printDecroissant
                printDecroissant(file);
                break;
            // Si la valeur saisie est 5
            case 5:
                // Affichage du message dans la console
                printf("Pour quel instant voulez vous obtenir la valeur du pouls ?");
                // Lecture et copie (dans temps) de la valeur saisie
                scanf("%d",&temps);
                // Appel de la fonction printPoulsTemps
                printPoulsTemps(file,temps);
                break;
            // Si la valeur saisie est 6
            case 6:
                // Affichage du message sur la console
                printf("Indiquez la plage de temps voulu !");
                // Lecture et copie (dans min et dans max) des valeurs saisies
                scanf("%d %d",&min,&max);
                // Appel de la fonction printMoyenne
                printMoyenne(file,min,max);
                break;
            // Si la valeur saisie est 7
            case 7:
                // Appel de la fonction printNbLigne
                printNbLigne(file);
                break;
            // Si la valeur saisie est 8
            case 8:
                // Appel de la fonction printMinMax
                printMinMax(file);
                break;
            default:
                break;

        }
    }
}

// Cr�ation de la fonction printOrdre
void printOrdre(File *file){
    // La valeur de l'element actuel correspond au premier element de la file
    Element *actuel = file->premier;
    // Passage � l'element suivant de la file
    actuel = actuel->suivant;
    // Tant qu'il existe un element suivant on affiche le message dans la console
    while(actuel != NULL){
        printf("Le pouls est de %d a l'instant %d\n",actuel->Mesure.pouls,actuel->Mesure.temps);
        // Passage � l'element suivant de la file
        actuel = actuel->suivant;
    }
}

// Cr�ation de la fonction printInverse
void printInverse(File *file){
    // Initialisation
    int size = 0;
    // La valeur de l'element actuel correspond au premier element de la file
    Element *actuel = file->premier;
    // Passage � l'element suivant de la file
    actuel = actuel->suivant;
    // Tant qu'il existe un element suivant
    while(actuel != NULL){
        // Ajout de 1 � size
        size ++;
        // Passage � l'element suivant de la file
        actuel = actuel->suivant;
    }

    // Cr�ation d'un tableau de la taille de la file
    mesure tab[size];
    // Initialisation
    int i;
    // La valeur d'actuel correspond au premier element de la file
    actuel = file->premier;
    // Passage � l'element suivant de la file
    actuel = actuel->suivant;
    // Pour i allant de 0 � size
    for(i = 0;i<size;i++){
        // Ajout de chaque mesure (une par une) de la file dans un tableau
        tab[i] = actuel->Mesure;
        actuel = actuel->suivant;
    }
    // Appel de la fonction tri_bulle_decroissant_temps
    tri_bulle_decroissant_temps(size, tab);
    // Pour i allait de i � size
    for(i = 0;i<size;i++){
        // Affichage de chaque mesure du tableau (le pouls et le temps correspondant) sur la console
        printf("Le pouls est de %d a l'instant %d\n",tab[i].pouls,tab[i].temps);
    }
}

// Cr�ation de la fonction printCroissant
void printCroissant(File *file){
    // Initialisation
    int size = 0;
    // La valeur de l'element actuel correspond au premier element de la file
    Element *actuel = file->premier;
    // Passage � l'element suivant de la file
    actuel = actuel->suivant;
    // Tant qu'il existe un element suivant
    while(actuel != NULL){
        // Ajout de 1 � size
        size ++;
        // Passage � l'element suivant
        actuel = actuel->suivant;
    }
    // Cr�ation d'un tableau de la taille de la file
    mesure tab[size];
    // Initialisation
    int i;
    // La valeur d'actuel correspond au premier element de la file
    actuel = file->premier;
    // Passage � l'element suivant de la file
    actuel = actuel->suivant;
    // Pour i allant de 0 � size
    for(i = 0;i<size;i++){
        // Ajout de chaque mesure (une par une) de la file dans un tableau
        tab[i] = actuel->Mesure;
        actuel = actuel->suivant;
    }
    // Appel de la fonction tri_bulle_croissant_pouls
    tri_bulle_croissant_pouls(size, tab);
    // Pour i allant de 0 � size
    for(i = 0;i<size;i++){
        // Affichage de chaque mesure du tableau (le pouls et le temps correspondant) sur la console
        printf("Le pouls est de %d a l'instant %d\n",tab[i].pouls,tab[i].temps);
    }
}

// Cr�ation de la fonction printDecroissant
void printDecroissant(File *file){
    // Initialisation
    int size = 0;
    // La valeur de l'element actuel correspond au premier element de la file
    Element *actuel = file->premier;
    // Passage � l'element suivant de la file
    actuel = actuel->suivant;
    // Tant qu'il existe un element suivant
    while(actuel != NULL){
        // Ajout de 1 � size
        size ++;
        // Passage � l'element suivant
        actuel = actuel->suivant;
    }
    // Cr�ation d'un tableau de la taille de la file
    mesure tab[size];
    // Initialisation
    int i;
    // La valeur d'actuel correspond au premier element de la file
    actuel = file->premier;
    // Passage � l'element suivant
    actuel = actuel->suivant;
    // Pour i allant de 0 � size
    for(i = 0;i<size;i++){
        // Ajout de chaque mesure (une par une) de la file dans un tableau
        tab[i] = actuel->Mesure;
        actuel = actuel->suivant;
    }
    tri_bulle_decroissant_pouls(size, tab);
    // pour i allant de 0 � size
    for(i = 0;i<size;i++){
        // Affichage de chaque mesure du tableau (le pouls et le temps correspondant) sur la console
        printf("Le pouls est de %d a l'instant %d\n",tab[i].pouls,tab[i].temps);
    }
}

// Cr�ation de la fonction printPoulsTemps
void printPoulsTemps(File *file, int temps){
    int pouls = recherchePouls(temps, file);
    // Si l'algorithme de recherche trouve une mesure correspondante alors on l'affiche dans la console
    if(pouls != -1){
        printf("Le pouls est de %d a l'instant %d\n",pouls,temps);
    }
}

// Cr�ation de la fonction printMoyenne
void printMoyenne(File *file, int min, int max){
    // Initialisation
    int size = 0, totalPouls = 0, poulsMoyen = 0, temp;
    // La valeur de l'element actuel correspond au premier element de la file
    Element *actuel = file->premier;
    // Passage � l'element suivant de la file
    actuel = actuel->suivant;

    Element *prec = file->premier;
    // Si min est sup�rieur � max, on inverse les valeurs
    if(min > max){
        min = temp;
        min = max;
        max = temp;
    }

    // Tant qu'il existe un element suivant
    while(actuel != NULL){
        // Si la mesure analys�e est inf�rieure au max, passage � la mesure suivante
        if(actuel->Mesure.temps < max){
            prec = prec->suivant;
            actuel = actuel->suivant;
        }else{
            break;
        }
    }
    // S'il n'y a plus de mesure, max est �gal � la mesure stock�e dans prec
    if(actuel == NULL){
        max = prec->Mesure.temps;
    }

    actuel = file->premier;
    actuel = actuel->suivant;

    // Si min est inf�rieur � la mesure actuelle, on inverse les valeurs
    if(min < actuel->Mesure.temps)min = actuel->Mesure.temps;

    actuel = file->premier;
    actuel = actuel->suivant;

    // Tant que le temps r�cup�r� est le minimum
    while(actuel->Mesure.temps < min && actuel != NULL){
        actuel = actuel->suivant;
    }
    // Si la mesure analys�e n'est pas nulle
    if(actuel != NULL){
        // Tant que le temps r�cup�r� est le maximum
        while(actuel->Mesure.temps < max && actuel != NULL){
            // Addition de chacun des pouls
            totalPouls+=actuel->Mesure.pouls;
            // Ajout de 1 � size
            size++;
            // Passage � l'element suivant
            actuel = actuel->suivant;
        }
        // Si la mesure analys�e n'est pas nulle
        if(actuel != NULL){
            // Addition de chacun des pouls
            totalPouls+=actuel->Mesure.pouls;
            // Ajout de 1 � size
            size++;

            // Calcul moyenne
            poulsMoyen = totalPouls/size;
            // Affichage du pouls moyen
            printf("Le pouls moyen est de %d\n", poulsMoyen);
        }
    }
}

// Cr�ation de la fonction printNbLigne
void printNbLigne(File *file){
    // Initialisation
    int size = 0;
    // La valeur de l'element actuel correspond au premier element de la file
    Element *actuel = file->premier;
    // Passage � l'element suivant de la file
    actuel = actuel->suivant;
    // Tant qu'il existe un element suivant
    while(actuel != NULL){
        // Ajout de 1 � size
        size ++;
        // Passage � l'element suivant
        actuel = actuel->suivant;
    }
    // Affichage la taille de la liste sur la console
    printf("Il y a %d valeur enregistre pour le moment !\n",size);
}

// Cr�ation de la fonction printMinMax
void printMinMax(File *file){
    // Initialisation
    int sizeMin = 1, sizeMax = 1,min = 500,max = 0, rngMin = 0, rngMax = 0,i;
    mesure minMesure[sizeMin], maxMesure[sizeMax];

    // La valeur de l'element actuel est d�finie comme le premier element de la file
    Element *actuel = file->premier;
    // Passage � l'element suivant
    actuel = actuel->suivant;

    // Tant qu'un element actuel existe
    while(actuel != NULL){
        // Si min est sup�rieur au pouls de la mesure analys�e
        if(min > actuel->Mesure.pouls){
            // On d�fini la taille du tableau qui stocke les valeurs minimales � 1
            sizeMin = 1;
            // Min prend la valeur du pouls actuellement mesur�
            min = actuel->Mesure.pouls;
        // Si une autre valeur mesur�e est �gale au min
        }else if(min == actuel->Mesure.pouls){
            // Ajout de 1 au tableau
            sizeMin++;
        }
        // Si max est inf�rieur au pouls de la mesure analys�e
        if(max < actuel->Mesure.pouls){
            // On d�fini la taille du tableau qui stocke les valeurs maximales � 1
            sizeMax = 1;
            // Max prend la valeur du pouls actuellement mesur�
            max = actuel->Mesure.pouls;
        // Si une autre valeur mesur�e est �gale au max
        }else if(max == actuel->Mesure.pouls){
            // Ajout de 1 au tableau
            sizeMax++;
        }
        // Passage � l'element suivant
        actuel = actuel->suivant;
    }

    actuel = file->premier;
    actuel = actuel->suivant;

    // Tant qu'un element suivant existe
    while(actuel != NULL){
        // Si la mesure analys�e du pouls est �gale � min
        if(actuel->Mesure.pouls == min){
            // Ajout de la mesure min au tableau
            minMesure[rngMin] = actuel->Mesure;
            // Ajout de 1 au tableau
            rngMin++;
        }
        // Si la mesure analys�e du pouls est �gale � max
        if(actuel->Mesure.pouls == max){
            // Ajout de la mesure max au tableau
            maxMesure[rngMax] = actuel->Mesure;
            // Ajout de 1 au tableau
            rngMax++;
        }
        // Passage � l'element suivant
        actuel = actuel->suivant;
    }

    // Pour i allant de 0 � sizeMin
    for(i = 0;i < sizeMin;i++){
        // On affiche le pouls minimum
        printf("Un pouls minimum est %d a l'instant %d\n",minMesure[i].pouls,minMesure[i].temps);
    }

    // Pour i allant de 0 � sizeMax
    for(i = 0;i < sizeMax;i++){
        // On affiche le pouls maximum
        printf("Un pouls maximum est %d a l'instant %d\n",maxMesure[i].pouls,maxMesure[i].temps);
    }
}

// Cr�ation de la fonction recherchePouls
int recherchePouls(int temps, File *file){
    Element *actuel = file->premier;
    actuel = actuel->suivant;
    Element *prec = file->premier;
    // Tant que temps est sup�rieur ou �gal au temps de la mesure analys�
    while(actuel->Mesure.temps <= temps && actuel != NULL){
        prec = prec->suivant;
        actuel = actuel->suivant;
    }
    // Si l'element est inexistant
    if(actuel == NULL){
        return -1;
    }else{
        return prec->Mesure.pouls;
    }
}

// Cr�ation de la fonction tri_bulle_croissant_pouls
void tri_bulle_croissant_pouls(int size, mesure tab[]){
    // Initialisation
    int change;
    mesure temp;
    // Faire tant qu'il y a un changement dans le tableau
    do{
        int i;
        change = 0;
        // Pour i allant de 0 � size
        for(i = 0;i<size-1;i++){
            // Si le pouls analys� est sup�rieur au pouls suivant alors on inverse les mesures dans le tableau
            if(tab[i].pouls > tab[i+1].pouls){
                temp = tab[i];
                tab[i] = tab[i+1];
                tab[i+1] = temp;
                change = 1;
            }
        }
    }while(change == 1);
}

// Cr�ation de la fonction tri_bulle_decroissant_pouls
void tri_bulle_decroissant_pouls(int size, mesure tab[]){
    // Initialisation
    int change;
    mesure temp;
    //Faire tant qu'il y a un changement dans le tableau
    do{
        int i;
        change = 0;
        // Pour i allant de 0 � size
        for(i = 0;i<size-1;i++){
            // Si le pouls analys� est inf�rieur au pouls suivant alors on inverse les mesures dans le tableau
            if(tab[i].pouls < tab[i+1].pouls){
                temp = tab[i];
                tab[i] = tab[i+1];
                tab[i+1] = temp;
                change = 1;
            }
        }
    }while(change == 1);
}

// Cr�ation de la fonction tri_bulle_decroissant_temps
void tri_bulle_decroissant_temps(int size, mesure tab[]){
    // Initialisation
    int change;
    mesure temp;
    // Faire tant qu'il y a un changement dans le tableau
    do{
        int i;
        change = 0;
        // Pour i allant de 0 � size
        for(i = 0;i<size-1;i++){
            // Si le temps analys� est inf�rieur au temps suivant alors on inverse les mesures dans le tableau
            if(tab[i].temps < tab[i+1].temps){
                temp = tab[i];
                tab[i] = tab[i+1];
                tab[i+1] = temp;
                change = 1;
            }
        }
    }while(change == 1);
}

