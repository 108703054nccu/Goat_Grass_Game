#include "Game.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <ostream>
game::game(){;}
game::~game(){;}

namespace Color {
    enum Code {
        FG_RED      = 31,
        FG_GREEN    = 32,
        FG_BLUE     = 34,
        FG_DEFAULT  = 39,
	FG_WHITE    = 97,
        BG_RED      = 41,
        BG_GREEN    = 42,
        BG_BLUE     = 44,
        BG_DEFAULT  = 49,
	BG_WHITE = 107,
	BG_LIGHT_GREEN = 102
    };
    class Modifier {
        Code code;
    public:
        Modifier(Code pCode) : code(pCode) {}
        friend std::ostream&
        operator<<(std::ostream& os, const Modifier& mod) {
            return os << "\033[" << mod.code << "m";
        }
    };
}
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
	if(target->getCLR() != true){
		d_target->setFeature(feature::GOAT);
		d_target->setAge(target->getAge());
		d_target->setLife(target->getLife());
		target->setAge(1);
		target->setLife(20);
		target->setFeature(feature::EMPTY);
		d_target->setCLR(true);
	}
	return ;
}

void game::goat_grownewgoat(map_node *target,map_node *d_target){
	if(d_target->getFeature() == feature::EMPTY){
		d_target->setFeature(feature::GOAT);
		d_target->setAge(1);
		d_target->setLife(20);
		d_target->setCLR(true);
	}
	else{
		target->setAge(target->getAge()+5);
		d_target->setFeature(feature::GOAT);
		d_target->setAge(1);
		d_target->setLife(20);
		d_target->setCLR(true);
	}
	return ;
}

void game::goat_eatgrass(map_node *target,map_node *d_target){
	if(target->getCLR() != true){
		d_target->setFeature(feature::GOAT);
		d_target->setAge(target->getAge());
		d_target->setLife(target->getLife()+5);
		target->setAge(1);
		target->setLife(20);
		target->setFeature(feature::EMPTY);
		d_target->setCLR(true);
	}
	return ;
}

void game::grass_grownewgrass(map_node *d_target){
	if(d_target->getFeature() == feature::EMPTY){
		d_target->setFeature(feature::GRASS);
		d_target->setAge(1);
		d_target->setCLR(true);
	}
	return ;
}

