#include <stdio.h>
#include <stdlib.h>
#include "affichestanding.h"


void affichage() {
    FILE *f = fopen("data/standing2.txt", "r");
    if (!f) {
        printf("Erreur: impossible d'ouvrir le fichier.\n");
        
    }
    char line[255];
    while (fgets(line, sizeof(line), f) != NULL) {
        printf(line);
    }
    fclose(f);
}