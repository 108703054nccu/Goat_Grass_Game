#include "Lion.h"
lion::lion():animal(){;}
lion::~lion(){;}

std::string lion::getName(){      
	    return animal::getName();      
} 
int lion::getPower(){
	    return animal::getPower();
}
int lion::getAttack(){
	return 10*animal::getAge()+animal::getPower();
}	
