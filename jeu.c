#include "jeu.h"

Grille jouer_coup(Grille G){
    int x, y, mauvaise_val=1; 
    char retour_joueur;
    printf("Quelle case souhaitez-vous jouer? \n");
    scanf("%d %d",&y,&x);
    while(mauvaise_val){
        if((x>G.l) || (y>G.h) || (x<0) || (y<0)){
            printf("Votre valeur n'est pas dans la grille \n");
            printf("Quelle case souhaitez-vous jouer? \n");
            scanf("%d %d",&y,&x);
        }else if(G.tab[x][y]==LAMPE){
            printf("Il y a déjà une lampe sur cette case voulez vous la supprimer ? (Y/N)\n");
            scanf("\n");
            scanf("%c",&retour_joueur);
            if (retour_joueur=='Y'){
                supprimer_lampe(&G,x,y);
                printf("Voici la nouvelle grille : \n");
                afficher_Grille(G);
                return G;
            }
            else{
            printf("Quelle case souhaitez-vous jouer? \n");
            scanf("%d %d",&y,&x);
            }
        }
        else if(!est_libre(G,x,y)){
            afficher_grille(G);
            printf("Vous avez choisis une case deja prises.\n");
            printf("Quelle case souhaitez-vous jouer? \n");
            scanf("%d %d",&y,&x);
        }else{
            mauvaise_val = 0 ;
        }
    }

    G = ajouter_lampe(G,x,y);
    return G;
}


Grille fin_partie(Grille G,char *nom_fichier){
    FILE *f;
    char fich_dimacs[50];
    int i;
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

    f = fopen("output.txt","r");
    lecture_fich(f,G);

    return G;
}

int resultat_correcte(Grille G, char *nom_fichier){
    Grille correcte = copie_Grille(G);
    correcte = fin_partie(correcte, nom_fichier);
    int h, l;
    h = G.h;
    l = G.l;

    for(int i=0; i<h; i++){
        for(int j=0; j<l; j++){
            if(G.tab[i][j]!=correcte.tab[i][j]){
                return 0;
            }
        }
    }
    return 1;
}
void start(Grille grille, char *nom_fichier){
    int joue = 1, res;
    char retour_joueur;
    while(joue){
        printf("Voici la grille : \n");
        afficher_Grille(grille);
        jouer_coup(grille);
        printf("Voici la nouvelle grille : \n");
        afficher_Grille(grille);
        
        printf("Voulez-vous essayer ce résultats ? (Y/N) : ");
        scanf("%s",&retour_joueur);
        if( strcmp(&retour_joueur, "N")){
            res = resultat_correcte(grille,nom_fichier);
            if(res == 1){
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