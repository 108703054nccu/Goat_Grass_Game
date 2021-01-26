game.out:ColorGenerator.o Creature.o Animal.o Lion.o Snake.o Goat.o Grass.o Map.o GameKernal.o Game.o CommandIO.o
	g++ -std=c++11 main.cpp -o game.out -pthread ColorGenerator.o Creature.o Animal.o Lion.o Snake.o Goat.o Grass.o Map.o GameKernal.o CommandIO.o Game.o
ColorGenerator.o:ColorGenerator.cpp ColorGenerator.h
	g++ -c ColorGenerator.cpp 
Creature.o:Creature.cpp Creature.h
	g++ -c Creature.cpp 
Animal.o:Animal.cpp Animal.h
	g++ -c Animal.cpp 
Goat.o:Goat.cpp Goat.h
	g++ -c Goat.cpp
Lion.o:Lion.cpp Lion.h
	g++ -c Lion.cpp
Snake.o:Snake.cpp Snake.h
	g++ -c Snake.cpp
Grass.o:Grass.cpp Grass.h
	g++ -c Grass.cpp
Map.o:Map.cpp Map.h
	g++ -c Map.cpp
GameKernal.o:GameKernal.cpp GameKernal.h
	g++ -c GameKernal.cpp
CommandIO.o:CommandIO.cpp CommandIO.h
	g++ -c CommandIO.cpp
Game.o:Game.cpp Game.h
	g++ -std=c++11 -c Game.cpp -pthread
clean:
	rm -f game.out main.o ColorGenerator.o Creature.o Animal.o Goat.o Snake.o Lion.o Grass.o Map.o GameKernal.o CommandIO.o Game.o
