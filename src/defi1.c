#include <stdio.h>
#define tache1_H
#include <stdbool.h>

int cible;
int l[6];
int liste2[6];       
int solutions = 0;

typedef struct {
    int left;
    int right;
    char op;   
    int resultat;
} operations;

operations operationss[10];
int operations_count = 0;

int solve(int entier) {
    if (entier == cible) {
        solutions = 1;
        return 1;
    }
    if (entier > cible + 100 || entier < 0) return 0;

    for (int i = 0; i < 6; i++) {
        if (liste2[i]) continue;

        int x = l[i];

        liste2[i] = 1;
        operationss[operations_count].left = entier;
        operationss[operations_count].right = x;
        operationss[operations_count].op = '+';
        operationss[operations_count].resultat = entier + x;
        operations_count++;

        if (solve(entier + x)) return 1;

        operations_count--;

        operationss[operations_count].left = entier;
        operationss[operations_count].right = x;
        operationss[operations_count].op = '-';
        operationss[operations_count].resultat = entier - x;
        operations_count++;

        if (solve(entier - x)) return 1;

        operations_count--;

        operationss[operations_count].left = entier;
        operationss[operations_count].right = x;
        operationss[operations_count].op = '*';
        operationss[operations_count].resultat = entier * x;
        operations_count++;

        if (solve(entier * x)) return 1;

        operations_count--;
        if (x != 0 && entier % x == 0) {
            operationss[operations_count].left = entier;
            operationss[operations_count].right = x;
            operationss[operations_count].op = '/';
            operationss[operations_count].resultat = entier / x;
            operations_count++;

            if (solve(entier / x)) return 1;

            operations_count--;
        }

        liste2[i] = 0;
    }

    return 0;
}

bool defi1() {
    printf("ENTRER 6 NOMBRES : ");
    for (int i = 0; i < 6; i++) {
        scanf("%d", &l[i]);
        liste2[i] = 0;
    }
    printf("ENTRER LA CIBLE : ");
    scanf("%d", &cible);

    for (int i = 0; i < 6 && !solutions; i++) {
        for (int k = 0; k < 6; k++) liste2[k] = 0;
        operations_count = 0;

        int start = l[i];
        liste2[i] = 1;

        if (solve(start)) {
            printf("SOLUTION TROUVEE:\n");
            
            int prev = l[i];
            for (int s = 0; s < operations_count; s++) {
                printf("%d%c%d=%d\n",
                       operationss[s].left,
                       operationss[s].op,
                       operationss[s].right,
                       operationss[s].resultat);
                prev = operationss[s].resultat;
            }
            return true ;
            return 0;
        }
    }

    if (!solutions) {
        printf("AUCUNE SOLUTION TROUVEE.\n");
        return false;
    }

    return 0;
}
