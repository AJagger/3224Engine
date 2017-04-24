#include "stdafx.h"
#include "GameShutdown.h"
#include "../Frameworks/Sound.h"

GameShutdown::GameShutdown()
{
}

GameShutdown::~GameShutdown()
{
}

void GameShutdown::TerminateGame(GameLoop* gameLoop)
{
	//Deleting the gameLoop calls the destructor 
	//Which deletes the gameState and gameScene
	//Deleting the gameScene will delete the game asset arrays: gameTextures and gameMeshes
	delete gameLoop;
	Sound::TerminateSoundEngine();
}

