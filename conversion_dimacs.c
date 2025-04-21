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

int gestion_cond_MUR0(int i,int j,int l,int h,FILE *f){
    if(i == 0){

        if(j == 0){
            fprintf(f,"-%d 0\n",nom_variable_dimacs(i+1,j,l,LAMPE));
            fprintf(f,"-%d 0\n",nom_variable_dimacs(i,j+1,l,LAMPE));
            return 2;
        }
        else if(j == l-1){
            fprintf(f,"-%d 0\n",nom_variable_dimacs(i+1,j,l,LAMPE));
            fprintf(f,"-%d 0\n",nom_variable_dimacs(i,j-1,l,LAMPE));
            return 2;
        }
        else{
            fprintf(f,"-%d 0\n",nom_variable_dimacs(i+1,j,l,LAMPE));
            fprintf(f,"-%d 0\n",nom_variable_dimacs(i,j-1,l,LAMPE));
            fprintf(f,"-%d 0\n",nom_variable_dimacs(i,j+1,l,LAMPE));
            return 3;
        }

    }
    else if(i == h-1){

        if(j == 0){
            fprintf(f,"-%d 0\n",nom_variable_dimacs(i-1,j,l,LAMPE));
            fprintf(f,"-%d 0\n",nom_variable_dimacs(i,j+1,l,LAMPE));
            return 2;
        }
        else if(j == l-1){
            fprintf(f,"-%d 0\n",nom_variable_dimacs(i-1,j,l,LAMPE));
            fprintf(f,"-%d 0\n",nom_variable_dimacs(i,j-1,l,LAMPE));
            return 2;
        }
        else{
            fprintf(f,"-%d 0\n",nom_variable_dimacs(i-1,j,l,LAMPE));
            fprintf(f,"-%d 0\n",nom_variable_dimacs(i,j-1,l,LAMPE));
            fprintf(f,"-%d 0\n",nom_variable_dimacs(i,j+1,l,LAMPE));
            return 3;
        }

    }
    else if(j == 0){ //ici i != 0 et i != h-1
        fprintf(f,"-%d 0\n",nom_variable_dimacs(i-1,j,l,LAMPE));
        fprintf(f,"-%d 0\n",nom_variable_dimacs(i+1,j,l,LAMPE));
        fprintf(f,"-%d 0\n",nom_variable_dimacs(i,j+1,l,LAMPE));
        return 3;    
    }
    else if(j == l-1){ //ici aussi i != 0 et i != h-1
        fprintf(f,"-%d 0\n",nom_variable_dimacs(i-1,j,l,LAMPE));
        fprintf(f,"-%d 0\n",nom_variable_dimacs(i+1,j,l,LAMPE));
        fprintf(f,"-%d 0\n",nom_variable_dimacs(i,j-1,l,LAMPE));
        return 3;
    }
    else{
        fprintf(f,"-%d 0\n",nom_variable_dimacs(i-1,j,l,LAMPE));
        fprintf(f,"-%d 0\n",nom_variable_dimacs(i+1,j,l,LAMPE));
        fprintf(f,"-%d 0\n",nom_variable_dimacs(i,j-1,l,LAMPE));
        fprintf(f,"-%d 0\n",nom_variable_dimacs(i,j+1,l,LAMPE));
        return 4;
    }


}

