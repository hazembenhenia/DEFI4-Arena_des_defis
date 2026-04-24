#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "defi4.h"

#define N 5  // taille du tableau

// Fonction pour vérifier si le tableau est trié
int estTrie(int tab[], int n) {
    for(int i = 0; i < n - 1; i++) {
        if(tab[i] > tab[i+1]) return 0;
    }
    return 1;
}

// Afficher le tableau
void afficher(int tab[], int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", tab[i]);
    }
    printf("\n");
}

bool defi4() {
    int tab[N];
    int ech = 0;

    srand(time(NULL));

    // Générer un tableau aléatoire entre 1 et 20
    for(int i = 0; i < N; i++) {
        tab[i] = rand() % 20 + 1;
    }

    printf("=== DEFI 4 : TRI ULTIME INTERACTIF ===\n\n");
    printf("OBJECTIF : TRIER LE TABLEAU AVEC LE MOINS D'ECHANGES POSSIBLES.\n");
    printf("TABLEAU INITIAL : ");
    afficher(tab, N);

    int pos1, pos2;

    while(!estTrie(tab, N)) {
        printf("\nENTREZ DEUX POSITIONS A ECHANGER (0-%d) : ", N-1);
        scanf("%d %d", &pos1, &pos2);

        // Vérifier validité
        if(pos1 < 0 || pos1 >= N || pos2 < 0 || pos2 >= N) {
            printf("POSITIONS INVALIDES. REESSAYER.\n");
            continue;
        }

        // Faire l'échange
        int tmp = tab[pos1];
        tab[pos1] = tab[pos2];
        tab[pos2] = tmp;

        ech++;  // compter l'échange

        printf("TABLEAU ACTUEL : ");
        afficher(tab, N);
    }

    printf("\nBRAVO ! TABLEAU TRIE.\n");
    printf("NOMBRE TOTAL D'ECHANGES : %d\n", ech);

    // Optionnel : calculer le nombre minimal d'échanges théorique
    // (pour N petit on peut l’afficher pour info)
    printf("NOMBRE MINIMAL D'ECHANGES THEORIQUES (ESTIMATION) : %d\n", N-1);
    if (ech<=N-1){
        printf("TU AS GAGNE\n");
        return true;
    }
    else{
        printf("TU AS PERDU\n");
        return false;
    }
    system("pause");

    
}
