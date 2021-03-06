/* CSC3224 Code
* Author: Aidan Jagger | 130281034
* Class Description:
* Basic GameObject class which contains basic information relating to game engine function. When developing a game, a class inherited from this should be
* used with more specific variables.
*/

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
	//The physice object pointer points to an object managed by the physics engine and so should not need to be deleted by this class
	physicsObject = nullptr;
}
