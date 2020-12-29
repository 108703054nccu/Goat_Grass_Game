game.out:main.o Creature.o Goat.o Grass.o Map.o Game.o
	g++ -o game.out  main.o Creature.o Goat.o Grass.o Map.o Game.o
main.o:main.cpp
	g++ -c main.cpp
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
