#pragma once
#include <string>

class GameObject
{
public:
	GameObject();
	GameObject(bool AIControlled, bool physicsEnabled, std::string entityName);
	~GameObject();

	bool AIControlled;
	bool physicsEnabled;
	std::string entityName;
};
