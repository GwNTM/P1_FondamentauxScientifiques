#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "donnees.h"
#include "actions.h"

// D�claration de la fonction readDonnees
void readDonnees(File *file){
    // D�claration de la structure mesure
    struct mesure Mesure;
    int rangLigne = -1, caractereActuel = 0,  stop = 0;
    FILE *fichier = NULL;
    // Cr�ation tableau de caract�res pour analys� le fichier
    char motFichier[100];

    // D�claration du fichier Battements
    fichier = fopen("Battements.csv","r");

    // Si le fichier existe
    if(fichier != NULL){

        while(1){
            // Tant que le caractere analys� n'est pas un point virgule
            while(caractereActuel != ';'){
                // Le caract�re analys� prend la valeur du caract�re lu par le fichier
                caractereActuel = getc(fichier);
                // Si le caract�re lu est inexistant
                if(caractereActuel == -1){
                    // Stop prend la valeur 1
                    stop = 1;
                    break;
                }
                // Passage au caract�re suivant dans une ligne
                rangLigne++;
                // Ajout du caract�re lu dans le tableau de caract�res
                motFichier[rangLigne] = caractereActuel;
            }
            // On sort de la boucle pour arr�ter de lire le fichier
            if(stop == 1){
                break;
            }

            // Conversion du tableau de caract�res en int
            Mesure.pouls = atoi(motFichier);
            // Retour d�but ligne
            rangLigne = -1;

            // Tant que le caract�re analys� n'est pas un retour � la ligne
            while(caractereActuel != '\n'){
                // Le caract�re analys� prend la valeur du caract�re lu par le fichier
                caractereActuel = getc(fichier);
                // Passage au caract�re suivant dans une ligne
                rangLigne++;
                // Ajout du caract�re lu dans le tableau de caract�res
                motFichier[rangLigne] = caractereActuel;
            }

            // Conversion du tableau de caract�res en int
            Mesure.temps = atoi(motFichier);
            // Retour d�but ligne
            rangLigne = -1;
            // Appel de la fonction enfilage
            enfilage(file, Mesure);

        }

    }else{
        // Sinon affichage du message
        printf("Erreur lors de l'ouverture du fichier : Fichier introuvable !");
    }
}

// D�claration de la fonction initialisation
File *initialisation()
{
    // On cr�e une file en allouant de la m�moire
    File *file = malloc(sizeof(*file));
    // On cr�e un element en allouant de la m�moire
    Element *element = malloc(sizeof(*element));

    // Si la file est vide ou que l'element analys� est vide
    if (file == NULL || element == NULL)
    {
        exit(EXIT_FAILURE);
    }

    // Mise � 0
    element->Mesure.pouls = 0;
    element->Mesure.temps = 0;
    element->suivant = NULL;
    // On d�fini element comme le premier element de la file
    file->premier = element;

    return file;
}

// D�claration de la fonction enfilage
void enfilage(File *file, mesure mesure){
    // On cr�e un nouvel element en allouant de la m�moire
    Element *newElement = malloc(sizeof(*newElement));
    // Si la file est vide ou que l'element analys� est vide
    if (file == NULL || newElement == NULL)
    {
        exit(EXIT_FAILURE);
    }

    // On d�fini la mesure du nouvel element comme �tant la mesure mise en param�tre
    newElement->Mesure = mesure;
    // On d�fini l'element suivant � nul
    newElement->suivant = NULL;

    // Si le premier element de la file existe
    if (file->premier != NULL)
    {
        // La valeur de l'element actuel est d�finie comme le premier element de la file
        Element *elementActuel = file->premier;
        // Tant qu'il existe un element suivant
        while (elementActuel->suivant != NULL)
        {
            // L'element actuel prend la valeur de l'element suivant
            elementActuel = elementActuel->suivant;
        }
        // L'element suivant prend la valeur du nouvel element
        elementActuel->suivant = newElement;
    }
    else
    {
        // Sinon le premier element de la file prend la valeur du nouvel element
        file->premier = newElement;
    }
}


