#include "stdafx.h"
#include "GameInitialise.h"
#include "../Frameworks/DataArray.h"
#include "../Frameworks/DataArray.cpp" //Temp fix to Visual Studio linker errors
#include "GameObject.h"
#include "GameState.h"
#include "GameScene.h"
#include "GameLoop.h"
#include "../Frameworks/Sound.h"

GameInitialise::GameInitialise()
{
}

GameInitialise::~GameInitialise()
{
}

void GameInitialise::StartGame()
{
	//Initialise WWise Audio
	if (InitSoundEngine()) {

		//Initialise Game Data
		GameState* gameState = new GameState();
		GameScene* gameScene = new GameScene();

		gameScene->LoadTestLevel();

		GameLoop* gameLoop = new GameLoop(gameState, gameScene);

		gameLoop->RunLoop();

		delete gameLoop;
		delete gameScene;
		delete gameState;
		Sound::TerminateSoundEngine();
	}
}

bool GameInitialise::InitSoundEngine()
{
	return Sound::InitSoundEngine();
}


