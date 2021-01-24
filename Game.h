#ifndef GMAE_H
#define GAME_H
#include "Map.h"
#include "ColorGenerator.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <ostream>
#include <unistd.h>
#include <string>
#include <thread>
#include <chrono>             
#include <mutex>              
#include <condition_variable> 
enum status{
        GRASS_EMPTY,
        GOAT_EMPTY,
        GOAT_GRASS
};
class game{
        public:
                game();
                ~game();
                status two_compare_pixels(map_node,map_node);
                void goat_move(map_node*,map_node*);
                void goat_grownewgoat(map_node*,map_node*);
                void goat_eatgrass(map_node*,map_node*);
                void grass_grownewgrass(map_node*);
                void goat_action(int, int, direction);
                void grass_action(int ,int , direction);
                void RunGameOne();
                void StartGame();
                void ShowMap();
		void GameExecute();
		void ChangeCommand();
        private:
                map game_map;
		std::condition_variable cv;
		int value;
};
#endif //GAME_H
