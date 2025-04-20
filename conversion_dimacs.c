#include"conversion_dimacs.h"

/* Formules pour trouver la variable dimacs à partir des coordonnées i,j :
    i * nb_de_lignes * 3 + j * 3 + nb_variable = (i*nb_lignes + j)*3 + nb_variable
    avec nb_variable =
    1 pour Ei,j
    2 pour Li,j
    3 pour Mi,j
    on peut donc utiliser les valeurs du type énuméré Case
    Ne pas utiliser les valeurs libre, mur_0, mur_1, mur_2, mur_3 et mur_4!!
    */
int nom_variable_dimacs(int i, int j, int l, Case nb_variable){
    return (i*l + j)*3 + nb_variable;
}

void gestion_cond_MUR0(int i,int j,int l,int h,FILE *f){

    if(i == 0){

        if(j == 0){
            fprintf(f,"-%d 0\n",nom_variable_dimacs(i+1,j,l,LAMPE));
            fprintf(f,"-%d 0\n",nom_variable_dimacs(i,j+1,l,LAMPE));
        }
        else if(j == l-1){
            fprintf(f,"-%d 0\n",nom_variable_dimacs(i+1,j,l,LAMPE));
            fprintf(f,"-%d 0\n",nom_variable_dimacs(i,j-1,l,LAMPE));

        }
        else{
            fprintf(f,"-%d 0\n",nom_variable_dimacs(i+1,j,l,LAMPE));
            fprintf(f,"-%d 0\n",nom_variable_dimacs(i,j-1,l,LAMPE));
            fprintf(f,"-%d 0\n",nom_variable_dimacs(i,j+1,l,LAMPE));
        }

    }
    else if(i == h-1){

        if(j == 0){
            fprintf(f,"-%d 0\n",nom_variable_dimacs(i-1,j,l,LAMPE));
            fprintf(f,"-%d 0\n",nom_variable_dimacs(i,j+1,l,LAMPE));
        }
        else if(j == l-1){
            fprintf(f,"-%d 0\n",nom_variable_dimacs(i-1,j,l,LAMPE));
            fprintf(f,"-%d 0\n",nom_variable_dimacs(i,j-1,l,LAMPE));

        }
        else{
            fprintf(f,"-%d 0\n",nom_variable_dimacs(i-1,j,l,LAMPE));
            fprintf(f,"-%d 0\n",nom_variable_dimacs(i,j-1,l,LAMPE));
            fprintf(f,"-%d 0\n",nom_variable_dimacs(i,j+1,l,LAMPE));
        }

    }
    else if(j == 0){ //ici i != 0 et i != h-1
        fprintf(f,"-%d 0\n",nom_variable_dimacs(i-1,j,l,LAMPE));
        fprintf(f,"-%d 0\n",nom_variable_dimacs(i+1,j,l,LAMPE));
        fprintf(f,"-%d 0\n",nom_variable_dimacs(i,j+1,l,LAMPE));    }
    else if(j == l-1){ //ici aussi i != 0 et i != h-1
        fprintf(f,"-%d 0\n",nom_variable_dimacs(i-1,j,l,LAMPE));
        fprintf(f,"-%d 0\n",nom_variable_dimacs(i+1,j,l,LAMPE));
        fprintf(f,"-%d 0\n",nom_variable_dimacs(i,j-1,l,LAMPE));
    }
    else{
        fprintf(f,"-%d 0\n",nom_variable_dimacs(i-1,j,l,LAMPE));
        fprintf(f,"-%d 0\n",nom_variable_dimacs(i+1,j,l,LAMPE));
        fprintf(f,"-%d 0\n",nom_variable_dimacs(i,j-1,l,LAMPE));
        fprintf(f,"-%d 0\n",nom_variable_dimacs(i,j+1,l,LAMPE));
    }


}

