#include "Snake.h"
std::string snake::getName(){
	    return animal::getName();
	}
int snake::getPower(){
	    return animal::getPower();
}
int snake::getAttack(){
	    return (animal::getAge())*(animal::getPower());
}
