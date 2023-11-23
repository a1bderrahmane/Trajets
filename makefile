ECHO = @echo
GCC = g++
RM = @rm -f
CCFLAGS = -c -g -O1 -ansi -pedantic -Wall -std=c++11 
MAP = -DMAP #Commenter cette ligne si on veut compiler sans le mode Mise Au Point
OBJETS = $(SRC:.cpp=.o)
SRC = $(wildcard *.cpp) #Récupère tous les fichiers .cpp du répertoire courant
EXE = trajets
LIBRAIRIES = 

$(EXE) : $(OBJETS)
	$(ECHO) "-Edition des liens de $(EXE)-"
	$(GCC) -o $@ $^ $(LIBRAIRIES)
	
%.o:%.cpp
	$(ECHO) "-Compilation de $<- "
	$(GCC) $(CCFLAGS) $(MAP) -o $@ $<

.PHONY: clean #Pour que make clean fonctionne même si un fichier s'appelant clean existe
clean:
	$(ECHO) "-Nettoyage-"
	$(RM) $(OBJETS) $(EXE)
