#include <stdio.h>
#include <stdlib.h>
#include "affichestats.h"

void affiche_stats() {
    printf("STATISTIQUES DU DEFI 1 \n\n");
    FILE *f = fopen("data/statsdefi1.txt", "r");
    if (!f) {
        printf("Erreur: impossible d'ouvrir le fichier.\n");
        
    }
    char line[255];
    while (fgets(line, sizeof(line), f) != NULL) {
        printf(line);
    }
    fclose(f);

    printf("\n\n\nSTATISTIQUES DU DEFI 2 \n\n");
    f = fopen("data/statsdefi2.txt", "r");
    if (!f) {
        printf("Erreur: impossible d'ouvrir le fichier.\n");
        
    }
    while (fgets(line, sizeof(line), f) != NULL) {
        printf(line);
    }
    fclose(f);

    printf("\n\n\nSTATISTIQUES DU DEFI 3 \n\n");
    f = fopen("data/statsdefi3.txt", "r");
    if (!f) {
        printf("Erreur: impossible d'ouvrir le fichier.\n");
        
    }

    while (fgets(line, sizeof(line), f) != NULL) {
        printf(line);
    }
    fclose(f);

    printf("\n\n\nSTATISTIQUES DU DEFI 4 \n\n");
    f = fopen("data/statsdefi4.txt", "r");
    if (!f) {
        printf("Erreur: impossible d'ouvrir le fichier.\n");
    }

    while (fgets(line, sizeof(line), f) != NULL) {
        printf(line);
    }
    fclose(f);

}