#pragma once
#include "GameLoop.h"
#include "Dynamics/b2World.h"

static class GameInitialise
{
public:
	GameInitialise();
	~GameInitialise();

	static GameLoop* InitialiseGame();
	static bool InitSoundEngine();
	static b2World* InitPhysicsEngine();
};

/*Create GameState
 *Create GameScene
 *Populate GameScene with appropriate level data
 *Create GameLoop
 *
 *
 *
 */