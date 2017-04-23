#include "stdafx.h"
#include "GameLoop.h"
#include "../Game/DemoCode/DemoKeyInterpreter.h"
#include "../Frameworks/Draw.h"
#include <ctime>

GameLoop::GameLoop(GameState * gameState, GameScene * gameScene)
{
	state = gameState;
	scene = gameScene;

	tickLength = 16; //Set each tick to 16ms (= 60 ticks per second). Can't change for now
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
		}

		//Clear input keys ready for next loop //NECESSARY? IDK !_!_!_!_!_!_!
		input.clear();
	}
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
