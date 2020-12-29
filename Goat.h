#ifndef GOAT_H
#define GOAT_H

#include "Creature.h"
#include <string>
#define AddLife 5
#define MinusLife 1:
enum class direction{
	UP,
	DOWN,
	RIGHT,
	LEFT
};
class goat:public creature{
	public:
		goat(std::string);
		~goat();
		void move(direction);//
		int getLife();//
		void addLife();
		void minusLife();
	protected:
		int *position;//position
		int *age;	
	private:
		int life;

};
#endif //GOAT_H
