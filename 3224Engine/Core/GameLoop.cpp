#include "stdafx.h"
#include "GameLoop.h"
#include "../Game/DemoCode/DemoKeyInterpreter.h"
#include "../Frameworks/Draw.h"
#include <ctime>
#include "../Frameworks/Sound.h"
#include "../Game/DemoCode/DemoGameRules.h"

GameLoop::GameLoop(GameState * gameState, GameScene * gameScene)
{
	state = gameState;
	scene = gameScene;

	tickLength = 16; //Set each tick to 16ms default (= 60 ticks per second)
}

GameLoop::~GameLoop()
{
	delete state;
	delete scene;
	input.clear();
}

void GameLoop::RunLoop()
{
	DemoKeyInterpreter keyInterp = DemoKeyInterpreter();
	Draw renderer = Draw();

	lastTick = clock();

	while(!state->end && state->gameWindow.UpdateWindow())
	{
		//Take Keyboard input
		//input = state->gameWindow.GetKeyboard()->CurrentlyPressed();
		input = Window::GetKeyboard()->CurrentlyPressed();

		//if(Window::GetKeyboard()->KeyDown(KEYBOARD_ESCAPE))
		//{
		//	state->end = true;
		//}

		if (!state->paused && (clock() - lastTick) >= tickLength)
		{
			lastTick = clock();

			//Process Inputs
			keyInterp.ProcessKeyPresses(input, *state, *scene);
			//AI Processes Insert point
			//Process GameRules
			DemoGameRules::EnactGameRules(scene, state);
			//UpdatePositions (collision detection & resolution happens here)
			TempPositionUpdater();
			//RenderScene
			renderer.RenderObjects(scene, state);
			Sound::ProcessAudio();
		}
		else
		{
			//Still need to process limited key presses for program functionality such as unpausing
			keyInterp.ProcessLimitedKeys(input, *state);
		}

		//Clear input keys
		input.clear();
	}
}

void GameLoop::SetTickLength(int tickLength)
{
	this->tickLength = tickLength;
}

void GameLoop::TempPositionUpdater()
{
	DemoGameObject *returnedEntity = scene->gameObjects.TryToGetFirst();
	if (returnedEntity != nullptr)
	{
		if (!returnedEntity->staticObject)
		{
			returnedEntity->position = returnedEntity->position + Vector3(returnedEntity->movementVector.x, returnedEntity->movementVector.y, 0);
			returnedEntity->movementVector.ToZero();
		}

		while (scene->gameObjects.IsNext())
		{
			returnedEntity = scene->gameObjects.Next();
			if (!returnedEntity->staticObject)
			{
				returnedEntity->position = returnedEntity->position + Vector3(returnedEntity->movementVector.x, returnedEntity->movementVector.y, 0);
				returnedEntity->movementVector.ToZero();
			}
		}
	}
}
