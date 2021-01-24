class animal{
    private:
    public:
	string Name;
	int Age;
	int Power;
	animal(){
	    Name = "";
	    Age = 0;
	    Power = 0;	
	}
	~animal(){;}
	void set(string n,int a,int p){
	    Name = n;
	    Age = a;
	    Power = p;
	}
	virtual void printName(){
	    cout<<"animal: "<<Name<<endl;
	}
	void printAge(){
	    cout<<"Age: "<<Age<<endl;
	} 
	virtual void printPower(){
	    cout<<"Power :"<<Power<<endl;
	}
	virtual void printAttack(){
	    cout<<" Attack: "<<10*Age+Power;
	}
	void printFinal(){
	    for(int i = 0; i<9; i++)cout<<"=";
	    cout<<endl;
	}
};
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
