#ifndef _CONVERSION_DIMACS_H_
#define _CONVERSION_DIMACS_H_
#include <stdio.h>
#include <stdlib.h>
#include "grille.h"

int nom_variable_dimacs(int i ,int j ,int l,Case nb_variable);

void gestion_cond_MUR0(int i,int j,int l,int h,FILE *f);

void gestion_cond_MUR1(int i,int j,int l,int h,FILE *f);

void gestion_cond_MUR2(int i,int j,int l,int h,FILE *f);

void gestion_cond_MUR3(int i,int j,int l,int h,FILE *f);

void gestion_cond_MUR4(int i,int j,int l,int h,FILE *f);

void ecriture_fich(FILE *f,Grille G);

#endif