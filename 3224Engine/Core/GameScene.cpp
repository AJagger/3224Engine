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
	//MAKE THIS RELATIVE
	objMesh->SetTexture(SOIL_load_OGL_texture("C:\\Users\\Aidan\\Documents\\Visual Studio 2015\\Projects\\3224Engine\\3224Engine\\Game\\DemoCode\\DemoTextures\\uc.tga", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, 0));
	obj->ConfigureDefaultPlayer(objMesh);

	obj = gameObjects.CreateNew();
	objMesh = Mesh::GenerateTriangle();
	//MAKE THIS RELATIVE
	objMesh->SetTexture(SOIL_load_OGL_texture("C:\\Users\\Aidan\\Documents\\Visual Studio 2015\\Projects\\3224Engine\\3224Engine\\Game\\DemoCode\\DemoTextures\\brick.tga", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, 0));
	obj->ConfigureDefaultStatic(objMesh);
	obj->position = Vector2(1,1);
}
