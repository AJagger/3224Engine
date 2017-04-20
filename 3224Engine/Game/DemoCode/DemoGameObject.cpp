#include "stdafx.h"
#include "DemoGameObject.h"

DemoGameObject::DemoGameObject()
{
}

DemoGameObject::DemoGameObject(GameEntityType type, Mesh *mesh)
{
	if(type == STATIC_OBJECT)
	{
		ConfigureDefaultStatic(mesh);
	} 
	else if(type == NPC)
	{
		ConfigureDefaultNPC(mesh);
	}
	else if (type == PLAYER)
	{
		ConfigureDefaultPlayer(mesh);
	}
	else if (type == PROJECTILE)
	{
		ConfigureDefaultProjectile(mesh);
	}
	else if (type == EFFECT)
	{
		ConfigureDefaultEffect(mesh);
	}
}

DemoGameObject::~DemoGameObject()
{
}

void DemoGameObject::ConfigureDefaultStatic(Mesh *mesh)
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

	this->mesh = mesh;
}

void DemoGameObject::ConfigureDefaultNPC(Mesh *mesh)
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

	this->mesh = mesh;
}

void DemoGameObject::ConfigureDefaultPlayer(Mesh * mesh)
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

	this->mesh = mesh;
}

void DemoGameObject::ConfigureDefaultProjectile(Mesh *mesh)
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

	this->mesh = mesh;
}

void DemoGameObject::ConfigureDefaultEffect(Mesh *mesh)
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

	this->mesh = mesh;
}
