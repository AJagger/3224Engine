#include "stdafx.h"
#include "Draw.h"
#include "../../Frameworks/DataArray.cpp" //Temp fix to Linker Errors

Draw::Draw()
{
}


Draw::~Draw()
{
}

void Draw::RenderObjects(GameScene *scene, GameState *state)
{
	vector<DrawData> renderData = vector<DrawData>();
	DataArray<DemoGameObject> *objects = &scene->gameObjects;

	DemoGameObject *object = objects->TryToGetFirst();
	if(object != nullptr)
	{
		state->renderer.AddToPipeline(*scene->gameMeshes->TryToGet(object->meshId), *scene->gameTextures->TryToGet(object->textureId), object->position, object->rotation);

		while(objects->IsNext())
		{
			object = objects->Next();
			if (object != nullptr)
			{
				state->renderer.AddToPipeline(*scene->gameMeshes->TryToGet(object->meshId), *scene->gameTextures->TryToGet(object->textureId), object->position, object->rotation);
			}
		}
	}

	state->renderer.RenderScene();

}
