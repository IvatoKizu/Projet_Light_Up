#include <string.h>
#include "grille.h"
#include "conversion_dimacs.h"
#include "jeu.h"


int main(int argc, char* argv[]){
    Grille grille, grille_sol;
    int jouer = 1, choix_mode;
    char *nom_fichier=NULL;
    printf("===================================\n");
    printf("\nBienvenue dans le jeu Light Up\n\n");
    printf("===================================\n");
    while(jouer){
        printf("Menu Principal:\n");
        printf("===================================\n");
        printf("1. Jouer\n2. Solutions\n3. Les règles\n4. Quitter\n");
        printf("Que souhaitez-vous faire ? (1/2/3/4) :");
        scanf("%d",&choix_mode);
        switch (choix_mode)
        {
        case 1:    
            grille = choix_fichier(&nom_fichier);
            start(grille, argv[1]);
            break;
        case 2:
            printf("===================================\n");
            grille = choix_fichier(&nom_fichier);
            printf("%s\n",nom_fichier);
            grille_sol = copie_Grille(grille);
            grille_sol = fin_partie(grille_sol, nom_fichier);
            printf("La grille vide est : \n");
            afficher_Grille(grille);
            printf("La solution est : \n");
            afficher_Grille(grille_sol);
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
            break;
        default:
            printf("\nVeuillez rentrez uniquement une des valeurs suivants: 1 2 3 4 \n");
            printf("===================================\n");
            jouer = 1;
            break;
        }
    }
}