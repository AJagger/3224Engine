#pragma once
#include "GameLoop.h"

static class GameShutdown
{
public:
	GameShutdown();
	~GameShutdown();

	static void TerminateGame(GameLoop *gameLoop);
};