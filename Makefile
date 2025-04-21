CC = clang -g -Wall

EXECUTABLES = test_grille test_conversion main

all : $(EXECUTABLES)

grille.o : grille.c grille.h
	@echo ""
	@echo "---------------------------------------------"
	@echo "Compilation du module grille"
	@echo "---------------------------------------------"
	$(CC) -c $<

test_grille.o : test_grille.c grille.h
	@echo ""
	@echo "---------------------------------------------"
	@echo "Compilation du module test_grille"
	@echo "---------------------------------------------"
	$(CC) -c $<

conversion_dimacs.o : conversion_dimacs.c conversion_dimacs.h 
	@echo ""
	@echo "---------------------------------------------"
	@echo "Compilation du module conversion_dimacs"
	@echo "---------------------------------------------"
	$(CC) -c $<

test_conversion.o : test_conversion.c grille.h conversion_dimacs.h
	@echo ""
	@echo "---------------------------------------------"
	@echo "Compilation du module test_conversion"
	@echo "---------------------------------------------"
	$(CC) -c $<

jeu.o : jeu.c conversion_dimacs.h grille.h
	@echo ""
	@echo "---------------------------------------------"
	@echo "Compilation du module jeu"
	@echo "---------------------------------------------"
	$(CC) -c $<

main.o : main.c jeu.h grille.h conversion_dimacs.h
	@echo ""
	@echo "---------------------------------------------"
	@echo "Compilation du module main"
	@echo "---------------------------------------------"
	$(CC) -c $<

test_grille : test_grille.o grille.o
	@echo ""
	@echo "---------------------------------------------"
	@echo "Creation de l'executable "$@
	@echo "---------------------------------------------"
	$(CC) $^ -o $@

test_conversion : test_conversion.o grille.o conversion_dimacs.o
	@echo ""
	@echo "---------------------------------------------"
	@echo "Creation de l'executable "$@
	@echo "---------------------------------------------"
	$(CC) $^ -o $@

main : main.o jeu.o grille.o conversion_dimacs.o
	@echo ""
	@echo "---------------------------------------------"
	@echo "Creation de l'executable "$@
	@echo "---------------------------------------------"
	$(CC) $^ -o $@

clean:
	rm -fR $(EXECUTABLES) *.o
