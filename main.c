#include <string.h>
#include "grille.h"
#include "conversion_dimacs.h"

Grille jouer_coup(Grille G){
    int x, y; 
    Case **tab = G.tab;
    printf("Quelle case souhaitez-vous jouer? \n");
    scanf("%d %d",&x,&y);

    if((x))
}


int main(int argc, char* argv[]){
    FILE *f;
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
    printf("Vous jouez avec la grille suivante : \n");

    afficher_Grille(grille);
    int joue = 1;

    While(joue){
        
    }
}