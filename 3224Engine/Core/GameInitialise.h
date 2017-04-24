#pragma once

static class GameInitialise
{
public:
	GameInitialise();
	~GameInitialise();

	static void StartGame();
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