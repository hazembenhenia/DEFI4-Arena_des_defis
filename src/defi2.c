#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "defi2.h"

/**********************************************
 * DEFI 2 : MASTERMIND ALGORITHMIQUE (EN C)   *
 **********************************************/

#define CODE_LEN 4

#define MAX_DIGIT 6


// Générer un code secret aléatoire
void generer_code(int code[]) {
    for(int i = 0; i < CODE_LEN; i++) {
        code[i] = rand() % MAX_DIGIT + 1;
    }
}

// Comparer l'essai du joueur avec le code secret
void comparer_codes(int code[], int essai[], int *bien_places, int *mal_places) {
    int utilise_code[CODE_LEN] = {0};
    int utilise_essai[CODE_LEN] = {0};

    *bien_places = 0;
    *mal_places = 0;

    // Comptage des bien placés
    for(int i = 0; i < CODE_LEN; i++) {
        if(code[i] == essai[i]) {
            (*bien_places)++;
            utilise_code[i] = 1;
            utilise_essai[i] = 1;
        }
    }

    // Comptage des mal placés
    for(int i = 0; i < CODE_LEN; i++) {
        if(!utilise_code[i]) {
            for(int j = 0; j < CODE_LEN; j++) {
                if(!utilise_essai[j] && code[i] == essai[j]) {
                    (*mal_places)++;
                    utilise_essai[j] = 1;
                    break;
                }
            }
        }
    }
}

// Le jeu Mastermind
bool mastermind() {
    int code[CODE_LEN], essai[CODE_LEN];
    int bien, mal;
    int tentatives = 0;
    const int MAX_TENTATIVES = 5;

    generer_code(code);

    printf("=== DEFI 2 : MASTERMIND ===\n");
    printf("Devine une combinaison de %d chiffres entre 1 et %d.\n", CODE_LEN, MAX_DIGIT);
    printf("Tu as %d tentatives maximum.\n", MAX_TENTATIVES);

    while(tentatives < MAX_TENTATIVES) {
        printf("\nTentative %d : ", tentatives);

        // Lire une tentative complète de CODE_LEN chiffres
        for(int i = 0; i < CODE_LEN; i++) {
            scanf("%d", &essai[i]);
        }
        tentatives++;
        // Comparer le code
        comparer_codes(code, essai, &bien, &mal);

        // Afficher le résultat immédiatement
        printf("Bien places : %d | Mal places : %d\n", bien, mal);

        // Vérifier si le joueur a gagné
        if(bien == CODE_LEN) {
            printf("\nBravo ! Tu as trouve le code en %d tentatives.\n", tentatives);
            return true;
        }
    }

    // Si le joueur n'a pas trouvé après MAX_TENTATIVES
    printf("\nDésolé ! Tu as depasse %d tentatives.\n", MAX_TENTATIVES);
    printf("Le code secret etait : ");
    for(int i = 0; i < CODE_LEN; i++) printf("%d ", code[i]);
    printf("\n");
    return false;
}


bool defi2() {
    printf("TEST");
    srand(time(NULL));
    return mastermind();

}
