#pragma once
#include "GameScene.h"
#include "GameState.h"

class GameLoop
{
public:
	GameLoop(GameState *gameState, GameScene *gameScene);
	~GameLoop();

	void RunLoop();
	void TogglePause();

private:
	GameState *state;
	GameScene *scene;


};