void gestion_cond_MUR1(int i,int j,int l,int h,FILE *f){

    if(i == 0){

        if(j == 0){
            fprintf(f,"%d %d 0\n",nom_variable_dimacs(i+1,j,l,LAMPE),nom_variable_dimacs(i,j+1,l,LAMPE));
            fprintf(f,"-%d -%d 0\n",nom_variable_dimacs(i+1,j,l,LAMPE),nom_variable_dimacs(i,j+1,l,LAMPE));
        }
        else if(j == l-1){
            fprintf(f,"%d %d 0\n",nom_variable_dimacs(i+1,j,l,LAMPE),nom_variable_dimacs(i,j-1,l,LAMPE));
            fprintf(f,"-%d -%d 0\n",nom_variable_dimacs(i+1,j,l,LAMPE),nom_variable_dimacs(i,j-1,l,LAMPE));
        }
        else{
            fprintf(f,"%d %d %d 0\n",nom_variable_dimacs(i+1,j,l,LAMPE),nom_variable_dimacs(i,j-1,l,LAMPE),nom_variable_dimacs(i,j+1,l,LAMPE));
            fprintf(f,"-%d -%d 0\n",nom_variable_dimacs(i+1,j,l,LAMPE),nom_variable_dimacs(i,j-1,l,LAMPE));
            fprintf(f,"-%d -%d 0\n",nom_variable_dimacs(i+1,j,l,LAMPE),nom_variable_dimacs(i,j+1,l,LAMPE));
            fprintf(f,"-%d -%d 0\n",nom_variable_dimacs(i,j-1,l,LAMPE),nom_variable_dimacs(i,j+1,l,LAMPE));
        }

    }
    else if(i == h-1){

        if(j == 0){
            fprintf(f,"%d %d 0\n",nom_variable_dimacs(i-1,j,l,LAMPE),nom_variable_dimacs(i,j+1,l,LAMPE));
            fprintf(f,"-%d -%d 0\n",nom_variable_dimacs(i-1,j,l,LAMPE),nom_variable_dimacs(i,j+1,l,LAMPE));
        }
        else if(j == l-1){
            fprintf(f,"%d %d 0\n",nom_variable_dimacs(i-1,j,l,LAMPE),nom_variable_dimacs(i,j-1,l,LAMPE));
            fprintf(f,"-%d -%d 0\n",nom_variable_dimacs(i-1,j,l,LAMPE),nom_variable_dimacs(i,j-1,l,LAMPE));

        }
        else{
            fprintf(f,"-%d -%d 0\n",nom_variable_dimacs(i-1,j,l,LAMPE),nom_variable_dimacs(i,j-1,l,LAMPE));
            fprintf(f,"-%d -%d 0\n",nom_variable_dimacs(i-1,j,l,LAMPE),nom_variable_dimacs(i,j+1,l,LAMPE));
            fprintf(f,"%d %d %d 0\n",nom_variable_dimacs(i-1,j,l,LAMPE),nom_variable_dimacs(i,j-1,l,LAMPE),nom_variable_dimacs(i,j+1,l,LAMPE));
            fprintf(f,"-%d -%d 0\n",nom_variable_dimacs(i,j-1,l,LAMPE),nom_variable_dimacs(i,j+1,l,LAMPE));
        }

    }
    else if(j == 0){ //ici i != 0 et i != h-1
        fprintf(f,"-%d -%d 0\n",nom_variable_dimacs(i-1,j,l,LAMPE),nom_variable_dimacs(i+1,j,l,LAMPE));
        fprintf(f,"-%d -%d 0\n",nom_variable_dimacs(i-1,j,l,LAMPE),nom_variable_dimacs(i,j+1,l,LAMPE));
        fprintf(f,"%d %d %d 0\n",nom_variable_dimacs(i-1,j,l,LAMPE),nom_variable_dimacs(i+1,j,l,LAMPE),nom_variable_dimacs(i,j+1,l,LAMPE));
        fprintf(f,"-%d -%d 0\n",nom_variable_dimacs(i+1,j,l,LAMPE),nom_variable_dimacs(i,j+1,l,LAMPE));
    }
    else if(j == l-1){ //ici aussi i != 0 et i != h-1
        fprintf(f,"-%d -%d 0\n",nom_variable_dimacs(i-1,j,l,LAMPE),nom_variable_dimacs(i+1,j,l,LAMPE));
        fprintf(f,"-%d -%d 0\n",nom_variable_dimacs(i-1,j,l,LAMPE),nom_variable_dimacs(i,j-1,l,LAMPE));
        fprintf(f,"%d %d %d 0\n",nom_variable_dimacs(i-1,j,l,LAMPE),nom_variable_dimacs(i+1,j,l,LAMPE),nom_variable_dimacs(i,j-1,l,LAMPE));
        fprintf(f,"-%d -%d 0\n",nom_variable_dimacs(i+1,j,l,LAMPE),nom_variable_dimacs(i,j-1,l,LAMPE));
    }
    else{
        fprintf(f,"-%d -%d 0\n",nom_variable_dimacs(i-1,j,l,LAMPE),nom_variable_dimacs(i+1,j,l,LAMPE));
        fprintf(f,"-%d -%d 0\n",nom_variable_dimacs(i-1,j,l,LAMPE),nom_variable_dimacs(i,j-1,l,LAMPE));
        fprintf(f,"-%d -%d 0\n",nom_variable_dimacs(i-1,j,l,LAMPE),nom_variable_dimacs(i,j+1,l,LAMPE));
        fprintf(f,"%d %d %d %d 0\n",nom_variable_dimacs(i-1,j,l,LAMPE),nom_variable_dimacs(i+1,j,l,LAMPE),nom_variable_dimacs(i,j-1,l,LAMPE),nom_variable_dimacs(i,j+1,l,LAMPE));
        fprintf(f,"-%d -%d 0\n",nom_variable_dimacs(i+1,j,l,LAMPE),nom_variable_dimacs(i,j-1,l,LAMPE));
        fprintf(f,"-%d -%d 0\n",nom_variable_dimacs(i+1,j,l,LAMPE),nom_variable_dimacs(i,j+1,l,LAMPE));
        fprintf(f,"-%d -%d 0\n",nom_variable_dimacs(i,j-1,l,LAMPE),nom_variable_dimacs(i,j+1,l,LAMPE));
    }


}

