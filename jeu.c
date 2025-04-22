#include "jeu.h"

Grille choix_fichier(char **nom_fichier){
    Grille grille;
    int choix,c;
    float pourcentage;
    int x,y,bonne_valeur = 1;
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
        printf("Vous avez choisis le fichier: %s\n",*nom_fichier);
        f = fopen(*nom_fichier,"r");
        grille = lire_Grille(f);
        fclose(f);
        break;
    case 2:
        *nom_fichier = "test/grille_7x7_ez.txt";
        printf("Vous avez choisis le fichier: %s\n",*nom_fichier);
        f = fopen(*nom_fichier,"r");
        grille = lire_Grille(f);
        fclose(f);
        break;
    case 3:
        *nom_fichier = "test/grille_7x7_tricky.txt";
        printf("Vous avez choisis le fichier: %s\n",*nom_fichier);
        f = fopen(*nom_fichier,"r");
        grille = lire_Grille(f);
        fclose(f);
        break;
    case 4:
        *nom_fichier = "test/grille_7x7_hard.txt";
        printf("Vous avez choisis le fichier: %s\n",*nom_fichier);
        f = fopen(*nom_fichier,"r");
        grille = lire_Grille(f);
        fclose(f);
        break;
    case 5:
        *nom_fichier = "test/grille_10x10_ez.txt";
        printf("Vous avez choisis le fichier: %s\n",*nom_fichier);
        f = fopen(*nom_fichier,"r");
        grille = lire_Grille(f);
        fclose(f);
        break;
    case 6:
        *nom_fichier = "test/grille_10x10_tricky.txt";
        printf("Vous avez choisis le fichier: %s\n",*nom_fichier);
        f = fopen(*nom_fichier,"r");
        grille = lire_Grille(f);
        fclose(f);
        break;
    case 7:
        *nom_fichier = "test/grille_14x14_ez.txt";
        printf("Vous avez choisis le fichier: %s\n",*nom_fichier);
        f = fopen(*nom_fichier,"r");
        grille = lire_Grille(f);
        fclose(f);
        break;
    case 8:
        *nom_fichier = "test/grille_14x14_tricky.txt";
        printf("Vous avez choisis le fichier: %s\n",*nom_fichier);
        f = fopen(*nom_fichier,"r");
        grille = lire_Grille(f);
        fclose(f);
        break;
    case 9:
        *nom_fichier = "test/grille_14x14_hard.txt";
        printf("Vous avez choisis le fichier: %s\n",*nom_fichier);
        f = fopen(*nom_fichier,"r");
        grille = lire_Grille(f);
        fclose(f);
        break;
    case 10:
        printf("Combien de ligne souhaitez-vous?");
        scanf("%d",&y);
        printf("Combien de colonne souhaitez-vous?");
        scanf("%d",&x);
        printf("Quel pourcentage de mur voulez-vous?(entre 1 et 100)");
        scanf("%f",&pourcentage);

        while(bonne_valeur){
            if(y<0 || x<0){
                printf("Le nombre de lignes et de colonnes doivent être positifs\n");
                printf("Combien de ligne souhaitez-vous?");
                scanf("%d",&y);
                printf("Combien de colonne souhaitez-vous?");
                scanf("%d",&x);
            }else if(pourcentage>100 || pourcentage <1){
                printf("Le pourcentage doit être entre 1 et 100 inclus\n");
                printf("Quel pourcentage de mur voulez-vous?(entre 1 et 100)");
                scanf("%f",&pourcentage);
                while ((c = getchar()) != '\n' && c != EOF);    // Permet de vider le cache du scanf pour ne pas boucler à l'infini dans le cas des lettres

            }else{
                bonne_valeur = 0;
            }
        }

        grille = unique_sat_generation_grille_random(x,y,pourcentage);
        *nom_fichier = "test/grille_alea.txt";
        break;
    default:
        grille = init_Grille(-1,-1);
        break;
    }


    return grille;
}

Grille jouer_coup(Grille G, int *resultat){
    int x, y, res,mauvaise_val=1; 
    char retour_joueur;
    printf("Quelle case souhaitez-vous jouer? (-1 pour un indice et -2 pour vérifier votre solution)\n");
    res=scanf("%d %d",&y,&x);
    if(res!=2){
        printf("Saisi incorrecte veuillez saisir les coordonnée x et y \n");
        printf("Quelle case souhaitez-vous jouer? \n");
        scanf("%*s");
        res=scanf("%d %d",&y,&x); 
    }
    while(mauvaise_val){
        x=x-1;
        y=y-1;
        if(x==-2 || y ==-2){
            *resultat = -1;
            mauvaise_val = 0 ;
        }else if(x==-3 || y ==-3){
            *resultat = -2;
            mauvaise_val = 0 ;
        }else if((x>=G.h) || (y>=G.l) || (x<0) || (y<0)){
            printf("Votre valeur n'est pas dans la grille \n");
            printf("Quelle case souhaitez-vous jouer? \n");
            res=scanf("%d %d",&y,&x);
            if(res!=2){
                printf("Saisi incorrecte veuillez saisir les coordonnée x et y \n");
                printf("Quelle case souhaitez-vous jouer? \n");
                scanf("%*s");
                res=scanf("%d %d",&y,&x); 
            }
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
                res=scanf("%d %d",&y,&x);
                if(res!=2){
                    printf("Saisi incorrecte veuillez saisir les coordonnée x et y \n");
                    printf("Quelle case souhaitez-vous jouer? \n");
                    scanf("%*s");
                    res=scanf("%d %d",&y,&x); 
                }
            }
        }else if(!est_libre(G,x,y)){
            afficher_Grille(G);
            printf("Vous avez choisis une case deja prise.\n");
            printf("Quelle case souhaitez-vous jouer? \n");
            res=scanf("%d %d",&y,&x);
            if(res!=2){
                printf("Saisi incorrecte veuillez saisir les coordonnée x et y \n");
                printf("Quelle case souhaitez-vous jouer? \n");
                scanf("%*s");
                res=scanf("%d %d",&y,&x); 
            }
        }else{
            mauvaise_val = 0 ;
        }
    }
    if(x>=0){
        G = ajouter_lampe(G,x,y);
    }
    return G;
}

