#ifndef _GRILLE_H_
#define _GRILLE_H_

#include <stdio.h>
#include <stdlib.h>

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

/*  prends en paramètre la longueur et la largeur
    renvoi une grille avec les valeurs l et h inialisées 
    et un tableau de la taille correspondantes au valeurs non-initialisées*/
Grille init_Grille(int longueur, int hauteur);

/*  prends en paramètre un pointeur de fichier terrain
    renvoie la grille correspondantes*/
Grille lire_Grille(FILE *f);

/*  renvoie une copie de la grille en paramètre.*/
Grille copie_Grille(Grille G);

/*  ajoute une lampe sur la grille G à la case x,y pris en paramètre
    effectue les modification nécessaire sur les case éclairés.*/
Grille ajouter_lampe(Grille G, int x, int y);

/*  supprime une lampe sur la grille G à la case i,j pris en paramètre
    effectue les modification nécessaire sur les case éclairés.*/
void supprimer_lampe(Grille *G,int i,int j);
 
/*  Verifie si la case i,j est éclairé par une lampe.
    renvoi 1 si la case est éclairé 0 sinon*/
int est_eclaire(Grille G, int i,int j); 

/*  Verifie que la case i,j soit libre.*/
int est_libre(Grille G,int i,int j);

/*  Verifie que la case i,j soit un mur (peut importe le type de mur).*/
int est_mur(Grille G,int i,int j);

/*  affiche la grille G à l'écran.*/
void afficher_Grille(Grille G);

/*  génère une grille de longeur et largeur voulu avec un pourcentage de mur proche de celui fournit en paramètre.*/
Grille generation_grille_random(int longueur, int hauteur, int pourcentage_mur);

/*  génère une grille qui à une unique solution.*/
Grille unique_sat_generation_grille_random(int longueur, int hauteur, int pourcentage_mur);

void supprime_Grille(Grille G);    // Free le tableau contenu dans la Grille G

#endif 
