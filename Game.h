#ifndef GAME_H
#define GAME_H
#include "Map.h"
enum class status{
	GOAT_GRASS,
	GOAT_GOAT,
	GOAT_NULL,
	GRASS_NULL,
	GRASS_GRASS,
	NULL_NULL,
};
class game{
	public:
		game();
		~game();
		void runGame();
		void stopGame();
		void startGame();
		status two_compare_pixel(map_node&,map_node&);//比較兩個map node的關係//
		//void goat_move(int,int, int);//羊的移動//
		void goat_move(map_node,map_node);//
		void goat_eatgrass(map_node,map_node);//羊吃草
		void grass_grow(map_node);//草生長
		void goat_makenewgoat(map_node);//羊生小羊
		void showMap();//
	protected:
	private:
		map game_map;
};
#endif //GAME_H
