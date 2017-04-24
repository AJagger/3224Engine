#include "stdafx.h"
#include "DemoGameObject.h"

DemoGameObject::DemoGameObject()
{
	entityType = UNINITIALISED;
}

DemoGameObject::DemoGameObject(GameEntityType type, int meshId, int textureId)
{
	if(type == STATIC_OBJECT)
	{
		ConfigureDefaultStatic(meshId, textureId);
	} 
	else if(type == NPC)
	{
		ConfigureDefaultNPC(meshId, textureId);
	}
	else if (type == PLAYER)
	{
		ConfigureDefaultPlayer(meshId, textureId);
	}
	else if (type == PROJECTILE)
	{
		ConfigureDefaultProjectile(meshId, textureId);
	}
	else if (type == EFFECT)
	{
		ConfigureDefaultEffect(meshId, textureId);
	}
}

DemoGameObject::~DemoGameObject()
{
}

void DemoGameObject::ConfigureDefaultStatic(int meshId, int textureId)
{
	entityType = STATIC_OBJECT;
	playerControlled = false;
	hostile = false;
	AIEnabled = false;
	physicsEnabled = false;
	collisionsEnabled = true;
	staticObject = true;
	entityName = "DefaultObject";

	hasTarget = false;
	targetObjectId = -1;
	lifeTime = 0;

	position = Vector2(0, 0);
	movementVector = Vector2(0, 0);
	rotation = 0;

	this->meshId = meshId;
	this->textureId = textureId;
}

void DemoGameObject::ConfigureDefaultNPC(int meshId, int textureId)
{
	entityType = NPC;
	playerControlled = false;
	hostile = false;
	AIEnabled = true;
	physicsEnabled = true;
	collisionsEnabled = true;
	staticObject = false;
	entityName = "DefaultObject";

	hasTarget = false;
	targetObjectId = -1;
	lifeTime = 0;

	position = Vector2(0, 0);
	movementVector = Vector2(0, 0);
	rotation = 0;

	this->meshId = meshId;
	this->textureId = textureId;
}

void DemoGameObject::ConfigureDefaultPlayer(int meshId, int textureId)
{
	entityType = PLAYER;
	playerControlled = true;
	hostile = false;
	AIEnabled = false;
	physicsEnabled = true;
	collisionsEnabled = true;
	staticObject = false;
	entityName = "DefaultPlayer";

	hasTarget = false;
	targetObjectId = -1;
	lifeTime = 0;

	position = Vector2(0, 0);
	movementVector = Vector2(0, 0);
	rotation = 0;

	this->meshId = meshId;
	this->textureId = textureId;
}

void DemoGameObject::ConfigureDefaultProjectile(int meshId, int textureId)
{
	entityType = PROJECTILE;
	playerControlled = false;
	hostile = false;
	AIEnabled = true;
	physicsEnabled = false;
	collisionsEnabled = true;
	staticObject = false;
	entityName = "DefaultObject";

	hasTarget = false;
	targetObjectId = -1;
	lifeTime = 0;

	position = Vector2(0, 0);
	movementVector = Vector2(0, 0);
	rotation = 0;

	this->meshId = meshId;
	this->textureId = textureId;
}

void DemoGameObject::ConfigureDefaultEffect(int meshId, int textureId)
{
	entityType = EFFECT;
	playerControlled = false;
	hostile = false;
	AIEnabled = false;
	physicsEnabled = false;
	collisionsEnabled = false;
	staticObject = false;
	entityName = "DefaultEffect";

	hasTarget = false;
	targetObjectId = -1;
	lifeTime = 0;

	position = Vector2(0, 0);
	movementVector = Vector2(0, 0);
	rotation = 0;

	this->meshId = meshId;
	this->textureId = textureId;
}
