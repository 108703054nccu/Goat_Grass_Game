#ifndef SNAKE_H
#define SNAKE_H
#include "Animal.h"
class snake:public animal{
    private:
    public:
	snake():animal(){;}
	~snake(){;}
	virtual std::string getName() override;
	virtual int getPower() override;
	virtual int getAttack() override;
};

#endif //SNAKE_H
