#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ecriredansclassement.h"





int comparerScore(const void *a, const void *b) {
    joueur *j1 = (joueur*)a;
    joueur *j2 = (joueur*)b;
    return j2->score - j1->score;   
}


void mise_a_jour () {
    FILE *f = fopen("data/standing2.txt", "r");
    if (!f) {
        printf("Erreur: impossible d'ouvrir le fichier.\n");
        
    }
    joueur basedonnes[100];
    
    char line[256];
    char nom[100];
    int score,rang;
    fgets(line, sizeof(line), f);
    fgets(line, sizeof(line), f);
    fgets(line, sizeof(line), f);
    int i=0;



    //remplir le base de donnes 
    while (fgets(line, sizeof(line), f) != NULL) {
        char *token ;
        token = strtok(line, "\t");
        token = strtok(NULL, "\t");
        strcpy(basedonnes[i].nom, token);
        token = strtok(NULL, "\t");
        basedonnes[i].score=atoi(token);
        i++;
    }


    fclose(f);
    qsort(basedonnes, i, sizeof(joueur), comparerScore);

    f = fopen("data/standing2.txt", "w");
    if (!f) {
        printf("Erreur: impossible d'écrire dans le fichier.\n");
        
    }

    // Réécrire l'en-tête
    fprintf(f, "RANG\tNOM\t\tSCORE\n");
    fprintf(f, "=========================\n");
    fprintf(f, "=========================\n");

    // Réécrire les données triées
    
    for (int j = 0; j < i; j++) {
        fprintf(f, "%d\t%s\t\t%d\n", j+1, basedonnes[j].nom, basedonnes[j].score);
    }

    fclose(f);

}


