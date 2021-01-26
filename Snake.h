class snake:public animal{
    private:
    public:
	snake():animal(){;}
	~snake(){;}
	virtual void printnName(){
	    cout<<"Snake: "<<Name<<endl;
	}
	virtual void printPower(){
	    cout<<"Poison: "<<Power<<endl;
	}
	virtual void printAttack(){
	    cout<<"Attack: "<<Age*Power<<endl;
	}
	void printAll(){
	    printName();                                                
	    printAge();              
	    printPower();                                                                   
	    printAttack();
	}

};
