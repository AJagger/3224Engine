#include "stdafx.h"
#include "GameObject.h"

GameObject::GameObject()
{
	AIControlled = false;
	physicsEnabled = false;
	entityName = "DefaultEntityObject";
}

GameObject::GameObject(bool AIControlled, bool physicsEnabled, std::string entityName)
{
	this->AIControlled= AIControlled;
	this->physicsEnabled = physicsEnabled;
	this->entityName = entityName;
}

GameObject::~GameObject()
{
}
