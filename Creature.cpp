#include "Creature.h"

using namespace std;
creature::creature(){
	position=new int[2];
	age=new int;
	position[0]=0;//x_position
	position[1]=0;//y_position
	*age=1;
}
creature::creature(int pos[2]){
	position=new int[2];
	age=new int;
	position[0]=pos[0];
	position[1]=pos[1];
	*age=1;
}
creature::~creature(){
	delete[] position;
	delete age;
}
void creature::setPosition(int pos[2]){
	position[0]=pos[0];
	position[1]=pos[1];
}
int* creature::getPosition(){
	return position;
}
int creature::getAge(){return *age;}
void creature::setAge(int &a){*age=a;}
void creature::addAge(){(*age)++;}
