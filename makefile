game.out:ColorGenerator.o Creature.o Goat.o Grass.o Map.o Game.o
	g++ -std=c++11 main.cpp -pthread  -o game.out ColorGenerator.o Creature.o Goat.o Grass.o Map.o Game.o
ColorGenerator.o:ColorGenerator.cpp ColorGenerator.h
	g++ -c ColorGenerator.cpp
Creature.o:Creature.cpp Creature.h
	g++ -c Creature.cpp
Animal.o:Animal.h Animal.cpp
	g++ -c Animal.cpp
Goat.o:Goat.cpp Goat.h
	g++ -c Goat.cpp
Grass.o:Grass.cpp Grass.h
	g++ -c Grass.cpp
Map.o:Map.cpp Map.h
	g++ -c Map.cpp
Game.o:Game.cpp Game.h
	g++ -std=c++11 -c Game.cpp -pthread
clean:
	rm -f game.out main.o ColorGenerator.o Creature.o Goat.o Grass.o Map.o Game.o
