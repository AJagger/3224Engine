#pragma once
#include "DataArray.h"
#include "gl/glew.h"
#include <vector>
#include "../Renderer/nclgl/Mesh.h"

class ResourceLoader
{
public:
	ResourceLoader();
	~ResourceLoader();
	
	static bool LoadTextures(DataArray<GLuint> *textures, const string & texDirPath);
	static bool LoadMeshes(DataArray<Mesh*> *meshes, const string & meshDirPath);

private:
	static const int BUFFER_SIZE = 200;

	//struct IdMesh
	//{
	//	int id;
	//	Mesh* meshPtr;
	//};
};

