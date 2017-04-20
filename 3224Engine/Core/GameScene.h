#pragma once
#include "GameObject.h"
#include "../Frameworks/DataArray.h"
#include "../Game/DemoCode/DemoGameObject.h"

class GameScene
{
public:
	GameScene();
	~GameScene();

	//DataArray<GameObject> environment = DataArray<GameObject>(); //Custom GameObject implementation required
	//DataArray<GameObject> entities = DataArray<GameObject>(); //Custom GameObject implementation required
	//DataArray<GameObject> particles = DataArray<GameObject>(); //Custom GameObject implementation required

	DataArray<DemoGameObject> gameObjects = DataArray<DemoGameObject>();

	void LoadLevel();

};
