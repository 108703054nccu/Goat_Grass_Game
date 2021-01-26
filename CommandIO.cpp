#include "CommandIO.h"

static Color::Modifier bgdef(Color::BG_DEFAULT);
static Color::Modifier def(Color::FG_DEFAULT);
static Color::Modifier blue(Color::FG_BLUE);
static Color::Modifier bgwhite(Color::BG_WHITE);

commandIO::commandIO(){
	command = 1;
}
commandIO::~commandIO(){;}
void commandIO::ShowCommandList(){
	//Show Command list
	std::cout<<std::endl<<bgwhite<<blue<< \
		"1. continue	2. Restart	3. Quit"<<def<<bgdef<<std::endl;
}
void commandIO::setCommand(){
	std::cin>>command;
	std::cout<<"value :"<<command<<std::endl;
	return ;
}
int commandIO::getCommand(){
	return command;
}