void game::goat_action(int height,int width,direction d){
	int x = width;
	int y = height;
	if( game_map.is_at_border(y, x, d)){
		switch(d){
			case direction::UP:
				switch(two_compare_pixels(game_map.nodes[y][x],game_map.nodes[y+1][x])){
					case status::GOAT_EMPTY:
						if(game_map.nodes[y][x].getAge() >= 50 && game_map.nodes[y][x].getAge() <= 55){
							goat_grownewgoat(&(game_map.nodes[y][x]),&(game_map.nodes[y+1][x]));
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
				break;
			case direction::DOWN:   
				switch(two_compare_pixels(game_map.nodes[y][x],game_map.nodes[y-1][x])){
					case status::GOAT_EMPTY:
						if(game_map.nodes[y][x].getAge() >= 50 && game_map.nodes[y][x].getAge() <= 55){
							goat_grownewgoat(&(game_map.nodes[y][x]),&(game_map.nodes[y-1][x]));
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
				break;
			case direction::RIGHT:  
				switch(two_compare_pixels(game_map.nodes[y][x],game_map.nodes[y][x+1])){
					case status::GOAT_EMPTY:
						if(game_map.nodes[y][x].getAge() >= 50 && game_map.nodes[y][x].getAge() <= 55){
							goat_grownewgoat(&(game_map.nodes[y][x]),&(game_map.nodes[y][x+1]));
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
				break;
			case direction::LEFT:   
				switch(two_compare_pixels(game_map.nodes[y][x],game_map.nodes[y][x-1])){
					case status::GOAT_EMPTY:
						if(game_map.nodes[y][x].getAge() >= 50 && game_map.nodes[y][x].getAge() <= 55){
							goat_grownewgoat(&(game_map.nodes[y][x]),&(game_map.nodes[y][x-1]));
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
				}
				break;
		}
	}
}

void game::grass_action(int height,int width,direction d){
	int x = width;
	int y = height;
	if(game_map.is_at_border(y, x, d)){
		switch(d){
			case direction::UP:
				switch(two_compare_pixels(game_map.nodes[y][x],game_map.nodes[y+1][x])){
					case status::GRASS_EMPTY:
						if(game_map.nodes[y][x].getAge() >= 3 && game_map.nodes[y][x].getAge() <=5){
							grass_grownewgrass(&(game_map.nodes[y+1][x]));
							game_map.nodes[y+1][x].setPosition(x,y+1);
						}     
						break;
				}
				break;
			case direction::DOWN:   
				switch(two_compare_pixels(game_map.nodes[y][x],game_map.nodes[y-1][x])){
					case status::GRASS_EMPTY:       
						if(game_map.nodes[y][x].getAge() >= 3 && game_map.nodes[y][x].getAge() <=5){
							grass_grownewgrass(&(game_map.nodes[y-1][x]));  
							game_map.nodes[y-1][x].setPosition(x,y-1);
						}
						break;
				}
				break;
			case direction::RIGHT:  
				switch(two_compare_pixels(game_map.nodes[y][x],game_map.nodes[y][x+1])){
					case status::GRASS_EMPTY:       
						if(game_map.nodes[y][x].getAge() >= 3 && game_map.nodes[y][x].getAge() <=5){
							grass_grownewgrass(&(game_map.nodes[y][x+1]));     	
							game_map.nodes[y][x+1].setPosition(x+1,y);
						}
						break;
				}
				break;
			case direction::LEFT:   
				switch(two_compare_pixels(game_map.nodes[y][x],game_map.nodes[y][x-1])){
					case status::GRASS_EMPTY:       
						if(game_map.nodes[y][x].getAge() >= 3 && game_map.nodes[y][x].getAge() <=5){
							grass_grownewgrass(&(game_map.nodes[y][x-1]));     	
							game_map.nodes[y][x-1].setPosition(x-1,y);
						}
						break;
				}
				break;
		}
	}
}

void game::StartGame(){
	int InitGoatNum,InitGrassNum ;
	Color::Modifier def(Color::FG_DEFAULT);
        Color::Modifier defBG(Color::BG_DEFAULT);
	Color::Modifier Blue(Color::FG_BLUE);
	Color::Modifier WhiteBG(Color::BG_WHITE);
	std::cout<<WhiteBG<<Blue<<"Now,Goat number:"<<def<<defBG;
	std::cin>>InitGoatNum;
	std::cout<<WhiteBG<<Blue<<"Now,Grass number:"<<def<<defBG;
	std::cin>>InitGrassNum;
	if(InitGoatNum>=100||InitGoatNum<0)InitGoatNum = 50;
	if(InitGrassNum>=100||InitGrassNum<0)InitGrassNum = 50;
	srand( time( NULL) + 2000);
	bool isEmpty[Width*Height];
	for(int i=0;i<Width*Height;i++)isEmpty[i]=true;
	int pos;
	pos= rand() %(Width*Height);
	for(int i=0; i<InitGoatNum;){
		if(isEmpty[pos]){
			game_map.nodes[pos/Width][pos%Width].setFeature(feature::GOAT);
			game_map.nodes[pos/Width][pos%Width].setPosition(pos%Width,pos/Width);
			isEmpty[pos]=false;
			i++;
		}
		else pos = rand()%(Width*Height); 
	}
	pos= rand() %(Width*Height);
	for(int i=0; i<InitGrassNum;){
		if(isEmpty[pos]){
			game_map.nodes[pos/Width][pos%Width].setFeature(feature::GRASS);
			game_map.nodes[pos/Width][pos%Width].setPosition(pos%Width,pos/Width);
			isEmpty[pos]=false;
			i++;
		}
		else pos = rand()%(Width*Height); 
	}
}
void game::ShowMap(){
	Color::Modifier def(Color::FG_DEFAULT);
	Color::Modifier defBG(Color::BG_DEFAULT);
	Color::Modifier Blue(Color::FG_BLUE);
	Color::Modifier Green(Color::FG_GREEN);
	Color::Modifier GreenBG(Color::BG_GREEN);
	Color::Modifier WhiteBG(Color::BG_WHITE);
	Color::Modifier LgreenBG(Color::BG_LIGHT_GREEN);
	for(int i =0 ;i<=Width;i++)std::cout<<"--";
	std::cout<<std::endl;
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
			if(game_map.nodes[y][x].getFeature() == feature::GOAT) 
				if(game_map.nodes[y][x].getLife()/10 == 0)
				std::cout<<WhiteBG<<Blue<<" "<<game_map.nodes[y][x].getLife()<<def<<defBG;
				else if(game_map.nodes[y][x].getLife() < 99)
				std::cout<<WhiteBG<<Blue<<game_map.nodes[y][x].getLife()<<def<<defBG;
				else	
				std::cout<<WhiteBG<<Blue<<"FF"<<def<<defBG;
			if(game_map.nodes[y][x].getFeature() == feature::GRASS) std::cout<<LgreenBG<<Green<<"||"<<def<<defBG;
			if(game_map.nodes[y][x].getFeature() == feature::EMPTY) std::cout<<GreenBG<<"  "<<defBG;
		}
		std::cout<<std::endl;
	}
	for(int i =0 ;i<=Width;i++)std::cout<<"--";
	std::cout<<std::endl;
}
void game::RunGameOne(){
	srand( time( NULL)+ 2000);

	for(int y=0;y<Height;y++){
		for(int x=0;x<Width;x++){
			game_map.nodes[y][x].setAge(game_map.nodes[y][x].getAge()+1);
			game_map.nodes[y][x].setLife(game_map.nodes[y][x].getLife()-1);

			if(game_map.nodes[y][x].getFeature()==feature::GOAT){
				if(game_map.nodes[y][x].getLife() <= 0 ||game_map.nodes[y][x].getAge() > 70){
					game_map.nodes[y][x].setAge(1);
					game_map.nodes[y][x].setLife(20);
					game_map.nodes[y][x].setFeature(feature::EMPTY);
				} 
			}
			if(game_map.nodes[y][x].getFeature()==feature::GRASS){
				if(game_map.nodes[y][x].getAge() > 7){
					game_map.nodes[y][x].setAge(1);
					game_map.nodes[y][x].setFeature(feature::EMPTY);
				}
			}
		}
	}

	for(int y=0;y<Height;y++){
		for(int x=0;x<Width;x++){
			if(game_map.nodes[y][x].getCLR()!=true){
				if(game_map.nodes[y][x].getFeature() == feature::GOAT){ 
					switch((int)rand()%4+1){
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
			}
			else game_map.nodes[y][x].setCLR(false);
		}
	}
	for(int y=0;y<Height;y++){
		for(int x=0;x<Width;x++){
			game_map.nodes[y][x].setCLR(false);
		}
	}
}
