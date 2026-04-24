#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include "date_submission.h"
#include "statspersonnel.h"


void add_to_historique(char *l,int c,bool b) {
    
    FILE *f = fopen("data/basedonne.txt", "a");
    if (!f) {
        printf("Erreur: impossible d'ouvrir le fichier.\n");
    }
    char *nom_defi = "INCONNU";
    if (c==1) {
        nom_defi="DEFI1";
    } 
    if (c==2) {
        nom_defi="DEFI2";
    } 
    if (c==3) {
        nom_defi="DEFI3";
    } 
    if (c==4) {
        nom_defi="DEFI4";
    } 

    if (b) fprintf(f,"%s\t%s\t%s\tACCEPTED\n",l,nom_defi,timing());
    else fprintf(f,"%s\t%s\t%s\tREFUSED\n",l,nom_defi,timing());
    fclose(f);

    
}