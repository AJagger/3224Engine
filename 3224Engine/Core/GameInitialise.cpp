#include "stdafx.h"
#include "GameInitialise.h"
#include "../Frameworks/DataArray.h"
#include "../Frameworks/DataArray.cpp" //Temp fix to Visual Studio linker errors
#include "GameObject.h"
#include "GameState.h"
#include "GameScene.h"
#include "GameLoop.h"

GameInitialise::GameInitialise()
{
}

GameInitialise::~GameInitialise()
{
}

void GameInitialise::StartGame()
{
	//Will be a lot of shit here

	GameState* gameState = new GameState();
	GameScene* gameScene = new GameScene();

	gameScene->LoadTestLevel();

	GameLoop* gameLoop = new GameLoop(gameState, gameScene);

	gameLoop->RunLoop();

	delete gameLoop;
	delete gameScene;
	delete gameState;

	//=====TEST CODE BELOW=====
	//auto testImplementation = DataArray<GameObject>();

	//GameObject *working = testImplementation.CreateNew();
	//working->entityName = "ObjId1";

	//GameObject *returned = testImplementation.TryToGet(0);
}
