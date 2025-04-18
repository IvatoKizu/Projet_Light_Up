#ifndef _GRILLE_H_
#define _GRILLE_H_

#include<stdio.h>
#include<stdlib.h>

/* Format des fichiers grille : 
1 longueur
2 hauteur
3...grille...

La grille est composée de 8 cases différentes : 
LIBRE, représentée par un .
LAMPE, représentée par un L
MUR, représentée par un M
MUR_0, représentée par un 0
MUR_1, représentée par un 1
MUR_2, représentée par un 2
MUR_3, représentée par un 3
MUR_4, représentée par un 4
mettre un retour à la ligne à la fin du fichier
*/

typedef enum {LIBRE,ECLAIRE,LAMPE,MUR,MUR_0,MUR_1,MUR_2,MUR_3,MUR_4} Case;

typedef struct {

    int l,h;
    Case **tab;

} Grille;

//Grille init_Grille();

Grille lire_Grille(FILE *f);

void afficher_Grille(Grille G);

#endif 