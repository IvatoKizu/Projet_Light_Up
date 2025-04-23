#ifndef _CONVERSION_DIMACS_H_
#define _CONVERSION_DIMACS_H_
#include <stdio.h>
#include <stdlib.h>
#include "grille.h"

/*  prend en argument les coordonnées d'une case la largeur de la grille et la variable voulu
    renvoi le numéro de la variable associée pour le fichier dimacs*/
int nom_variable_dimacs(int i ,int j ,int l,Case nb_variable);

/*  prend en argument les coordonnées d'une case la largeur de la grille et le fichier dans lequel on écrit les clauses
    écrit les clauses correspondantes au fait d'avoir un MUR_0 sur cette case et renvoi le nombre de clauses écrites.*/
int gestion_cond_MUR0(int i,int j,int l,int h,FILE *f);

/*  prend en argument les coordonnées d'une case la largeur de la grille et le fichier dans lequel on écrit les clauses
    écrit les clauses correspondantes au fait d'avoir un MUR_1 sur cette case et renvoi le nombre de clauses écrites.*/
int gestion_cond_MUR1(int i,int j,int l,int h,FILE *f);

/*  prend en argument les coordonnées d'une case la largeur de la grille et le fichier dans lequel on écrit les clauses
    écrit les clauses correspondantes au fait d'avoir un MUR_2 sur cette case et renvoi le nombre de clauses écrites.*/
int gestion_cond_MUR2(int i,int j,int l,int h,FILE *f);

/*  prend en argument les coordonnées d'une case la largeur de la grille et le fichier dans lequel on écrit les clauses
    écrit les clauses correspondantes au fait d'avoir un MUR_3 sur cette case et renvoi le nombre de clauses écrites.*/
int gestion_cond_MUR3(int i,int j,int l,int h,FILE *f);

/*  prend en argument les coordonnées d'une case la largeur de la grille et le fichier dans lequel on écrit les clauses
    écrit les clauses correspondantes au fait d'avoir un MUR_4 sur cette case et renvoi le nombre de clauses écrites.*/
int gestion_cond_MUR4(int i,int j,int l,int h,FILE *f);

/*  prend en argument les coordonnées d'une case la largeur de la grille et le fichier dans lequel on écrit les clauses
    écrit les clauses correspondantes au fait d'avoir une lampe sur cette case et renvoi le nombre de clauses écrites.*/
int gestion_cond_lampe(int i,int j,Grille G, FILE *f);

/*  prend en argument les coordonnées d'une case la largeur de la grille et le fichier dans lequel on écrit les clauses
    écrit la clause correspondante au fait d'avoir une case éclairée à ces coordonnées.*/
void gestion_cond_eclaire(int i,int j,Grille G,FILE *f);

/*  prend une grille de départ(sans lampe déjà placée) et un fichier en paramètre
    écrit toutes les clauses correspondantes à cette grille dans le fichier et renvoi le nombre totale de clauses.*/
int ecriture_condition(FILE *f, Grille G);

/*  prend une grille de départ(sans lampe déjà placée) et un fichier en paramètre
    écrit l'entête du fichier DIMACS ainsi que les clause sorrepondantes à la grille.*/
void ecriture_dimacs(FILE *f, Grille G);

/*  prend en paramètre le fichier sortie du SAT solver et la grille correspondantes à la formule fournit au sat solver
    écrit la grille correspondante à la solution du SAT solver dans la grille en paramètre
    renvoie un entier en fonction du résultat fournit par le SAT solver:
    0 Le SAT solver à trouver une solution correcte
    1 La grille est insatisfaisable
    2 La solution fournit par le sat solver ne correspond pas à la grille (n'arrive jamais présent pour les tests)*/
int lecture_fich(FILE *f, Grille G); // Retourne 0 si satisfaisable 1 sinon

#endif