int gestion_cond_MUR1(int i,int j,int l,int h,FILE *f){

    if(i == 0){

        if(j == 0){
            fprintf(f,"%d %d 0\n",nom_variable_dimacs(i+1,j,l,LAMPE),nom_variable_dimacs(i,j+1,l,LAMPE));
            fprintf(f,"-%d -%d 0\n",nom_variable_dimacs(i+1,j,l,LAMPE),nom_variable_dimacs(i,j+1,l,LAMPE));
            return 2;
        }
        else if(j == l-1){
            fprintf(f,"%d %d 0\n",nom_variable_dimacs(i+1,j,l,LAMPE),nom_variable_dimacs(i,j-1,l,LAMPE));
            fprintf(f,"-%d -%d 0\n",nom_variable_dimacs(i+1,j,l,LAMPE),nom_variable_dimacs(i,j-1,l,LAMPE));
            return 2;
        }
        else{
            fprintf(f,"%d %d %d 0\n",nom_variable_dimacs(i+1,j,l,LAMPE),nom_variable_dimacs(i,j-1,l,LAMPE),nom_variable_dimacs(i,j+1,l,LAMPE));
            fprintf(f,"-%d -%d 0\n",nom_variable_dimacs(i+1,j,l,LAMPE),nom_variable_dimacs(i,j-1,l,LAMPE));
            fprintf(f,"-%d -%d 0\n",nom_variable_dimacs(i+1,j,l,LAMPE),nom_variable_dimacs(i,j+1,l,LAMPE));
            fprintf(f,"-%d -%d 0\n",nom_variable_dimacs(i,j-1,l,LAMPE),nom_variable_dimacs(i,j+1,l,LAMPE));
            return 4;
        }

    }
    else if(i == h-1){

        if(j == 0){
            fprintf(f,"%d %d 0\n",nom_variable_dimacs(i-1,j,l,LAMPE),nom_variable_dimacs(i,j+1,l,LAMPE));
            fprintf(f,"-%d -%d 0\n",nom_variable_dimacs(i-1,j,l,LAMPE),nom_variable_dimacs(i,j+1,l,LAMPE));
            return 2;
        }
        else if(j == l-1){
            fprintf(f,"%d %d 0\n",nom_variable_dimacs(i-1,j,l,LAMPE),nom_variable_dimacs(i,j-1,l,LAMPE));
            fprintf(f,"-%d -%d 0\n",nom_variable_dimacs(i-1,j,l,LAMPE),nom_variable_dimacs(i,j-1,l,LAMPE));
            return 2;
        }
        else{
            fprintf(f,"-%d -%d 0\n",nom_variable_dimacs(i-1,j,l,LAMPE),nom_variable_dimacs(i,j-1,l,LAMPE));
            fprintf(f,"-%d -%d 0\n",nom_variable_dimacs(i-1,j,l,LAMPE),nom_variable_dimacs(i,j+1,l,LAMPE));
            fprintf(f,"%d %d %d 0\n",nom_variable_dimacs(i-1,j,l,LAMPE),nom_variable_dimacs(i,j-1,l,LAMPE),nom_variable_dimacs(i,j+1,l,LAMPE));
            fprintf(f,"-%d -%d 0\n",nom_variable_dimacs(i,j-1,l,LAMPE),nom_variable_dimacs(i,j+1,l,LAMPE));
            return 4;
        }

    }
    else if(j == 0){ //ici i != 0 et i != h-1
        fprintf(f,"-%d -%d 0\n",nom_variable_dimacs(i-1,j,l,LAMPE),nom_variable_dimacs(i+1,j,l,LAMPE));
        fprintf(f,"-%d -%d 0\n",nom_variable_dimacs(i-1,j,l,LAMPE),nom_variable_dimacs(i,j+1,l,LAMPE));
        fprintf(f,"%d %d %d 0\n",nom_variable_dimacs(i-1,j,l,LAMPE),nom_variable_dimacs(i+1,j,l,LAMPE),nom_variable_dimacs(i,j+1,l,LAMPE));
        fprintf(f,"-%d -%d 0\n",nom_variable_dimacs(i+1,j,l,LAMPE),nom_variable_dimacs(i,j+1,l,LAMPE));
        return 4;
    }
    else if(j == l-1){ //ici aussi i != 0 et i != h-1
        fprintf(f,"-%d -%d 0\n",nom_variable_dimacs(i-1,j,l,LAMPE),nom_variable_dimacs(i+1,j,l,LAMPE));
        fprintf(f,"-%d -%d 0\n",nom_variable_dimacs(i-1,j,l,LAMPE),nom_variable_dimacs(i,j-1,l,LAMPE));
        fprintf(f,"%d %d %d 0\n",nom_variable_dimacs(i-1,j,l,LAMPE),nom_variable_dimacs(i+1,j,l,LAMPE),nom_variable_dimacs(i,j-1,l,LAMPE));
        fprintf(f,"-%d -%d 0\n",nom_variable_dimacs(i+1,j,l,LAMPE),nom_variable_dimacs(i,j-1,l,LAMPE));
        return 4;
    }
    else{
        fprintf(f,"-%d -%d 0\n",nom_variable_dimacs(i-1,j,l,LAMPE),nom_variable_dimacs(i+1,j,l,LAMPE));
        fprintf(f,"-%d -%d 0\n",nom_variable_dimacs(i-1,j,l,LAMPE),nom_variable_dimacs(i,j-1,l,LAMPE));
        fprintf(f,"-%d -%d 0\n",nom_variable_dimacs(i-1,j,l,LAMPE),nom_variable_dimacs(i,j+1,l,LAMPE));
        fprintf(f,"%d %d %d %d 0\n",nom_variable_dimacs(i-1,j,l,LAMPE),nom_variable_dimacs(i+1,j,l,LAMPE),nom_variable_dimacs(i,j-1,l,LAMPE),nom_variable_dimacs(i,j+1,l,LAMPE));
        fprintf(f,"-%d -%d 0\n",nom_variable_dimacs(i+1,j,l,LAMPE),nom_variable_dimacs(i,j-1,l,LAMPE));
        fprintf(f,"-%d -%d 0\n",nom_variable_dimacs(i+1,j,l,LAMPE),nom_variable_dimacs(i,j+1,l,LAMPE));
        fprintf(f,"-%d -%d 0\n",nom_variable_dimacs(i,j-1,l,LAMPE),nom_variable_dimacs(i,j+1,l,LAMPE));
        return 7; 
    }


}

