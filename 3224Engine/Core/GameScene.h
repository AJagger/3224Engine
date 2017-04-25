#pragma once
#include "GameObject.h"
#include "../Frameworks/DataArray.h"
#include "../Game/DemoCode/DemoGameObject.h"
#include "../Renderer/nclgl/Mesh.h"
#include "../Physics/Box2D-master/Box2D/Box2D/Dynamics/b2World.h"
#include "Box2D.h"
#include "Box2D/Common/b2Math.h"
#include "../Frameworks/PhysicsResolver.h"

class GameScene
{
public:
	GameScene(DataArray<Mesh*> *gameMeshes, DataArray<GLuint> *gameTextures, DataArray<CollisionMesh> *gameCollisionMeshes, b2World *world);
	~GameScene();

	void CreateRelatedPhysicsObject(int gameObjectId);
	void DeleteRelatedPhysicsObject(int gameObjectId);

	DataArray<DemoGameObject> gameObjects = DataArray<DemoGameObject>();
	DataArray<Mesh*> *gameMeshes;
	DataArray<GLuint> *gameTextures;
	DataArray<CollisionMesh> *gameCollisionMeshes;
	b2World *world;

	void LoadLevel(const string &sceneFile);
	void LoadTestLevel();

};
