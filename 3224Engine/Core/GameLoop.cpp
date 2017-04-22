#include "stdafx.h"
#include "GameLoop.h"
#include "../Game/DemoCode/DemoKeyInterpreter.h"
#include "../Frameworks/Draw.h"
#include <chrono>
#include <thread>

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
	DemoKeyInterpreter keyInterp = DemoKeyInterpreter();
	Draw renderer = Draw();

	while(!state->end && state->gameWindow.UpdateWindow())
	{
		//std::this_thread::sleep_for(std::chrono::milliseconds(5000));
		//Take Keyboard input
		//input = state->gameWindow.GetKeyboard()->CurrentlyPressed();
		input = Window::GetKeyboard()->CurrentlyPressed();

		//if(Window::GetKeyboard()->KeyDown(KEYBOARD_ESCAPE))
		//{
		//	state->end = true;
		//}

		if (!state->paused)
		{
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
