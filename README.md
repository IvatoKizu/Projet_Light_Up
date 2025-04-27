Afin de pouvoir jouer au jeu, il est nécessaire de télécharger minisat. 
Pour compiler : make permet de créer l'exécutable Light_Up et test_conversion
Faire la commande ./Light_Up pour commencer à jouer. 
./test_conversion <fichier_grille.txt> crée fichier_grille.cnf, la modélisation des règles de la grille choisie. 
Le programme produira aussi le fichier de sortie du sat solveur sous le nom output.txt.
Dans l'exécutable Light_up, les fichiers .cnf et les fichiers de sortie du SAT solveur sont automatiquement supprimés. 
Pour empêcher leur suppression mettre en commentaire les lignes 309 et 314 du fichier jeu.c