void gestion_cond_MUR2(int i,int j,int l,int h,FILE *f){

    if(i == 0){

        if(j == 0){
            fprintf(f,"%d 0\n",nom_variable_dimacs(i+1,j,l,LAMPE));
            fprintf(f,"%d 0\n",nom_variable_dimacs(i,j+1,l,LAMPE));
        }
        else if(j == l-1){
            fprintf(f,"%d 0\n",nom_variable_dimacs(i+1,j,l,LAMPE));
            fprintf(f,"%d 0\n",nom_variable_dimacs(i,j-1,l,LAMPE));
        }
        else{
            fprintf(f,"%d %d 0\n",nom_variable_dimacs(i+1,j,l,LAMPE),nom_variable_dimacs(i,j-1,l,LAMPE));
            fprintf(f,"%d %d 0\n",nom_variable_dimacs(i+1,j,l,LAMPE),nom_variable_dimacs(i,j+1,l,LAMPE));
            fprintf(f,"%d %d 0\n",nom_variable_dimacs(i,j-1,l,LAMPE),nom_variable_dimacs(i,j+1,l,LAMPE));
            fprintf(f,"-%d -%d -%d 0\n",nom_variable_dimacs(i+1,j,l,LAMPE),nom_variable_dimacs(i,j-1,l,LAMPE),nom_variable_dimacs(i,j+1,l,LAMPE));
        }

    }
    else if(i == h-1){

        if(j == 0){
            fprintf(f,"%d 0\n",nom_variable_dimacs(i-1,j,l,LAMPE));
            fprintf(f,"%d 0\n",nom_variable_dimacs(i,j+1,l,LAMPE));
        }
        else if(j == l-1){
            fprintf(f,"%d 0\n",nom_variable_dimacs(i-1,j,l,LAMPE));
            fprintf(f,"%d 0\n",nom_variable_dimacs(i,j-1,l,LAMPE));
        }
        else{
            fprintf(f,"-%d -%d -%d 0\n",nom_variable_dimacs(i-1,j,l,LAMPE),nom_variable_dimacs(i,j-1,l,LAMPE),nom_variable_dimacs(i,j+1,l,LAMPE));
            fprintf(f,"%d %d 0\n",nom_variable_dimacs(i-1,j,l,LAMPE),nom_variable_dimacs(i,j-1,l,LAMPE));
            fprintf(f,"%d %d 0\n",nom_variable_dimacs(i-1,j,l,LAMPE),nom_variable_dimacs(i,j+1,l,LAMPE));
            fprintf(f,"%d %d 0\n",nom_variable_dimacs(i,j-1,l,LAMPE),nom_variable_dimacs(i,j+1,l,LAMPE));
        }

    }
    else if(j == 0){ //ici i != 0 et i != h-1
        fprintf(f,"-%d -%d -%d 0\n",nom_variable_dimacs(i-1,j,l,LAMPE),nom_variable_dimacs(i+1,j,l,LAMPE),nom_variable_dimacs(i,j+1,l,LAMPE));
        fprintf(f,"%d %d 0\n",nom_variable_dimacs(i-1,j,l,LAMPE),nom_variable_dimacs(i+1,j,l,LAMPE));
        fprintf(f,"%d %d 0\n",nom_variable_dimacs(i+1,j,l,LAMPE),nom_variable_dimacs(i,j+1,l,LAMPE));
        fprintf(f,"%d %d 0\n",nom_variable_dimacs(i-1,j,l,LAMPE),nom_variable_dimacs(i,j+1,l,LAMPE));
    }
    else if(j == l-1){ //ici aussi i != 0 et i != h-1
        fprintf(f,"-%d -%d -%d 0\n",nom_variable_dimacs(i-1,j,l,LAMPE),nom_variable_dimacs(i+1,j,l,LAMPE),nom_variable_dimacs(i,j-1,l,LAMPE));
        fprintf(f,"%d %d 0\n",nom_variable_dimacs(i+1,j,l,LAMPE),nom_variable_dimacs(i,j-1,l,LAMPE));
        fprintf(f,"%d %d 0\n",nom_variable_dimacs(i-1,j,l,LAMPE),nom_variable_dimacs(i+1,j,l,LAMPE));
        fprintf(f,"%d %d 0\n",nom_variable_dimacs(i-1,j,l,LAMPE),nom_variable_dimacs(i,j-1,l,LAMPE));
    }
    else{
        fprintf(f,"-%d -%d -%d 0\n",nom_variable_dimacs(i-1,j,l,LAMPE),nom_variable_dimacs(i+1,j,l,LAMPE),nom_variable_dimacs(i,j-1,l,LAMPE));
        fprintf(f,"-%d -%d -%d 0\n",nom_variable_dimacs(i-1,j,l,LAMPE),nom_variable_dimacs(i+1,j,l,LAMPE),nom_variable_dimacs(i,j+1,l,LAMPE));
        fprintf(f,"-%d -%d -%d 0\n",nom_variable_dimacs(i-1,j,l,LAMPE),nom_variable_dimacs(i,j-1,l,LAMPE),nom_variable_dimacs(i,j+1,l,LAMPE));
        fprintf(f,"%d %d %d 0\n",nom_variable_dimacs(i-1,j,l,LAMPE),nom_variable_dimacs(i+1,j,l,LAMPE),nom_variable_dimacs(i,j-1,l,LAMPE));
        fprintf(f,"%d %d %d 0\n",nom_variable_dimacs(i-1,j,l,LAMPE),nom_variable_dimacs(i+1,j,l,LAMPE),nom_variable_dimacs(i,j+1,l,LAMPE));
        fprintf(f,"%d %d %d 0\n",nom_variable_dimacs(i-1,j,l,LAMPE),nom_variable_dimacs(i,j-1,l,LAMPE),nom_variable_dimacs(i,j+1,l,LAMPE));
        fprintf(f,"-%d -%d -%d 0\n",nom_variable_dimacs(i+1,j,l,LAMPE),nom_variable_dimacs(i,j-1,l,LAMPE),nom_variable_dimacs(i,j+1,l,LAMPE));
    }


}

