/* CSC3224 Code
* Author: Aidan Jagger | 130281034
* Class Description:
* Game loop combines all the elements and systems that make up the game engine and loops until victory is achieved or the game is quit.
* Has a default tick rate of 60 ticks per second.
*/

#include "stdafx.h"
#include "GameLoop.h"
#include "../Game/DemoCode/DemoKeyInterpreter.h"
#include "../Frameworks/Draw.h"
#include <ctime>
#include "../Frameworks/Sound.h"
#include "../Game/DemoCode/DemoGameRules.h"

GameLoop::GameLoop(GameState *gameState, GameScene *gameScene)
{
	state = gameState;
	scene = gameScene;

	lastTick = 0;
	tickLength = 16; //Set each tick to 16ms default (= 60 ticks per second)
}

GameLoop::~GameLoop()
{
	input.clear();
	delete state;
	delete scene;
}

void GameLoop::RunLoop()
{
	//Set up the Key Interpreter to process user input and the Draw class to interface between the renderer and other parts of the engine
	DemoKeyInterpreter keyInterp = DemoKeyInterpreter();
	Draw renderer = Draw();

	lastTick = clock();

	//Main loop
	while(!state->end && state->gameWindow.UpdateWindow())
	{
		//Take Keyboard input
		input = Window::GetKeyboard()->CurrentlyPressed();

		//If the game is not paused and we're ready for a new tick...
		if (!state->paused && (clock() - lastTick) >= tickLength)
		{
			lastTick = clock();

			//Process Inputs
			keyInterp.ProcessKeyPresses(input, *state, *scene);
			//AI Processes Insert point - the game idea I have has very rudimentary AI processes which can be created when creating the actual game
			//Process GameRules
			DemoGameRules::EnactGameRules(scene, state);
			//UpdatePositions (collision detection & resolution happens here)
			PhysicsResolver::SimulateActions(scene->world, &scene->gameObjects);
			//RenderScene
			renderer.RenderObjects(scene, state);
			//Process Audio
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

//Allows for the tick rate to be changed
void GameLoop::SetTickLength(int tickLength)
{
	this->tickLength = tickLength;
}


//Temporary position updater to allow the game loop to function with no physics engine for testing/debugging
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
