#include "grille.h"
#include "conversion_dimacs.h"
#include "jeu.h"
#include <string.h>


int main(int argc,char* argv[]){

    Grille G;
    int l,h;
    // Verif de la bonne utilisation du programme
    if(argc!=1){

        printf("Exemple d'utilisation : ./test_conversion\n");
        return 1;

    }
    printf("Veuillez entrer la longueur de la grille souhaitee (supérieur a 1 de préférence) :\n");
    scanf("%d",&l);
    printf("Veuillez entrer la hauteur de la grille souhaitee (supérieur a 1 de préférence) :\n");
    scanf("%d",&h);
    G = unique_sat_generation_grille_random(l,h,20);
    afficher_Grille(G);

    return 0;

}
