#ifndef LION_H
#define LION_H
#include "Animal.h"
class lion:public animal{
    private:
    public:
	lion();
	virtual ~lion();
	virtual std::string getName() override;      
	virtual int getPower() override;
	virtual int getAttack() override;
};

#endif //LION_H
