#pragma once
#include "GameScene.h"
#include "GameState.h"

class GameLoop
{
public:
	GameLoop(GameState *gameState, GameScene *gameScene);
	~GameLoop();

	void RunLoop();

private:
	GameState *state;
	GameScene *scene;
	vector<int> input;

	unsigned int lastTick;
	int tickLength;

	void TempPositionUpdater(); //For use until implementation of physics engine


};