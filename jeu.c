#include "jeu.h"

Grille jouer_coup(Grille G){
    int x, y, mauvaise_val=1; 
    printf("Quelle case souhaitez-vous jouer? \n");
    scanf("%d %d",&y,&x);
    while(mauvaise_val){
        if((x>G.l) || (y>G.h) || (x<0) || (y<0)){
            printf("Votre valeur n'est pas dans la grille \n");
            printf("Quelle case souhaitez-vous jouer? \n");
            scanf("%d %d",&y,&x);
        }else if(!est_libre(G,x,y)){
            printf("Vous avez choisis une case deja prises.\n");
            printf("Quelle case souhaitez-vous jouer? \n");
            scanf("%d %d",&y,&x);
        }else{
            mauvaise_val = 0 ;
        }
    }

    G = ajouter_lampe(G,x,y);
    printf("Voici le nouvelle grille : \n");
    afficher_Grille(G);

    return G;
}


int fin_partie(Grille G,char *nom_fichier){
    FILE *f;
    char fich_dimacs[50];
    int i,res;
    char command[150] = "minisat ";
    char *fin_executable = " output.txt";

    // Création du fichier dimacs avec le nom du fichier grille mais en .cnf
    strcpy(fich_dimacs,nom_fichier);
    i = 0;
    while(fich_dimacs[i] !='.' && fich_dimacs[i] !='\0'){
    
      i++;
    
    }
    fich_dimacs[i+1]='c';
    fich_dimacs[i+2]='n';
    fich_dimacs[i+3]='f';
    fich_dimacs[i+4]='\0';

    f = fopen(fich_dimacs,"w"); // On ouvre le fichier .cnf
    ecriture_dimacs(f,G); // le fclose(f); est dans la fonction
     
    strcat(command,fich_dimacs);
    strcat(command,fin_executable);
    
    system(command);
    remove(fich_dimacs);

    f = fopen("output.txt","r");
    res = lecture_fich(f,G);
    afficher_Grille(G);

    if(res == 0){
        return 0;
    }else{
        return 1;
    }
}
void start(Grille grille, char *nom_fichier){
    int joue = 1, res;
    char retour_joueur;
    printf("Vous jouez avec la grille suivante : \n");

    afficher_Grille(grille);
    while(joue){
        jouer_coup(grille);

        printf("Voulez-vous essayer ce résultat ? (Y/N) : ");
        scanf("%s",&retour_joueur);
        if(strcmp(&retour_joueur, "N")){
            res = fin_partie(grille,nom_fichier);

            if(res == 0){
                printf("Votre solution est correcte !\n");
                joue = 0;
            }else{
                printf("Votre solution est incorrecte.\n");
                printf("Voulez-la modifier? (Y/N):");
                scanf("%s",&retour_joueur);
                if(strcmp(&retour_joueur, "Y")){
                    joue = 0;
                }else{
                    joue = 1;
                }
            }
        }else{
            joue = 1;
        }
    }
    printf("retour vers le menu \n");
}