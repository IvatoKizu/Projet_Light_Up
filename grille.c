#include "grille.h"

Grille init_Grille(int longueur, int hauteur){

    Grille G;

    G.l = longueur;
    G.h = hauteur;

    G.tab = malloc(sizeof(Case*) * hauteur);

    for(int i = 0; i<hauteur;i++){

        G.tab[i] = malloc(sizeof(Case) * longueur);

    }

    return G;

}

Grille lire_Grille(FILE *f){

    int l,h,i,j;
    Grille G;
    char c;
    
    fscanf(f,"%d\n",&l);
    fscanf(f,"%d\n",&h);

    G = init_Grille(l,h);

    for(i = 0;i<h;i++){

        for(j = 0;j<l;j++){

            fscanf(f,"%c",&c);
            switch(c){

                case '.' :
                G.tab[i][j] = LIBRE;
                break;

                case 'L' : // A enlever, là pour les tests d'affichage
                G.tab[i][j] = LAMPE;
                break;

                case '*' : // A enlever, là pour les tests d'affichage
                G.tab[i][j] = ECLAIRE;
                break;

                case 'M' :
                G.tab[i][j] = MUR;
                break;

                case '0' :
                G.tab[i][j] = MUR_0;
                break;

                case '1' :
                G.tab[i][j] = MUR_1;
                break;

                case '2' :
                G.tab[i][j] = MUR_2;
                break;

                case '3' :
                G.tab[i][j] = MUR_3;
                break;

                case '4' :
                G.tab[i][j] = MUR_4;
                break;

            }

        }

        fscanf(f,"\n");

    }

    fscanf(f,"\n");

    return G;

}


void afficher_Grille(Grille G){

    int i,j,k;

    printf("+");
        for(k = 0;k<G.l;k++){

            printf("---+");

        }

    printf("\n");

    for(i = 0;i<G.h;i++){

         printf("|");

        for(j = 0;j<G.l;j++){

            switch(G.tab[i][j]){

                case LIBRE:
                printf("   |");
                break;

                case LAMPE:
                printf(" @ |");
                break;

                case ECLAIRE:
                printf(" . |");
                break;

                case MUR:
                printf(" # |");
                break;

                case MUR_0:
                printf(" 0 |");
                break;

                case MUR_1:
                printf(" 1 |");
                break;
                
                case MUR_2:
                printf(" 2 |");
                break;

                case MUR_3:
                printf(" 3 |");
                break;

                case MUR_4:
                printf(" 4 |");
                break;
            }

        }

        printf("\n");
        printf("+");
        for(k = 0;k<G.l;k++){

            printf("---+");

        }

        printf("\n");

    }

}