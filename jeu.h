#ifndef _JEU_H_
#define _JEU_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grille.h"
#include "conversion_dimacs.h"

Grille jouer_coup(Grille G);

int fin_partie(Grille G,char *nom_fichier);

void start(Grille grille, char *nom_fichier);
#endif 