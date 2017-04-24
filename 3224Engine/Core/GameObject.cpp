#include "stdafx.h"
#include "GameObject.h"

GameObject::GameObject()
{
	AIEnabled = false;
	physicsEnabled = false;
	entityName = "DefaultEntityObject";
	textureId = 0;
}

GameObject::GameObject(bool AIEnabled, bool physicsEnabled, std::string entityName)
{
	this->AIEnabled= AIEnabled;
	this->physicsEnabled = physicsEnabled;
	this->entityName = entityName;
}

GameObject::~GameObject()
{
}
