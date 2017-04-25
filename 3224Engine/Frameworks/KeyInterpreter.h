/* Abstract class which processes captured user input.
 * Classes created with this are game specific.
 */

#pragma once
#include "../nclgl/Keyboard.h"
#include "../../Core/GameState.h"
#include "../../Core/GameScene.h"
#include "../../Frameworks/DataArray.h"

#include "vector"

class KeyInterpreter
{
public:
	KeyInterpreter();
	virtual ~KeyInterpreter();

	virtual void ProcessKeyPresses(std::vector<int> keys, GameState &gameState, GameScene &gameScene) = 0;
	virtual void ProcessLimitedKeys(std::vector<int> keys, GameState &gameState) = 0;
};

