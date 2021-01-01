#include "Game.h"
#include<iostream>
int main(){
	game this_game;
	this_game.StartGame();
	this_game.ShowMap();
	for(int i = 0;i<20;i++)this_game.RunGameOne();
	this_game.ShowMap();
	return 0;
}
