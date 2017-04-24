#include "stdafx.h"
#include "GameScene.h"
#include "../Frameworks/DataArray.cpp" //Temp fix to Linker Error
#include "../Renderer/SOIL/SOIL.h"

GameScene::GameScene(DataArray<Mesh*> *gameMeshes, DataArray<GLuint> *gameTextures)
{
	this->gameMeshes = gameMeshes;
	this->gameTextures = gameTextures;
}

GameScene::~GameScene()
{
	delete gameMeshes;
	delete gameTextures;
	gameMeshes = nullptr;
	gameTextures = nullptr;
}

void GameScene::LoadLevel()
{
}

void GameScene::LoadTestLevel()
{
	//DemoGameObject *obj = gameObjects.CreateNew();
	////Mesh *objMesh = Mesh::GenerateTriangle();
	//Mesh *objMesh = *gameMeshes->TryToGet(1);
	////MAKE THIS RELATIVE
	//objMesh->SetTexture(SOIL_load_OGL_texture("C:\\Users\\Aidan\\Documents\\Visual Studio 2015\\Projects\\3224Engine\\3224Engine\\Game\\DemoCode\\DemoTextures\\uc.tga", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, 0));
	//obj->ConfigureDefaultPlayer(objMesh);

	//obj = gameObjects.CreateNew();
	//objMesh = Mesh::GenerateTriangle();
	////MAKE THIS RELATIVE
	//objMesh->SetTexture(SOIL_load_OGL_texture("C:\\Users\\Aidan\\Documents\\Visual Studio 2015\\Projects\\3224Engine\\3224Engine\\Game\\DemoCode\\DemoTextures\\brick.tga", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, 0));
	//obj->ConfigureDefaultStatic(objMesh);
	//obj->position = Vector2(1,1);

	//obj = gameObjects.CreateNew();
	//objMesh = Mesh::LoadMeshFile("C:\\Users\\Aidan\\Documents\\Visual Studio 2015\\Projects\\3224Engine\\3224Engine\\Game\\DemoCode\\DemoMeshes\\square.asciimesh");
	//objMesh->SetTexture(SOIL_load_OGL_texture("C:\\Users\\Aidan\\Documents\\Visual Studio 2015\\Projects\\3224Engine\\3224Engine\\Game\\DemoCode\\DemoTextures\\uc.tga", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, 0));
	//obj->ConfigureDefaultStatic(objMesh);
	//obj->position = Vector2(3, 3);

	DemoGameObject *obj = gameObjects.CreateNew();
	int meshId = 0;
	int textureId = 1;
	obj->ConfigureDefaultPlayer(meshId, textureId);

	obj = gameObjects.CreateNew();
	meshId = 1;
	textureId = 2;
	obj->ConfigureDefaultStatic(meshId, textureId);
	obj->position = Vector2(1, 1);

	obj = gameObjects.CreateNew();
	meshId = 1;
	obj->ConfigureDefaultStatic(meshId);
	obj->position = Vector2(3, 3);
}
