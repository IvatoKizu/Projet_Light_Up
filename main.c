#include <string.h>
#include "grille.h"
#include "conversion_dimacs.h"

int main(int argc,char* argv[]){
    Grille grille;

    grille = init_Grille(5,5);
    afficher_Grille(grille);
}