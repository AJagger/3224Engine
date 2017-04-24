#include "stdafx.h"
#include "GameInitialise.h"
#include "../Frameworks/DataArray.h"
#include "../Frameworks/DataArray.cpp" //Temp fix to Visual Studio linker errors
#include "GameObject.h"
#include "GameState.h"
#include "GameScene.h"
#include "../Frameworks/Sound.h"
#include "../Frameworks/ResouceLoader.h"

GameInitialise::GameInitialise()
{
}

GameInitialise::~GameInitialise()
{
}

GameLoop* GameInitialise::InitialiseGame()
{
	//Initialise WWise Audio
	if (InitSoundEngine()) {

		//Create the Game State. This initialises the renderer and GLEW
		GameState* gameState = new GameState();

		//Initialise DataArrays of textures & Meshes contained within the game
		DataArray<Mesh*> *gameMeshes = new DataArray<Mesh*>();
		DataArray<GLuint> *gameTextures = new DataArray<GLuint>();

		if(ResourceLoader::LoadMeshes(gameMeshes, "C:\\Users\\Aidan\\Documents\\Visual Studio 2015\\Projects\\3224Engine\\3224Engine\\Game\\DemoCode\\DemoMeshes") &&
			ResourceLoader::LoadTextures(gameTextures, "C:\\Users\\Aidan\\Documents\\Visual Studio 2015\\Projects\\3224Engine\\3224Engine\\Game\\DemoCode\\DemoTextures"))
		{
			//Initialise Game Scene
			GameScene* gameScene = new GameScene(gameMeshes, gameTextures);

			//gameScene->LoadTestLevel();
			gameScene->LoadLevel("C:\\Users\\Aidan\\Documents\\Visual Studio 2015\\Projects\\3224Engine\\3224Engine\\Game\\DemoCode\\DemoLevelData\\DemoScene.csv");

			GameLoop* gameLoop = new GameLoop(gameState, gameScene);
			return gameLoop;
		}

		//If initialiser has reached this point then an error has occured. Clean up created objects and then return null
		delete gameMeshes;
		delete gameTextures;
		delete gameState;
		gameMeshes = nullptr;
		gameTextures = nullptr;
		gameState = nullptr;

		Sound::TerminateSoundEngine();
	}
}

bool GameInitialise::InitSoundEngine()
{
	return Sound::InitSoundEngine();
}


