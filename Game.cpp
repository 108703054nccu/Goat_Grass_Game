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

void game::goat_action(map_node n1,direction d){
	srand ( time ( NULL) );
	goat* goat_store = n1.getGoatPixel();
	int *pos_store = goat_store->getPosition();
	int x = pos_store[0];
	int y = pos_store[1];
	switch(d){
		case direction::UP:
			if(!game_map.is_at_border(pos_store[0],pos_store[1],d)){
				if(two_compare_pixel(game_map.all_node[y][x],game_map.all_node[y+1][x]) == status::GOAT_NULL){
					if(game_map.all_node[y][x].getYear()>=50 && game_map.all_node[y][x].getYear()<=55 )
						goat_makenewgoat(game_map.all_node[y+1][x]);
					else
						goat_move(game_map.all_node[y][x],game_map.all_node[y+1][x]);//move or grow new Goat
				}
				if(two_compare_pixel(game_map.all_node[y][x],game_map.all_node[y+1][x]) == status::GOAT_GRASS){
					if(game_map.all_node[y][x].getYear()>=50 && game_map.all_node[y][x].getYear()<=55 ){
						goat_eatgrass(game_map.all_node[y][x],game_map.all_node[y+1][x]);
						goat_move(game_map.all_node[y+1][x],game_map.all_node[y][x]);
						goat_makenewgoat(game_map.all_node[y+1][x]);
					}
					else
						goat_eatgrass(game_map.all_node[y][x],game_map.all_node[y+1][x]);//eatGrass
				}
			}
			break;
		case direction::DOWN:
			if(!game_map.is_at_border(pos_store[0],pos_store[1],d)){
				if(two_compare_pixel(game_map.all_node[y][x],game_map.all_node[y-1][x]) == status::GOAT_NULL){
					if(game_map.all_node[y][x].getYear()>=50 && game_map.all_node[y][x].getYear()<= 55)
						goat_makenewgoat(game_map.all_node[y-1][x]);
					else
						goat_move(game_map.all_node[y][x],game_map.all_node[y-1][x]);//move or grow new Goat
				}
				if(two_compare_pixel(game_map.all_node[y][x],game_map.all_node[y-1][x]) == status::GOAT_GRASS){
					if(game_map.all_node[y][x].getYear()>=50 && game_map.all_node[y][x].getYear()<=55){
						goat_eatgrass(game_map.all_node[y][x],game_map.all_node[y-1][x]);
						goat_move(game_map.all_node[y-1][x],game_map.all_node[y][x]);
						goat_makenewgoat(game_map.all_node[y-1][x]);
					}
					else
						goat_eatgrass(game_map.all_node[y][x],game_map.all_node[y-1][x]);//eatGrass
				}
			}
			break;
		case direction::RIGHT:
			if(!game_map.is_at_border(pos_store[0],pos_store[1],d)){
				if(two_compare_pixel(game_map.all_node[y][x],game_map.all_node[y][x+1]) == status::GOAT_NULL){
					goat_move(game_map.all_node[y][x],game_map.all_node[y][x+1]);//move or grow new Goat
				}
				if(two_compare_pixel(game_map.all_node[y][x],game_map.all_node[y][x+1]) == status::GOAT_GRASS){
					goat_eatgrass(game_map.all_node[y][x],game_map.all_node[y][x+1]);//eatGrass
				}
			}
			break;
		case direction::LEFT:
			if(!game_map.is_at_border(pos_store[0],pos_store[1],d)){
				if(two_compare_pixel(game_map.all_node[y][x],game_map.all_node[y][x-1]) == status::GOAT_NULL){
					goat_move(game_map.all_node[y][x],game_map.all_node[y][x-1]);//move or grow new Goat
				}
				if(two_compare_pixel(game_map.all_node[y][x],game_map.all_node[y][x-1]) == status::GOAT_GRASS){
					goat_eatgrass(game_map.all_node[y][x],game_map.all_node[y][x-1]);//eatGrass
				}
			}
			break;
	}
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
					cout<<"X";
					break;
				case feature::GRASS:
					cout<<"I";
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
					switch(new_step){
						case 1:
							goat_action(game_map.all_node[y][x],direction::UP);
							break;
						case 2:
							goat_action(game_map.all_node[y][x],direction::DOWN);
							break;
						case 3:
							goat_action(game_map.all_node[y][x],direction::RIGHT);
							break;
						case 4:
							goat_action(game_map.all_node[y][x],direction::LEFT);
							break;
					}
					break;
				case feature::GRASS:
					//Grass grow new grass
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

