#pragma once
#include "Box2D.h"
#include "Dynamics/b2World.h"
#include "../Game/DemoCode/DemoGameObject.h"
#include "Common/b2Math.h"
#include "DataArray.h"

struct CollisionMesh
{
	b2Vec2 *points;
	int pointCount;
};

class PhysicsResolver
{
public:
	PhysicsResolver();
	~PhysicsResolver();

	static b2Body* CreatePhysicsObjectFromGameObject(b2World *world, DemoGameObject *gameObject, CollisionMesh *collisionMesh);
	static void RemovePhysicsObjectFromWorld(b2World *world, DemoGameObject *gameobject);
	static void SimulateActions(b2World *world, DataArray<DemoGameObject> *gameObjects);
};
