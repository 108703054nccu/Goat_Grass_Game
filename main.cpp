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
	while(1){
		this_game.RunGameOne();
		this_game.ShowMap();
		sleep(1);
		std::cout<<std::string ( 1000, '\n');
	}
	return 0;
}
