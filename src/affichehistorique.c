#include <stdio.h>
#include <stdlib.h>
#include "affichehistorique.h"


void affichage_historique() {
    printf("====================HISTORIQUE====================\n");
    FILE *f = fopen("data/basedonne.txt", "r");
    if (!f) {
        printf("Erreur: impossible d'ouvrir le fichier.\n");
        
    }
    char line[255];
    while (fgets(line, sizeof(line), f) != NULL) {
        printf(line);
    }
    fclose(f);
    printf("=================================================\n\n");
}