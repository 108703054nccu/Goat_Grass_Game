#include "Creature.h"

creature::creature(){
        X = 0;
        Y = 0;
        Age = 1;
}

creature::~creature(){;}

void creature::setPosition(int x,int y){
        X = x;
        Y = y;
}

void creature::setAge(int a){
        Age = a;
}

int creature::getPositionX(){
        return X;
}

int creature::getPositionY(){
        return Y;
}

int creature::getAge(){
        return Age;
}