void gestion_cond_MUR3(int i,int j,int l,int h,FILE *f){

    if(i == 0){
        fprintf(f,"%d 0\n",nom_variable_dimacs(i+1,j,l,LAMPE));
        fprintf(f,"%d 0\n",nom_variable_dimacs(i,j-1,l,LAMPE));
        fprintf(f,"%d 0\n",nom_variable_dimacs(i,j+1,l,LAMPE));
    }
    else if(i == h-1){

        fprintf(f,"%d 0\n",nom_variable_dimacs(i-1,j,l,LAMPE));
        fprintf(f,"%d 0\n",nom_variable_dimacs(i,j-1,l,LAMPE));
        fprintf(f,"%d 0\n",nom_variable_dimacs(i,j+1,l,LAMPE));

    }
    else if(j == 0){ //ici i != 0 et i != h-1
        fprintf(f,"%d 0\n",nom_variable_dimacs(i+1,j,l,LAMPE));
        fprintf(f,"%d 0\n",nom_variable_dimacs(i-1,j,l,LAMPE));
        fprintf(f,"%d 0\n",nom_variable_dimacs(i,j+1,l,LAMPE));
    }
    else if(j == l-1){ //ici aussi i != 0 et i != h-1
        fprintf(f,"%d 0\n",nom_variable_dimacs(i+1,j,l,LAMPE));
        fprintf(f,"%d 0\n",nom_variable_dimacs(i,j-1,l,LAMPE));
        fprintf(f,"%d 0\n",nom_variable_dimacs(i-1,j,l,LAMPE));
    }
    else{
        fprintf(f,"-%d -%d -%d -%d 0\n",nom_variable_dimacs(i-1,j,l,LAMPE),nom_variable_dimacs(i+1,j,l,LAMPE),nom_variable_dimacs(i,j-1,l,LAMPE),nom_variable_dimacs(i,j+1,l,LAMPE));
        fprintf(f,"%d %d 0\n",nom_variable_dimacs(i-1,j,l,LAMPE),nom_variable_dimacs(i+1,j,l,LAMPE));
        fprintf(f,"%d %d 0\n",nom_variable_dimacs(i-1,j,l,LAMPE),nom_variable_dimacs(i,j-1,l,LAMPE));
        fprintf(f,"%d %d 0\n",nom_variable_dimacs(i-1,j,l,LAMPE),nom_variable_dimacs(i,j+1,l,LAMPE));
        fprintf(f,"%d %d 0\n",nom_variable_dimacs(i+1,j,l,LAMPE),nom_variable_dimacs(i,j-1,l,LAMPE));
        fprintf(f,"%d %d 0\n",nom_variable_dimacs(i+1,j,l,LAMPE),nom_variable_dimacs(i,j+1,l,LAMPE));
        fprintf(f,"%d %d 0\n",nom_variable_dimacs(i,j-1,l,LAMPE),nom_variable_dimacs(i,j+1,l,LAMPE));
    }


}

