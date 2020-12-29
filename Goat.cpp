#include "Goat.h"


//goat::goat(string::name):creature(name);
//goat::~goat();
void goat::move(direction dcase){
	switch(dcase){
		case direction::UP:
			position[0] += 1;
			break;
		case direction::DOWN:
			position[0] -= 1;
			break;
		case direction::RIGHT:
			position[1] += 1;
			break;
		case direction::LEFT:
			position[1] -= 1;
			break;
	}
}
int goat::getLife(){return life;}
void goat::addLife(){life+=5;}
void goat::minusLife(){life-=5;}



