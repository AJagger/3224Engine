#pragma once
#include <string>
#include "../Renderer/nclgl/Vector2.h"
#include "../Renderer/nclgl/Mesh.h"


class GameObject
{
public:
	GameObject();
	GameObject(bool AIEnabled, bool physicsEnabled, std::string entityName);
	~GameObject();

	bool playerControlled;
	bool hostile;
	bool AIEnabled;
	bool physicsEnabled;
	bool collisionsEnabled;
	bool staticObject;
	std::string entityName;
	
	Vector2 position;
	Vector2 movementVector;
	float rotation;

	Mesh* mesh;
	
};
