FLAGS = -Wall -std=c++14
MAIN = main.cpp
FICS = task.cpp
EXEC = exe

main: $(MAIN) $(FICS)
	g++ $(FLAGS) $(MAIN) $(FICS) -o $(EXEC)

clean:
	rm $(EXEC)
