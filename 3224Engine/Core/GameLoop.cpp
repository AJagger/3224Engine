#include "stdafx.h"
#include "GameLoop.h"

GameLoop::GameLoop(GameState * gameState, GameScene * gameScene)
{
	state = gameState;
	scene = gameScene;
}

GameLoop::~GameLoop()
{
	delete state;
	delete scene;
}

void GameLoop::RunLoop()
{
	while(!state->end && state->gameWindow.UpdateWindow())
	{
		//Take Keyboard input


		if (!state->paused)
		{
			//Process Inputs (with Physics)
			//AI Processes (with Physics)
			//RenderScene
		}
	}
}

void GameLoop::TogglePause()
{
	state->paused = !state->paused;
}
