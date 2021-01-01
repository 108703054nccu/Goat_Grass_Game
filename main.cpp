#include "Game.h"
#include<iostream>
#include<unistd.h>
#include<string>
int main(){
	game this_game;
	this_game.StartGame();
	this_game.ShowMap();
	sleep(1);
	std::cout<<std::string ( 1000, '\n');
	for(int i = 0;i<300;i++){
		this_game.RunGameOne();
		this_game.ShowMap();
		sleep(1);
		std::cout<<std::string ( 1000, '\n');
	}
	return 0;
}
