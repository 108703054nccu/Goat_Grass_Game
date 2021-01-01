#include "Game.h"
#include<iostream>
int main(){
	game this_game;
	this_game.StartGame();
	this_game.ShowMap();
	std::cout<<"------------------------------------------"<<std::endl;
	for(int i = 0;i<4;i++)this_game.RunGameOne();
	this_game.ShowMap();
	return 0;
}
