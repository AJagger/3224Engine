#include "stdafx.h"
#include "GameLoop.h"
#include "../Game/DemoCode/DemoKeyInterpreter.h"
#include "../Frameworks/Draw.h"
#include <ctime>
#include "../Frameworks/Sound.h"

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
			//AI Processes
			//UpdatePositions (with physics)
			TempPositionUpdater();
			//RenderScene
			renderer.RenderObjects(&scene->gameObjects, state);
			Sound::ProcessAudio();
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
		if(!returnedEntity->staticObject)
		{
			returnedEntity->position = returnedEntity->position + returnedEntity->movementVector;
			returnedEntity->movementVector.ToZero();

			while (scene->gameObjects.IsNext())
			{
				returnedEntity = scene->gameObjects.Next();
				if (!returnedEntity->staticObject)
				{
					returnedEntity->position = returnedEntity->position + returnedEntity->movementVector;
					returnedEntity->movementVector.ToZero();
				}
			}
		}
	}
}
