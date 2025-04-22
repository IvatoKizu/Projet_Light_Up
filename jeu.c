#include "jeu.h"

Grille choix_fichier(char **nom_fichier){
    Grille grille;
    int choix;
    FILE *f;
    printf("1.  grille 1\n2.  grille 7x7 facile \n3.  grille 7x7 Moyenne \n4.  grille 7x7 Difficile\n");
    printf("5.  grille 10x10 facile \n6.  grille 10x10 Difficile\n");
    printf("7.  grille 14x14 facile \n8.  grille 14x14 Moyenne \n9.  grille 14x14 Difficile\n");
    printf("10. Grille aléatoire\n");
    printf("Avec quelle grille souhaitez-vous jouer? (1/2/3/4/5/6/7/8/9/10): ");
    scanf("%d",&choix);
    
    switch (choix)
    {
    case 1:
        *nom_fichier = "test/grille_1.txt";
        break;
    case 2:
        *nom_fichier = "test/grille_7x7_ez.txt";
        break;
    case 3:
        *nom_fichier = "test/grille_7x7_tricky.txt";
        break;
    case 4:
        *nom_fichier = "test/grille_7x7_hard.txt";
        break;
    case 5:
        *nom_fichier = "test/grille_10x10_ez.txt";
        break;
    case 6:
        *nom_fichier = "test/grille_10x10_tricky.txt";
        break;
    case 7:
        *nom_fichier = "test/grille_14x14_ez.txt";
        break;
    case 8:
        *nom_fichier = "test/grille_14x14_tricky.txt";
        break;
    case 9:
        *nom_fichier = "test/grille_14x14_hard.txt";
        break;
    case 10:
        printf("en construction pour l'instant ce sera la grille_1.txt\n");
        *nom_fichier = "test/grille_1.txt";
        break;
    default:
        break;
    }

    printf("Vous avez choisis le fichier: %s\n",*nom_fichier);
    f = fopen(*nom_fichier,"r");
    grille = lire_Grille(f);
    fclose(f);
    return grille;
}

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
            afficher_Grille(G);
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
    remove(fich_dimacs);

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
