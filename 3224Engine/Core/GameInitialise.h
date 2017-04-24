#pragma once
#include "GameLoop.h"

static class GameInitialise
{
public:
	GameInitialise();
	~GameInitialise();

	static GameLoop* InitialiseGame();
	static bool InitSoundEngine();
};

/*Create GameState
 *Create GameScene
 *Populate GameScene with appropriate level data
 *Create GameLoop
 *
 *
 *
 */