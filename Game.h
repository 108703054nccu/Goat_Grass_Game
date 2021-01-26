#ifndef GAME_H
#define GAME_H
#include "GameKernal.h"
#include "CommandIO.h"
#include <mutex>
#include <thread>
#include <condition_variable>
#include <chrono>
class game{
	public:
		game();
		~game();
		void StartGame();
		void GameExe();
		void GameMainExe();
		void CommandExe();
		void QuitGame();
	private:
		std::mutex GameExetx;
		std::mutex CommandExetx;
		std::mutex MainExetx;
		std::condition_variable GameExecv;
		std::condition_variable CommandExecv;
		std::condition_variable MainExecv;
		int command;
		bool isgamestart;
		gamekernal GameKernal;
		commandIO CommandKernal;
};
#endif //GAME_H
