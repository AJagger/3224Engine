#pragma once
#include "../../Core/GameScene.h"
#include "../../Core/GameState.h"

class DemoGameRules
{
public:
	DemoGameRules();
	~DemoGameRules();

	static void EnactGameRules(GameScene *gameScene, GameState *gameState);

private:
	static bool CheckVictoryConditions(GameScene *gameScene, GameState *gameState);
};
