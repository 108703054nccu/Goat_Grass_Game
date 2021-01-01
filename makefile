game.out:Creature.o Goat.o Grass.o Map.o Game.o
	g++ main.cpp -o game.out Creature.o Goat.o Grass.o Map.o Game.o
Creature.o:Creature.cpp Creature.h
	g++ -c Creature.cpp
Goat.o:Goat.cpp Goat.h
	g++ -c Goat.cpp
Grass.o:Grass.cpp Grass.h
	g++ -c Grass.cpp
Map.o:Map.cpp Map.h
	g++ -c Map.cpp
Game.o:Game.cpp Game.h
	g++ -c Game.cpp
clean:
	rm -f game.out main.o Creature.o Goat.o Grass.o Map.o Game.o
