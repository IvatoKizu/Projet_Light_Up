#include "grille.h"
#include "jeu.h"
#include <time.h>


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

                case 'L' : // Uniquement utile pour les tests d'affichage
                G.tab[i][j] = LAMPE;
                break;

                case '*' : // Uniquement utile pour les tests d'affichage
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

Grille copie_Grille(Grille G){
    Grille copie;
    copie = init_Grille(G.l, G.h);

    for(int i=0;i<G.h;i++){
        for(int j=0; j<G.l; j++){
            copie.tab[i][j] = G.tab[i][j];
        }
    }
    return copie;
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

void supprimer_lampe(Grille *G,int i,int j){
    int l,h,k;
    l=G->l;
    h=G->h;
    if (G->tab[i][j]!=LAMPE){
        printf("Erreur il n'y as pas de lampe a suprrimer sur cette case\n");
        return;
    }
    G->tab[i][j]=LIBRE;
    k=i-1;
    while (k>=0 && !est_mur(*G,k,j)){
        if (!est_eclaire(*G,k,j)){
            G->tab[k][j]=LIBRE;
        }
        k--;
    }
    k=j-1;
    while (k>=0 && !est_mur(*G,i,k)){
        if (!est_eclaire(*G,i,k)){
            G->tab[i][k]=LIBRE;
        }
        k--;
    }
    k=j+1;
    while (k<l && !est_mur(*G,i,k)){
        if (!est_eclaire(*G,i,k)){
            G->tab[i][k]=LIBRE;
        }
        k++;
    }
    k=i+1;
    while (k<h && !est_mur(*G,k,j)){
        if (!est_eclaire(*G,k,j)){
            G->tab[k][j]=LIBRE;
        }
        k++;
    }
}

int est_eclaire(Grille G, int i,int j){
    int l,h,k;
    l=G.l;
    h=G.h;
    k=i-1;
    if (G.tab[i][j]==LAMPE) return 1;
    while (k>=0 && !est_mur(G,k,j)){
        if (G.tab[k][j]==LAMPE) return 1;
        k--;
    }
    k=j-1;
    while (k>=0 && !est_mur(G,i,k)){
        if (G.tab[i][k]==LAMPE) return 1;
        k--;
    }
    k=j+1;
    while (k<l && !est_mur(G,i,k)){
        if (G.tab[i][k]==LAMPE) return 1;
        k++;
    }
    k=i+1;
    while (k<h && !est_mur(G,k,j)){
        if (G.tab[k][j]==LAMPE) return 1;
        k++;
    }
    return 0;
}



void afficher_Grille(Grille G){

    int i,j,k,l;
    printf("  ");
    for(l = 1;l<=G.l;l++){
        if(l<10){
            printf("   %d",l);
        }
        else{
            printf("  %d",l);
        }
    }
    printf("\n");
    printf("   +");
        for(k = 0;k<G.l;k++){

            printf("---+");

        }

    printf("\n");

    for(i = 0;i<G.h;i++){
        if(i+1<10){
            printf("%d  |",i+1);
        }
        else{
            printf("%d |",i+1);
        }
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
        printf("   +");
        for(k = 0;k<G.l;k++){

            printf("---+");

        }

        printf("\n");

    }

}

int est_libre(Grille G,int i,int j){
    if ((i>=G.h) || (j>=G.l) || (i<0) || (j<0)) return 0;
    if (G.tab[i][j]== LIBRE) return 1;
    else return 0;
}

int est_mur(Grille G,int i,int j){
    if (G.tab[i][j]==MUR || G.tab[i][j]==MUR_0 || G.tab[i][j]==MUR_1 || G.tab[i][j]==MUR_2 || G.tab[i][j]==MUR_3 || G.tab[i][j]==MUR_4) return 1;
    else return 0;
}

Grille generation_grille_random(int longueur, int hauteur, int pourcentage_mur){

    Grille G;
    int i,j,pourcentage,acc;

    G = init_Grille(longueur,hauteur);
    for(i = 0;i<G.h;i++){

       for(j = 0;j<G.l;j++){

            pourcentage = rand() % 100 + 1;
            if(pourcentage <= pourcentage_mur){
                G.tab[i][j] = MUR;
            }
            else{
                G.tab[i][j] = LIBRE;
            }
       }

    }
    for(i = 0;i<G.h;i++){

        for(j = 0;j<G.l;j++){
            if(G.tab[i][j]==MUR){
                pourcentage = rand() % 100 + 1;
                if(pourcentage <= 50){
                    G.tab[i][j]=MUR;
                }
                else if(pourcentage <= 60) {
                    G.tab[i][j]=MUR_0;
                }
                else if(pourcentage <= 70 ){
                    if(est_libre(G,i-1,j) || est_libre(G,i+1,j) || est_libre(G,i,j-1) || est_libre(G,i,j+1)){
                        G.tab[i][j] = MUR_1;
                    }
                }
                else if(pourcentage <= 80){
                    acc=0;
                    acc+=est_libre(G,i-1,j);
                    acc+=est_libre(G,i+1,j);
                    acc+=est_libre(G,i,j+1);
                    acc+=est_libre(G,i,j-1);
                    if(acc>=2){
                    G.tab[i][j] = MUR_2;
                    }
                }
                else if(pourcentage <= 90){
                    acc=0;
                    acc+=est_libre(G,i-1,j);
                    acc+=est_libre(G,i+1,j);
                    acc+=est_libre(G,i,j+1);
                    acc+=est_libre(G,i,j-1);
                    if(acc>=3){
                        G.tab[i][j] = MUR_3;
                    }
                }
                else {
                    acc=0;
                    acc+=est_libre(G,i-1,j);
                    acc+=est_libre(G,i+1,j);
                    acc+=est_libre(G,i,j+1);
                    acc+=est_libre(G,i,j-1);
                    if(acc==4){
                        G.tab[i][j] = MUR_4;
                    }
                }
            }
        }
 
     }
    return G;
}

Grille unique_sat_generation_grille_random(int longueur, int hauteur, int pourcentage_mur){ 

    Grille G,G2;
    
    srand(time(NULL));
    G = generation_grille_random(longueur,hauteur,pourcentage_mur);
    G2 = copie_Grille(G);
    while(satisfaisabilite_unicite(G)){
        supprime_Grille(G);
        supprime_Grille(G2);
        G = generation_grille_random(longueur,hauteur,pourcentage_mur);
        G2 = copie_Grille(G);
    }
    supprime_Grille(G);
    return G2;
}

void supprime_Grille(Grille G){

    int i;
    
    for(i = 0;i<G.h; i++){

        free(G.tab[i]);

    }
    free(G.tab);

}
