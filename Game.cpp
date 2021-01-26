#include "Game.h"
#include <iostream>
#include <string>
#include <unistd.h>
game::game(){
	command = 1;
	isgamestart = false;
}
game::~game(){;}
void game::StartGame(){
	system("clear");
	GameKernal.allclear();
	std::cout<<"Now, it is empty"<<std::endl;
	GameKernal.ShowMap();
	sleep(1);
	system("clear");
	GameKernal.setCreaturesNum();
	GameKernal.GameInitalize();
	GameKernal.ShowMap();
	isgamestart = true;
	command = 1;
}
void game::GameMainExe(){
	StartGame();
	if(isgamestart){
		GameExe();
		isgamestart = false;
	}
	switch(command){
		case 2:GameMainExe();
		case 3:QuitGame();break;
	}
}
void game::CommandExe(){
	std::string commands;
	while(std::cin>>commands){
		if(commands == "3"){
			command = 3;
			commands.clear();
			break;
		}
		else if(commands == "2"){
			command = 2;
			commands.clear();
			break;
		}
		else{
			commands.clear();
			continue;
		}
	}
	if(command != 1)GameExecv.notify_one();
}
void game::GameExe(){
	std::unique_lock<std::mutex> lck(GameExetx);
	std::thread Commandth(&game::CommandExe,this);
	while(GameExecv.wait_for(lck, std::chrono::milliseconds(400)) == \
			std::cv_status::timeout || \
			command == 1){
		system("clear");
		GameKernal.GameOneRun();
		GameKernal.ShowMap();
		CommandKernal.ShowCommandList();
	}
	Commandth.join();
}
void game::QuitGame(){;}