int gestion_cond_MUR2(int i,int j,int l,int h,FILE *f){

    if(i == 0){

        if(j == 0){
            fprintf(f,"%d 0\n",nom_variable_dimacs(i+1,j,l,LAMPE));
            fprintf(f,"%d 0\n",nom_variable_dimacs(i,j+1,l,LAMPE));
            return 2;
        }
        else if(j == l-1){
            fprintf(f,"%d 0\n",nom_variable_dimacs(i+1,j,l,LAMPE));
            fprintf(f,"%d 0\n",nom_variable_dimacs(i,j-1,l,LAMPE));
            return 2;
        }
        else{
            fprintf(f,"%d %d 0\n",nom_variable_dimacs(i+1,j,l,LAMPE),nom_variable_dimacs(i,j-1,l,LAMPE));
            fprintf(f,"%d %d 0\n",nom_variable_dimacs(i+1,j,l,LAMPE),nom_variable_dimacs(i,j+1,l,LAMPE));
            fprintf(f,"%d %d 0\n",nom_variable_dimacs(i,j-1,l,LAMPE),nom_variable_dimacs(i,j+1,l,LAMPE));
            fprintf(f,"-%d -%d -%d 0\n",nom_variable_dimacs(i+1,j,l,LAMPE),nom_variable_dimacs(i,j-1,l,LAMPE),nom_variable_dimacs(i,j+1,l,LAMPE));
            return 4;
        }

    }
    else if(i == h-1){

        if(j == 0){
            fprintf(f,"%d 0\n",nom_variable_dimacs(i-1,j,l,LAMPE));
            fprintf(f,"%d 0\n",nom_variable_dimacs(i,j+1,l,LAMPE));
            return 2;
        }
        else if(j == l-1){
            fprintf(f,"%d 0\n",nom_variable_dimacs(i-1,j,l,LAMPE));
            fprintf(f,"%d 0\n",nom_variable_dimacs(i,j-1,l,LAMPE));
            return 2;
        }
        else{
            fprintf(f,"-%d -%d -%d 0\n",nom_variable_dimacs(i-1,j,l,LAMPE),nom_variable_dimacs(i,j-1,l,LAMPE),nom_variable_dimacs(i,j+1,l,LAMPE));
            fprintf(f,"%d %d 0\n",nom_variable_dimacs(i-1,j,l,LAMPE),nom_variable_dimacs(i,j-1,l,LAMPE));
            fprintf(f,"%d %d 0\n",nom_variable_dimacs(i-1,j,l,LAMPE),nom_variable_dimacs(i,j+1,l,LAMPE));
            fprintf(f,"%d %d 0\n",nom_variable_dimacs(i,j-1,l,LAMPE),nom_variable_dimacs(i,j+1,l,LAMPE));
            return 4;
        }

    }
    else if(j == 0){ //ici i != 0 et i != h-1
        fprintf(f,"-%d -%d -%d 0\n",nom_variable_dimacs(i-1,j,l,LAMPE),nom_variable_dimacs(i+1,j,l,LAMPE),nom_variable_dimacs(i,j+1,l,LAMPE));
        fprintf(f,"%d %d 0\n",nom_variable_dimacs(i-1,j,l,LAMPE),nom_variable_dimacs(i+1,j,l,LAMPE));
        fprintf(f,"%d %d 0\n",nom_variable_dimacs(i+1,j,l,LAMPE),nom_variable_dimacs(i,j+1,l,LAMPE));
        fprintf(f,"%d %d 0\n",nom_variable_dimacs(i-1,j,l,LAMPE),nom_variable_dimacs(i,j+1,l,LAMPE));
        return 4;
    }
    else if(j == l-1){ //ici aussi i != 0 et i != h-1
        fprintf(f,"-%d -%d -%d 0\n",nom_variable_dimacs(i-1,j,l,LAMPE),nom_variable_dimacs(i+1,j,l,LAMPE),nom_variable_dimacs(i,j-1,l,LAMPE));
        fprintf(f,"%d %d 0\n",nom_variable_dimacs(i+1,j,l,LAMPE),nom_variable_dimacs(i,j-1,l,LAMPE));
        fprintf(f,"%d %d 0\n",nom_variable_dimacs(i-1,j,l,LAMPE),nom_variable_dimacs(i+1,j,l,LAMPE));
        fprintf(f,"%d %d 0\n",nom_variable_dimacs(i-1,j,l,LAMPE),nom_variable_dimacs(i,j-1,l,LAMPE));
        return 4;
    }
    else{
        fprintf(f,"-%d -%d -%d 0\n",nom_variable_dimacs(i-1,j,l,LAMPE),nom_variable_dimacs(i+1,j,l,LAMPE),nom_variable_dimacs(i,j-1,l,LAMPE));
        fprintf(f,"-%d -%d -%d 0\n",nom_variable_dimacs(i-1,j,l,LAMPE),nom_variable_dimacs(i+1,j,l,LAMPE),nom_variable_dimacs(i,j+1,l,LAMPE));
        fprintf(f,"-%d -%d -%d 0\n",nom_variable_dimacs(i-1,j,l,LAMPE),nom_variable_dimacs(i,j-1,l,LAMPE),nom_variable_dimacs(i,j+1,l,LAMPE));
        fprintf(f,"%d %d %d 0\n",nom_variable_dimacs(i-1,j,l,LAMPE),nom_variable_dimacs(i+1,j,l,LAMPE),nom_variable_dimacs(i,j-1,l,LAMPE));
        fprintf(f,"%d %d %d 0\n",nom_variable_dimacs(i-1,j,l,LAMPE),nom_variable_dimacs(i+1,j,l,LAMPE),nom_variable_dimacs(i,j+1,l,LAMPE));
        fprintf(f,"%d %d %d 0\n",nom_variable_dimacs(i-1,j,l,LAMPE),nom_variable_dimacs(i,j-1,l,LAMPE),nom_variable_dimacs(i,j+1,l,LAMPE));
        fprintf(f,"-%d -%d -%d 0\n",nom_variable_dimacs(i+1,j,l,LAMPE),nom_variable_dimacs(i,j-1,l,LAMPE),nom_variable_dimacs(i,j+1,l,LAMPE));
        return 7;
    }


}

