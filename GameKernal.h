#ifndef GAMEKERNAL_H
#define GAMEKERNAL_H
#include "Map.h"
#include "ColorGenerator.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <ostream>
#include <string>
enum status{
        GRASS_EMPTY,
        GOAT_EMPTY,
        GOAT_GRASS
};
class gamekernal{
        public:
                gamekernal();
                ~gamekernal();
                status two_compare_pixels(map_node,map_node);
                void goat_move(map_node*,map_node*);
                void goat_grownewgoat(map_node*,map_node*);
                void goat_eatgrass(map_node*,map_node*);
                void grass_grownewgrass(map_node*);
                void goat_action(int, int, direction);
                void grass_action(int ,int , direction);
                void setCreaturesNum();
		void GameInitalize();
		void GameOneRun();
                void ShowMap();
		void allclear();
        private:
                map game_map;
		int InitGoatNum;
		int InitGrassNum ;
		int Goat_Num;
		int Grass_Num;
};
#endif //GAMEKERNAL_H
