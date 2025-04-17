#ifndef _CONVERSION_DIMACS_H_
#define _CONVERSION_DIMACS_H_
#include <stdio.h>
#include <stdlib.h>
#include "grille.h"

int nom_variable_dimacs(int i ,int j ,int l,Case nb_variable);

void ecriture_fich(FILE *f,Grille G);

#endif