void gestion_cond_MUR4(int i,int j,int l,int h,FILE *f){

    fprintf(f,"%d 0\n",nom_variable_dimacs(i-1,j,l,LAMPE));
    fprintf(f,"%d 0\n",nom_variable_dimacs(i+1,j,l,LAMPE));
    fprintf(f,"%d 0\n",nom_variable_dimacs(i,j-1,l,LAMPE));
    fprintf(f,"%d 0\n",nom_variable_dimacs(i,j+1,l,LAMPE));
    
}

void ecriture_fich(FILE *f,Grille G){

    int i,j,l,h;
    int n_eclaire_ij,n_lampe_ij,n_mur_ij;
    l = G.l;
    h = G.h;

    

    for(i = 0;i<h;i++){

        for(j = 0;j<l;j++){
            n_eclaire_ij=nom_variable_dimacs(i,j,l,ECLAIRE);
            n_lampe_ij=nom_variable_dimacs(i,j,l,LAMPE);
            n_mur_ij=nom_variable_dimacs(i,j,l,MUR);
            fprintf(f,"-%d -%d 0\n",n_lampe_ij,n_mur_ij);
            fprintf(f,"%d %d 0\n",n_eclaire_ij,n_mur_ij);
            switch(G.tab[i][j]){

                case MUR:
                //fixations des valeurs des variables sur les murs
                fprintf(f,"%d 0\n",n_mur_ij);
                break;

                case MUR_0:
                //fixations des valeurs des variables sur les murs
                fprintf(f,"%d 0\n",n_mur_ij);
                // Gestion des mur avec conditions
                gestion_cond_MUR0(i,j,l,h,f);
                break;

                case MUR_1:
                //fixations des valeurs des variables sur les murs
                fprintf(f,"%d 0\n",n_mur_ij);
                // Gestion des mur avec conditions
                gestion_cond_MUR1(i,j,l,h,f);
                break;

                case MUR_2:
                //fixations des valeurs des variables sur les murs
                fprintf(f,"%d 0\n",n_mur_ij);
                // Gestion des mur avec conditions
                gestion_cond_MUR2(i,j,l,h,f);
                break;

                case MUR_3:
                //fixations des valeurs des variables sur les murs
                fprintf(f,"%d 0\n",n_mur_ij);
                // Gestion des mur avec conditions
                gestion_cond_MUR3(i,j,l,h,f);
                break;

                case MUR_4:
                //fixations des valeurs des variables sur les murs
                fprintf(f,"%d 0\n",n_mur_ij);
                // Gestion des mur avec conditions
                gestion_cond_MUR4(i,j,l,h,f);
                break;

                default:
                //fixations des valeurs des variables sur les murs
                fprintf(f,"-%d 0\n",n_mur_ij);
                break;

            }
            
        }

    }

}


