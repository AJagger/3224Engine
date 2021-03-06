/* CSC3224 Code
 * Author: Aidan Jagger | 130281034
 * Class Description:	
 * Basic static class to initialise the various Game objects and systems.
 */

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