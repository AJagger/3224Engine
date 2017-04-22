#include "stdafx.h"
#include "GameScene.h"
#include "../Frameworks/DataArray.cpp" //Temp fix to Linker Error

GameScene::GameScene()
{
}

GameScene::~GameScene()
{
}

void GameScene::LoadLevel()
{
}

void GameScene::LoadTestLevel()
{
	DemoGameObject *obj = gameObjects.CreateNew();
	Mesh *objMesh = Mesh::GenerateTriangle();
	obj->ConfigureDefaultPlayer(objMesh);

	obj = gameObjects.CreateNew();
	objMesh = Mesh::GenerateTriangle();
	obj->ConfigureDefaultStatic(objMesh);
}
