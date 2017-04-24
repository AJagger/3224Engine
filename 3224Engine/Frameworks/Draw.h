#pragma once
#include "DataArray.h"
#include "../Game/DemoCode/DemoGameObject.h"
#include "../Core/GameState.h"
#include "../nclglExpansion/Renderer.h"
#include <gl/glew.h>
#include "../Core/GameScene.h"

class Draw
{
public:
	Draw();
	~Draw();

	static void RenderObjects(GameScene *scene, GameState *state);
};

