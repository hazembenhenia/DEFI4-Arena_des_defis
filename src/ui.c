#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "ecriredansclassement.h"
#include "ajouterligne.h"
#include "affichestanding.h"
#include "addsubmission.h"
#include "affichestats.h"
#include "defi1.h"
#include "defi2.h"
#include "defi3.h"
#include "defi4.h"
#include "ui.h"
#include "statspersonnel.h"
#include "affichehistorique.h"

void ui_run(){

    char name[25];
    printf("Saisir votre surnom : ");
    scanf("%24s", name);
    int s=0;

    

    int choice;
    int nb_essai1=1,nb_essai2=1,nb_essai3=1,nb_essai4=1;

    while(1){
        printf("\n============ MENU ============\n\n");
        printf("1) RESOUDRE DES DEFIS\n");
        printf("2) AFFICHER LES STATISTIQUES\n");
        printf("3) AFFICHER LE CLASSEMENT\n");
        printf("4) AFFICHER L'HISTORIQUE\n");
        printf("0) QUITTER\n\n");
        printf("============================\n\n\n");
        printf("SAISIR VOTRE CHOIX : ");
        scanf("%d", &choice);
        printf("\n\n");

        if(choice == 0) break;
        else if(choice == 1) {
            bool b;
            printf("1) DEFI: LE COMPTE EST BON\n");
            printf("2) DEFI: MASTERMIND ALGORITHMIQUE\n");
            printf("3) DEFI: COURSE DE ROBOTS\n");
            printf("4) DEFI: TRI ULTIME\n");
            printf("0) QUITTER\n\n");
            printf("SAISIR VOTRE CHOIX : ");
            scanf("%d", &choice);
            printf("\n\n");
            if(choice == 0) {
                break;
            }
            else if(choice == 1) {
                if (defi1()) {
                    b=true;
                    s+=20;
                    ajouter_submission(name,nb_essai1,choice);
                    
                }
                else {
                    nb_essai1++;
                    s-=5;
                    b=false;
                }
            
            
            }
            else if(choice == 2) {
                if (defi2()) {
                    b=true;
                    s+=35;
                    ajouter_submission(name,nb_essai2,choice);
                }
                else {
                    nb_essai2++;
                    s-=5;
                    b=false;

                }
            
         
            }
            else if(choice == 3) {
                if (defi3()) {
                    b=true;
                    s+=10;
                    ajouter_submission(name,nb_essai3,choice);
                    
                }
                else {
                    nb_essai3++;
                    s-=5;
                    b=false;
                }
            }
            else if(choice == 4) {
                if (defi4()) {
                    s+=25;
                    ajouter_submission(name,nb_essai4,choice);
                    b=true;
                }
                else {
                    nb_essai4++;
                    s-=5;
                    b=false;
                }
            }
            else printf("CHOIX INVALIDE\n");
            add_to_historique(name,choice,b);

            
        }
        else if(choice == 2) {
            affiche_stats();
            
        }
        else if(choice == 3) {
            affichage();
        }
        else if (choice == 4){
            affichage_historique();
        }
        
        else printf("Choix invalide\n");
        
        ajouter_ligne(name,s);
        
    }
    

    
}
