#include "stdafx.h"
#include "Draw.h"
#include "../../Frameworks/DataArray.cpp" //Temp fix to Linker Errors

Draw::Draw()
{
}


Draw::~Draw()
{
}

void Draw::RenderObjects(DataArray<DemoGameObject>* objects, GameState *state)
{
	vector<DrawData> renderData = vector<DrawData>();

	DemoGameObject *object = objects->TryToGetFirst();
	if(object != nullptr)
	{
		state->renderer.AddToPipeline(object->mesh, Vector3(object->position.x, object->position.y, 0));

		while(objects->IsNext())
		{
			object = objects->Next();
			if (object != nullptr)
			{
				state->renderer.AddToPipeline(object->mesh, Vector3(object->position.x, object->position.y, 0));
			}
		}
	}

	state->renderer.RenderScene();

}
