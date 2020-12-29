#include "Map.h"
#include <iostream>
map_node::map_node(){
	goat_pixel=NULL;
	grass_pixel=NULL;
}
map_node::~map_node(){
	if(goat_pixel||grass_pixel){deletePixel();}
}
feature map_node::getPixel(){
	if(goat_pixel)return feature::GOAT;
	if(grass_pixel)return feature::GRASS;
	return feature::EMPTY;
}
void map_node::clearPixel(){
	if(goat_pixel)goat_pixel = NULL;
	if(grass_pixel)grass_pixel = NULL;
}
void map_node::setPixel(goat *g1,grass *g2){
	if(!goat_pixel&&!grass_pixel){
		if(!(g1&&g2)){
			goat_pixel=g1;
			grass_pixel=g2;
		}
	}
}
goat*	map_node::getGoatPixel(){return goat_pixel;}
grass* map_node::getGrassPixel(){return grass_pixel;}
map_node map_node::operator = (map_node mnode){
	goat_pixel = mnode.getGoatPixel();
	grass_pixel = mnode.getGrassPixel();
	mnode.clearPixel();
}
bool map::is_at_border(int& x,int& y,direction d){
	switch(d){
		case direction::UP:
			if(y+1 >= Height) return true;
			else return false;
		case direction::DOWN:
			if(y-1 <= 0) return true;
			else return false;
		case direction::RIGHT:
			if(x+1 >= Width) return true;
			else return false;
		case direction::LEFT:
			if(x-1 <= 0) return true;
			else return false;
	}
}
void map_node::deletePixel(){
	delete goat_pixel;
	delete grass_pixel;
}
int map_node::getGoatLife(){
	try{
		if(!goat_pixel)throw "No Goat here";
		if(goat_pixel->getLife()>0)return goat_pixel->getLife();
		else throw 0;
	}
	catch(const char* err){
		std::cout<<err<<std::endl;
	}
	catch(int nonint){
		deletePixel();
	}
}
void map_node::addGoatLife(){
	if(!goat_pixel)goat_pixel->addLife();
}
void map_node::minusGoatLife(){
	if(!goat_pixel)goat_pixel->minusLife();
}
int map_node::getYear(){return goat_pixel->getAge();}
void map_node::addYear(){goat_pixel->addAge();}

