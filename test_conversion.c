#include "grille.h"
#include "conversion_dimacs.h"
#include <string.h>


int main(int argc,char* argv[]){

    FILE *f;
    Grille G;
    char fich_dimacs[50];
    int i,res;

    if(argc!=2){

        printf("Exemple d'utilisation : ./test_conversion <fichier_grille>\n");
        return 1;

    }

    strcpy(fich_dimacs,argv[1]);
    i = 0;
    while(fich_dimacs[i] !='.' && fich_dimacs[i] !='\0'){
    
      i++;
    
    }
    if(fich_dimacs[i]=='\0'){
    
      printf("ERREUR\nL'argument n'est pas un fichier .txt\n");
      return 1;
    
    }
    fich_dimacs[i+1]='c';
    fich_dimacs[i+2]='n';
    fich_dimacs[i+3]='f';
    fich_dimacs[i+4]='\0';

    // Test d'utilisation du minisat avec system


    //system("minisat Dimacs_tests/test_1.cnf Output_minisat/output.txt > /dev/null");

    return 0;

}