#include "grille.h"
#include "conversion_dimacs.h"
#include <string.h>


int main(int argc,char* argv[]){

    FILE *f;
    Grille G;
    char fich_dimacs[50];
    int i,res;
    char command[150] = "minisat ";
    char *fin_executable = " output.txt";

    // Verif de la bonne utilisation du programme
    if(argc!=2){

        printf("Exemple d'utilisation : ./test_conversion <fichier_grille>\n");
        return 1;

    }
    // Création du fichier dimacs avec le nom du fichier grille mais en .cnf
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

    f = fopen(argv[1],"r");
    if(f == NULL){
      printf("ERREUR, impossible le fichier %s n'existe pas",argv[1]);
      return 1;
    }
    G = lire_Grille(f);
    fclose(f);  // On a fait la lecture de la grille du fichier .txt, on peut donc fclose
    f = fopen(fich_dimacs,"w"); // On ouvre le fichier .cnf
    ecriture_dimacs(f,G); // le fclose(f); est dans la fonction
     
    strcat(command,fich_dimacs);
    strcat(command,fin_executable);
    
    system(command);

    f = fopen("output.txt","r");
    res = lecture_fich(f,G);
    afficher_Grille(G);

    return 0;

}