int gestion_cond_MUR3(int i,int j,int l,int h,FILE *f){

    if(i == 0){
        fprintf(f,"%d 0\n",nom_variable_dimacs(i+1,j,l,LAMPE));
        fprintf(f,"%d 0\n",nom_variable_dimacs(i,j-1,l,LAMPE));
        fprintf(f,"%d 0\n",nom_variable_dimacs(i,j+1,l,LAMPE));
        return 3;
    }
    else if(i == h-1){

        fprintf(f,"%d 0\n",nom_variable_dimacs(i-1,j,l,LAMPE));
        fprintf(f,"%d 0\n",nom_variable_dimacs(i,j-1,l,LAMPE));
        fprintf(f,"%d 0\n",nom_variable_dimacs(i,j+1,l,LAMPE));
        return 3;
    }
    else if(j == 0){ //ici i != 0 et i != h-1
        fprintf(f,"%d 0\n",nom_variable_dimacs(i+1,j,l,LAMPE));
        fprintf(f,"%d 0\n",nom_variable_dimacs(i-1,j,l,LAMPE));
        fprintf(f,"%d 0\n",nom_variable_dimacs(i,j+1,l,LAMPE));
        return 3;
    }
    else if(j == l-1){ //ici aussi i != 0 et i != h-1
        fprintf(f,"%d 0\n",nom_variable_dimacs(i+1,j,l,LAMPE));
        fprintf(f,"%d 0\n",nom_variable_dimacs(i,j-1,l,LAMPE));
        fprintf(f,"%d 0\n",nom_variable_dimacs(i-1,j,l,LAMPE));
        return 3;
    }
    else{
        fprintf(f,"-%d -%d -%d -%d 0\n",nom_variable_dimacs(i-1,j,l,LAMPE),nom_variable_dimacs(i+1,j,l,LAMPE),nom_variable_dimacs(i,j-1,l,LAMPE),nom_variable_dimacs(i,j+1,l,LAMPE));
        fprintf(f,"%d %d 0\n",nom_variable_dimacs(i-1,j,l,LAMPE),nom_variable_dimacs(i+1,j,l,LAMPE));
        fprintf(f,"%d %d 0\n",nom_variable_dimacs(i-1,j,l,LAMPE),nom_variable_dimacs(i,j-1,l,LAMPE));
        fprintf(f,"%d %d 0\n",nom_variable_dimacs(i-1,j,l,LAMPE),nom_variable_dimacs(i,j+1,l,LAMPE));
        fprintf(f,"%d %d 0\n",nom_variable_dimacs(i+1,j,l,LAMPE),nom_variable_dimacs(i,j-1,l,LAMPE));
        fprintf(f,"%d %d 0\n",nom_variable_dimacs(i+1,j,l,LAMPE),nom_variable_dimacs(i,j+1,l,LAMPE));
        fprintf(f,"%d %d 0\n",nom_variable_dimacs(i,j-1,l,LAMPE),nom_variable_dimacs(i,j+1,l,LAMPE));
        return 7;
    }


}