int lecture_fich(FILE *f, Grille G){

    int i,j,l,h,eclaire,lampe,mur,fin;
    l = G.l;
    h = G.h;

    fscanf(f,"UNSAT\n");
    if(feof(f)){
        return 1;
    }

    fscanf(f,"SAT\n");

    for(i = 0;i<h;i++){

        for(j = 0;j<l;j++){

            fscanf(f,"%d ",&eclaire);
            fscanf(f,"%d ",&lampe);
            fscanf(f,"%d ",&mur);

            if(eclaire == 0 || lampe == 0 || mur == 0){
                printf("ERREUR, on vient de lire un 0 dans le fichier solution du SAT solver, cela veut donc dire que l'on ne cree pas toutes les variables\n");
                    return 2;
            }

            else if(G.tab[i][j] == MUR || G.tab[i][j] == MUR_0 || G.tab[i][j] == MUR_1 || G.tab[i][j] == MUR_2 || G.tab[i][j] == MUR_3 || G.tab[i][j] == MUR_4){

                if(mur < 0 ){
                    printf("ERREUR, le SAT solver a decide que la case %d,%d n'est pas un mur, alors qu'il en est un sur la grille d'origine.\n",i,j);
                    return 2;
                }

            }
            else if(lampe > 0){
                G.tab[i][j] = LAMPE;
            }
            else if(eclaire > 0){
                if(mur > 0){
                    printf("ERREUR, le SAT solver a decide que la case %d,%d est un mur, alors qu'il n'en est pas un sur la grille d'origine.\n",i,j);
                    return 2;
                }
                G.tab[i][j] = ECLAIRE;
            }
            else{
                printf("ERREUR, on ne devrait pas arriver ici\nVoici les valeurs de eclairee : %d\nlampe : %d\nmur : %d\n",eclaire,lampe,mur);
                return 2;
            }

            
        }

    }
    fscanf(f,"%d",&fin);
    if(fin != 0){
        printf("ERREUR, le dernier caractère que l'on a lu n'est pas 0, on a cree trop de variable dans le fichier Dimacs.\n");
        return 2;
    }

    return 0;
}
