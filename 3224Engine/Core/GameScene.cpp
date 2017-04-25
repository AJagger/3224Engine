#include "stdafx.h"
#include "GameScene.h"
#include "../Frameworks/DataArray.cpp" //Temp fix to Linker Error
#include "../Renderer/SOIL/SOIL.h"
#include "../Frameworks/ResouceLoader.h"
#include "Common/b2Math.h"

GameScene::GameScene(DataArray<Mesh*> *gameMeshes, DataArray<GLuint> *gameTextures, DataArray<CollisionMesh> *gameCollisionMeshes, b2World *world)
{
	this->gameMeshes = gameMeshes;
	this->gameTextures = gameTextures;
	this->gameCollisionMeshes = gameCollisionMeshes;
	this->world = world;
}

GameScene::~GameScene()
{
	delete gameMeshes;
	delete gameTextures;
	delete gameCollisionMeshes;
	delete world;
	gameMeshes = nullptr;
	gameTextures = nullptr;
	gameCollisionMeshes = nullptr;
	world = nullptr;
}

//Manage the linking of objects in game space and physics space
void GameScene::CreateRelatedPhysicsObject(int gameObjectId)
{
	DemoGameObject *gameObject = gameObjects.TryToGet(gameObjectId);
	CollisionMesh *collisionMesh = gameCollisionMeshes->TryToGet(gameObject->physMeshId);

	//Only attempt to create a physics object if both the gameObject and collisionMesh are found
	if (gameObject && collisionMesh && gameObject->collisionsEnabled) {
		gameObject->physicsObject = PhysicsResolver::CreatePhysicsObjectFromGameObject(world, gameObject, collisionMesh);
	}
	else
	{
		gameObject->physicsObject = nullptr;
	}
}

//Manage the linking of objects in game space and physics space
void GameScene::DeleteRelatedPhysicsObject(int gameObjectId)
{
	DemoGameObject *gameObject = gameObjects.TryToGet(gameObjectId);

	//Check that a gameObject has been found and that that gameObject has linked physics engine data.
	if (gameObject && gameObject->physicsObject) {
		PhysicsResolver::RemovePhysicsObjectFromWorld(world, gameObject);
	}
}

void GameScene::LoadLevel(const string &sceneFile)
{
	ResourceLoader::LoadObjectList(&gameObjects, sceneFile);

	//Iterate through the game objects that have been added and add them into the physics simulation if required.
	DemoGameObject *returnedEntity = gameObjects.TryToGetFirst();
	if (returnedEntity != nullptr)	//Continue only if there is a returned item (i.e. don't try to do anything if there are no objects in the data structure)
	{
		if (returnedEntity->collisionsEnabled)
		{
			CreateRelatedPhysicsObject(gameObjects.GetId(*returnedEntity));
		}

		while (gameObjects.IsNext())
		{
			returnedEntity = gameObjects.Next();
			if (returnedEntity->collisionsEnabled)
			{
				CreateRelatedPhysicsObject(gameObjects.GetId(*returnedEntity));
			}
		}
	}
}


//Very basic test scene used in early development
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
	obj->position = Vector3(1, 1, 0);

	obj = gameObjects.CreateNew();
	meshId = 1;
	obj->ConfigureDefaultStatic(meshId);
	obj->position = Vector3(3, 3, 0);
}
