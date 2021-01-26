#ifndef ANIMAL_H
#define ANIMAL_H
#include "Creature.h"
#include <string>
#include <iostream>
class animal:public creature{
	private:
		std::string Name;
		int Power;
	public:
		animal();
		~animal();
		void set(std::string,int);
		virtual std::string getName();
		virtual int getPower();
		virtual int getAttack();
};


#endif //ANIMAL_H
