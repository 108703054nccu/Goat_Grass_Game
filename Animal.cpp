#include "Animal.h"
animal::animal(){
	Name = "";
	Power = 0;	
}
animal::~animal(){;}
void animal::set(std::string n,int p){
	Name = n;
	Power = p;
}
virtual std::string animal::getName(){
	return Name;
}
virtual int animal::getPower(){
	return Power;
}
virtual int animal::getAttack(){
	return 10*Age+Power;
}

