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

Grille ajouter_lampe(Grille G, int x, int y){
    int i, hauteur, largeur;
    largeur = G.l;
    hauteur = G.h;
    Case **tab = G.tab;
    if(est_mur(G, x, y)){
        printf("Erreur de coordonné\n");
        return G;
    }
    tab[x][y] = LAMPE;


    int decalage_x[] = {-1,1,0,0};
    int decalage_y[] = {0,0,-1,1};

    for(i = 0; i < 4; i++){
        int nouveau_x = x + decalage_x[i];
        int nouveau_y = y + decalage_y[i];

        while( (nouveau_x >= 0) && (nouveau_x < hauteur) && (nouveau_y >= 0) && (nouveau_y < largeur)){
            Case c = tab[nouveau_x][nouveau_y];

            if(est_mur(G, nouveau_x, nouveau_y)){
                break;
            }

            if(c == LIBRE){
                tab[nouveau_x][nouveau_y] = ECLAIRE;
            }

            nouveau_x += decalage_x[i];
            nouveau_y += decalage_y[i];
        }
    }
    
    G.tab = tab;
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

int est_mur(Grille G,int i,int j){
    if (G.tab[i][j]==MUR || G.tab[i][j]==MUR_0 || G.tab[i][j]==MUR_1 || G.tab[i][j]==MUR_2 || G.tab[i][j]==MUR_3 || G.tab[i][j]==MUR_4) return 1;
    else return 0;
}