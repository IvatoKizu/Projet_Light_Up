#include "conversion_dimacs.h"


void ecriture_fich(FILE *f,Grille G){

    int i,j,l,h;
    l = G.l;
    h = G.h;

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
    */

    for(i = 0;i<h;i++){

        for(j = 0;j<l;j++){

            switch(G.tab[i][j]){

                case MUR:
                fprintf("%d 0",(i*l + j)*8 + 3);
                break;

                case MUR_0:
                fprintf("%d 0",(i*l + j)*8 + 4);
                break;

                case MUR_1:
                fprintf("%d 0",(i*l + j)*8 + 5);
                break;

                case MUR_2:
                fprintf("%d 0",(i*l + j)*8 + 6);
                break;

                case MUR_3:
                fprintf("%d 0",(i*l + j)*8 + 7);
                break;

                case MUR_4:
                fprintf("%d 0",(i*l + j)*8 + 8);
                break;

                case default:
                break;

            }
            
        }

    }

}