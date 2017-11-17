#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "donnees.h"
#include "actions.h"

// Déclaration de la fonction readDonnees
void readDonnees(File *file){
    // Déclaration de la structure mesure
    struct mesure Mesure;
    int rangLigne = -1, caractereActuel = 0,  stop = 0;
    FILE *fichier = NULL;
    // Création tableau de caractères pour analysé le fichier
    char motFichier[100];

    // Déclaration du fichier Battements
    fichier = fopen("Battements.csv","r");

    // Si le fichier existe
    if(fichier != NULL){

        while(1){
            // Tant que le caractere analysé n'est pas un point virgule
            while(caractereActuel != ';'){
                // Le caractère analysé prend la valeur du caractère lu par le fichier
                caractereActuel = getc(fichier);
                // Si le caractère lu est inexistant
                if(caractereActuel == -1){
                    // Stop prend la valeur 1
                    stop = 1;
                    break;
                }
                // Passage au caractère suivant dans une ligne
                rangLigne++;
                // Ajout du caractère lu dans le tableau de caractères
                motFichier[rangLigne] = caractereActuel;
            }
            // On sort de la boucle pour arrêter de lire le fichier
            if(stop == 1){
                break;
            }

            // Conversion du tableau de caractères en int
            Mesure.pouls = atoi(motFichier);
            // Retour début ligne
            rangLigne = -1;

            // Tant que le caractère analysé n'est pas un retour à la ligne
            while(caractereActuel != '\n'){
                // Le caractère analysé prend la valeur du caractère lu par le fichier
                caractereActuel = getc(fichier);
                // Passage au caractère suivant dans une ligne
                rangLigne++;
                // Ajout du caractère lu dans le tableau de caractères
                motFichier[rangLigne] = caractereActuel;
            }

            // Conversion du tableau de caractères en int
            Mesure.temps = atoi(motFichier);
            // Retour début ligne
            rangLigne = -1;
            // Appel de la fonction enfilage
            enfilage(file, Mesure);

        }

    }else{
        // Sinon affichage du message
        printf("Erreur lors de l'ouverture du fichier : Fichier introuvable !");
    }
}

// Déclaration de la fonction initialisation
File *initialisation()
{
    // On crée une file en allouant de la mémoire
    File *file = malloc(sizeof(*file));
    // On crée un element en allouant de la mémoire
    Element *element = malloc(sizeof(*element));

    // Si la file est vide ou que l'element analysé est vide
    if (file == NULL || element == NULL)
    {
        exit(EXIT_FAILURE);
    }

    // Mise à 0
    element->Mesure.pouls = 0;
    element->Mesure.temps = 0;
    element->suivant = NULL;
    // On défini element comme le premier element de la file
    file->premier = element;

    return file;
}

// Déclaration de la fonction enfilage
void enfilage(File *file, mesure mesure){
    // On crée un nouvel element en allouant de la mémoire
    Element *newElement = malloc(sizeof(*newElement));
    // Si la file est vide ou que l'element analysé est vide
    if (file == NULL || newElement == NULL)
    {
        exit(EXIT_FAILURE);
    }

    // On défini la mesure du nouvel element comme étant la mesure mise en paramètre
    newElement->Mesure = mesure;
    // On défini l'element suivant à nul
    newElement->suivant = NULL;

    // Si le premier element de la file existe
    if (file->premier != NULL)
    {
        // La valeur de l'element actuel est définie comme le premier element de la file
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