int gestion_cond_MUR4(int i,int j,int l,int h,FILE *f){

    fprintf(f,"%d 0\n",nom_variable_dimacs(i-1,j,l,LAMPE));
    fprintf(f,"%d 0\n",nom_variable_dimacs(i+1,j,l,LAMPE));
    fprintf(f,"%d 0\n",nom_variable_dimacs(i,j-1,l,LAMPE));
    fprintf(f,"%d 0\n",nom_variable_dimacs(i,j+1,l,LAMPE));
    return 4;
    
}

int gestion_cond_lampe(int i,int j,Grille G, FILE *f){
    int l,h,k,n_variable_lampe_ij,cpt;
    l=G.l;
    h=G.h;
    n_variable_lampe_ij=nom_variable_dimacs(i,j,l,LAMPE);
    fprintf(f,"%d -%d 0\n",nom_variable_dimacs(i,j,l,ECLAIRE),n_variable_lampe_ij);
    cpt=1;
    k=i-1;
    while (k>=0 && !est_mur(G,k,j)){
        fprintf(f,"-%d -%d 0\n",n_variable_lampe_ij,nom_variable_dimacs(k,j,l,LAMPE));
        fprintf(f,"%d -%d 0\n",nom_variable_dimacs(k,j,l,ECLAIRE),n_variable_lampe_ij);
        cpt+=2;
        k--;
    }
    k=j-1;
    while (k>=0 && !est_mur(G,i,k)){
        fprintf(f,"-%d -%d 0\n",n_variable_lampe_ij,nom_variable_dimacs(i,k,l,LAMPE));
        fprintf(f,"%d -%d 0\n",nom_variable_dimacs(i,k,l,ECLAIRE),n_variable_lampe_ij);
        cpt+=2;
        k--;
    }
    k=j+1;
    while (k<l && !est_mur(G,i,k)){
        fprintf(f,"-%d -%d 0\n",n_variable_lampe_ij,nom_variable_dimacs(i,k,l,LAMPE));
        fprintf(f,"%d -%d 0\n",nom_variable_dimacs(i,k,l,ECLAIRE),n_variable_lampe_ij);
        cpt+=2;
        k++;
    }
    k=i+1;
    while (k<h && !est_mur(G,k,j)){
        fprintf(f,"-%d -%d 0\n",n_variable_lampe_ij,nom_variable_dimacs(k,j,l,LAMPE));
        fprintf(f,"%d -%d 0\n",nom_variable_dimacs(k,j,l,ECLAIRE),n_variable_lampe_ij);
        cpt+=2;
        k++;
    }
    return cpt;
}

