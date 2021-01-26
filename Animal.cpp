#include "Animal.h"
animal::animal():creature(){
	Name = "";
	Power = 0;	
}
animal::~animal(){;}
void animal::set(std::string n,int p){
	Name = n;
	Power = p;
}
std::string animal::getName(){
	return Name;
}
int animal::getPower(){
	return Power;
}
int animal::getAttack(){
	return 10*getAge()+Power;
}

