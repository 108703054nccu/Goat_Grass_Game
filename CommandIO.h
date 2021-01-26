#ifndef COMMANDIO_H
#define COMMANDIO_H
#include <iostream>
#include "ColorGenerator.h"
class commandIO{
	public:
		commandIO();
		~commandIO();
		void ShowCommandList();
		void setCommand();
		int getCommand();
	private:
		int command;
};

#endif //COMMANDIO_H
