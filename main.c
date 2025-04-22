#include <string.h>
#include "grille.h"
#include "conversion_dimacs.h"
#include "jeu.h"


int main(int argc, char* argv[]){
    FILE *f;
    char retour_joueur;
    int jouer = 1, choix_mode;
    if(argc!=2){

        printf("Exemple d'utilisation : ./test_grille <fichier_grille>\n");
        return 1;
    }


    f = fopen(argv[1],"r");
    if(f == NULL){

        printf("ERREUR : Fichier non existant\n");
        return 1;
    }
    printf("===================================\n");
    printf("\nBienvenue dans le jeu Light Up\n\n");
    printf("===================================\n");
    while(jouer){
        printf("Que souhaitez-vous faire ? (1/2/3/4)\n");
        printf("1. Jouer\n2. Solutions\n3. Les règles\n4. Quitter\n");
        scanf("%d",&choix_mode);
        switch (choix_mode)
        {
        case 1:    
            Grille grille = lire_Grille(f);
            fclose(f);
            start(grille, argv[1]);
            break;
        case 2:
            printf("===================================\n");
            printf("en construction\n");
            printf("===================================\n");
            break;  
        case 3:
            printf("===================================\n");
            printf("         REGLES DU JEU LIGHT UP     \n");
            printf("===================================\n\n");

            printf("Objectif :\n");
            printf("Placer des ampoules sur une grille pour que toutes les cases blanches soient eclairees.\n\n");

            printf("Regles :\n");
            printf("1. Une ampoule eclaire dans les 4 directions (haut, bas, gauche, droite)\n");
            printf("   jusqu'a rencontrer un mur (case noire).\n");
            printf("2. Aucune case blanche ne doit rester dans l'ombre.\n");
            printf("3. Deux ampoules ne peuvent pas s'eclairer mutuellement.\n");
            printf("4. Certaines cases noires portent un chiffre (de 0 a 4) :\n");
            printf("   - Ce chiffre indique le nombre exact d'ampoules qui doivent l'entourer.\n");
            printf("   - Les cases adjacentes sont celles en haut, bas, gauche et droite.\n\n");

            printf("Conseils :\n");
            printf("- Utilisez la logique pour deduire les emplacements des ampoules.\n");
            printf("- Commencez par les cases chiffre '4', car elles imposent 4 ampoules autour.\n");
            printf("- Evitez les configurations ou deux ampoules se voient.\n\n");

            printf("Bonne chance et amusez-vous bien !\n");
            printf("===================================\n");
            break;
        case 4:
            jouer = 0;
            printf("===================================\n");
            printf("Au revoir !\n");
            printf("===================================\n");
        default:
            break;
        }
    }
}