#include <string.h>
#include "grille.h"
#include "conversion_dimacs.h"
#include "jeu.h"


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
    fclose(f);

    retour_joueur = 'Y';

    while(jouer){
        if(strcmp(&retour_joueur, "N")){
            start(grille, argv[1]);
            printf("Voulez-vous rejouer ? (Y/N) : ");
            scanf("%s",&retour_joueur);
        }else{
            jouer = 0;
            printf("Au revoir!\n");
        }
    }

}