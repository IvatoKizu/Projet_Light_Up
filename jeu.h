#ifndef _JEU_H_
#define _JEU_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grille.h"
#include "conversion_dimacs.h"

/*  Prends en paramètre un pointeur sur une chaine de caractère
    Demande au joueur le terrain sur lequel il souhaite jouer place le nom du fichier terrain dans la chaine de caractère
    renvoie la grille correspondantes au terrain choisi
    permet au joueur de choisir un terrain générer aléatoirement*/
Grille choix_fichier(char **nom_fichier);

/*  Prends en paramètre la grille de jeu
    Permet au joueur de placer/supprimer une lampe
                        demander un indice
                        tester si la disposition est la solution
    modifie la variable résultat pour connaitre le type de coup jouer*/
Grille jouer_coup(Grille G, int *resultat);

/*  Prends en paramètre la grille de jeu et la grille de solution
    donne un indice au joueur:
    une lampe à supprimer si une lampe ne fait pas parti de la solution
    une lampe à placer s'il n'y as pas de lampe incorrecte
    renvoi 1 si la grille est dejà identique à la solution 0 sinon*/
int indice(Grille G, Grille solution);

/*  prends en paramètre une grille de départ et le nom du fichier terrain associer à la grille
    appele les fonctions présente dans conversion DIMACS pour générer la grille de solution. (G est écrasé)*/
Grille fin_partie(Grille G,char *nom_fichier);

/*  prends en paramètre la grille de jeu et la grille de solution
    compare les grilles pour savoir si le joueur à gagner.*/
int resultat_correcte(Grille G, Grille solution);

/*  prends en paramètre la grille de départ et la grille de solution
    effectue la boucle de jeu.*/
void start(Grille grille, Grille solution);

/*  prends en paramètre un grille vérifie que cett cette grille à une unique solution*/
int satisfaisabilite_unicite(Grille G); // Retourne 0 si satisfaisable et solution unique

#endif 

