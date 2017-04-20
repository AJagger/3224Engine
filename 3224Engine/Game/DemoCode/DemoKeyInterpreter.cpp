#include "stdafx.h"
#include "DemoKeyInterpreter.h"
#include "../../Frameworks/DataArray.cpp" //Temp fix to Linker Errors

DemoKeyInterpreter::DemoKeyInterpreter()
{
}

DemoKeyInterpreter::~DemoKeyInterpreter()
{
}

void DemoKeyInterpreter::ProcessKeyPresses(std::vector<int> keys, GameState &gameState, GameScene &gameScene)
{
	//If no key presses then do nothing
	if (!keys.empty())
	{
		//Look for controlled entities and store Ids in vector. Saves lookups when processing multiple keypresses.
		DemoGameObject *returnedEntity = gameScene.gameObjects.TryToGetFirst();
		if (returnedEntity != nullptr)	//Continue only if there is a returned item (i.e. don't try to do anything if there are no objects in the data structure)
		{
			if (returnedEntity->playerControlled)
			{
				controlledEntities.push_back(returnedEntity);
			}

			while(gameScene.gameObjects.IsNext())
			{
				returnedEntity = gameScene.gameObjects.Next();
				if(returnedEntity->playerControlled)
				{
					controlledEntities.push_back(returnedEntity);
				}
			}

			//If player controlled entities have been found, proceed to processing the keypresses
			if (controlledEntities.size() > 0)
			{
				//Loop through keypresses and determine what function to perform
				for (int i = 0; i < keys.size(); i++)
				{
					switch (keys[i])
					{
					case CONFIG_TOGGLE_PAUSE: Toggle_Pause(gameState);
					case CONFIG_PLAYER_FORWARD:;
					case CONFIG_PLAYER_BACKWARD:;
					case CONFIG_PLAYER_LEFT:;
					case CONFIG_PLAYER_RIGHT:;
					}
				}
			}

			//Clear the controlled entities vector
			controlledEntities.clear();
		}
	}

}

void DemoKeyInterpreter::Toggle_Pause(GameState & gamestate)
{
	gamestate.paused = !gamestate.paused;
}

void DemoKeyInterpreter::Player_Forward(GameScene & gamescene)
{
	for(int i = 0; i < controlledEntities.size(); i++)
	{
		if(controlledEntities[i]->entityType == PLAYER)
		{
			controlledEntities[i]->movementVector = controlledEntities[i]->movementVector + Vector2(0, 1);
		}
	}
}

void DemoKeyInterpreter::Player_Backward(GameScene & gamescene)
{
	for (int i = 0; i < controlledEntities.size(); i++)
	{
		if (controlledEntities[i]->entityType == PLAYER)
		{
			controlledEntities[i]->movementVector = controlledEntities[i]->movementVector + Vector2(0, -1);
		}
	}
}

void DemoKeyInterpreter::Player_Left(GameScene & gamescene)
{
	for (int i = 0; i < controlledEntities.size(); i++)
	{
		if (controlledEntities[i]->entityType == PLAYER)
		{
			controlledEntities[i]->movementVector = controlledEntities[i]->movementVector + Vector2(-1, 0);
		}
	}
}

void DemoKeyInterpreter::Player_Right(GameScene & gamescene)
{
	for (int i = 0; i < controlledEntities.size(); i++)
	{
		if (controlledEntities[i]->entityType == PLAYER)
		{
			controlledEntities[i]->movementVector = controlledEntities[i]->movementVector + Vector2(1, 0);
		}
	}
}
