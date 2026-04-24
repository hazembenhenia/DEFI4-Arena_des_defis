#include <stdio.h>
#include <stdlib.h>
#include "date_submission.h"
#include "addsubmission.h"

void ajouter_submission (char *ch ,int nb ,int c) {
    if (c==1) {
        FILE *f = fopen("data/statsdefi1.txt", "a");
        if (!f) {
            printf("Erreur: impossible d'ouvrir le fichier.\n");
        
        }

        fprintf(f, "%s\t\t%d\t\t%s\n",ch, nb,timing());
        fclose(f);
    }

    if (c==2) {
        FILE *f = fopen("data/statsdefi2.txt", "a");
        if (!f) {
            printf("Erreur: impossible d'ouvrir le fichier.\n");
        
        }

        fprintf(f, "%s\t\t%d\t\t%s\n",ch, nb,timing());
        fclose(f);
    }

    if (c==3) {
        FILE *f = fopen("data/statsdefi3.txt", "a");
        if (!f) {
            printf("Erreur: impossible d'ouvrir le fichier.\n");
        
        }

        fprintf(f, "%s\t\t%d\t\t%s\n",ch, nb,timing());
        fclose(f);
    }

    if (c==4) {
        FILE *f = fopen("data/statsdefi4.txt", "a");
        if (!f) {
            printf("Erreur: impossible d'ouvrir le fichier.\n");
        }
        fprintf(f, "%s\t\t%d\t\t%s\n",ch, nb,timing());
        fclose(f);
    }
    
    printf("\n\n\n");
}