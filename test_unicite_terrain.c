#include "grille.h"
#include "conversion_dimacs.h"
#include "jeu.h"
#include <string.h>

int main(int argc,char* argv[]){

    Grille G;
    FILE *f;
    int res;
    if(argc!=2){

        printf("Exemple d'utilisation : ./test_unicite_terrain <fichier terrain.txt>\n");
        return 1;

    }
    f=fopen(argv[1],"r");
    G=lire_Grille(f);
    fclose(f);
    afficher_Grille(G);
    res=satisfaisabilite_unicite(G);
    if (res){
        printf("Le terrain a plusieurs solution \n");
    }
    else {
        printf("Le terrain à une solution unique \n");
    }
    return 0;

}