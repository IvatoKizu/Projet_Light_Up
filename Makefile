CC = clang -g -Wall

EXECUTABLES = test_grille

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

test_grille : test_grille.o grille.o
	@echo ""
	@echo "---------------------------------------------"
	@echo "Creation de l'executable "$@
	@echo "---------------------------------------------"
	$(CC) $^ -o $@

clean:
	rm -fR $(EXECUTABLES) *.o
