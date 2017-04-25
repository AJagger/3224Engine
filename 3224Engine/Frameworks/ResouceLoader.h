#pragma once
#include "DataArray.h"
#include "gl/glew.h"
#include <vector>
#include "../Renderer/nclgl/Mesh.h"
#include "../Game/DemoCode/DemoGameObject.h"
#include "Common/b2Math.h"
#include "PhysicsResolver.h"

class ResourceLoader
{
public:
	ResourceLoader();
	~ResourceLoader();
	
	static bool LoadTextures(DataArray<GLuint> *textures, const string & texDirPath);
	static bool LoadMeshes(DataArray<Mesh*> *meshes, const string & meshDirPath);
	static bool LoadObjectList(DataArray<DemoGameObject> *gameObjects, const string &sceneFile);
	static bool LoadCollisionMeshes(DataArray<CollisionMesh> *gameCollisionMeshes, const string &meshDirPath);
	static CollisionMesh ImportCollisionMesh(const string &collisionMeshPath);

private:
	static const int BUFFER_SIZE = 200;

	//struct IdMesh
	//{
	//	int id;
	//	Mesh* meshPtr;
	//};
};

