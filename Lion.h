#ifndef LION_H
#define LION_H
#include "Animal.h"
class lion:public animal{
    private:
    public:
	lion():animal(){;}
	~lion(){;}
	virtual void printName(){      
	    cout<<"Lion: "<<Name<<endl;      
	} 
	virtual void printPower(){
	    cout<<"Energy: "<<Power<<endl;
	}
	virtual void printAttack(){cout<<"Attack: "<<10*Age+Power<<endl;
	}	
	void printAll(){printName();printAge();printPower();printAttack();}		
};

#endif //LION_H
