#ifndef _CONVERSION_DIMACS_H_
#define _CONVERSION_DIMACS_H_
#include <stdio.h>
#include <stdlib.h>
#include "grille.h"

typedef struct {    // L'idée est d'avoir un tableau 2D d'associations afin de pouvoir retrouver la valeur Dimacs des informations 
                    // Li,j / Ei,j / Mi,j ... 

    int L,E,M,M0,M1,M2,M3,M4;

} association;

typedef struct {
    
    int l,h;
    association **tab;

} annuaire;


void ecriture_fich(FILE *f,Grille G);

#endif