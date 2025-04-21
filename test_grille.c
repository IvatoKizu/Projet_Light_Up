#include "grille.h"

int main(int argc,char* argv[]){

    FILE *f;
    Grille G;

    if(argc!=2){

        printf("Exemple d'utilisation : ./test_grille <fichier_grille>");

    }

    f = fopen(argv[1],"r");

    if(f == NULL){

        printf("ERREUR : Fichier non existant\n");
        return 1;

    }

    G = lire_Grille(f);

    afficher_Grille(G);


    printf("test d'ajout lampe\n");

    G = ajouter_lampe(G, 1, 1);

    afficher_Grille(G);
    return 1;

}