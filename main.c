#include <string.h>
#include "grille.h"
#include "conversion_dimacs.h"

Grille jouer_coup(Grille G){
    int x, y, mauvaise_val=1; 
    printf("Quelle case souhaitez-vous jouer? \n");
    scanf("%d %d",&y,&x);
    while(mauvaise_val){
        if((x>G.l) || (y>G.h) || (x<0) || (y<0)){
            printf("Votre valeur n'est pas dans la grille \n");
            printf("Quelle case souhaitez-vous jouer? \n");
            scanf("%d %d",&y,&x);
        }else if(!est_libre(G,x,y)){
            printf("Vous avez choisis une case deja prises.\n");
            printf("Quelle case souhaitez-vous jouer? \n");
            scanf("%d %d",&y,&x);
        }else{
            mauvaise_val = 0 ;
        }
    }

    G = ajouter_lampe(G,x,y);
    printf("Voici le nouvelle grille : \n");
    afficher_Grille(G);

    return G;
}

void start(Grille grille){
    int joue = 1;
    char retour_joueur;
    printf("Vous jouez avec la grille suivante : \n");

    afficher_Grille(grille);
    while(joue){
        printf("boucle\n");
        jouer_coup(grille);

        printf("Voulez-vous essayer ce résultats ? (Y/N) : ");
        scanf("%s",&retour_joueur);
        if(strcmp(&retour_joueur, "N")){
            // fin_partie(grille);
            joue = 0;
        }else{
            joue = 1;
        }
    }
    printf("retour vers le menu \n");
}

int main(int argc, char* argv[]){
    FILE *f;
    char retour_joueur;
    int jouer = 1;
    if(argc!=2){

        printf("Exemple d'utilisation : ./test_grille <fichier_grille>\n");
        return 1;
    }


    f = fopen(argv[1],"r");
    if(f == NULL){

        printf("ERREUR : Fichier non existant\n");
        return 1;
    }
    printf("\nBienvenue dans le jeu Light Up\n\n");
    Grille grille = lire_Grille(f);

    retour_joueur = 'Y';

    while(jouer){
        if(strcmp(&retour_joueur, "N")){
            start(grille);
            printf("Voulez-vous rejouer ? (Y/N) : ");
            scanf("%s",&retour_joueur);
        }else{
            jouer = 0;
            printf("Au revoir!\n");
        }
    }

}