#include <string.h>
#include "grille.h"
#include "conversion_dimacs.h"

Grille start(){
    int largeur, hauteur;

    printf("Création de votre grille\n");
    printf("Combien de ligne souhaitez-vous? ");
    scanf("%d",&largeur);

    printf("\nCombien de colonnes souhaitez-vous? ");
    scanf("%d",&hauteur);
    printf("\n");

    return init_Grille(hauteur,largeur);
}


int main(int argc,char* argv[]){
    Grille grille = start();
    afficher_Grille(grille);

    printf("test\n");

    grille = ajouter_lampe(grille, 3, 3);

    afficher_Grille(grille);
}