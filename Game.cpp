#include "Game.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
game::game(){;}
game::~game(){;}

status game::two_compare_pixels(map_node target,map_node d_target){
	if(target.getFeature() == feature::GOAT && \
			d_target.getFeature() == feature::EMPTY )
		return status::GOAT_EMPTY;
	if(target.getFeature() == feature::GOAT && \
			d_target.getFeature() == feature::GRASS )
		return status::GOAT_GRASS;
	if(target.getFeature() == feature::GRASS && \
			d_target.getFeature() == feature::EMPTY )
		return status::GRASS_EMPTY;
}

void game::goat_move(map_node *target,map_node *d_target){
	d_target->setFeature(feature::GOAT);
	d_target->setAge(target->getAge());
	d_target->setLife(target->getLife());
	target->setFeature(feature::EMPTY);
	d_target->setClr(true);
	return ;
}

void game::goat_grownewgoat(map_node *d_target){
	d_target->setFeature(feature::GOAT);
	d_target->setAge(1);
	d_target->setLife(20);
	d_target->setClr(true);
	return ;
}

void game::goat_eatgrass(map_node *target,map_node *d_target){
	goat_move(target,d_target);
	d_target->setLife(d_target->getLife()+5);
	target->setFeature(feature::EMPTY);
	d_target->setClr(true);
	return ;
}

void game::grass_grownewgrass(map_node *d_target){
	d_target->setFeature(feature::GRASS);
	d_target->setAge(1);
	d_target->setClr(true);
	return ;
}

void game::goat_action(int height,int width,direction d){
	int x = width;
	int y = height;
	if(game_map.nodes[y][x].getCLR()== false && game_map.nodes[y][x].getAge()<= 70){
		switch(d){
			case direction::UP:
				if(game_map.is_at_border(x, y, d)){
					switch(two_compare_pixels(game_map.nodes[y][x],game_map.nodes[y+1][x])){
						case status::GOAT_EMPTY:
							if(game_map.nodes[y][x].getAge() >= 50 && game_map.nodes[y][x].getAge() <= 55){
								goat_grownewgoat(&(game_map.nodes[y+1][x]));
								game_map.nodes[y+1][x].setPosition(x,y+1);
							}
							else{ 
								goat_move(&(game_map.nodes[y][x]),&(game_map.nodes[y+1][x]));
								game_map.nodes[y+1][x].setPosition(x,y+1);
							}
							break;
						case status::GOAT_GRASS:
							goat_eatgrass(&(game_map.nodes[y][x]),&(game_map.nodes[y+1][x]));     
							game_map.nodes[y+1][x].setPosition(x,y+1);
							break;
					}
				}
				//minus life
				break;
			case direction::DOWN:   
				if(game_map.is_at_border(x, y, d)){
					switch(two_compare_pixels(game_map.nodes[y][x],game_map.nodes[y-1][x])){
						case status::GOAT_EMPTY:
							if(game_map.nodes[y][x].getAge() >= 50 && game_map.nodes[y][x].getAge() <= 55){
								goat_grownewgoat(&(game_map.nodes[y-1][x]));
								game_map.nodes[y-1][x].setPosition(x,y-1);
							}
							else{  	
								goat_move(&(game_map.nodes[y][x]),&(game_map.nodes[y-1][x]));
								game_map.nodes[y-1][x].setPosition(x,y-1);
							}
							break;
						case status::GOAT_GRASS:
							goat_eatgrass(&(game_map.nodes[y][x]),&(game_map.nodes[y-1][x]));     
							game_map.nodes[y-1][x].setPosition(x,y-1);
							break;
					}
				}
				//minus life
				break;
			case direction::RIGHT:  
				if(game_map.is_at_border(x, y, d)){
					switch(two_compare_pixels(game_map.nodes[y][x],game_map.nodes[y][x+1])){
						case status::GOAT_EMPTY:
							if(game_map.nodes[y][x].getAge() >= 50 && game_map.nodes[y][x].getAge() <= 55){
								goat_grownewgoat(&(game_map.nodes[y][x+1]));
								game_map.nodes[y][x+1].setPosition(x+1,y);
							}
							else{  	
								goat_move(&(game_map.nodes[y][x]),&(game_map.nodes[y][x+1]));
								game_map.nodes[y][x+1].setPosition(x+1,y);
							}
							break;
						case status::GOAT_GRASS:
							goat_eatgrass(&(game_map.nodes[y][x]),&(game_map.nodes[y][x+1]));     
							game_map.nodes[y][x+1].setPosition(x+1,y);
							break;
					}
				}
				//minus life
				break;
			case direction::LEFT:   
				if(game_map.is_at_border(x, y, d)){
					switch(two_compare_pixels(game_map.nodes[y][x],game_map.nodes[y][x-1])){
						case status::GOAT_EMPTY:
							if(game_map.nodes[y][x].getAge() >= 50 && game_map.nodes[y][x].getAge() <= 55){
								goat_grownewgoat(&(game_map.nodes[y][x-1]));
								game_map.nodes[y][x-1].setPosition(x-1,y);
							}
							else{  	
								goat_move(&(game_map.nodes[y][x]),&(game_map.nodes[y][x-1]));
								game_map.nodes[y][x-1].setPosition(x-1,y);
							}
							break;
						case status::GOAT_GRASS:
							goat_eatgrass(&(game_map.nodes[y][x]),&(game_map.nodes[y][x-1]));     
							game_map.nodes[y][x-1].setPosition(x-1,y);
							break;
					}
				}
				//minus life
				break;
		}

	}
	else{ 
		if(game_map.nodes[y][x].getAge() > 70) {
			game_map.nodes[y][x].setFeature(feature::EMPTY);
			game_map.nodes[y][x].setAge(1);
			game_map.nodes[y][x].setLife(20);
		}
		game_map.nodes[y][x].setClr(false);
	}
}

