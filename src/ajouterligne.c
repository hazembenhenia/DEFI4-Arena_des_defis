#include <stdio.h>
#include <stdlib.h>
#include "ecriredansclassement.h"
#include "ajouterligne.h"
#include <string.h>




// Renvoie l'indice du joueur trouvé, ou -1 s'il n'existe pas
int trouver_joueur(joueur basedonnes[], int count, char *nom_recherche) {
    for (int k = 0; k < count; k++) {
        
        if (strcmp(basedonnes[k].nom, nom_recherche) == 0) {
            return k;
        }
    }
    return -1;
}


void ajouter_ligne(char *l, int p) {
    FILE *f = fopen("data/standing2.txt", "r");
    joueur basedonnes[100];
    int i = 0; // Compteur d'entrées de joueurs

    if (!f) {
        printf("Erreur: impossible d'ouvrir le fichier standing2.txt en lecture.\n");
        return;
    }

    char line[256];
    
    // Ignorer les 3 lignes d'en-tête (RANG, ===, ===)
    for (int h = 0; h < 3; h++) {
        if (fgets(line, sizeof(line), f) == NULL) {
             break; 
        }
    }

    // 1. LIRE TOUTES LES ENTRÉES EXISTANTES DANS basedonnes
    while (fgets(line, sizeof(line), f) != NULL && i < 100) {
        char *token;
        char temp_line[256];
        strcpy(temp_line, line); 

        
        token = strtok(temp_line, "\t");

        // NOM
        token = strtok(NULL, "\t");
        if (token == NULL) continue;
        
        token[strcspn(token, "\n\r")] = 0; 
        strcpy(basedonnes[i].nom, token);
        
        // SCORE
        token = strtok(NULL, "\t\t");
        if (token == NULL) continue;
        basedonnes[i].score = atoi(token);
        
        i++;
    }
    fclose(f);

    // 2. CHERCHER ET METTRE À JOUR OU AJOUTER LE JOUEUR
    int index_existant = trouver_joueur(basedonnes, i, l);
    
    // Si le joueur existe
    if (index_existant != -1) {
        
        if (p > basedonnes[index_existant].score) { 
            basedonnes[index_existant].score = p;
        }

    } 
    // Si le joueur n'existe pas
    else if (i < 100) {
        // Ajouter un nouveau joueur à la fin du tableau
        strcpy(basedonnes[i].nom, l);
        basedonnes[i].score = p;
        i++; // Incrémenter le compteur total
    }

    

    f = fopen("data/standing2.txt", "w"); // Ouvre pour écraser (TRUNCATE)
    if (!f) {
        printf("Erreur: impossible d'ouvrir le fichier standing2.txt en écriture.\n");
        return;
    }
    
    // Réécrire l'en-tête (nécessaire car la lecture l'avait ignoré)
    fprintf(f, "RANG\tNOM\t\tSCORE\n");
    fprintf(f, "===========================\n");
    fprintf(f, "===========================\n");

    // Écrire les données mises à jour
    for (int k = 0; k < i; k++) {
         fprintf(f, "%d\t%s\t\t%d\n", k+1, basedonnes[k].nom, basedonnes[k].score);
    }
    fclose(f);


    // 4. TRIER LE CLASSEMENT 
    mise_a_jour(); 
}