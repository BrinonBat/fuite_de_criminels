FLAGS = -Wall -std=c++14
MAIN = main.cpp
FICS =Jeu.cc Entites.cc
EXEC = exe

main: $(MAIN) $(FICS)
	g++ $(FLAGS) $(MAIN) $(FICS) -o $(EXEC)

clean:
	rm $(EXEC)