void game::grass_action(int height,int width,direction d){
	int x = width;
	int y = height;
	if(game_map.nodes[y][x].getCLR()== false && game_map.nodes[y][x].getAge()<= 7){
		switch(d){
			case direction::UP:
				if(game_map.is_at_border(x, y, d)){
					switch(two_compare_pixels(game_map.nodes[y][x],game_map.nodes[y+1][x])){
						case status::GRASS_EMPTY:
							if(game_map.nodes[y][x].getAge() >= 3 && \
									game_map.nodes[y][x].getAge() <=5){
								grass_grownewgrass(&(game_map.nodes[y+1][x]));
								game_map.nodes[y+1][x].setPosition(x,y+1);
							}     
							break;
					}
				}
				break;
			case direction::DOWN:   
				if(game_map.is_at_border(x, y, d)){
					switch(two_compare_pixels(game_map.nodes[y][x],game_map.nodes[y-1][x])){
						case status::GRASS_EMPTY:       
							if(game_map.nodes[y][x].getAge() >= 3 && \
									game_map.nodes[y][x].getAge() <=5){
								grass_grownewgrass(&(game_map.nodes[y-1][x]));  
								game_map.nodes[y-1][x].setPosition(x,y-1);
							}
							break;
					}
				}
				break;
			case direction::RIGHT:  
				if(game_map.is_at_border(x, y, d)){
					switch(two_compare_pixels(game_map.nodes[y][x],game_map.nodes[y][x+1])){
						case status::GRASS_EMPTY:       
							if(game_map.nodes[y][x].getAge() >= 3 && \
									game_map.nodes[y][x].getAge() <=5){
								grass_grownewgrass(&(game_map.nodes[y][x+1]));     	
								game_map.nodes[y][x+1].setPosition(x+1,y);
							}
							break;
					}
				}
				break;
			case direction::LEFT:   
				if(game_map.is_at_border(x, y, d)){
					switch(two_compare_pixels(game_map.nodes[y][x],game_map.nodes[y][x-1])){
						case status::GRASS_EMPTY:       
							if(game_map.nodes[y][x].getAge() >= 3 && \
									game_map.nodes[y][x].getAge() <=5){
								grass_grownewgrass(&(game_map.nodes[y][x-1]));     	
								game_map.nodes[y][x-1].setPosition(x-1,y);
							}
							break;
					}
				}
				break;
		}
	}
	else{
		if(game_map.nodes[y][x].getAge()> 7){
		       	game_map.nodes[y][x].setFeature(feature::EMPTY);
			game_map.nodes[y][x].setAge(1);
		}
		else game_map.nodes[y][x].setClr(false);
	}
}
void game::StartGame(){
	srand( time( NULL) + 2000);
	bool isEmpty[35*20];
	for(int i=0;i<35*20;i++)isEmpty[i]=true;
	int pos;
	pos= rand() %(35*20);
	for(int i=0; i<5;){
		if(isEmpty[pos]){
			game_map.nodes[pos/35][pos%35].setFeature(feature::GOAT);
			game_map.nodes[pos/35][pos%35].setPosition(pos%35,pos/35);
			isEmpty[pos]=false;
			i++;
		}
		else pos = rand()%(35*20); 
	}
	pos= rand() %(35*20);
	for(int i=0; i<10;){
		if(isEmpty[pos]){
			game_map.nodes[pos/35][pos%35].setFeature(feature::GRASS);
			game_map.nodes[pos/35][pos%35].setPosition(pos%35,pos/35);
			isEmpty[pos]=false;
			i++;
		}
		else pos = rand()%(35*20); 
	}
}
void game::ShowMap(){
	std::cout<<"  ";
	for(int i=0;i<Width;i++){
		if((i+1)/10 == 0)std::cout<<i+1<<" ";
		else std::cout<<i+1;
	}
	std::cout<<std::endl;
	for(int y=0;y<Height;y++){
		if((y+1)/10 == 0)std::cout<<y+1<<" ";
		else std::cout<<y+1;
		for(int x=0;x<Width;x++){
			if(game_map.nodes[y][x].getFeature() == feature::GOAT) std::cout<<"X ";
			if(game_map.nodes[y][x].getFeature() == feature::GRASS) std::cout<<"I ";	
			if(game_map.nodes[y][x].getFeature() == feature::EMPTY) std::cout<<"  ";
		}
		std::cout<<std::endl;
	}
	std::cout<<"--------------------------------------------------------------"<<std::endl;
}
void game::RunGameOne(){
	srand( time( NULL)+ 2000);
	for(int y=0;y<Height;y++){
		for(int x=0;x<Width;x++){
			if(game_map.nodes[y][x].getFeature() == feature::GOAT){ 
				switch(rand()%4+1){
					case 1:
						goat_action(y,x,direction::UP);
						break;
					case 2:
						goat_action(y,x,direction::DOWN);
						break;
					case 3:
						goat_action(y,x,direction::RIGHT);
						break;
					case 4:
						goat_action(y,x,direction::LEFT);
						break;			
				}
			}
			if(game_map.nodes[y][x].getFeature() == feature::GRASS){
				switch(rand()%4+1){
					case 1:
						grass_action(y,x,direction::UP);
						break;
					case 2:
						grass_action(y,x,direction::DOWN);
						break;
					case 3:
						grass_action(y,x,direction::RIGHT);
						break;
					case 4:
						grass_action(y,x,direction::LEFT);
						break;			
				}

			}
			game_map.nodes[y][x].setAge(game_map.nodes[y][x].getAge()+1);
		}
	}
	for(int y=0;y<Height;y++){
		for(int x=0;x<Width;x++){
			if(game_map.nodes[y][x].getFeature() == feature::GOAT) 
				std::cout<<game_map.nodes[y][x].getLife()<<std::endl;
		}
	}
}
