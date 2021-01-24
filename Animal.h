#ifndef ANIMAL_H
#define ANIMAL_H
#include "Creature.h"
#include <string>
#include <iostream>
class animal:public creatrue{
	private:
		string Name;
		int Power;
	public:
		animal();
		~animal();
		void set(std::string,int);
		virtual std::string animal::getName();
		virtual int getPower();
		virtual int getAttack();
};


#endif //ANIMAL_H
