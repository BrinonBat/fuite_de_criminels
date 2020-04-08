FLAGS = -Wall -std=c++14
MAIN = main.cpp
FICS = Personnage.cc Jeu.cc
EXEC = exe

main: $(MAIN) $(FICS)
	g++ $(FLAGS) $(MAIN) $(FICS) -o $(EXEC)

clean:
	rm $(EXEC)