int indice(Grille G, Grille solution){
    int h,l,x,y;
    x=-1;
    h = G.h;
    l = G.l;
    for(int i=0; i<h; i++){
        for(int j=0; j<l; j++){
            if(G.tab[i][j]==LAMPE && solution.tab[i][j]!=LAMPE){
                printf("Il y à une lampe qui n'est pas presente dans la solution sur la case (%d,%d) essayer de la supprimer et de recommencer.\n",j+1,i+1); 
                return 0;
            }
            else if(solution.tab[i][j]==LAMPE && G.tab[i][j]!=LAMPE){
                x=i;
                y=j;
            }
        }
    }
    if (x==-1){
        printf("Bravo vous avez gagnez vous avez deja la bonne solution.\n");
        return 1;
    }
    else{
        printf("=================================================================\n");
        printf("                            INDICE : \n");
        printf("        Vous pouvez placer une lampe sur la case (%d,%d)\n",y+1,x+1);
        printf("=================================================================\n");

        return 0;
    }
}

Grille fin_partie(Grille G,char *nom_fichier){
    FILE *f;
    char fich_dimacs[50];
    int i;
    char command[150] = "minisat ";
    char *fin_executable = " output.txt > /dev/null";

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
    fclose(f);
    remove("output.txt");
    return G;
}

int resultat_correcte(Grille G, Grille solution){
    int h, l;
    h = G.h;
    l = G.l;

    for(int i=0; i<h; i++){
        for(int j=0; j<l; j++){
            if(G.tab[i][j]!=solution.tab[i][j]){
                return 0;
            }
        }
    }
    return 1;
}
void start(Grille grille, Grille solution){
    int joue = 1, res, choix=0;
    char retour_joueur;
    while(joue){
        printf("Voici la grille : \n");
        afficher_Grille(grille);
        jouer_coup(grille,&choix);
        printf("choix : %d\n",choix);
        printf("Voici la nouvelle grille : \n");
        afficher_Grille(grille);

        if( choix== -1){
            if(indice(grille,solution)){
                joue =0;
            }  
        }else if( choix== -2){
            res = resultat_correcte(grille, solution);
            if(res == 1){
                printf("Votre solution est correcte !\n");
                joue = 0;
            }
            else{
                printf("Votre solution est incorrecte.\n");
                printf("Voulez-la modifier? (Y/N):");
                scanf("\n");
                scanf("%s",&retour_joueur);
                while(retour_joueur!='Y' && retour_joueur!='N'){
                    printf("Valeur saisie incorrecte\n");
                    printf("Votre solution est incorrecte.\n");
                    printf("Voulez-la modifier? (Y/N):");
                    scanf("\n");
                    scanf("%c",&retour_joueur);
                }
                if(retour_joueur=='N'){
                    joue = 0;
                }
                else{
                    joue = 1;
                }
            }
        }
        else{
            joue = 1;
        }
    }
    printf("retour vers le menu \n");
}

int satisfaisabilite_unicite(Grille G){
    // Retourne 0 si une grille est satisfaisable et possède une unique solution
    FILE *f,*g,*h;
    Grille G2;
    int res,variable_solution,nombre_var,nombre_clause;
    char c;
    char *fich_dimacs = "grille_alea.cnf";
    char command[150] = "minisat grille_alea.cnf output.txt > /dev/null";

    G2 = copie_Grille(G);

    f = fopen(fich_dimacs,"w"); // On ouvre le fichier .cnf
    ecriture_dimacs(f,G); // le fclose(f); est dans la fonction
    
    system(command);
    //remove(fich_dimacs);

    f = fopen("output.txt","r");
    res = lecture_fich(f,G);
    fclose(f);
    if(res == 0){
        g = fopen(fich_dimacs,"r");  // Ouvre le fichier en lecture puis en ecriture pour changer le nombre de clauses 
        fscanf(g,"p cnf %d %d\n",&nombre_var,&nombre_clause);
        h = fopen("temporaire.txt","w");
        fprintf(h,"p cnf %d %d\n",nombre_var,nombre_clause+1);
        while(!feof(g)){
            fscanf(g,"%c",&c);
            fprintf(h,"%c",c);
        }
        
        // On vient de reecrire tout le fich_dimacs dans temporaire.txt
        fclose(g);
        f = fopen("output.txt","r");
        fscanf(f,"SAT\n");
        while(!feof(f)){

            fscanf(f,"%d ",&variable_solution);
            fprintf(h,"%d ",-variable_solution);

        }
        fprintf(h,"\n");
        fclose(h);
        fclose(g);
        system("cp temporaire.txt grille_alea.cnf");
        remove("temporaire.txt");
        // On vient de rajouter la negation de la solution dans le fichier .cnf On rappelle donc minisat pour verifier si la solution est unique ou non
        system(command);
        f = fopen("output.txt","r");
        res = lecture_fich(f,G2);
        fclose(f);
        //remove(fich_dimacs);
        if(res == 1){
            return 0;
        }
        else{
            return 2;
        }
    }
    else{
        remove(fich_dimacs);
        return 1;
    }

}
