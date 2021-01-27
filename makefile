OBJECTS= ColorGenerator.o Creature.o Animal.o Lion.o Snake.o Goat.o Grass.o Map.o GameKernal.o CommandIO.o Game.o
CERROR= complieError.txt
THREAD= -pthread
C++11= -std=c++11
game.out:$(OBJECTS)
	g++ $(C++11) main.cpp -o game.out $(THREAD) $(OBJECTS) 2>>$(CERROR)
	rm -f *.o
ColorGenerator.o:ColorGenerator.h
	rm -f $(CERROR)
	g++ $(C++11) -c ColorGenerator.cpp  2>>$(CERROR)
Creature.o:Creature.h
	g++ $(C++11) -c Creature.cpp  2>>$(CERROR)
Animal.o:Animal.h
	g++ $(C++11) -c Animal.cpp  2>>$(CERROR)
Goat.o:Goat.h
	g++ $(C++11) -c Goat.cpp  2>>$(CERROR)
Lion.o:Lion.h
	g++ $(C++11) -c Lion.cpp  2>>$(CERROR)
Snake.o:Snake.h
	g++ $(C++11) -c Snake.cpp  2>>$(CERROR)
Grass.o:Grass.h
	g++ $(C++11) -c Grass.cpp  2>>$(CERROR)
Map.o:Map.h
	g++ $(C++11) -c Map.cpp  2>>$(CERROR)
GameKernal.o:GameKernal.h
	g++ $(C++11) -c GameKernal.cpp  2>>$(CERROR)
CommandIO.o:CommandIO.h
	g++ $(C++11) -c CommandIO.cpp  2>>$(CERROR)
Game.o:Game.h
	g++ $(C++11) -c Game.cpp $(THREAD) 2>>$(CERROR)
.PHONY: clean
clean:
	rm -f *.out $(CERROR) 
