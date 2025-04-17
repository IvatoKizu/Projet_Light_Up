#include"conversion_dimacs.h"

/* Formules pour trouver la variable dimacs à partir des coordonnées i,j :
    i * nb_de_lignes * 8 + j * 8 + nb_variable = (i*nb_lignes + j)*8 + nb_variable
    avec nb_variable =
    1 pour Ei,j
    2 pour Li,j
    3 pour Mi,j
    4 pour M0i,j
    5 pour M1i,j
    6 pour M2i,j
    7 pour M3i,j
    8 pour M4i,j
    on peut donc utiliser les valeurs du type énuméré Case
    Ne pas utiliser la valeur libre!!
    */
int nom_variable_dimacs(int i ,int j ,int l,Case nb_variable){
    return (i*l + j)*8 + nb_variable;
}

void ecriture_fich(FILE *f,Grille G){

    int i,j,l,h;
    int n_eclaire_ij,n_lampe_ij,n_mur_ij,n_mur_0_ij,n_mur_1_ij,n_mur_2_ij,n_mur_3_ij,n_mur_4_ij;
    l = G.l;
    h = G.h;

    

    for(i = 0;i<h;i++){

        for(j = 0;j<l;j++){
            n_eclaire_ij=nom_variable_dimacs(i,j,l,ECLAIRE);
            n_lampe_ij=nom_variable_dimacs(i,j,l,LAMPE);
            n_mur_ij=nom_variable_dimacs(i,j,l,MUR);
            n_mur_0_ij=nom_variable_dimacs(i,j,l,MUR_0);
            n_mur_1_ij=nom_variable_dimacs(i,j,l,MUR_1);
            n_mur_2_ij=nom_variable_dimacs(i,j,l,MUR_2);
            n_mur_3_ij=nom_variable_dimacs(i,j,l,MUR_3);
            n_mur_4_ij=nom_variable_dimacs(i,j,l,MUR_4);
            fprintf(f,"-%d -%d 0\n",n_lampe_ij,n_mur_ij);
            fprintf(f,"%d %d 0\n",n_eclaire_ij,n_mur_ij);
            switch(G.tab[i][j]){

                case MUR:
                //fixations des valeurs des variables sur les murs
                fprintf(f,"%d 0\n",n_mur_ij);
                fprintf(f,"-%d 0\n",n_mur_0_ij);
                fprintf(f,"-%d 0\n",n_mur_1_ij);
                fprintf(f,"-%d 0\n",n_mur_2_ij);
                fprintf(f,"-%d 0\n",n_mur_3_ij);
                fprintf(f,"-%d 0\n",n_mur_4_ij);
                break;

                case MUR_0:
                //fixations des valeurs des variables sur les murs
                fprintf(f,"%d 0\n",n_mur_ij);
                fprintf(f,"%d 0\n",n_mur_0_ij);
                fprintf(f,"-%d 0\n",n_mur_1_ij);
                fprintf(f,"-%d 0\n",n_mur_2_ij);
                fprintf(f,"-%d 0\n",n_mur_3_ij);
                fprintf(f,"-%d 0\n",n_mur_4_ij);
                break;

                case MUR_1:
                //fixations des valeurs des variables sur les murs
                fprintf(f,"%d 0\n",n_mur_ij);
                fprintf(f,"-%d 0\n",n_mur_0_ij);
                fprintf(f,"%d 0\n",n_mur_1_ij);
                fprintf(f,"-%d 0\n",n_mur_2_ij);
                fprintf(f,"-%d 0\n",n_mur_3_ij);
                fprintf(f,"-%d 0\n",n_mur_4_ij);
                break;

                case MUR_2:
                //fixations des valeurs des variables sur les murs
                fprintf(f,"%d 0\n",n_mur_ij);
                fprintf(f,"-%d 0\n",n_mur_0_ij);
                fprintf(f,"-%d 0\n",n_mur_1_ij);
                fprintf(f,"%d 0\n",n_mur_2_ij);
                fprintf(f,"-%d 0\n",n_mur_3_ij);
                fprintf(f,"-%d 0\n",n_mur_4_ij);
                break;

                case MUR_3:
                //fixations des valeurs des variables sur les murs
                fprintf(f,"%d 0\n",n_mur_ij);
                fprintf(f,"-%d 0\n",n_mur_0_ij);
                fprintf(f,"-%d 0\n",n_mur_1_ij);
                fprintf(f,"-%d 0\n",n_mur_2_ij);
                fprintf(f,"%d 0\n",n_mur_3_ij);
                fprintf(f,"-%d 0\n",n_mur_4_ij);
                break;

                case MUR_4:
                //fixations des valeurs des variables sur les murs
                fprintf(f,"%d 0\n",n_mur_ij);
                fprintf(f,"-%d 0\n",n_mur_0_ij);
                fprintf(f,"-%d 0\n",n_mur_1_ij);
                fprintf(f,"-%d 0\n",n_mur_2_ij);
                fprintf(f,"-%d 0\n",n_mur_3_ij);
                fprintf(f,"%d 0\n",n_mur_4_ij);
                
                break;

                case default:
                //fixations des valeurs des variables sur les murs
                fprintf(f,"-%d 0\n",n_mur_ij);
                fprintf(f,"-%d 0\n",n_mur_0_ij);
                fprintf(f,"-%d 0\n",n_mur_1_ij);
                fprintf(f,"-%d 0\n",n_mur_2_ij);
                fprintf(f,"-%d 0\n",n_mur_3_ij);
                fprintf(f,"-%d 0\n",n_mur_4_ij);
                break;

            }
            
        }

    }

}