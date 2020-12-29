#ifndef CREATURE_H
#define CREATURE_H


class creature{
	public:
		creature();//non positioin//
		creature(int*);//position//
		~creature();//
		void setPosition(int*);//
		int *getPosition();//
		void setAge(int &);//
		int getAge();//
		void addAge();//
	protected:
	private:
		int *position;//position
		int *age;
};

#endif //CREATURE_H