int ecriture_condition(FILE *f,Grille G){

    int i,j,l,h,cpt;
    int n_eclaire_ij,n_lampe_ij,n_mur_ij;
    l = G.l;
    h = G.h;
    //cpt est un compteur du nombre de clauses totale dans le fichier
    cpt = 0;

    for(i = 0;i<h;i++){

        for(j = 0;j<l;j++){
            n_eclaire_ij=nom_variable_dimacs(i,j,l,ECLAIRE);
            n_lampe_ij=nom_variable_dimacs(i,j,l,LAMPE);
            n_mur_ij=nom_variable_dimacs(i,j,l,MUR);
            //condition empechant d'avoir une lampen dans un mur 
            fprintf(f,"-%d -%d 0\n",n_lampe_ij,n_mur_ij);
            //condition de victoire (toutes les cases sont éclairées sauf les murs)
            fprintf(f,"%d %d 0\n",n_eclaire_ij,n_mur_ij);
            cpt+=2;
            switch(G.tab[i][j]){

                case MUR:
                //fixations des valeurs des variables sur les murs
                fprintf(f,"%d 0\n",n_mur_ij);
                cpt++;
                break;

                case MUR_0:
                //fixations des valeurs des variables sur les murs
                fprintf(f,"%d 0\n",n_mur_ij);
                cpt++;
                // Gestion des mur avec conditions
                cpt+=gestion_cond_MUR0(i,j,l,h,f);
                break;

                case MUR_1:
                //fixations des valeurs des variables sur les murs
                fprintf(f,"%d 0\n",n_mur_ij);
                cpt++;
                // Gestion des mur avec conditions
                cpt+=gestion_cond_MUR1(i,j,l,h,f);
                break;

                case MUR_2:
                //fixations des valeurs des variables sur les murs
                fprintf(f,"%d 0\n",n_mur_ij);
                cpt++;
                // Gestion des mur avec conditions
                cpt+=gestion_cond_MUR2(i,j,l,h,f);
                break;

                case MUR_3:
                //fixations des valeurs des variables sur les murs
                fprintf(f,"%d 0\n",n_mur_ij);
                cpt++;
                // Gestion des mur avec conditions
                cpt+=gestion_cond_MUR3(i,j,l,h,f);
                break;

                case MUR_4:
                //fixations des valeurs des variables sur les murs
                fprintf(f,"%d 0\n",n_mur_ij);
                cpt++;
                // Gestion des mur avec conditions
                cpt+=gestion_cond_MUR4(i,j,l,h,f);
                break;

                default:
                //fixations des valeurs des variables sur les murs
                fprintf(f,"-%d 0\n",n_mur_ij);
                cpt++;
                // Gestion des condition sur la presence d'une lampe
                cpt+=gestion_cond_lampe(i,j,G,f);
                break;
                
            }
            
        }

    }

    return cpt;

}

void ecriture_dimacs(FILE *f, Grille G){
    int nb_clause;
    char c;
    FILE *tmp;
    tmp=fopen("condition_tmp.txt","w");
    nb_clause=ecriture_condition(tmp,G);
    fclose(tmp);
    fopen("condition_tmp.txt","r");
    fprintf("p cnf %d %d",G.h*G.l*3,nb_clause);
    while(!feof(tmp)){
        fscanf(tmp,"%c",c);
        fprintf(f,"%c",c);
    }
    fclose(f);
    fclose(tmp);
    remove(tmp);

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
