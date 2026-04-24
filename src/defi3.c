#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>


#define MAX_list 100


typedef struct element {
    char val;
    struct element *suivant;
}element;
element *liste = NULL;

element *ajout(element* liste,int valeur){
    element *nouveau=malloc(sizeof(element));
    nouveau->val=valeur;
    nouveau->suivant=NULL;
    if(liste==NULL) return nouveau;
    element* tmp=liste;
    while(tmp->suivant!=NULL){
        tmp=tmp->suivant;
    }
    tmp->suivant=nouveau;
    return liste;
}


void afficherliste(element* liste){
    while(liste!=NULL){
        printf("%c ", liste->val);
        liste=liste->suivant;
    }
    printf("\n");
}


int comparer(element* a,element* b){
    while(a!=NULL && b!=NULL){
        if(a->val !=b->val){
            return 0;
        }    
        a=a->suivant;
        b=b->suivant;
        
    }
    return(a==NULL && b==NULL);
}


int random_range(int min,int max){
    return(min+rand()%(max-min+1));
}


element* grille(int n){
    char grille1[]={'E','S','E','S'};
    char grille2[]={'E','N','E','S','E','S','E'};
    element* liste=NULL;
    if(n==1){
        for(int i=0;i<4;i++){
            liste=ajout(liste,grille1[i]);
        }
    }else{
        for(int i=0;i<7;i++){
            liste=ajout(liste,grille2[i]);
        }
    }
    return liste;
    
    
}
bool defi3(){
    srand((unsigned)time(NULL));
    int x=random_range(1,2);
    element* solution=grille(x);
    char line[255];
    if(x==1){
        FILE *f1 = fopen("data/grille1.txt", "r");
        if (!f1) {
            printf("Erreur: impossible d'ouvrir le fichier.\n");
        }    
        while (fgets(line, sizeof(line), f1) != NULL) {
            printf("%s",line);
        }
        fclose(f1);
        
    }else{
        FILE *f2 = fopen("data/grille2.txt", "r");
        if (!f2) {
            ("Erreur: impossible d'ouvrir le fichier.\n");
        
        }
        while (fgets(line, sizeof(line), f2) != NULL) {
            printf("%s",line);
        }
        fclose(f2);

    }
    printf("\n\n");
    
    printf("\nDONNER LE PLUS COURT CHEMIN (N E S W) POUR ARRIVER A LA SORTIE\n");
    
    element* user =NULL;
    char c;
    printf("ENTRER VOTRE CHEMIN SEPARES PAR DES ESPACES (AVEC X A LA FIN): ");
    while(1){
        scanf(" %c", &c);
        if(c=='X') break;
        user=ajout(user,c);
    }
    if(comparer(solution,user)){
        printf("\n LE CHEMIN EST CORRECT ,TU AS GAGNE!\n");
        return true;
        
    }else{
        printf("CHEMIN INCORRECT.\n");
        
        
        return false;
        
    }
    
}