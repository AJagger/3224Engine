#pragma once
#include "GameObject.h"
#include "../Frameworks/DataArray.h"

class GameScene
{
public:
	GameScene();
	~GameScene();

	DataArray<GameObject> environment = DataArray<GameObject>(); //Custom GameObject implementation required
	DataArray<GameObject> entities = DataArray<GameObject>(); //Custom GameObject implementation required
	DataArray<GameObject> particles = DataArray<GameObject>(); //Custom GameObject implementation required

	void LoadLevel();

};
