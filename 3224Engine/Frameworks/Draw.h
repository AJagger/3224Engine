#pragma once
#include "DataArray.h"
#include "../Game/DemoCode/DemoGameObject.h"
#include "../Core/GameState.h"
#include "../nclglExpansion/Renderer.h"

class Draw
{
public:
	Draw();
	~Draw();

	static void RenderObjects(DataArray<DemoGameObject> *objects, GameState *state);
};

