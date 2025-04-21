#ifndef _CONVERSION_DIMACS_H_
#define _CONVERSION_DIMACS_H_
#include <stdio.h>
#include <stdlib.h>
#include "grille.h"

int nom_variable_dimacs(int i ,int j ,int l,Case nb_variable);

int gestion_cond_MUR0(int i,int j,int l,int h,FILE *f);

int gestion_cond_MUR1(int i,int j,int l,int h,FILE *f);

int gestion_cond_MUR2(int i,int j,int l,int h,FILE *f);

int gestion_cond_MUR3(int i,int j,int l,int h,FILE *f);

int gestion_cond_MUR4(int i,int j,int l,int h,FILE *f);

int gestion_cond_lampe(int i,int j,Grille G, FILE *f);

void gestion_cond_eclaire(int i,int j,Grille G,FILE *f);

int ecriture_condition(FILE *f, Grille G);

void ecriture_dimacs(FILE *f, Grille G);

int lecture_fich(FILE *f, Grille G); // Retourne 0 si satisfaisable 1 sinon

#endif