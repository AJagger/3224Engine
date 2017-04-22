#pragma once
#include <string>
#include "../../Core/GameObject.h"

enum GameEntityType
{
	STATIC_OBJECT = 0,
	NPC = 1,
	PLAYER = 2,
	PROJECTILE = 3,
	EFFECT = 4,
	UNINITIALISED = 5
};

class DemoGameObject : public GameObject
{
public:
	DemoGameObject();
	DemoGameObject(GameEntityType type, Mesh *mesh);
	~DemoGameObject();

	GameEntityType entityType;
	bool hasTarget;					// hasTarget &
	int targetObjectId;				// targetObjectId used for NPCs & Projectiles
	int lifeTime;					// lifeTime used for Effects

	void ConfigureDefaultStatic(Mesh *mesh);
	void ConfigureDefaultNPC(Mesh *mesh);
	void ConfigureDefaultPlayer(Mesh *mesh);
	void ConfigureDefaultProjectile(Mesh *mesh);
	void ConfigureDefaultEffect(Mesh *mesh);

};
