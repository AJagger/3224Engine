#include "stdafx.h"
#include "../../Frameworks/DataArray.cpp" //Temp fix to Linker Errors
#include "ResouceLoader.h"
#include "../Renderer/SOIL/SOIL.h"
#include <sstream>

ResourceLoader::ResourceLoader()
{
}

ResourceLoader::~ResourceLoader()
{
}

bool ResourceLoader::LoadTextures(DataArray<GLuint> *textures, const string & texDirPath)
{
	char buffer[BUFFER_SIZE];
	int prevId = -1;

	ifstream f(texDirPath + "\\IncludeTextures.txt");

	if (!f) {
		return false;
	}

	stringstream ss;

	while (f.getline(buffer, BUFFER_SIZE))
	{
		ss << buffer;

		int fileId = -1;
		string texFile;

		for (int i = 0; i < 2; i++)
		{
			ss.getline(buffer, BUFFER_SIZE, ',');
			if (i == 0)
			{
				fileId = atoi(buffer);
			}
			else
			{
				texFile = buffer;
			}
		}

		//The data file being read must have a complete ordered list of game assets. If this is not the case then stop
		if (fileId != prevId + 1)
		{
			return false;
		}

		prevId = fileId;

		//Import texture and add the corresponding GLuint to the textures DataArray
		string pathString = texDirPath + "\\" + texFile;
		GLuint *tempGLuint = textures->CreateNew();
		*tempGLuint = SOIL_load_OGL_texture(pathString.c_str(), SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, 0);

		ss.clear();
	}

	f.close();

	return true;
}

bool ResourceLoader::LoadMeshes(DataArray<Mesh*> *meshes, const string & meshDirPath)
{
	char buffer[BUFFER_SIZE];
	int prevId = -1;

	ifstream f(meshDirPath + "\\IncludeMeshes.txt");

	if (!f) {
		return false;
	}

	stringstream ss;

	while(f.getline(buffer, BUFFER_SIZE))
	{
		ss << buffer;

		int fileId = -1;
		string meshFile;

		for(int i = 0; i < 2; i++)
		{
			ss.getline(buffer, BUFFER_SIZE, ',');
			if(i == 0)
			{
				fileId = atoi(buffer);
			}
			else
			{
				meshFile = buffer;
			}
		}

		//The data file being read must have a complete ordered list of game assets. If this is not the case then stop
		if (fileId != prevId + 1)
		{
			return false;
		}
		
		prevId = fileId;
		
		//Create new mesh* in the DataArray, import the mesh from the file and add it
		Mesh **tempMesh = meshes->CreateNew();
		*tempMesh = Mesh::LoadMeshFile(meshDirPath + "\\" + meshFile);

		ss.clear();
	}

	f.close();
	
	return true;
}

bool ResourceLoader::LoadObjectList(DataArray<DemoGameObject>* gameObjects, const string & sceneFile)
{
	char buffer[BUFFER_SIZE];

	ifstream f(sceneFile);

	if (!f) {
		return false;
	}

	stringstream ss;

	//Disregard the first line in the file
	f.ignore(500, '\n');

	while (f.getline(buffer, BUFFER_SIZE))
	{
		ss << buffer;

		//Create new GameObject in the DataArray
		DemoGameObject *import = gameObjects->CreateNew();

		for (int i = 0; i < 18; i++)
		{
			ss.getline(buffer, BUFFER_SIZE, ',');
			switch(i)
			{
				case 0: import->entityType = GameEntityType(atoi(buffer)); break;			//EntityType
				case 1: import->playerControlled = atoi(buffer) == 1 ? true : false; break;	//playerControlled
				case 2: import->hostile = atoi(buffer) == 1 ? true : false; break;			//hostile
				case 3: import->AIEnabled = atoi(buffer) == 1 ? true : false; break;		//AiEnabled
				case 4: import->physicsEnabled = atoi(buffer) == 1 ? true : false; break;	//physicsEnabled
				case 5: import->collisionsEnabled = atoi(buffer) == 1 ? true : false; break;//collisionsEnabled
				case 6: import->staticObject = atoi(buffer) == 1 ? true : false; break;		//staticObject
				case 7: import->position.x = atoi(buffer); break;							//position.x
				case 8: import->position.y = atoi(buffer); break;							//position.y
				case 9: import->position.z = atoi(buffer); break;							//position.z
				case 10: import->movementVector.x = atoi(buffer); break;					//movementVector.x
				case 11: import->movementVector.y = atoi(buffer); break;					//movementVector.y
				case 12: import->rotation = atoi(buffer) % 360; break;						//rotation
				case 13: import->meshId = atoi(buffer); break;								//meshId
				case 14: import->textureId = atoi(buffer); break;							//textureId
				case 15: import->hasTarget = atoi(buffer) == 1 ? true : false; break;		//hasTarget
				case 16: import->targetObjectId = atoi(buffer); break;						//targetObjectId
				case 17: import->lifeTime = atoi(buffer); break;							//Lifetime
			}
		}

		ss.clear();
	}

	f.close();

	return true;
}
