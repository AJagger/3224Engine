#pragma once
#include "GameObject.h"
#include "../Frameworks/DataArray.h"
#include "../Game/DemoCode/DemoGameObject.h"
#include "../Renderer/nclgl/Mesh.h"

class GameScene
{
public:
	//GameScene(vector<Mesh> *gameMeshes, vector<GLuint> *gameTextures);
	GameScene(DataArray<Mesh*> *gameMeshes, DataArray<GLuint> *gameTextures);
	~GameScene();

	//DataArray<GameObject> environment = DataArray<GameObject>(); //Custom GameObject implementation required
	//DataArray<GameObject> entities = DataArray<GameObject>(); //Custom GameObject implementation required
	//DataArray<GameObject> particles = DataArray<GameObject>(); //Custom GameObject implementation required

	DataArray<DemoGameObject> gameObjects = DataArray<DemoGameObject>();
	DataArray<Mesh*> *gameMeshes;
	DataArray<GLuint> *gameTextures;

	void LoadLevel(const string &sceneFile);
	void LoadTestLevel();

};
