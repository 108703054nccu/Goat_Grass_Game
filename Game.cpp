#include "Game.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
status game::two_compare_pixel(map_node &n1,map_node &n2){
	if(n1.getPixel()==feature::EMPTY&&n2.getPixel()==feature::EMPTY)return status::NULL_NULL;
	if(n1.getPixel()==feature::GOAT&&n2.getPixel()==feature::EMPTY)return status::GOAT_NULL;
	if(n1.getPixel()==feature::GRASS&&n2.getPixel()==feature::EMPTY)return status::GRASS_NULL;
	if(n1.getPixel()==feature::GOAT&&n2.getPixel()==feature::GOAT)return status::GOAT_GOAT;
	if(n1.getPixel()==feature::GOAT&&n2.getPixel()==feature::GRASS)return status::GOAT_GRASS;
	if(n1.getPixel()==feature::GRASS&&n2.getPixel()==feature::GRASS)return status::GRASS_GRASS;
}
/*
void game::goat_move(int x,int y,int randomnum){
	switch(randomnum%4+1){
		case 1:
			if(!game_map.is_at_border(x,y,direction::UP)){
				game_map.all_node[y+1][x].setPixel(game_map.all_node[y][x].getGoatPixel(),game_map.all_node[y][x].getGrassPixel());
				game_map.all_node[y][x].clearPixel();	
			}
			break;
		case 2:
			if(!game_map.is_at_border(x,y,direction::DOWN)){
				game_map.all_node[y-1][x].setPixel(game_map.all_node[y][x].getGoatPixel(),game_map.all_node[y][x].getGrassPixel());
				game_map.all_node[y][x].clearPixel();	
			}
			break;
		case 3:
			if(!game_map.is_at_border(x,y,direction::RIGHT)){
				game_map.all_node[y][x+1].setPixel(game_map.all_node[y][x].getGoatPixel(),game_map.all_node[y][x].getGrassPixel());
				game_map.all_node[y][x].clearPixel();
			}
			break;
		case 4:
			if(!game_map.is_at_border(x,y,direction::LEFT)){
				game_map.all_node[y][x-1].setPixel(game_map.all_node[y][x].getGoatPixel(),game_map.all_node[y][x].getGrassPixel());
				game_map.all_node[y][x].clearPixel();
			}
			break;
	}
}
*/
void game::goat_move(map_node n1,map_node n2){
	n2.setPixel(n1.getGoatPixel(),NULL);
	n1.clearPixel();
}

void game::goat_eatgrass(map_node n1,map_node n2){
	n2.deletePixel();
	goat_move(n1,n2);
	n2.addGoatLife();
}

void game::goat_makenewgoat(map_node n1){
	if(n1.getPixel() == feature::EMPTY){
		goat *littlegoat=new goat("goat");
		n1.setPixel(littlegoat,NULL);
	}
	//n1.goat need new life
}

void game::grass_grow(map_node n1){
	if(n1.getPixel() == feature::EMPTY){
		grass *newgrass = new grass();
		n1.setPixel(NULL,newgrass);
	}
	//n1.grass need new life
}

void game::showMap(){
	for(int y=0;y<Height;y++){
		for(int x=0;x<Width;x++){
			switch(game_map.all_node[y][x].getPixel()){
				case feature::GOAT:
					cout<<"";
					break;
				case feature::GRASS:
					cout<<"";
					break;
				case feature::EMPTY:
					cout<<" ";
					break;
			}
		}
		cout<<endl;
	}
}

void game::runGame(){
	srand (time(NULL));
	int new_step;
	for(int y=0;y<Height;y++){
		for(int x=0;x<Width;x++){
			//generate a random number between zero to three
			switch(game_map.all_node[y][x].getPixel()){
				case feature::GOAT:
					if(game_map.all_node[y][x].getGoatLife() <= 0){
					       	game_map.all_node[y][x].deletePixel();
						break;
					} 
					new_step = rand() % 4 + 1;
					//goat eat grass
					//goat move
					//goat make little goat
					game_map.all_node[y][x].addGoatLife();
					break;
				case feature::GRASS:
					//grass grow
					break;
			}     
		}
		//all thing age++
	}
}

void game::startGame(){
	//make five goat
	goat* init_goats;
	init_goats = new goat[5];
	//make five grass
	grass* init_grass;
	init_grass = new grass[5];
	//make ten random posistions
	//set posistions of grass and goats
}



