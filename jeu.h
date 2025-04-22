#ifndef _JEU_H_
#define _JEU_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grille.h"
#include "conversion_dimacs.h"

Grille choix_fichier(char **nom_fichier);

Grille jouer_coup(Grille G);

Grille fin_partie(Grille G,char *nom_fichier);

int resultat_correcte(Grille G, Grille solution);

void start(Grille grille, Grille solution);
#endif 